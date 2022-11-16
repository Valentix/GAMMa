#define led LED_BUILTIN
#define tou 6

void setup() {
  // put your setup code here, to run once:
  pinMode(tou, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(tou)==HIGH)
    digitalWrite(led,HIGH);
  else
    digitalWrite(led,LOW);  
}
