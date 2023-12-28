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


    Der Servomotor kann nur etwa eine halbe Umdrehung machen,
    aber man kann ihn in eine bestimmte Stellung bringen.
    Dafür gibt man einfach einen Winkel zwischen 0 und 180 Grad an.
*/

// CLARA TEEKANNE

// Servo aktivieren
 #define SERVO_1
// Modus festlegen, folgende Modi sind möglich: NORMAL, RANDOM, RANDOM_GRID
#define SERVO_1_MODE NORMAL
// minimale Dauer desZufallintervals
#define SERVO_1_RANDOM_MIN 2000
// maximale Dauer desZufallintervals
#define SERVO_1_RANDOM_MAX 4000
// Größe des zeitlichen Rasters für den RANDOM_GRID Modus in Milliskeunden (1 Sekunde = 1000 Millisekunden)
#define SERVO_1_GRID 125

// INTERVAL ( nur im Modus NORMAL ), WINKEL (0 - 180)
const uint16_t table_servo_1[] PROGMEM = {
    /******* ANFANG *******/
    1000, 45,
    500,30,
    800,45,
    300,30,
    700,45,
    1000,30
    
    /******** ENDE *******/
};
