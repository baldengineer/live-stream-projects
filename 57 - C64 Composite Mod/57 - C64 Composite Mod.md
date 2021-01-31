## C64 Composite Mod (Bypass RF Modulator)

"Based" on:
https://github.com/c0pperdragon/C64-Video-Enhancement

TI part is only available in SOIC packge, but the KiCad design above uses SSOP. However, verifying measurements in library and datasheet show they should match.

What is JPLUM1?
https://github.com/c0pperdragon/C64-Video-Enhancement/issues/51
> You can install this mod in a short board by connecting the 2 times 4 pins only, as these already have a GND connection.

JPLUM1 needs to be closed when running with a 12 volt VIC - these are the older variants used in the long boards. This changes the resistor value needed for attenuating the luma signal. For for a short board you will leave this bridge open.