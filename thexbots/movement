void DoAction(char* dirorstraight, int length, int speed)
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
	delay(length);
	}
}
