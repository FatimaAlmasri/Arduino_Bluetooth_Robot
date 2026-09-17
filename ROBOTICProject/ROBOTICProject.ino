const int motor1A = 2; const int motor1B = 3; 
const int motor2A = 4; const int motor2B = 5; 
const int rightLed = 7;  
const int leftLed = 6;   
const int redLeds = 8;   
const int greenLeds = 9; 
const int buzzer = 11;   

void setup() {
  Serial.begin(9600);
  pinMode(motor1A, OUTPUT); pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT); pinMode(motor2B, OUTPUT);
  
  pinMode(rightLed, OUTPUT);
  pinMode(leftLed, OUTPUT);
  pinMode(redLeds, OUTPUT);
  pinMode(greenLeds, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    switch(command) {
      case 'F': // 
        clearLeds(); 
        digitalWrite(greenLeds, HIGH); 
        moveForward(); 
        break;
        
      case 'B': 
        clearLeds(); 
        digitalWrite(greenLeds, HIGH); 
        moveBackward(); 
        break;
        
      case 'R': 
        clearLeds(); 
        digitalWrite(greenLeds, HIGH); 
        digitalWrite(rightLed, HIGH); 
        turnRight(); 
        break;
        
      case 'L': 
        clearLeds(); 
        digitalWrite(greenLeds, HIGH); 
        digitalWrite(leftLed, HIGH); 
        turnLeft(); 
        break;
        
      case 'S': 
      case '0': 
        clearLeds(); 
        digitalWrite(redLeds, HIGH); 
        stopMotors(); 
        break;

      case 'Z': 
      case 'z':
        digitalWrite(buzzer, HIGH);
        break;
      
      case 'x':
        digitalWrite(buzzer, LOW);
        break;
    }
  }
}

// 
void clearLeds() {
  digitalWrite(rightLed, LOW);
  digitalWrite(leftLed, LOW);
  digitalWrite(redLeds, LOW);
  digitalWrite(greenLeds, LOW);
  digitalWrite(buzzer, LOW);
}


void moveForward() {
  digitalWrite(motor1A, HIGH); digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH); digitalWrite(motor2B, LOW);
  
 
  digitalWrite(buzzer, HIGH);
  delay(250); 
  digitalWrite(buzzer, LOW);
  delay(250); 


void moveBackward() {
  digitalWrite(motor1A, LOW); digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW); digitalWrite(motor2B, HIGH);
}

void turnRight() {
  digitalWrite(motor1A, LOW);  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH); digitalWrite(motor2B, LOW);
}

void turnLeft() {
  digitalWrite(motor1A, HIGH); digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);  digitalWrite(motor2B, HIGH);
}

void stopMotors() {
  digitalWrite(motor1A, LOW); digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW); digitalWrite(motor2B, LOW);
}