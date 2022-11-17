/*
                                 ____
                    +------------|  |---+
                    |                   |
    +---------------+                   |
    |                                   |
    |                                   |
    |                                   |
    |                                   |
    |           S E R V O  1            |
    |                                   |
    |                                   |–––––––––brown–––––––o  GND ( - )
    |                                   |–––––––––red–––––––––o  5V ( + )
    |                                   |–––––––––yellow––––––o  PIN A1
    +-----------------------------------+


    The servo motor only has a moving range of 180° so it can not even make a full revolution.
    The advantage of these motors is, that they are quite poweerful and you can make them move
    to a specific position. Therefore you can just set a certain angle between 0 and 180.
*/

// activate servo motor
// #define SERVO_1
// set mode, the follwing modes are possible NORMAL, RANDOM, RANDOM_GRID
#define SERVO_1_MODE NORMAL

// the following settings are only needed for RANDOM and RANDOM_GRID mode
// minimum duration of random interval
#define SERVO_1_RANDOM_MIN 2000
// maximum duration of the random interval
#define SERVO_1_RANDOM_MAX 4000
// the following setting is only needed for RANDOM_GRID mode
// grid size in milliseconds   (1 second = 1000 milliseconds)
#define SERVO_1_GRID 125


/*
|- set angle 1 -|                           |-set angle 2 -|
|------------------interval 1 --------------|------------------interval 2 --------------| ...

*/

const uint16_t table_servo_1[] PROGMEM = {
    /******* START *******/
    1000, 0,
    1000, 140
    /******** END *******/
};