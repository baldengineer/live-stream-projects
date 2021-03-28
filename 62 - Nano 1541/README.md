## 62 - Nano 1541
Access a Commodore 1541 from an Arduino Nano 33 IoT

Design files: https://github.com/baldengineer/Arduino-1541

Using Sparkfun's level-shifter as reference: https://learn.sparkfun.com/tutorials/bi-directional-logic-level-converter-hookup-guide


## Commmodore DOS commands for the 1541
[Summerized from Jay Versluis's post](https://wpguru.co.uk/2014/06/commodore-1541-dos-commands/) and [Commodore DOS Wikipedia](https://en.wikipedia.org/wiki/Commodore_DOS) page.

### command string
`0:ADDRESSBOOK,S,W`
#### Save BASIC program as a SEQ
`SAVE "0:FILE,SEQ,WRITE",8,1`

### open a channel
`OPEN 15,8,15`  (channel, device,?)
### issue command
`PRINT#15, "command"`
### close the channel
`CLOSE 15`
* SAVE or LOAD closes the channel

### Reading Error Channel
Has to be run as a BASIC program because `INPUT#` doesn't work in direct mode.
```
10 OPEN 15,8,15
20 INPUT# 15,a,b$,c,d
30 PRINT "error number: ";a
40 PRINT "error name: ";b$
50 PRINT "on track: ";c
60 PRINT "sector: ";d
70 CLOSE 15
```
Alternative method:
`OPEN 1,8,15:INPUT#1,E,E$,T,S:PRINT E,E$,T,S:CLOSE 1`

* Note: `0` and `1` are for dual-drive systems (two drives in one unit, like old PET drives)

### Format a Flopy disk
`PRINT#15,"NEW0:disktitle,id"`
`PRINT#15,"N0:disktitle,id"`


* Not including id clears BAM, no sectors

### Initialize
`PRINT#15,"INITALIZE:0"`
`PRINT#15,"I0:"`
* Reads BAM into drive's memory (not a format)

### Copy Files
`PRINT#15,"COPY:foo=bar"`
`PRINT#15,"C0:NEW=0:OLD"`

### Rename Files
`PRINT#15,"RENAME0:foo=bar"`
`PRINT#15,"R0:foo=bar"`

### Delete Files
`PRINT#15,"SCRATCH0:foo"`

### Validate (repair)
`PRINT#15,"VALIDATE"` (no drive select?)

#### Channels
* 0 and 1: OS to transfer files
* 2-14: User Channels (isn't screen one of them?)
* 15: Common for drive communication


## 2021-03-27 Streaming Notes
### Happy Arduino Day!

[This page on pagetable](https://www.pagetable.com/?p=1135) has a great explanation of the physical layer.


## 2021-03-26 Streaming Notes
Used the wrong pinout on the DIN6 connector.
`
PCB   C64
---------
DAT = DAT - Green
ATN = CLK - Blue
SRQ = ATN - Purple
`

Soldering the interposer and breadboard breakout board. Then we're going to try and capture some traffic on a scope or logic analyzer between a C64 and disk drive.

151DEC, 97 HEX, 1001 0111
                1000 0111

199DEC, C7 HEX, 1101 0111
D7

---`
Host  Device
0x14			0001 0100 -> 1101 0111 B7
0xF6			1111 0110 -> 1001 0000 90
	  0x92		1001 0010 -> 1011 0110 B6
	  0x0C		0000 1100 -> 1100 1111 CF
	  0x5C		0101 1100 -> 1100 0101 C5
	  0xB0		1101 0000 -> 1111 0100 F4
0xFC
`---
Bus is definitely LSB first. Data appears to be CLK falling edge and polarity is "normal."

### magicaros Full IEC
 LISTEN DEV -> OPEN CHAN -> SEND FILENAME -> UNLISTEN ALL -> TALK DEV -> REOPEN CHAN -> DEVICE become master of the bus -> DATA TRANSFER -> C64 master again -> UNTALK ALL -> LISTEN -> CLOSE CHAN -> UNLISTEN ALL

## 2021-03-14 Streaming Notes
Happy Pie Day!!

## Livestream
These notes are part of Bald Engineer Live. An [electronics live stream](https://twitch.tv/baldengineer) that covers soldering, programming, and blinking LEDs.


