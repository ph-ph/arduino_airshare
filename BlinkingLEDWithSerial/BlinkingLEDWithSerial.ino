#define LED_PIN 12

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PIN, OUTPUT);

  // initialize communication over serial port
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  String command;
  if (Serial.available() > 0) {
    command = Serial.readStringUntil(' ');
  }

  if (command == "on") {
    Serial.write("turning the LED on\n");
    digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  } else if (command == "off") {
    Serial.write("turning the LED off\n");
    digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
  }
  delay(100);
}
