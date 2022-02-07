## 74 - Golden Delicious

Creating a mini Apple //e using original hardware.

## Link to Design Files
* https://github.com/baldengineer/Golden-Delicious

## 2022-02-06 Stream Notes
Joystick stuff:
x: pdl(0)
y: pdl(1)
```
10 print pdl(0);",";pdl(1)
20 goto 10
```

Joystick buttons are Open and Closed Apple Keys! 
open apple: `peek(49249)`
close apple: `peek(49250)`

[Applesoft BASIC Frequency Asked Questions](https://fjkraan.home.xs4all.nl/comp/apple2faq/app2asoftfaq.html)

CPx output time:
* Min time is: 400us(?)
* Max time is: 7ms? (totally forgot now)

Geek has [math in discord](https://discord.com/channels/369243434080272385/843878836471201902/940097887281483778) on it.


## 2022-01-14 Stream Notes
(Am I still putting them here?)

```
// N-Key Roll Over on the IIe

Press key0, repeat key0
if key1 is pressed, then report key1 and repeat key1
keep repeating key1 until no more pressees


AAAAAAAAAAAAAAAAAAAAAAAAAAAAASSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS

AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAASSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS

as

asasasasasasasasasasasas
asasasasasasasasasasasasas
asasasasasasasasasasasasasasdssdsd

sdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsfsfsfsfsfsfsfsfsfqppqqpqpqp

qpqpqpqpqpqppqqpqppqsaasasasasasasasasasasasas

// todo: what happens on USB reports when you get more than 4 (or 6 or whatever)?

instead of 'any key' make it 'last key' and have it set to null if no key is pressed

while (any_key_pressed) {
    key0 is pressed
        write_key(key_value)

    key1 is pressed
        write_key(key_value)    
}

raise_key();

report: 4,22,0,0,0,0,
report: 4,22,7,0,0,0,
report: 4,22,7,9,0,0,
report: 4,22,7,0,0,0,
report: 4,22,7,11,0,0,```


## 2021-11-14 Stream Notes
Oh, by the way, we can boot from disks. Like, real ones.

* This is the 8-bit and 7-bit strings for the Apple //f (0x03FA, in ROM file)
C1 F0 F0 EC E5 A0 DD DB
41 70 70 6C 65 20 5D 5B
 A  p  p  l  e     ]  [
 
41 70 70 6C 65 20 

## 2021-10-20 Stream Notes
Left Arrow: 80
Right Arrow: 79
Up Arrow: 82
Down Arrow: 81
ESC: 41
Tab: 43
Enter: 40

CLR/Home: 74
Restore: 70
40/80 Display: 71
Run Stop: 72
F1-F12: 58 to 69

## 2021-10-17 Stream Notes
`PR#4` returned:
```
MMU FLAG E4:4
IOU FLAG E5:1
```
LA shows address loop:
```
C510
C511
C512
```
which is also on the data bus

### Slotmaker is acting like a IIgs
`C02D` is enable for slotmaker to switch between internal and cards.

`0x02` enables the slot card 1

pg 183 (Chapter 8 I/O Expansion Slots) in the IIgs hardware reference



## 2021-10-14 Discord VC Notes
We met to discuss how C000 and C010 work. It was realized that the strobes for each are different signals. It is still unclear how the IOU and MMU in the IIe work together to determine WHICH switch is being hit. But, we at least understand what software expects to happen. (and we think we understand how the IIgs's KBDGLU and MEGA talk to each other.)

```
Reqs:
 1. MD6:0 out of the PIO

 2. Tasks:
         1. enabling the 245 during data phase AND
             C000 READ + KEYRDY
             C010 READ + ANYRD
    
         2. C010 READ or WRITE, clear KEYRDY
---
$C000 Keyboard data and KEYRDY
    Combo flag and switch

$C010 Keyboard Data and ANYKEY, 
    but also clears KEYRDY

```
## 2021-10-10 Stream Notes
RP2040 booting with 0x00 0x20 as the keyboard key, causes a "p00p boot" and a overflow error (that types slowly).

Booting with 0xA0 or 0xC1 (0x20 and 0x41 with anykey bit set), it seems to boot okay and types stupid fast. :)

### Trying to explain difference between C000 and C010
```
Cxxx

C000 -> Checking if a key has been pressed
C010 -> Clearing the pressed flag

; bit 7 (8th) is the ANYKEY strobe
-> C000
<- 0x00  ?010 0000

-> C010
<- 0xC1 1100 0001
        0100 0001

-> C000
<- 0x41 0100 0001
```

### KSELx notes that used to be in the PIO:
```
; KSEL0 to go HIGH
; KSEL1 and KSEL1 to be LOW
; RW to be HIGH
; PH0 low or high?
; ---
; KSEL2 go LOW
; KSEL1 is low?
; KSEL0 is HIGH or LOW
;
; KSEL0 is HIGH AND R/W is HIGH
; then we'll put data out when PH0 goes HIGH
; --or--
; KSEL1 is LOW and R/W is LOW 
; then we'll put data when PH0 goes HIGH 
; and then clear high bit of keyboard value

; AKD  1=key pressed 0=keys free
;
;; if KSEL0 == LOW and R/W == LOW, then do nothing
;; if KSEL0 == LOW and R/W == HIGH, then we put value on the bus
;; --
;; if KSEL0 == HIGH and R/W == XX, then we put value on bus and clear it
;;
```

## 2021-09-08 Stream Notes
* Link to (branched) prototyping pcb files: https://github.com/baldengineer/Golden-Delicious/tree/gd-protoboard-pcb-rev1/kicad%20files/gd%20protoboard%20pcb

## 2021-08-04 Stream Notes: So close...
### AKA, the Day of the first boot:
* https://clips.twitch.tv/DarlingOddAdminOSsloth-mlyplWCnhfDNCTM2
Links to help:

ROM Disassembly. There are two separate ROM files in the IIe. Boot process switches 
between them. Each defines different soft switches. 
* IIe Monitor ROM (Fxxx): https://6502disassembly.com/a2-rom/Unenh_IIe_F8ROM.html
* IIe 80-col ROM (Cxxx):  https://6502disassembly.com/a2-rom/Unenh_IIe_80col.html

Design Files for the three prototype boards available here.
* Golden Delicious Deisgn Files: https://github.com/baldengineer/Golden-Delicious
 * Also, decoders/symbol tables for IIe ROM and 6502: https://github.com/baldengineer/Golden-Delicious/tree/master/waveforms%20decoders

 Good resource for understanding 6502 instructions:
* https://www.masswerk.at/6502/6502_instruction_set.html#BPL

6502 Disassembly Plugin for HxD:
* https://github.com/DigicoolThings/HxD_DasmDataInspectorPlugin

---
* Why does SET80COL and KBD both share the $C000 soft switch?
 * squire: one is read and one is write, 

### Patched ROM to skip DIAGS (since no keyboard is attached)
 ```
 $C23F: jmp $C264

c23f: 0x4c 0x64 0xc2
nop nop
nop nop nop
nop nop


1010
1011
1100
```



## 2021-07-25 Stream Notes: Kinda boot?
Need to tie NMI, RDY, IRQ to HIGH for boot
RESET low then HIGH


## 2021-07-07 Stream Notes: IIe Keyboard Emulator
ANY_KEY to KEY_RDY is approxmiatley 13ms
    what clears any_key? active for about 100ms

KEY_RDY asserts (high) for 22us

KBD (at basic prompt) strobes every 22us



## 2021-05-14 Stream Notes
* What is "SERVIDEO"?
** From rjhelms: [classic NTSC output on MEGA II](https://comp.sys.apple2.narkive.com/WPcrB0W0/classic-ntsc-output-for-the-apple-iigs)
* [Adafruit 1.5" Diagonal TFT w/ composite](https://www.adafruit.com/product/910) from Al




## live stream projects
 Bald Engineer's Livestream projects

Working repo for projects while I live stream. If the project evolves more, it will get moved to its own repo.

This repo is not intended to be a statement-of-record. Just a place to dump stuff while I work on it, so the best chat on the internet can help. :) Hi Chat!

https://twitch.tv/baldengineer