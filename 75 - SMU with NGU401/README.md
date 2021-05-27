## 75 - SMU measurement with NGU401
Learning about Source Measurement Units with the Rohde & Scwharz NGU401.

## Links
* [Rohde & Schwarz NGU401](https://www.rohde-schwarz.com/us/products/test-and-measurement/dc-power-supplies/rs-ngu-source-measure-units_63493-1005128.html)
* [Manual](https://www.rohde-schwarz.com/us/manual/r-s-ngu-source-measure-units-user-manual-manuals-gb-sg_230144-1029972.html)
* ~~[NGU401 sweep tool and application note](https://www.rohde-schwarz.com/us/applications/sweep-tool-for-r-s-ngu201-ngu401-and-ngm200-application-note_56280-1029542.html)~~
  * Nevermind, the tool does not appear to work.


## 2021-05-25 Stream Notes
* Interesting Uno behavior... draws LESS current when the serial monitor is open.
* Constant resistance
  * 25 ohm, 1.98V, 77 mA
  * 1000 ohm, 5.014V, 4.95mA
  * 250 ohm, 4.6V, -18mA
  		
### Experiement Ideas
* V-I curve for a diode
* Measure current draws on:
  * ESP32
  * Raspberry Pi
  * Arduino Nano Every vs others?
  * Measure max current on an Arduino pin
    * see how long an LED lasts with that current

## Disclaimer
The [element14 Community](https://element14.com/workbenchwednesdays) sent me this unit. I am borrowing it from the Road Test program to create a Workbench Wednesdays episode on it.

## live stream projects
Bald Engineer's Livestream projects

Working repo for projects while I live stream. If the project evolves more, it will get moved to its own repo.

This repo is not intended to be a statement-of-record. Just a place to dump stuff while I work on it, so the best chat on the internet can help. :) Hi Chat!

https://twitch.tv/baldengineer