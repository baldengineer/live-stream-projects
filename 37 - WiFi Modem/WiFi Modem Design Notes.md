## 2020-12-09 Correct db25 ... finally
On Line Phone panel, threads are:
	ISO Metric
	6.0 mm
	M6 x 1
	6g
	Right hand

Create -> Thread on a face (like cylinder)
Make sure to selected Modeled


## 2020-12-06 "RS-232" Testing

DTE to DCE explantions
https://gridconnect.zendesk.com/hc/en-us/articles/115008733428-DB-9-Serial-Pinouts-DCE-DTE-Gender-and-Null-Modems-with-RS232

db25 connector graphic from:
http://www.softelectro.ru/db25.jpg

Should be able to simulate null modem, using the back panel's
pin-headers.

Need to swap for DCE:
   RXD to TXD
   DTR to DSR
   DSR to DTR
   RTS to CTS
   