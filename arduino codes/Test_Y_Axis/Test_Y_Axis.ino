#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define LED_PIN            13

void setup() {
  pinMode(LED_PIN  , OUTPUT);
  
  pinMode(Y_STEP_PIN  , OUTPUT);
  pinMode(Y_DIR_PIN    , OUTPUT);
  pinMode(Y_ENABLE_PIN    , OUTPUT);
  
  digitalWrite(Y_ENABLE_PIN    , LOW);
}

void loop () {
  
  if (millis() %1000 <500) 
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
  
/*  if (millis() %1000 <300) {
    digitalWrite(HEATER_0_PIN, HIGH);
    digitalWrite(HEATER_1_PIN, LOW);
    digitalWrite(FAN_PIN, LOW);
  } else if (millis() %1000 <600) {
    digitalWrite(HEATER_0_PIN, LOW);
    digitalWrite(HEATER_1_PIN, HIGH);
    digitalWrite(FAN_PIN, LOW);
  } else  {
    digitalWrite(HEATER_0_PIN, LOW);
    digitalWrite(HEATER_1_PIN, LOW);
    digitalWrite(FAN_PIN, HIGH);
  }
  if (millis() %10000 <5000) {
    digitalWrite(Y_DIR_PIN    , HIGH);
  }
  else {
    digitalWrite(Y_DIR_PIN    , LOW);
  } 
  
*/ 
  digitalWrite(Y_DIR_PIN    , LOW);
 
  digitalWrite(Y_STEP_PIN    , HIGH);
  delay(1);
  
  digitalWrite(Y_STEP_PIN    , LOW);
}
