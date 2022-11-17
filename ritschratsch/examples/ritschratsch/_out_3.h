/*

   DGITAL OUTPUT - PIN D7
    This output can be used to turn a DC motor on and off via a transistor.

*/

// activate output
// #define OUTPUT_3
// set mode, the follwing modes are possible NORMAL, RANDOM, RANDOM_GRID
#define OUTPUT_3_MODE NORMAL

// the following settings are only needed for RANDOM and RANDOM_GRID mode
// minimum duration of random interval
#define OUTPUT_3_RANDOM_MIN 1000
// maximum duration of the random interval
#define OUTPUT_3_RANDOM_MAX 2000
// the following setting is only needed for RANDOM_GRID mode
// grid size in milliseconds   (1 second = 1000 milliseconds)
#define OUTPUT_3_GRID 125

/*
|--- on-time 1 ---|                         |--- on-time 2---|
|------------------interval 1 --------------|------------------interval 2 --------------| ...

Order of values in the table:
on-time, interval duration, ON
*/
const uint16_t table_output_3[] PROGMEM = {
    /******* START *******/
    100, 500, ON,
    100, 500, ON,
    100, 500, ON
    /******** END *******/
};