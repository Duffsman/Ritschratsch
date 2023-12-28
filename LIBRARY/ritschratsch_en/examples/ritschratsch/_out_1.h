/*

    ANALOG OUTPUT - PIN D5

    This output can be used to control the speed (0-100) of a DC motor via a transistor.

*/

// activate output
// #define OUTPUT_1
// set mode, the follwing modes are possible NORMAL, RANDOM, RANDOM_GRID
#define OUTPUT_1_MODE NORMAL

// the following settings are only needed for RANDOM and RANDOM_GRID mode
// minimum duration of random interval
#define OUTPUT_1_RANDOM_MIN 1000
// maximum duration of the random interval
#define OUTPUT_1_RANDOM_MAX 2000
// the following setting is only needed for RANDOM_GRID mode
// grid size in milliseconds   (1 second = 1000 milliseconds)
#define OUTPUT_1_GRID 125

/*
|--- on-time 1 ---|                         |--- on-time 2---|
|------------------interval 1 --------------|------------------interval 2 --------------| ...

Order of values in the table:
on-time, interval duration, speed (0-100)
*/
const uint16_t table_output_1[] PROGMEM = {
    /******* START *******/
    100, 500, 50,
    100, 500, 75,
    100, 500, 100
    /******** END *******/
};