# Potentiometer and LED Current Measurement with Arduino

![Project Demonstration](resources/Project.gif)

This project uses an Arduino, a potentiometer, and an LED with a series resistor to measure and display on a 16x2 LCD:

- The voltage at the potentiometer wiper (VA)  
- The voltage after the resistor and LED (VB)  
- The current flowing through the LED (mA)  
- The equivalent resistance of the potentiometer (Ω/kΩ)  

The measurements are taken from analog inputs A5 and A4, processed in code, and updated in real-time on the LCD.

## How It Works

The potentiometer voltage is read at A5, and the LED voltage after the resistor is read at A4. Using these values, the Arduino calculates the potentiometer resistance relative to ground, the potentiometer position as a percentage, and the LED current from the voltage drop across the series resistor. Results are displayed on the LCD in two rows:

Row 1 shows VA and VB voltages.  
Row 2 shows the LED current in mA and the potentiometer resistance in kΩ.

# Project Scheme
![Project Scheme](resources\Scheme.png)

# Circuit Scheme
![Circuit Scheme](resources\Circuit%20Scheme.png)

## Components Used

<table>
  <thead>
    <tr>
      <th>Name</th>
      <th>Quantity</th>
      <th>Component</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>U1</td>
      <td>1</td>
      <td>Arduino Uno R3</td>
    </tr>
    <tr>
      <td>U2</td>
      <td>1</td>
      <td>LCD 16 x 2</td>
    </tr>
    <tr>
      <td>R1</td>
      <td>1</td>
      <td>2 kΩ Resistor</td>
    </tr>
    <tr>
      <td>R2, R4</td>
      <td>2</td>
      <td>330 Ω Resistor</td>
    </tr>
    <tr>
      <td>Rpot1</td>
      <td>1</td>
      <td>10 kΩ Potentiometer</td>
    </tr>
    <tr>
      <td>D1</td>
      <td>1</td>
      <td>Blue LED</td>
    </tr>
  </tbody>
</table>

