/*
                +-------------------------------------------+
                |                                           |
                |                                           |
                |               H - B R Ü C K E             |
                |                                           |
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
                                     3   2   4   7   8   9


Mit einer H-Brücke kann man die Richtung und  die Geschwindigkeit von einem DC Motor kontrollieren,
unsere kann sogar zwei Motoren steuern. Für jeden Motor werden drei Signale benötigt, ein Signal für 
die Geschwindigkeit (ENA sowie ENB) und je zwei Signale für die Richtung (IN1 & IN2 sowie IN3 & IN4).
Die Motoren werden an die Ausgännge OUT1 & OUT2 sowie OUT3 & OUT4 angeschlossen. Außerdem muss die 
H-Brücke auch noch mit Strom versorgt werden, das geht über den 12V (+) und GND (-) Anschluss.


*/
#define MOTOR_1
// Modus festlegen, folgende Modi sind möglich: NORMAL, RANDOM, RANDOM_GRID
#define MOTOR_1_MODE NORMAL
// minimale Dauer des Zufallintervals
#define MOTOR_1_RANDOM_MIN 500
// maximale Dauer des Zufallintervals
#define MOTOR_1_RANDOM_MAX  6000
// Größe des zeitlichen Rasters für den RANDOM_GRID Modus in Milliskeunden (1 Sekunde = 1000 Millisekunden)
#define MOTOR_1_GRID 125

// DAUER, PAUSE DANNACH (nur im Modus NORMAL, sonst 0), GESCHWINDIGKEIT (0 - 100), RICHTUNG (FWD, BWD)
const uint16_t table_motor_1[] PROGMEM = {
    /******* ANFANG *******/
    100, 400, 50, FWD,
    100, 400, 50, BWD,
     100, 800, 50, FWD,
    /******** ENDE *******/
    };