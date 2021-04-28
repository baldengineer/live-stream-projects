## 71 - Build 500 Project

To celebrate element14 Presents' 500th build episode, they are challeging three of the video hosts to build a a project using 6 components.

I have to use all of these components, but can add others.

The project / build I am attemping is a Star Trek: The Next Generation style Tricorder. 


### Links 
* [Build Inside the Box Competition Overview](https://www.element14.com/community/docs/DOC-96290/l/build-inside-the-box-500?ICID=baldengineer)
* [Build Inside 500 Contents](https://www.element14.com/community/docs/DOC-96361/l/build-inside-the-box-whats-in-the-box-member-challenge?ICID=baldengineer)
* [Vishay Photointerruptor - TCST1130](https://www.vishay.com/docs/83764/tcst1103.pdf) 
* [Github repo with code (and, eventually, design fles](https://github.com/baldengineer/baldcorder-mk1)

## 2021-04-25 Stream Notes
* on the 128x64, 9pt non-bold, 3 lines down, 12 characters across
* c++ pointers, from d3jake: `The syntax is to use . when accessing the member variable/function of an object. If you are accessing the member variable of an object via pointer, you use ->`

## 2021-04-23 Stream Notes
* Removing WAV header: Deleted from the end of the word "data" to the first 0x80. Should be 44 bytes.

## 2021-04-21 Stream Notes
* [Audio Library Link to play WAV on SAMD21](https://github.com/BriscoeTech/SamdAudio)
* [Arduino i2c scanner](https://playground.arduino.cc/Main/I2cScanner/)

### behaviors
Pieces connected to the MKR ZERO: 128x64 I2C OLED, 128x32 SPI OLED, Temp Sensor, VL53L0X, Speaker/Op-Amp on DAC0, 4 capacitive touch buttons, "light" sensor.

Bashed together code "works." With issues. The sound routine is still dropping the DAC to 0 volts for some reason. There are also brief moments where the audio drops out. These moments seem to coincide with errors on the 128x64 I2C OLED, which was displaying the VL53L0X output. Not sure if the issues are related.

Had to replace the wires on the VL53L0X to get good I2C behavior. Chat suggested the SHUTDN pin on the VL53 is floating. But pulling it high does not seem to fix I2C communication. If I2C-bus locks up again, try pulling that pin high (it is next to the SDA pin on the breakout board.)

### Veritcal OLED
Make sure to set to SSD1306_WHITE to actually see it ;)
DC, yellow, d7
RST, red, d6
CS, org, d5

Other display: i2c, 0x3c



## 2021-04-18 Stream Notes
Off stream, I got capacitive touch buttons to work. You can see them in this [Instagram post](https://www.instagram.com/p/CNtmSBfjlO5/?utm_source=ig_web_copy_link).






Tried with four resistor values:
* 4.7K: stuck closer to open and wasn't very sensitive to light
* 220: barely worked, stayed open
* 60K: decent dynamic range, good sensitivity
* 100Kish: slightly better than 60K but had harder time going to open

## 2021-04-13 Stream Notes
* [MCP603 Op Amp](https://www.microchip.com/wwwproducts/en/MCP603)

# live stream projects
 Bald Engineer's Livestream projects

Working repo for projects while I live stream. If the project evolves more, it will get moved to its own repo.

This repo is not intended to be a statement-of-record. Just a place to dump stuff while I work on it, so the best chat on the internet can help. :) Hi Chat!

https://twitch.tv/baldengineer
