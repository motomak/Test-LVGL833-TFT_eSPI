# Test-LVGL833-TFT_eSPI
This program is to confirm that the output coordinates of TFT_eSPI are wrong when using LVGL8.3.3.
<BR>

**Feature**<BR>
　Outputs the touched coordinates to the serial port.
<BR>
　Display nothing on the screen. It is blank white.<BR>
<BR>

**environment**<BR>
  - LVGL 8.3.3<BR>
  - TFT_eSPI<BR>
  - ArduinoIDE 1.8.19<BR>
  - ESP32<BR>
  - ILI9341 320x240 with touch<BR>
<BR>

**Problem**<BR>
　The full scale value of the touch detection position output from TFT_eSPI are swapped among X and Y.<BR>
<BR>

**modification**<BR>
　Lines 26-27 of the program<BR>
　Correcting the full scale values of X and Y.<BR>
<BR>

**checks**<BR>
  - Using <a href="https://github.com/lvgl/lv_arduino">lv_arduino3.0.1</a>, TFT_eSPI output the correct coordinates.<BR>
  - Using <a href="https://github.com/Bodmer/TFT_eSPI/blob/master/examples/Generic/Touch_calibrate/Touch_calibrate.ino">Touch_calibrate</a>" (TFT_eSPI), TFT_eSPI output the correct coordinates.<BR>
  - Coordinates were expanded when using LVGL 8.3.3.<BR>
<BR>
However, the stretched coordinates are output from TFT_eSPI.<BR>
It is inexplicable.
