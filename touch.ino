//LVGL8.3.3
#include <lvgl.h>
#include <TFT_eSPI.h>
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 240;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];
TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight);

void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p ){
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );
    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();
    lv_disp_flush_ready( disp );
}
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * dat ){
    uint16_t touchX, touchY;
    bool touched = tft.getTouch( &touchX, &touchY, 600 );
    if( !touched ){
        dat->state = LV_INDEV_STATE_REL;
    }else{
        dat->state = LV_INDEV_STATE_PR;
        dat->point.x = touchX*4/3;
        dat->point.y = touchY*3/4;
        Serial.print( " x:" ); Serial.print( dat->point.x );
        Serial.print( " y:" ); Serial.println( dat->point.y );
    }
}
void setup() {
    Serial.begin( 115200 );
    lv_init();

    tft.begin();
    tft.setRotation(3);
    uint16_t calData[5] = { 388, 3516, 241, 3525, 1 };
    tft.setTouch(calData);
    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );

    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register( &indev_drv );
}

void loop() {
    lv_timer_handler();
    delay(5);
}
