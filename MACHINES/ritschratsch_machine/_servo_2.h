/*
                                 ____
                    +------------|  |---+
                    |                   |
    +---------------+                   |
    |                                   |
    |                                   |
    |                                   |
    |                                   |
    |           S E R V O  2            |
    |                                   |
    |                                   |–––––––––brown–––––––o  GND ( - )
    |                                   |–––––––––red–––––––––o  5V ( + )
    |                                   |–––––––––yellow––––––o  PIN A2
    +-----------------------------------+


    Der Servomotor kann nur etwa eine halbe Umdrehung machen,
    aber man kann ihn in eine bestimmte Stellung bringen.
    Dafür gibt man einfach einen Winkel zwischen 0 und 180 Grad an.
*/

// Servo aktivieren
 #define SERVO_2
// Modus festlegen, folgende Modi sind möglich: NORMAL, RANDOM, RANDOM_GRID
#define SERVO_2_MODE NORMAL
// minimale Dauer desZufallintervals
#define SERVO_2_RANDOM_MIN 500
// maximale Dauer desZufallintervals
#define SERVO_2_RANDOM_MAX 6000
// Größe des zeitlichen Rasters für den RANDOM_GRID Modus in Milliskeunden (1 Sekunde = 1000 Millisekunden)
#define SERVO_2_GRID 125

// PAUSE DANNACH ( nur im Modus NORMAL ), WINKEL (0 - 180)
const uint16_t table_servo_2[] PROGMEM = {
    /******* ANFANG *******/
    400, 0,
    3000,70
    /******** ENDE *******/
};
