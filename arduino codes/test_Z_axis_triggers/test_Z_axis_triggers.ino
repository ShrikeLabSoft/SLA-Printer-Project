//Zhang Lab
//Z axis Triggers test
//Author Louis Bourguet 

char incomingByte;
String incomingString;
#define HOME_PIN 16
#define STEP_PIN 23


void setup() {
  pinMode(STEP_PIN , OUTPUT);
  pinMode(HOME_PIN , OUTPUT);
  

  digitalWrite(HOME_PIN , LOW);
  digitalWrite(STEP_PIN , LOW);
  
  Serial.begin(9600);      //Serial starts at 9600 bauds
  Serial.write("whatever ");
}

void loop() {
    if (Serial.available() > 0) {    //seek serial
    
    incomingByte = Serial.read();   //incoming serial
    if(incomingByte == 'H'){
      digitalWrite(HOME_PIN , LOW);
      digitalWrite(HOME_PIN , HIGH);
      Serial.write(" DOWN PIN on HIGH ");
      delay(5000);
      digitalWrite(HOME_PIN , LOW);
      Serial.write(" DOWN PIN on LOW ");
      delay(5);
    }
    if(incomingByte == 'R'){
      digitalWrite(STEP_PIN , LOW);
      digitalWrite(STEP_PIN , HIGH);
      Serial.write(" STEP PIN on HIGH ");
      delay(5000);
      digitalWrite(STEP_PIN , LOW);
      Serial.write(" STEP PIN on LOW ");
      delay(5);
    }
    if(incomingByte == 'F'){
      digitalWrite(STEP_PIN , LOW);
      delay(5);
    }
    delay(10);
  }
  }
