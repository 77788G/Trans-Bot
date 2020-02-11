#include "main.h"
#include "definition.h"

using namespace pros;

void autonomous(){
  if(autoLayer == 2) skillsAuton();
  else if(autoSelect      == 0) blueAuton();
  else if(autoSelect == 1) redAuton();
}
