#include "main.h"
#include "definition.h"

using namespace pros;

Controller master(E_CONTROLLER_MASTER);

Motor  driveBL(11, E_MOTOR_GEARSET_06, 1, E_MOTOR_ENCODER_DEGREES);
Motor  driveBR(20, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);
Motor  driveFL(12, E_MOTOR_GEARSET_06, 1, E_MOTOR_ENCODER_DEGREES);
Motor driveFR(19, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);
Motor     lift(1, E_MOTOR_GEARSET_06, 1, E_MOTOR_ENCODER_DEGREES);
Motor    angle(13, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);
Motor  intakeL(2, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
Motor  intakeR(10, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);
