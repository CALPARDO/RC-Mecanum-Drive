/* For more info go to www.calpardo.com  */

// Import
#include <Servo.h> 

// Integers to call functions
int s_func;

// Mapping Constants
const int cur_min = 1000; // 1000 is the min value for FS-IA6B Receiver
const int cur_max = 2000; // 2000 is the max value for FS-IA6B Receiver
const int tar_min = 0; // 0 means CCW full throttle
const int tar_max = 180; // 180 means CW full throttle

// Motors
const int M_1P = 4; // Motor 1 (Front Left)
const int M_2P = 5; // Motor 2 (Front Right)
const int M_3P = 6; // Motor 3 (Rear Left)
const int M_4P = 7; // Motor 4 (Rear Right)

// Motors like Servos
Servo M_1;
Servo M_2;
Servo M_3;
Servo M_4;

// Receiver Inputs
const int ch_xP = 10; // Horizontal Input
const int ch_yP = 11; // Vertical Input
const int ch_trP = 12; // Turn round
const int ch_emP = 13; // Emergency Switch

// Setup
void setup() {
  pinMode(ch_xP, INPUT);
  pinMode(ch_yP, INPUT);
  pinMode(ch_trP, INPUT);
  pinMode(ch_emP, INPUT);

  M_1.attach(M_1P);
  M_2.attach(M_2P);
  M_3.attach(M_3P);
  M_4.attach(M_4P);
  
  Serial.begin(115200);
}

// Stop
  int M_STOP(){
    M_1.write(90);
    M_2.write(90);
    M_3.write(90);
    M_4.write(90);
  }

void loop() {

  // Reading PWM Pulse
  int ch_x = pulseIn(ch_xP, HIGH);
  int ch_y = pulseIn(ch_yP, HIGH);
  int ch_tr = pulseIn(ch_trP, HIGH); 
  int ch_em = pulseIn(ch_emP, HIGH);

  // Mapping
  ch_x = map(ch_x, cur_min, cur_max, tar_min, tar_max);
  ch_y = map(ch_y, cur_min, cur_max, tar_min, tar_max);
  ch_tr = map(ch_tr, cur_min, cur_max, tar_min, tar_max);
  ch_em = map(ch_em, cur_min, cur_max, tar_min, tar_max);
  
  // Moving Right
  if (ch_x > 95){
    M_1.write(180-ch_x); // CCW
    M_2.write(180-ch_x); // CCW
    M_3.write(ch_x); // CW
    M_4.write(ch_x); // CW
    }

  // Moving Left
  else if (ch_x < 85){
    M_1.write(ch_x); // CW
    M_2.write(180-ch_x); // CCW
    M_3.write(180-ch_x); // CCW
    M_4.write(ch_x); // CW
    }

  // Moving Forward
  else if (ch_y > 95){
    M_1.write(ch_y); // CW
    M_2.write(180-ch_y); // CCW
    M_3.write(ch_y); // CW
    M_4.write(180-ch_y); // CCW
    }

  // Moving Backward
  else if (ch_y < 85){
    M_1.write(180-ch_y); // CCW
    M_2.write(ch_y); // CW
    M_3.write(180-ch_y); // CCW
    M_4.write(ch_y); // CW
    }

  // Turning Right
  else if (ch_tr > 90){
    M_1.write(180-ch_tr); // CCW
    M_2.write(180-ch_tr); // CCW
    M_3.write(180-ch_tr); // CCW
    M_4.write(180-ch_tr); // CCW
    }

  // Turning Left
  else if (ch_tr < 85){
    M_1.write(ch_tr); // CW
    M_2.write(ch_tr); // CW
    M_3.write(ch_tr); // CW
    M_4.write(ch_tr); // CW
    }
    
  // Emergency Switch ON
  else if (ch_em > 95){
    s_func = M_STOP();
    }

  // Else Stop Motors
  else {
    s_func = M_STOP();
    }
    
  // Printing
  Serial.println(ch_x);
  Serial.println(ch_y);
  Serial.println(ch_tr);
  Serial.println(ch_em);

}
