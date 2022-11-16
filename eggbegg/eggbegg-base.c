// define vars
int speed = 50;

// main actions
void doAction(char* direction, int delaylength) {
	if (direction == "right") {
		motor[motorB] = -speed;
		motor[motorC] = speed;
	}
	else if (direction == "left") {
		motor[motorB] = speed;
		motor[motorC] = -speed;
	}
	else if (direction == "straight") {
		motor[motorB] = speed;
		motor[motorC] = speed;
	}
	delay(delaylength);
	motor[motorB] = 0;
	motor[motorC] = 0;
	delay(500);
}

task main() {

}
