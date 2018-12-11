
//Zhang Lab
//UV Source Trigger test
//Author Louis Bourguet 

char incomingByte;
#define LIGHT_PIN 31


void setup() {
  pinMode(LIGHT_PIN , OUTPUT);

  digitalWrite(LIGHT_PIN , LOW);
  Serial.begin(9600);
  Serial.write("whatever ");

}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if(incomingByte == 'O'){
      digitalWrite(LIGHT_PIN , LOW);
      digitalWrite(LIGHT_PIN , HIGH);
      Serial.write(" LIGHT is ON ");
      delay(5);
    }
    if(incomingByte == 'D'){
      digitalWrite(LIGHT_PIN , LOW);
      Serial.write(" LIGHT is OFF ");
      delay(5);
    }
    delay(10);
  }

}
