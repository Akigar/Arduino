#define sensor_pin A2
#define led_pin 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  if (analogRead(sensor_pin) < 800) digitalWrite(led_pin, HIGH);
  else digitalWrite(led_pin, LOW);
}
