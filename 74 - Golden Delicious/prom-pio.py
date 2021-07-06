# PIO ROM emulation testing
# PIO puts valid data out about 40ns after the "enable" signal asserts
# actual Keyboard ROM in the Apple IIe takes about 100 ns.
# @baldengineer

import time
import board
import rp2pio
import adafruit_pioasm

iie_rom = """
.program iie_rom

; output pins : 21-27 (GP16-GP22)
; enable input: 31 (GP26)

mov x, null        ; fallback char if TX FIFO is empty
mov y, null        ; will store last decoded character

loop:
    wait 0 gpio 26     ; wait for ENABLE to assert
    pull noblock       ; if empty, MOV OSR, X

    ; check if there is a new character
    mov x, osr
    jmp !x output      

    ; mmmm fresh char, save for later
    mov y, x           

output:
    mov osr, y         ; repeat previous if not new
    out pins, 7        ; load out_pins register (7 bit data) from OSR
    mov osr, ~ null    ; load FFs into OSR (for change to output)
    out pindirs, 7     ; shift 7 FFs into pin direction register from OSR

    mov osr, null      ; load 0s into OSR (for change to Hi-Z)
    wait 1 gpio 26     ; wait for ENABLE to de-assert
    out pindirs, 7     ; shfit 7 0s into pin dir register from OSR

    mov x, null        ; reset x for next iteration
    jmp loop           ; do it again!

"""

assembled = adafruit_pioasm.assemble(iie_rom)

sm = rp2pio.StateMachine(
    assembled,
    frequency=125_000_000,
    first_out_pin=board.GP16,  # pin 21 (bottom right corner)
    out_pin_count=7,
    initial_out_pin_direction=0,
    first_in_pin=board.GP26,   # pin 31
)

print("real frequency", sm.frequency)
x=0 # simple counter for a lively display
print(".")
while True:
    time.sleep(0.1)
    sm.write(bytes((x,)))
    x = x + 1
    if (x >= 127):
        print(".")
        x=0
