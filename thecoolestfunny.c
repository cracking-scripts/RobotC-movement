#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
Code Created by werbored in "RobotC"
Credits to TheXbots and Eggbegg
2022-12-14
*/

// main function for all actions
void action(char* direction, int speed, int del, bool angle, char* material){
	if (direction == "r"){
		motor[motorB] = -speed;
		motor[motorC] = speed;
	}
	else if (direction == "l"){
		motor[motorB] = speed;
		motor[motorC] = -speed;
	}
	else if (direction == "s"){
		motor[motorB] = speed;
		motor[motorC] = speed;
	}
	else if (direction == "b"){
		motor[motorB] = -speed;
		motor[motorC] = -speed;
	}

  // specify materialized delay for angle
	if (angle == true){
		if (material == "mat") {
			delay(del * 3.8);
		}
		else if (material == "table") {
			delay(del * 3.55);
		}
		else if (material == "wood") {
			delay(del * 4.02);
		}
	}
	else if (angle == false){
		delay(del);
	}

  // limbo section (stop all motors to prevent offset)
	motor[motorB] = 0;
	motor[motorC] = 0;
	delay(200);
}

task main(){
  action("s", 50, 5000, false, "wood");
  action("r", 50, 90, true, "wood");
  action("s", 50, 2200, false, "wood");
  action("r", 50, 90, true, "wood");
  action("s", 50, 4650, false, "wood");
  action("l", 50, 90, true, "wood");
  action("s", 50, 1600, false, "wood");
  action("l", 50, 90, true, "wood");
  action("s", 50, 6300, false, "wood");
	action("l", 50, 90, true, "wood");
	action("s", 50, 2000, false, "wood");
	action("r", 50, 90, true, "wood");
	action("s", 50, 1200, false, "wood");
	action("l", 50, 90, true, "wood");
	action("s", 50, 1700, false, "wood");
	action("r", 50, 90, true, "wood");
	action("s", 50, 800, false, "wood");
}