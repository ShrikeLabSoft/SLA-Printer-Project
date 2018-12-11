a = arduino('COM6', 'Mega2560');

Y_STEP_PIN = 'A6';
configurePin(a,'A6','DigitalOutput');
Y_DIR_PIN = 'A7';
configurePin(a,'A7','DigitalOutput');
Y_ENABLE_PIN = 'A2';
configurePin(a,'A2','DigitalOutput');

LED_PIN = 'D13';

writeDigitalPin(a, Y_ENABLE_PIN , 0);

writeDigitalPin(a, LED_PIN, 1);

writeDigitalPin(a, Y_DIR_PIN    , 0);
while(1)
writeDigitalPin(a, Y_STEP_PIN    , 1);
%pause(0.0001);
writeDigitalPin(a, Y_STEP_PIN    , 0);
end
writeDigitalPin(a, LED_PIN, 0);
clear a;