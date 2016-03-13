int led = 13;
int knockSensor = 0;
int statePin = LOW;
int threshHold = 1;
int val = 0;

void setup() {
        // put your setup code here, to run once:
        pinMode(led, OUTPUT);
        Serial.begin(9600);
}

void loop() {
        // put your main code here, to run repeatedly:
        val = analogRead(knockSensor);

        if(val > threshHold){
                Serial.println(val);
                statePin = !statePin;
                digitalWrite(led, statePin);
//                analogWrite(knockSensor, 100);
        }
        delay(50);
}
