## 74 - Golden Delicious

Creating a mini Apple //e using original hardware.

## 2021-08-04 Stream Notes: So close...
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