## 56 - 555 Timer Measurements

### Background
To test the voltage coefficient of a ceramic capacitor, I built a simple 555 timer circuit. The idea was to change VCC and see if the frequency changed with it. In that video (and that stream), I made a mistake. I assumed that the full VCC got applied to the timing capacitor. But that isn't the case. Now I want to see how a 555 really works.

1. element14 Episode: [MLCC Voltage Coefficent](https://www.element14.com/community/docs/DOC-95781/l/workbench-wednesday-30-ceramic-capacitor-voltage-effect?ICID=baldengineer)

### 555 meausrements ... CAPS node vs. VCC
@ 5.1 VCC
Caps Vp+ = 3.3 V

@ 8 VCC
Caps Vp+ = 5.4 V

VCC		Caps V+
9		6.0		66%
8		5.4		68%
7		4.7
6		4.0
5		3.3
4		2.6
3		2.0

### 555 Meausrements CAPS charge and discharge at VCC=10V with 0201
charge: 2.13ms
discharge: 325 us

R1 = 6.8 K
R2 = 10 K
C = 1 uF 
Freq = 360 Hz (also saw 400 Hz)





### Stream History
2020-09-25: Soldering and Measurement Stream
2020-12-14: Measurement Stream
