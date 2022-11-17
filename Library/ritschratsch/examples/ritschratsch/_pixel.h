/* 

_____________________________________________
\                                            |
/   +–––––––+   +–––––––+   +–––––––+   +5V c|–––––––––––––––o 5V (+)
\   |       |   |       |   |       |        |
/   |   3   |   |   2   |   |   1   |    DI c|––––|220R|–––––o PIN D12
\   |       |   |       |   |       |        |
/   +–––––––+   +–––––––+   +–––––––+   GND c|–––––––––––––––o GND (-)
\____________________________________________|


The LED strip show colorfull lighteffects which are triggered when the different motors and outputs are active.
To make this work properly you have to count the LEDs and set the NUM_PIXELS value accordingly.
Be careful when connecting the strip to the arduino: you have to connect PIN D12 of the arduino via a 220 Ohm 
resistor to the input marked with DI on the strip. Power has to be provided via the 5V and GND connection on the strip.

When no motor or output is activ the strip will glow in its basecolor. 
For each output / motor you can set how fast and strong the basecolor will vary.
If there are more lighteffects activated simultaneously they will influence each other,
this way a you can create a colorfull spectacle!

*/

// activate leds
#define PIXEL
// number of leds on the strip
#define NUM_PIXEL 28


/** NOTE: all numbers have to be in the range of 0 - 255 **/

// set basecolor
#define BASECOLOR 60


// Motor 1
#define MOTOR_1_PIXEL_COLOR 40
#define MOTOR_1_PIXEL_VARIATION  40
#define MOTOR_1_PIXEL_VARIATION_SPEED 12 

// Motor 2
#define MOTOR_2_PIXEL_COLOR 60
#define MOTOR_2_PIXEL_VARIATION  100
#define MOTOR_2_PIXEL_VARIATION_SPEED 20

// Servo 1
#define SERVO_1_PIXEL_COLOR 80
#define SERVO_1_PIXEL_VARIATION  140
#define SERVO_1_PIXEL_VARIATION_SPEED 10 

// Servo 2
#define SERVO_2_PIXEL_COLOR 100
#define SERVO_2_PIXEL_VARIATION  180
#define SERVO_2_PIXEL_VARIATION_SPEED 18 

// Servo 3
#define SERVO_3_PIXEL_COLOR 120
#define SERVO_3_PIXEL_VARIATION  220
#define SERVO_3_PIXEL_VARIATION_SPEED 14 

// Output 1
#define OUTPUT_1_PIXEL_COLOR 140
#define OUTPUT_1_PIXEL_VARIATION  20
#define OUTPUT_1_PIXEL_VARIATION_SPEED 22

// Output 2
#define OUTPUT_2_PIXEL_COLOR 160
#define OUTPUT_2_PIXEL_VARIATION  60
#define OUTPUT_2_PIXEL_VARIATION_SPEED 16

// Output 3
#define OUTPUT_3_PIXEL_COLOR 200
#define OUTPUT_3_PIXEL_VARIATION  100
#define OUTPUT_3_PIXEL_VARIATION_SPEED 24

// Output 4
#define OUTPUT_4_PIXEL_COLOR 220
#define OUTPUT_4_PIXEL_VARIATION  140
#define OUTPUT_4_PIXEL_VARIATION_SPEED 30