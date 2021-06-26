int Motor1 = 2;
int Motor2 = 3;
int PWMControl= 6;
int PWM_Input = A0;
int PWM_Value = 0;
void setup() {
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(PWMControl, OUTPUT);
  pinMode(PWM_Input, INPUT);
  Serial.begin(9600);
}

void loop() {
  PWM_Value = analogRead(PWM_Input);
  PWM_Value = map(PWM_Value, 0, 1023, 0, 255);
  analogWrite(PWMControl, PWM_Value);
  if(Serial.available())
  {
    char data = Serial.read();
    Serial.println(data);
    if(data == 'C'){MotorClockwise();}
    if(data == 'A'){MotorAntiClockwise();}
    if(data == 'S'){MotorStop();}    
  }
}

void MotorAntiClockwise()
{
  digitalWrite(Motor1, HIGH);
  digitalWrite(Motor2, LOW);
}

void MotorClockwise()
{
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor2, HIGH);
}

void MotorStop()
{
  digitalWrite(Motor1, HIGH);
  digitalWrite(Motor2, HIGH);
}
