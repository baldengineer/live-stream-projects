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
  // store the data bit, reverses the bus words
  // to make it more readable
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

  // these aren't used yet
  // mode = digitalRead(atn_pin);
  last_clock_micros = micros();
  last_clock_rise = millis();
  EOI_flag = false;
}

void atn_change_isr() {
  byte pin_state = digitalRead(atn_pin);
  atn_change_flag = true;
  mode = pin_state;
  previous_atn_state = pin_state;
}


void decode_commands(uint8_t word, uint8_t mode) {
  Serial.print(millis());  Serial.print(", 0x");
  if (word <= 0xF)
    Serial.print(F("0"));
  Serial.print(word, HEX); Serial.print(F(", "));

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

      case 0x40:
        // OPEN CHANNEL
        Serial.print(F("TALK ADDRESS="));
        Serial.println(word & 0x1F);
      break;      

      case 0x60:
        // OPEN CHANNEL
        Serial.print(F("OPEN CHANNEL="));
        Serial.println(word & 0x1F);
      break;

      case 0xE0:
        // CLOSE Secondary Channel
        Serial.print(F("CLOSE SECONDARY="));
        Serial.println(word & 0x0F);
      break;

      case 0xF0:
        // OPEN Secondary channel
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