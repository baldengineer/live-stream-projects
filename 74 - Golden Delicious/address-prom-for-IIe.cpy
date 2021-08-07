# PIO ROM emulation testing
# PIO puts valid data out about 40ns after the "enable" signal asserts
# actual Keyboard ROM in the Apple IIe takes about 100 ns.
# @baldengineer

import array
import time
import board
import rp2pio
import adafruit_pioasm
import rom

iie_address_decode = """
.program iie_address_decode

loop:

in pins, 10     ; Need Inputs -- Johnny 5
in null, 22     ; shifts bits so address is readable
push            ; put pins into RX FIFO
; issue is, the FIFO is bigger than I need, so how
; to handle
jmp loop
"""


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
address_assembled = adafruit_pioasm.assemble(iie_address_decode)

sm_data = rp2pio.StateMachine(
    assembled,
    frequency=125_000_000,
    first_out_pin=board.GP16,  # pin 21 (bottom right corner)
    out_pin_count=7,
    initial_out_pin_direction=0,
    first_in_pin=board.GP26,   # pin 31
)

sm_addr = rp2pio.StateMachine(
    address_assembled,
    frequency=125_000_000,
    first_in_pin=board.GP0,   # Pin 1
    in_pin_count=10,          # A0 - A8, Caps (A9)
)

print("Data SM frequency", sm_data.frequency)
print("Addr SM frequency", sm_addr.frequency)

x=0 # simple counter for a lively display
print(".")

old_addr = array.array("I",[0])
while True:
   incoming_addr =  array.array("I",[0])
   sm_addr.readinto(incoming_addr)
   if (incoming_addr[0] != old_addr[0]):
      addr = incoming_addr[0]
      sm_data.write(bytes((rom.rom_array[addr],)))
      print(hex(addr) + "," + str(addr) + "," + str(rom.rom_array[addr]))
      old_addr[0] = incoming_addr[0]