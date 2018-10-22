#include "ev3dev.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace ev3dev;
using namespace std;

void moveToPosition(large_motor motor, int position, int speed = 30)
{
  motor.set_position_sp(position);
  motor.set_speed_sp(speed);
  motor.set_command(motor.command_run_to_abs_pos);

  while (abs(position - motor.position()) > 5)
    ;

  motor.set_command(motor.stop_action_brake);
}

int main(int argc, char **argv)
{
  large_motor motor(OUTPUT_D);
  motor.reset();
  int val = 0;
  sscanf(argv[1], "%d", &val);
  moveToPosition(motor, val);

  return 0;
}
