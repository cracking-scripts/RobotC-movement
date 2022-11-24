// eggbegg - square moving robot
// 2022-11-17

// define vars
int speed = 50;
int normdelay = 2000;
int turndelay = 636;
int time = 5;

// main actions
void doAction(char* direction, int delaylength) {
	if (direction == "turnright") {
		motor[motorB] = -speed;
		motor[motorC] = speed;
	}
	else if (direction == "turnleft") {
		motor[motorB] = speed;
		motor[motorC] = -speed;
	}
	else if (direction == "straight") {
		motor[motorB] = speed;
		motor[motorC] = speed;
	}
	else if (direction == "back") {
		motor[motorB] = -speed;
		motor[motorC] = -speed;
	}
	delay(delaylength);
	motor[motorB] = 0;
	motor[motorC] = 0;
	delay(500);
}

// robot task
task main() {
	for(time=0;time>10;time++) {
		doAction("straight", normdelay);
		doAction("turnleft", turndelay);
		doAction("straight", normdelay);
		doAction("turnleft", turndelay);
		doAction("straight", normdelay);
		doAction("turnleft", turndelay);
		doAction("straight", normdelay);
		doAction("turnleft", turndelay);
	}
}
