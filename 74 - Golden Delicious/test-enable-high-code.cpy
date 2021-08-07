# PIO ROM emulation testing
# PIO puts valid data out about 40ns after the "enable" signal asserts
# actual Keyboard ROM in the Apple IIe takes about 100 ns.
# @baldengineer

import array
import time
import board
import rp2pio
import adafruit_pioasm

iie_rom = """
.program iie_rom

; output pins : 21-27 (GP0-G7)
; enable input: 31 (GP14)

mov x, null        ; fallback char if TX FIFO is empty
mov y, null        ; will store last decoded character

loop:
    wait 0 gpio 14     ; wait for ENABLE to assert
    pull noblock       ; if empty, MOV OSR, X

    ; check if there is a new character
    mov x, osr
    jmp !x output      

    ; 0000 0000 0000 0000 1XXX XXXX 0XXX XXXX
    ; mmmm fresh char, save for later
    mov y, x
    out pins, 8
    jmp one_time_out

output:
    mov osr, y         ; repeat previous if not new
one_time_out:
    out pins, 8        ; load out_pins register (7 bit data) from OSR
    mov osr, ~ null    ; load FFs into OSR (for change to output)
    out pindirs, 8     ; shift 8 FFs into pin direction register from OSR

    mov osr, null      ; load 0s into OSR (for change to Hi-Z)
    wait 1 gpio 14     ; wait for ENABLE to de-assert
    out pindirs, 8     ; shfit 8 0s into pin dir register from OSR

    mov x, null        ; reset x for next iteration
    ; clear MSB in Y  (?XXX XXXX)
    ; shift left 33 times
    ; shift right 32 times

    jmp loop           ; do it again!


"""

assembled = adafruit_pioasm.assemble(iie_rom)

sm = rp2pio.StateMachine(
    assembled,
    frequency=125_000_000,
    first_out_pin=board.GP0,  # pin 21 (bottom right corner)
    out_pin_count=8,
    initial_out_pin_direction=0,
    first_in_pin=board.GP14,   # pin 31
)

# 0x07  0000 0111
# 0x97  1000 0111



print("real frequency", sm.frequency)
x=0 # simple counter for a lively display
print(".")
while True:
    time.sleep(1)
    temp_value = 0x7
    output_value = ((temp_value | 0x80) << 8) + temp_value
    data = array.array("I",[output_value])
#    sm.write(bytes((x,255,)))
    sm.write(data)
    x = x + 1
    if (x >= 255):
        print(".")
        x=0

#d32 = 0x20 (space)
#d65 = 0x41 A
#d97 = 0x60 a
