volatile uint8_t  serial_word = 0x0;
volatile uint8_t  bit_idx = 0;
volatile uint32_t last_clock_micros = 0;
volatile uint32_t last_clock_rise = 0;

volatile bool EOI_flag = false;
volatile bool byte_ready = false;
volatile bool atn_change_flag = false;
volatile bool previous_atn_state = false;

#define SELECT 0x0
#define DATA   0x1    // filename isn't data, its ontrol information (so ATN is asserted)
volatile uint8_t mode = 0;

const byte dat_pin = 2;
const byte clk_pin = 3;
const byte atn_pin = 4;
volatile bool skip_clock = false;