#include <Servo.h>

Servo myservo[5];  // create servo objects to control servo 

int pos = 0;       // variable to store the servo position
int min_val = 30;  // servo motor min threshold
int max_val = 150; // servo motor max threshold
/*
Note: Servo motor 0 and 1 are having opposite orientation as of servo 3, 4 and 5.
      so for motor 0 and 1 finger will close at min angle value whereas motor 3,4 and 5 will close finger at max angle value.
*/
void setup() {

  myservo[0].attach(5);   // pinky finger servo motor
  myservo[1].attach(6);   // ring finger servo motor 
  myservo[2].attach(9);   // middle finger servo motor
  myservo[3].attach(10);  // ankle finger servo motor
  myservo[4].attach(11);  // Thumb servo motor

  //all fingers close
  all_fingers_close();
  delay(1000);
  //all fingers open
  all_fingers_open();
  delay(1000);
}

void loop() {

//pattern 1: all finger will close and open for 5 times

 for(int i =0; i< 5; i++)
  {
    all_fingers_close();
    delay(1000);
    all_fingers_open();
    delay(1000);
  }

// pattern 2: Each finger will close and open separately

  for (int servo = 0; servo <5; servo ++)
  {
    if(servo >= 2)
    {
      for (pos = min_val; pos <= max_val; pos += 5) { 
        myservo[servo].write(pos); 
        delay(15);      
      }
      for (pos = max_val; pos >= min_val; pos -= 5) { 
        myservo[servo].write(pos);  
        delay(15);
      }
    }
    else
    {
      for (pos = max_val; pos >= min_val; pos -= 5) { 
        myservo[servo].write(pos);              
        delay(15); 
      }
      for (pos = min_val; pos <= max_val; pos += 5) { 
        myservo[servo].write(pos);  
        delay(15);  
      }

    }
  }
}


void all_fingers_close(void)
{
    myservo[0].write(min_val);
    myservo[1].write(min_val);
    myservo[2].write(max_val);
    myservo[3].write(max_val);
    myservo[4].write(max_val);
    delay(50);
}

void all_fingers_open(void)
{
    myservo[0].write(max_val);
    myservo[1].write(max_val);
    myservo[2].write(min_val);
    myservo[3].write(min_val);
    myservo[4].write(min_val);
    delay(50);
}