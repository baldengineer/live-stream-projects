## 62 - Nano 1541
Access a Commodore 1541 from an Arduino Nano 33 IoT

Design files: https://github.com/baldengineer/Arduino-1541

Using Sparkfun's level-shifter as reference: https://learn.sparkfun.com/tutorials/bi-directional-logic-level-converter-hookup-guide


## Commmodore DOS commands for the 1541
[Summerized from Jay Versluis's post](https://wpguru.co.uk/2014/06/commodore-1541-dos-commands/).
### open a channel
`OPEN 15,8,15`  (channel, device,?)
### issue command
`PRINT#15, "command"`
### close the channel
`CLOSE 15`
* SAVE or LOAD closes the channel

### Reading Error Channel
```
10 OPEN 15,8,15
20 INPUT# 15,a,b$,c,d
30 PRINT "error number: ";a
40 PRINT "error name: ";b$
50 PRINT "on track: ";c
60 PRINT "sector: ";d
70 CLOSE 15
```


### Format a Flopy disk
`PRINT#15,"NEW0:disktitle,id"`
* Note: `N0` also works instead of `NEW0`
* Note: `0` and `1` are for dual-drive systems (two drives in one unit, like old PET drives)
* Not including id clears BAM, no sectors

### Initialize
`PRINT#15,"INITALIZED0"`
* Reads BAM into drive's memory (not a format)

### Copy Files
`PRINT#15,"COPY:foo=bar"`

### Rename Files
`PRINT#15,"RENAME0:foo=bar"`

### Delete Files
`PRINT#15,"SCRATCH0:foo"`

### Validate (repair)
`PRINT#15,"VALIDATE"` (no drive select?)





#### Channels
* 0 and 1: OS to transfer files
* 2-14: User Channels (isn't screen one of them?)
* 15: Common for drive communication



## 2021-03-26 Streaming Notes
Soldering the interposer and breadboard breakout board. Then we're going to try and capture some traffic on a scope or logic analyzer between a C64 and disk drive.

## 2021-03-14 Streaming Notes
Happy Pie Day!!

## Livestream
These notes are part of Bald Engineer Live. An [electronics live stream](https://twitch.tv/baldengineer) that covers soldering, programming, and blinking LEDs.