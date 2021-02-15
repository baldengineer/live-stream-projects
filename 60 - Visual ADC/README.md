## 60 - Visual ADC Notes
Desinging a successive-approximation-registor analog-to-digital-converter. Otherwise known as a SAR ADC. 

My plan is to enter this project into an [element14 Community](https://element14.com/?ICID=baldengineer) contest. The [Project14 - Data Conversion](https://www.element14.com/community/community/project14/dataconversion?ICID=baldengineer) contest is all about, well, converting data.

Instead of a project involving data conversion, I wanted to build a discrete ADC. My pick is a "successive-approximation-registor" (SAR) ADC. Why? Because it needs a digital-to-analog converter to work! Also, because I think it would look really cool to have some LEDs and Relays when it runs. 

## 2021-02-14 Streawming Notes
Old In:
x = 123.947
y = 116.16166

Old Out:
x = 148.2548
y = 116.16166

## 2021-02-10 Streaming Notes
* Created repo for the project's design files: [files here](https://github.com/baldengineer/VADC-visualized-adc).

## 2021-02-07 Streaming Notes
Small Signal Realy from MCP [MC25120]: http://www.farnell.com/datasheets/3176363.pdf
	KiCad Footprint: Relay_THT:Relay_SPDT_HsinDa_Y14

* Planning to build 4 bit, but desgin can go to many more (why not 8?!)
* Individual boards for each "bit" of the R-2R
* Reverse Mounted LEDs to "light-up" the relays
* Shift-registers to control LEDs and relays
* "Playback mode" to show how the ADC got to the final value
* WS2812 on the input and output to match when value is achievedf
* SAR done in code by arduino (and to do some of the visualization)
* Clock button to step through conversion process 


## Livestream
These notes are part of Bald Engineer Live. An [electronics live stream](https://twitch.tv/baldengineer) that covers soldering, programming, and blinking LEDs.