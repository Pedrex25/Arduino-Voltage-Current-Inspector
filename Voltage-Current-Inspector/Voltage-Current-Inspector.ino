#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

const int max_potenciometer_r = 10000;   // total potentiometer resistance
const float R_LED = 330.0f;              // LED series resistor

const float ref_voltage = 5.0f;
const float ADC_max_value = 1023.0f;

const int analog_pin_A5 = A5, analog_pin_A4 = A4;

float voltage_output_A, voltage_output_B;
float current_output_A, current_output_B;
float potentiometer_resistance, potentiometer_position;

const int backlight_pin_10 = 10;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float calculate_voltage(int analog_pin){
  float analog_value = analogRead(analog_pin);
  float voltage_output = (ref_voltage / ADC_max_value) * analog_value;
  return voltage_output;
}

// calc current from Vdrop & R
float calculate_amps(float voltage_drop, float resistance){
  return (voltage_drop / resistance) * 1000.0f; // in mA
}

// calc potentiometer R (wiper to GND)
float calculate_potentiometer_resistance_to_ground(float wiper_voltage) {
  float R2 = (wiper_voltage * max_potenciometer_r) / ref_voltage;
  return R2;
}

// calc pot position %
float calculate_potentiometer_position(float wiper_voltage) {
  return (wiper_voltage / ref_voltage) * 100.0f;
}

void setup() {
  lcd.begin(16, 2);
  pinMode(backlight_pin_10, OUTPUT);
}

void loop() {
  // read voltages
  voltage_output_A = calculate_voltage(analog_pin_A5); // potentiometer (before R)
  voltage_output_B = calculate_voltage(analog_pin_A4); // after R+LED

  // calc potentiometer R & position
  potentiometer_resistance = calculate_potentiometer_resistance_to_ground(voltage_output_A);
  potentiometer_position = calculate_potentiometer_position(voltage_output_A);
  
  // potentiometer current (const in divider)
  current_output_A = (ref_voltage / max_potenciometer_r) * 1000.0f;

  // LED current (R drop)
  float resistor_drop = voltage_output_A - voltage_output_B;
  current_output_B = calculate_amps(resistor_drop, R_LED);

  lcd.clear();
  analogWrite(backlight_pin_10, 255); // set backlight

  // Top Screen Row
  lcd.setCursor(0, 0);
  lcd.print("VA:");
  lcd.print(voltage_output_A, 2);
  lcd.print(" VB:");
  lcd.print(voltage_output_B, 2);

  // Bottom Screen Row
  lcd.setCursor(0, 1);
  lcd.print("LED:");
  lcd.print(current_output_B, 1);
  lcd.print("mA R:");
  lcd.print(potentiometer_resistance/1000, 1);
  lcd.print("k");
  
  delay(50);
}