#include "iec.h"

void setup() {
  Serial.begin(115200);
  Serial.println(F("IEC Bus Decoder"));

  pinMode(clk_pin, INPUT);
  pinMode(dat_pin, INPUT);
  pinMode(atn_pin, INPUT);

  attachInterrupt(digitalPinToInterrupt(clk_pin), shift_register_isr, RISING);
  attachInterrupt(digitalPinToInterrupt(atn_pin), atn_change_isr, CHANGE);
}

void loop() {
  handle_serial();
  // not certain why this keeps the bits aligned
  if (millis() - last_clock_rise >= 900) {
    bit_idx = 0;
  }

  if (atn_change_flag) {
    Serial.print("ATN Change: ");
    Serial.println(mode);
    atn_change_flag = false;
  }

  if (byte_ready) {
    byte_ready = false;
    decode_commands(serial_word, mode);
  }

  if (EOI_flag && (digitalRead(clk_pin) == LOW) && (micros() - last_clock_micros >= 200))
    EOI_flag  = true;

  if (EOI_flag) {
    Serial.println("EOI");
    EOI_flag = false;
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