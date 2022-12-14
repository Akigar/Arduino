#define sensor_pin A0
#define led_pin 3

int photocellReading; 

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {

  if (Serial.available() > 0 ){
    char message = Serial.read();

    if (message == 'u'){
      digitalWrite(led_pin, HIGH);
    } else if (message == 'd'){
        digitalWrite(led_pin, LOW);
    } else if (message == 's'){
        int val = analogRead(sensor_pin);
        val = map (val, 0, 1023, 100, 1024);
        Serial.print(val);
    } else if (message == 'c'){
        while (true){
          int val = analogRead(sensor_pin);
          analogWrite(led_pin, map(val, 970, 1024, 0, 100));
      }
    } else if(message == 'f'){
        while(true){
          int val = analogRead(sensor_pin);
          val = map (val, 0, 1023, 100, 1024);
          if (val >= 990) digitalWrite(led_pin, HIGH);
          else digitalWrite(led_pin, LOW);
      }
    } else{
        Serial.println(" - Uknown message");
    }
  }
}
