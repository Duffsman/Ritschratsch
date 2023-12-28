#define FWD 0
#define BWD 1
#define NONE 0
#define ON 100

#include "_motor_1.h"
#include "_motor_2.h"
#include "_out_1.h"
#include "_out_2.h"
#include "_out_3.h"
#include "_out_4.h"
#include "_out_5.h"
#include "_out_6.h"
#include "_servo_1.h"
#include "_servo_2.h"
#include "_servo_3.h"
#include "_pixel.h"
#include "ritschratsch.h"


void setup()
{
    start_rira();
}

void loop()
{
    update_rira();
}