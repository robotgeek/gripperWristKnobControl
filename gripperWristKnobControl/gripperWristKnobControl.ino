/***********************************************************************************
 *     -(] [)-          RobotGeek Gripper with Wrist Servo
 *   / /     \ \              Knob Control
 *  | |       | |
 *   \ \_____/ /
 *    |  ___  |
 *    |_|___|_|
 *    | _____ |
 *     |     |
 *     |     |
 *     |_____|
 *
 *  The following sketch will allow you to open/close the RobotGeek Gripper and 
 *  control the angle of the wrist servo. 
 *  
 *  Products
 *    http://www.robotgeek.com/robotgeek-gripper
 *    http://www.robotgeek.com/robotgeek-geekduino-sensor-kit
 *    http://www.robotgeek.com/robotgeek-rotation-knob
 *    http://www.robotgeek.com/p/power-supply-6vdc-2a.aspx
 *    
 *  Wiring
 *
 *  Digital Input 9 - Blue Micro Servo (FT-FS90MG)      Orange - 'S' Brown -'G'
 *  Digital Input 11 - Black RobotGeek 180 Degree Servo  White -'S' Black -'G'
 *  Analog Input 0 - Knob 1
 *  Analog Input 1 - Knob 2
 *  
 *  Use an external power supply and set the jumper for pins 9/10/11 to 'VIN'
 *   
 *  Control 
 *    The two knobs will control the current position of the servos.
 *  
 ***********************************************************************************/
#include <Servo.h>   //include the servo library to control the RobotGeek Servos

#define MICRO_SERVOPIN 9  //pin that the micro servo will be attached to
#define LARGE_SERVOPIN 11  //pin that the large servo will be attached to
#define KNOB1_PIN 0        //analog pin of knob1 to control micro/gripper servo
#define KNOB2_PIN 1        //analog pin of knob2 to control large/wrist servo

Servo microServo;   //create an servo object for the 9g FT-FS90MG micro servo
Servo largeServo;   //create an servo object for the RobotGeek 180 degree serco

int knob1Value = 0;  //variable to hold the analgo input value from knob 1 
int knob2Value = 0;  //variable to hold the analgo input value from knob 2

int microServoValue = 150;
int largeServoValue = 90;

//setup servo objects and set initial position
void setup()
{ 
  //initialize servos
  microServo.attach(MICRO_SERVOPIN);    // attaches/activates the micro servo for the gripper on pin MICRO_SERVOPIN
  largeServo.attach(LARGE_SERVOPIN);    // attaches/activates the micro servo for the wrist on pin LARGE_SERVOPIN
  
  microServo.write(microServoValue);    // sets the servo position to 150 degress, positioning the servo for the gripper closed
  largeServo.write(largeServoValue);    // sets the servo position to 90 degress, centered
}
 
void loop()
{
  knob1Value = analogRead(KNOB1_PIN);
  delay(5);//short delay to allow the Analog-Digital-Converter (ADC) to settle down
  knob2Value = analogRead(KNOB2_PIN);
 
  //the knob values will be read as a value between 0-1023, 
  //so they must be converted to a value between 0 and 180 (150 for the micro servo)
  //the map()function will convert the values 
  microServoValue = map(knob1Value, 0, 1023, 0, 150);
  largeServoValue = map(knob2Value, 0, 1023, 0, 180);

  //write scaled values from the knobs to the servos.  
  microServo.write(microServoValue);   
  largeServo.write(largeServoValue);     
  
}
 
 
 
 
 
