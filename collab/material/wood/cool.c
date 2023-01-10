/*
Script by Mason Varey and Anthony Seyler
Started on 2022-12-16
*/
int i;
#pragma config(Sensor, S1,     ,               sensorTouch) // unused
#pragma config(Sensor, S2,     ,               sensorTemperature)
#pragma config(Sensor, S3,     ,               sensorLightActive)
#pragma config(Sensor, S4,     ,               sensorSONAR)

int temp; // temp value for display
int x; // temporary loop value

void turn(char* direction, int speed, int del, char* material){
	if (direction == "r"){ // right turn
		motor[motorB] = -speed;
		motor[motorC] = speed;
	}
	else if (direction == "l"){ // left turn
		motor[motorB] = speed;
		motor[motorC] = -speed;
	}

	if (material == "mat"){ // mat material motor config
		delay(del * 3.8);
	}
	else if (material == "table"){ // table material motor config
		delay(del * 3.55);
	}
	else if (material == "wood"){ // wood material motor config
		delay(del * 4);
	}
	motor[motorB] = 0;
	motor[motorC] = 0;
	delay(200);
}

void flamboyantwater() { // main water script
  motor[motorC] = 0; // halt movement
  motor[motorB] = 0; // halt movement
  motor[motorA] = 20;
  delay(400); // turn the robot to allow temp sensor
  motor[motorA] = 0;
  while(x < 20){ // repeat for 10 seconds
    Temperature = SensorValue[S4];
    displayTextLine(3, "temp=%d", Temperature); // display the temperature
    delay(500);
    x++; // add one for x after 500ms - loop break condition
  }
  motor[motorA] = -20; // turn the robot to align
  delay(400); // end with a delay
}

void straightaway(int speed, int del, bool backwards){
  if (backwards == true){
    motor[motorB] = -speed
    motor[motorC] = -speed
    delay(del)
  }
  else if (backwards == false) {
    motor[motorB] = speed
    motor[motorC] = speed
    delay(del)
  }
}

task main(){
 for (i=0;2;i++) {
  // forward until line
    while(SensorValue[S3] > 30){
      motor[motorB] = 50;
      motor[motorC] = 50;
    }
  // turn left after wall
  turn("l", 50, 90, "wood");
 }
  // forward until wall using sonar
  while(SensorValue[S4] > 30){
    motor[motorB] = 50;
    motor[motorC] = 50;
  }
  // turn left
  turn("l", 50, 90, "wood");
  // forward until water
  while(SensorValue[S4] > 30){
    motor[motorB] = 50;
    motor[motorC] = 50;
  }
  straightaway(20, 100, true)
  // flamboyantwater
  flamboyantwater();
  // backwards a little
  straightaway(50, 500, true){
  // turn right
  turn("r", 50, 90, "wood")
  // forward until wall no sonar
  straightaway(50, 700, false){
  // turn left
  turn("l", 50, 90, "wood")
  // straight
  straightaway(50, 1000, false){
  // turn right
  turn("r", 50, 90, "wood")
  // straight until finish
  straightaway(50, 700, false){
} 
