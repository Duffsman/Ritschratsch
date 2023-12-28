/*

    ANALOG OUTPUT

    Der Output kann verwendet werden um einen DC Motor zu steuern.
    Man kann zwar die Geschwindigkeit einstellen (0-100), aber nicht die Richtung.

    PIN 5
*/

// MYA WIPPE 

// Ausgang aktivieren
 #define OUTPUT_1
// Modus festlegen, folgende Modi sind möglich: NORMAL, RANDOM, RANDOM_GRID
#define OUTPUT_1_MODE RANDOM
// minimale Dauer des Zufallintervals
#define OUTPUT_1_RANDOM_MIN 2000
// maximale Dauer des Zufallintervals
#define OUTPUT_1_RANDOM_MAX 5000
// Größe des zeitlichen Rasters für den RANDOM_GRID Modus in Milliskeunden (1 Sekunde = 1000 Millisekunden)
#define OUTPUT_1_GRID 125

// DAUER, INTERVAL (Nur im Modus NORMAL, sonst 0), STÄRKE / GESCHWINDIGKEIT (0-100)
const uint16_t table_output_1[] PROGMEM = {
    /******* ANFANG *******/
    500, 500, 50,
    1000, 500, 75,
    2000, 500, ON,
    500, 500, 90,
    900, 500, 50,
    /******** ENDE *******/
};