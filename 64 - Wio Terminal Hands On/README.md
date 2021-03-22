## 64 - Wio Terminal Hands On
Available From:
[Wio Terminal](https://www.seeedstudio.com/Wio-Terminal-p-4509.html) from [Seeed Studio](https://www.seeedstudio.com/).

## 2021-03-21 Notes
* Needed to rename TFT-eSPI (?) library in libaries, so that the Seeed library would get used.
** Backlight would work but nothing else. (with correct library, backlight works on its own)
* TFT_eSPI appears to based on [this library](https://github.com/Bodmer/TFT_eSPI).

### WiFi
Followed [update instructions](https://wiki.seeedstudio.com/Wio-Terminal-Network-Overview/#step-2-flash-the-latest-firmware) but Wio does not response to RPC calls.

* Tried to update with [2.1.2 firmware](https://github.com/Seeed-Studio/seeed-ambd-firmware/releases/tag/v2.1.2): did not change behavior.

* Install rpcBLE, no change

* Downgraded rpcUnified to 2.1.1
** Deleted the directories in `~/Arduino/libraries/` for both 2.1.2 and 2.1.1
** re-installed rpcUnified 2.1.1 
** re-flashed Wio with 2.1.1 firmware (not sure if this is necessary)

### Post Stream Fixes
I realized I was making a code mistake for the MQTT client. 

Wio Terminal is connecting to my MQTT broker and is flag waving with Twitch events.

### Disclaimer
Seeed Studio sent me the unit to create a video.

## Livestream
These notes are part of Bald Engineer Live. An [electronics live stream](https://twitch.tv/baldengineer) that covers soldering, programming, and blinking LEDs.