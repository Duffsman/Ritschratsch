/*
                +-------------------------------------------+
                |                                           |
                |                                           |
                |               H - B R I D G E             |
                |                  L 2 9 8 D                |
                |                                           |
MOTOR 1 A o–––––| OUT 1                               OUT 4 |–––––o MOTOR 2 B
MOTOR 1 B o–––––| OUT 2                               OUT 3 |–––––o MOTOR 2 A
                |                                           |
                | | + | G |   |     | E | I | I | I | I | E |  
                | | 1 | N | + |     | N | N | N | N | N | N |
                | | 2 | D | 5 |     | A | 1 | 2 | 3 | 4 | B |
                +-------------------------------------------+
                    |   |   |        |   |   |   |   |   |
                    |   |   |        |   |   |   |   |   |
                    |   |   |        |   |   |   |   |   |
                    °   °   °        °   °   °   °   °   °
                    +   G   X        P   P   P   P   P   P
                    1   N            I   I   I   I   I   I
                    2   D            N   N   N   N   N   N
                                     D   D   D   D   D   D
                                     3   2   4   9   1   1
                                                     0   1

With the L298D h-bridge module the speed and direction of two DC motors can be controlled.
Each motor needs three connections from the Arduino, one for controlling the speed ( going to ENA resp. ENB)
and the other two for setting the direction (IN1/IN2 resp. IN3/IN4).
The motors have to be connected to the outputs OUT1/OUT2 and OUT3/OUT4, power is supplyed via the +12V and GND 
connection.
*/

// activate motor
// #define MOTOR_2
// set mode, the follwing modes are possible NORMAL, RANDOM, RANDOM_GRID
#define MOTOR_2_MODE NORMAL

// the following settings are only needed for RANDOM and RANDOM_GRID mode
// minimum duration of random interval
#define MOTOR_2_RANDOM_MIN 5000
// maximum duration of the random interval
#define MOTOR_2_RANDOM_MAX 6000
//the following setting is only needed for RANDOM_GRID mode
// grid size in milliseconds   (1 second = 1000 milliseconds)
#define MOTOR_2_GRID 125

/*
|--- on-time 1 ---|                         |--- on-time 2---|
|------------------interval 1 --------------|------------------interval 2 --------------| ...

Order of values in the table:
on-time, interval duration, speed (0-100), direction (FWD / BWD)
*/

const uint16_t table_motor_2[] PROGMEM = {
    /******* START *******/
    100, 400, 100, FWD,
    100, 400, 100, BWD
    /******** END *******/
};