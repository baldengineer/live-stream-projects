volatile uint8_t serial_word = 0x0;
volatile uint8_t bit_idx = 0;
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

void shift_register_isr() {   
 /* if (skip_clock == true) {
    skip_clock == false;
    return;
  } */
  if (false && atn_change_flag) {
    atn_change_flag = false;
    if ((mode == 0x1) && (digitalRead(dat_pin))) {
      bit_idx = 0;
      return;
    }
  } 
  // store the data bit
  serial_word = serial_word >> 1;

  if (digitalRead(dat_pin))
   serial_word = serial_word | 0x80;
  else
   serial_word = serial_word & 0x7F;

  // increment or wrap the index
  bit_idx++;
  if (bit_idx >= 9) {
    bit_idx = 0;
    byte_ready = true;
  }


 // mode = digitalRead(atn_pin);
  last_clock_micros = micros();
  last_clock_rise = millis();
  EOI_flag = false;
}

void atn_change_isr() {
  byte pin_state = digitalRead(atn_pin);
  if ((pin_state) && (digitalRead(clk_pin) == LOW)) {
   atn_change_flag = true;
  }
  mode = pin_state;
  previous_atn_state = pin_state;

 /* if ((pin_state == LOW) && digitalRead(dat_pin)) {
    skip_clock = true;
  }*/
}

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("IEC Bus Decoder");

  pinMode(clk_pin, INPUT);
  pinMode(dat_pin, INPUT);
  pinMode(atn_pin, INPUT);

  attachInterrupt(digitalPinToInterrupt(clk_pin), shift_register_isr, RISING);
  attachInterrupt(digitalPinToInterrupt(atn_pin), atn_change_isr, CHANGE);
}

void loop() {
  handle_serial();
  if (millis() - last_clock_rise >= 900) {
    bit_idx = 0;
  }

 /* if (atn_change_flag) {
    Serial.print("ATN Change: ");
    Serial.println(mode);
    atn_change_flag = false;
  }*/

  if (byte_ready) {
    byte_ready = false;
   /* if (serial_word <= 0xF)
      Serial.print("0");
    Serial.println(serial_word, HEX);*/
    decode_commands(serial_word, mode);
   // serial_word = 0x0;
  }


  if (EOI_flag && (digitalRead(clk_pin) == LOW) && (micros() - last_clock_micros >= 200))
    EOI_flag  = true;

  if (EOI_flag) {
    Serial.println("EOI");
    EOI_flag = false;
  }
}

void decode_commands(uint8_t word, uint8_t mode) {
  if (word <= 0xF)
    Serial.print(F("0x0"));
  else
    Serial.print(F("0x"));
  Serial.print(word, HEX);
  Serial.print(F(", "));

  if (mode == SELECT) {
    switch(word & 0xF0) {
      case 0x20:
      case 0x30:
        if (word == 0x3F) {
          // UNLISTEN
          Serial.println(F("UNLISTEN"));
        } else {
          // LISTEN command
          Serial.print(F("LISTEN DEV="));
          Serial.println(word & 0x1F);
        }
      break;

      case 0x60:
        // OPEN CHANNEL
        Serial.print(F("OPEN CHANNEL="));
        Serial.println(word & 0x0F);
      break;

      case 0xF0:
        // Open SEcondary channel
        Serial.print(F("OPEN SECONDARY="));
        Serial.println(word & 0x0F);
      break;


      default:
      Serial.println();
      break;
    }
  } else {
    char character = word;
    Serial.print("DATA: ");
    Serial.println(character);
  }
}

void handle_serial() {
  if (Serial.available()) {
    byte incoming_char = Serial.read();
    switch (incoming_char) {
      case '!':
        Serial.println("----");
        break;
    }
  }
}