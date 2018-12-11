//Zhang Lab
//Z axis Triggers test
//Author Louis Bourguet 

char incomingByte;
String incomingString;
#define Z_HOME_PIN 16
#define Z_STEP_PIN 23

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define LED_PIN            13

int stop = 0;

void setup() {
  pinMode(Z_STEP_PIN        , OUTPUT);
  pinMode(Z_HOME_PIN        , OUTPUT);
  pinMode(LED_PIN           , OUTPUT);
  
  pinMode(Y_STEP_PIN        , OUTPUT);
  pinMode(Y_DIR_PIN         , OUTPUT);
  pinMode(Y_ENABLE_PIN      , OUTPUT);
  
  digitalWrite(Y_ENABLE_PIN , LOW);

  digitalWrite(Z_HOME_PIN   , LOW);
  digitalWrite(Z_STEP_PIN   , LOW);
  
  Serial.begin(9600);      //Serial starts at 9600 bauds
  Serial.write("whatever ");
}

void loop() {
    if (Serial.available() > 0) {    //seek serial
      incomingByte = Serial.read();   //incoming serial
      if(incomingByte == 'H'){
        digitalWrite(Z_HOME_PIN , LOW);
        digitalWrite(Z_HOME_PIN , HIGH);
        Serial.write(" HOME PIN on HIGH ");
        delay(5000);
        digitalWrite(Z_HOME_PIN , LOW);
        Serial.write(" HOME PIN on LOW ");
        delay(5);
      }
      if(incomingByte == 'R'){
        digitalWrite(Z_STEP_PIN , LOW);
        digitalWrite(Z_STEP_PIN , HIGH);
        Serial.write(" STEP PIN on HIGH ");
        delay(5000);
        digitalWrite(Z_STEP_PIN , LOW);
        Serial.write(" STEP PIN on LOW ");
        delay(5);
      }
      if(incomingByte == 'F'){
        digitalWrite(Z_STEP_PIN , LOW);
        delay(5);
      }
      if(incomingByte == 'd'){
        digitalWrite(Y_DIR_PIN , LOW);
        delay(5);
      }
      if(incomingByte == 'u'){
        digitalWrite(Y_DIR_PIN , HIGH);
        delay(5);
      }
      if(incomingByte == 's'){
        if(stop == 1){
          stop = 0;
        }
        else{
          stop = 1;
        }
      }
    }
    if(stop == 0){
      digitalWrite(Y_STEP_PIN    , HIGH);
      delay(1);
      digitalWrite(Y_STEP_PIN    , LOW);
    }
}
