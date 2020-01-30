#include "main.h"
#include "definition.h"

using namespace pros;

void initialize() {
  angle.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  lift.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  intakeL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  intakeR.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  lcd::print(0, "THE 0-6 ROBOSLAM DREAM BABY!!!");
  lcd::print(1, "DRIVING PRACTICE MOMENT");
}
void competition_initialize() {}
void disabled() {}
