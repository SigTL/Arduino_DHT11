# Arduino_DHT11
Sketches for DHT11 temperature &amp; humidity sensor
DHT11_testWithLeds is based on the DHTTester sketch written by ladyada, public domain

REQUIRES the following Arduino libraries:
DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

Note to get timestamped temperature and humidity values out of the Arduino, use PuTTY to connect via Serial connection
On the logging tab, specify a directory and a file name - use a .csv file extention 
After failing to connect, I searched and found that you have to run PuTTY as root! so do this command to open in linux:
$ sudo putty
Make sure you connect to the same USB port that the Arduino is connected to as well.

I noticed I don't have date/timestamp data in my serial data so that will have to be a future improvement. 
Some of the output data gets garbled every few lines like it did not write correctly. I am not sure why, perhaps slowing the process will help. I have a few delays built in already and it writes data about every 5 seconds.
