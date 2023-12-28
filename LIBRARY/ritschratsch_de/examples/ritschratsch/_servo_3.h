/*
                                 ____
                    +------------|  |---+
                    |                   |
    +---------------+                   |
    |                                   |
    |                                   |
    |                                   |
    |                                   |
    |           S E R V O  3            |
    |                                   |
    |                                   |–––––––––brown–––––––o  GND ( - )
    |                                   |–––––––––red–––––––––o  5V ( + )
    |                                   |–––––––––yellow––––––o  PIN A3
    +-----------------------------------+


    Der Servomotor kann nur etwa eine halbe Umdrehung machen,
    aber man kann ihn in eine bestimmte Stellung bringen.
    Dafür gibt man einfach einen Winkel zwischen 0 und 180 Grad an.
*/

// Servo aktivieren
// #define SERVO_3
// Modus festlegen, folgende Modi sind möglich: NORMAL, RANDOM, RANDOM_GRID
#define SERVO_3_MODE NORMAL
// minimale Dauer des Zufallintervals
#define SERVO_3_RANDOM_MIN 500
// maximale Dauer des Zufallintervals
#define SERVO_3_RANDOM_MAX 6000
// Größe des zeitlichen Rasters für den RANDOM_GRID Modus in Milliskeunden (1 Sekunde = 1000 Millisekunden)
#define SERVO_3_GRID 125

// PAUSE DANNACH ( nur im Modus NORMAL ), WINKEL (0 - 180)
const uint16_t table_servo_3[] PROGMEM = {
    /******* ANFANG *******/
    1000, 0,
    1000, 140,
    1000, 0,
    1000, 140
    /******** ENDE *******/
};