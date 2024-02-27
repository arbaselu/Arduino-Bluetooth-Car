int IN1 = 11; // Define pin for motor input 1
int IN2 = 12; // Define pin for motor input 2
int IN3 = 6;  // Define pin for motor input 3
int IN4 = 5;  // Define pin for motor input 4
char command;  // Variable to store command received via Bluetooth

void setup()
{
  // Set motor input pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // Print a start-up message
  Serial.println("Bluetooth Motor Control");
}

void loop() {
  // Check if data is available to read from the Bluetooth module
  if (Serial.available() > 0) {
    // Read the incoming byte:
    command = Serial.read();

    // Check the received command and act accordingly
    switch (command) {
      case 'F': // Command to move forward
        forward();
        break;
      case 'B': // Command to move backward
        backward();
        break;
      case 'L': // Command to turn left
        left();
        break;
      case 'R': // Command to turn right
        right();
        break;
      case 'S': // Command to stop
        stop();
        break;
      default: // If an unknown command is received, do nothing
        break;
    }
  }
}

// Function to move the car forward
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to move the car backward
void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Function to turn the car left
void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to turn the car right
void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Function to stop the car
void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

 
  
  
