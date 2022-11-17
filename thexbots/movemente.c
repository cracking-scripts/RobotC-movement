//credit to TheXbots on Github
//Put this before the task main()

void DoAction(char* dirorstraight, int length, int speed, int angle)
{
	if (dirorstraight	== "Straight") {
		motor(motorB) = speed;
		motor(motorC) = speed;
	}
	else if (dirorstraight == "Left") {
		motor(motorB) = speed;
		motor(motorC) = -speed;
	}
	else if (dirorstraight == "Right") {
		motor(motorB) = -speed;
		motor(motorC) = speed;
		
	}
	else if (dirorstraight == "Back") {
		motor(motorB) = -speed;
		motor(motorC) = -speed;
	
	}
	
	if (dirorstraight == "Left") {
		delay(7.14624 * angle);
	}
	else if (dirorstraight == "Right") {
		delay(7.14624 * angle);
	}
	
	else if (dirorstraight == "Straight") {
		delay(length);
	}
	
	else if (dirorstraight == "Back") {
		delay(length);
	}
}
