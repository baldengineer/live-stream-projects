## 59 - Logic Level Demos 
What happens when you combine chips from the LS family with chips from the HCT or other 4000/7400-series families? Let's find out!

- [TI Logic Guide App Note - sdyu001ab](https://www.ti.com/lit/sg/sdyu001ab/sdyu001ab.pdf?ts=1612010759614)
- [On Semi Introduction to and Comparison of 74HCT TTL - AN 368](https://www.onsemi.com/pub/Collateral/AN-368.pdf)
- [7400 Series Info - Wikipedia](https://en.wikipedia.org/wiki/7400-series_integrated_circuits)

## Things to measure
- Input (and output) voltage levels
- Propigation delay
- edge rate (in vs. out)
- Max frequency?
- EMI

- Threshold input voltage changing with sine wave/slow edge on different families


## Raw Parts List

### Analog Switch
- CD4066BE (DIP) and 74HC4066D (SOIC)

### Inverter
- CD4049UBE (DIP) [74xx drive], 
- CD4041UBE (DIP) [CMOS buffer], 
- 74HCT04 (SOIC), 
- SN74AHCT1G14DBVR (single gate HCT), 
- NC7S04M5X Single Gate (S?), 
- SN74AHCT04D (SOIC)
-    
- 74HC14D, Hex Inverter, Schmidtt Trigger (SOIC)
-   
- 74S04, Hex Inverter, DIP, only one available

### Single Gates
- 74 VHC 1G 14 - 10 (these were super cheap, but schmidtt)
- 74 HC  1G 14
- 74 AHC 1G 04 - advanced HC
- 74 HC  1G 04 *** lost it
- 74 LVC 1G 04

Newark #10M5369, captial SOT to SIP adapter



## 2021-02-03 Stream Measurements

Prop Delay input 0 to 5 volt
		Prop-LH	RT 		FT
AHCT - 12ns 	4ns	   2.4ns
HCT  - 16ns		2.3ns  2ns
HC  -  1.8ns	2.5ns  2.2ns
LS  -  20ns    	20ns   6ns
S   -  16ns     2.5ns  2.5ns
TTL -  17.5ns   5.2ns  3.4ns

Prop delay input 0 to 3 volt
AHCT - 2ns
HCT  - 6ns
LS   - 6ns
S    - 4ns
TTL  - 6ns




## Livestream
These notes are part of Bald Engineer Live. An [electronics live stream](https://twitch.tv/baldengineer) that covers soldering, programming, and blinking LEDs.