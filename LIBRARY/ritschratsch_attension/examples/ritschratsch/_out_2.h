/*

    ANALOG OUTPUT

    Der Output kann verwendet werden um einen DC Motor zu steuern.
    Man kann zwar die Geschwindigkeit einstellen (0-100), aber nicht die Richtung.

    PIN 6
*/

// Ausgang aktivieren
// #define OUTPUT_2
// Modus festlegen, folgende Modi sind möglich: NORMAL, RANDOM, RANDOM_GRID
#define OUTPUT_2_MODE NORMAL
// minimale Dauer desZufallintervals
#define OUTPUT_2_RANDOM_MIN 500
// maximale Dauer desZufallintervals
#define OUTPUT_2_RANDOM_MAX 2000
// Größe des zeitlichen Rasters für den RANDOM_GRID Modus in Milliskeunden (1 Sekunde = 1000 Millisekunden)
#define OUTPUT_2_GRID 125

// DAUER,  INTERVAL (Nur im Modus NORMAL, sonst 0), STÄRKE / GESCHWINDIGKEIT (0-100)
const uint16_t table_output_2[] PROGMEM = {
    /******* ANFANG *******/
    100, 500, 50,
    100, 500, 75,
    100, 500, ON
    /******** ENDE *******/
};