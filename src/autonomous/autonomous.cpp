#include "main.h"
#include "definition.h"

using namespace pros;

void autonomous(){
  if(autoSelect      == 0) blueAuton();
  else if(autoSelect == 1){
    simultaneous(200, 100);
    simultaneous(-600, 100);
  }
  else if(autoSelect == 2) redAuton();
}
