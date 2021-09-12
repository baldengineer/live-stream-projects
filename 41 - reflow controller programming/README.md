# 41 - Reflow Controller V2

## 2021-09-12 Stream Notes
In Feburary 2021, we re-designed the Open Vapors reflow controller control board. It successfully soldered and powered-up on the first try. During a programming stream, new features and capabilities were attempted. That stream ended with trying to do *something* with the RTC.

On this 9/12 stream, we pick up where that one ended. 

Know things that need to be fixed:
* Is power wired correctly?
* Front Panel
* Date time
 * Tell date time to "use this value"
 * update date/time (through UI/serial)
 * get current time (print UI/serial)
 * get a timestamp (for datalogging)
* Buzzer
* Bluetooth (BLE Serial)
* SSR Testing

### Did Thermal Runaway get implemented?
In the Feb stream, I said I should implement thermal runaway. But I remember working on that. So I need to double check if the code has it.

# live stream projects
 Bald Engineer's Livestream projects

Working repo for projects while I live stream. If the project evolves more, it will get moved to its own repo.

This repo is not intended to be a statement-of-record. Just a place to dump stuff while I work on it, so the best chat on the internet can help. :) Hi Chat!

https://twitch.tv/baldengineer