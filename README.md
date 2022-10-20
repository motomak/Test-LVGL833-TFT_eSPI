# Test-LVGL833-TFT_eSPI
This program is to confirm that the output coordinates of TFT_eSPI are wrong when using LVGL8.3.3.
<BR>
<BR>
**Feature**<BR>
　Outputs the detection result of touched coordinates to the serial port.
<BR>
　Nothing is displayed on the screen. It is blank.<BR>
**environment**<BR>
　LVGL 8.3.3<BR>
　TFT_eSPI<BR>
　ArduinoIDE 1.8.19<BR>
　ESP32<BR>
　ILI9341 320x240 with touch<BR>
**Problems and Countermeasures**<BR>
　The touchX and touchY values output from TFT_eSPI are stretched.<BR>
　The problem is corrected. Lines 26-27 of the program are the relevant sections.<BR>
**Details**<BR>
　The full scale value of the touch detection position is reversed in X and Y.<BR>
　Originally, the touchX range was 0-320. The output of the calibration parameter detection program was also 0-320.<BR>
　However, touchX outputs a range of 0 to 240, reflecting the Y range.<BR>
　Similarly, the touchY output range is expanded from 0 to 320.<BR>
　Lines 26-27 of the program are the relevant sections.Correcting for the full scale ratio of X and Y results in the correct value.<BR>
<BR>
　Using <a href="https://github.com/lvgl/lv_arduino">lv_arduino3.0.1</a>, I got the correct coordinates.<BR>
　The coordinate output from the program "<a href="https://github.com/Bodmer/TFT_eSPI/blob/master/examples/Generic/Touch_calibrate/Touch_calibrate.ino">Touch_calibrate</a>" (TFT_eSPI) to get the calData also has the correct values.<BR>
　Coordinates were expanded only when using LVGL 8.3.3.<BR>
　However, the stretched coordinates are output from TFT_eSPI.<BR>
　It is inexplicable.
