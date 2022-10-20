# Test-LVGL833-TFT_eSPI
LVGL8.3.3を使った時に、TFT_eSPIの出力座標がおかしくなる事を確認するためのプログラムです。<BR>
<BR>
**機能**<BR>
　タッチした座標の検出結果をシリアルポートに出力します。<BR>
　画面には何も表示しません。真っ白です。<BR>
**環境**<BR>
　LVGL 8.3.3<BR>
　TFT_eSPI<BR>
　ArduinoIDE 1.8.19<BR>
　ESP32<BR>
　ILI9341 320x240 with touch<BR>
**問題と対策**<BR>
　TFT_eSPIから出力される touchX,touchY の値が伸縮されて出力されます。<BR>
　その問題点を補正しています。プログラムの26〜27行目が該当する箇所です。<BR>
**詳細**<BR>
　タッチ検出位置のフルスケール値が、X,Yが逆になっています。<BR>
　本来はtouchXは0〜320であり、TFT_eSPIのキャリブレーションパラメータ検出プログラムの出力もそうなっています。<BR>
　しかし、touchXは0〜240の範囲で出力されます。Yの範囲が反映されています。<BR>
　同様にtouchYの出力範囲も0〜320に拡大されています。<BR>
　プログラムの26〜27行目が該当する箇所で、XとYのフルスケール比で補正すれば正しい値が得られています。<BR>
**補足**<BR>
　lv_arduino3.0.1を使うと正しい座標が得られます。<BR>
　TFT_eSPIのcalData出力プログラム"Touch_calibrate"からの座標出力も正しい値が得られます。<BR>
　LVGL8.3.3を使うと座標が伸縮されます。<BR>
　しかし、伸縮された座標が出力されているのはTFT_eSPIからの座標出力の部分です。<BR>
   
   
