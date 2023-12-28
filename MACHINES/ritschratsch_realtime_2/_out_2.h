/*

    ANALOG OUTPUT

    Der Output kann verwendet werden um einen DC Motor zu steuern.
    Man kann zwar die Geschwindigkeit einstellen (0-100), aber nicht die Richtung.

    PIN 6
*/
// JANKO KANNE NASE
// Ausgang aktivieren
 #define OUTPUT_2
// Modus festlegen, folgende Modi sind möglich: NORMAL, RANDOM, RANDOM_GRID
#define OUTPUT_2_MODE RANDOM
// minimale Dauer desZufallintervals
#define OUTPUT_2_RANDOM_MIN 1500
// maximale Dauer desZufallintervals
#define OUTPUT_2_RANDOM_MAX 8000
// Größe des zeitlichen Rasters für den RANDOM_GRID Modus in Milliskeunden (1 Sekunde = 1000 Millisekunden)
#define OUTPUT_2_GRID 125

// DAUER,  INTERVAL (Nur im Modus NORMAL, sonst 0), STÄRKE / GESCHWINDIGKEIT (0-100)
const uint16_t table_output_2[] PROGMEM = {
    /******* ANFANG *******/
    200, 500, 50,
    400, 500, 75,
    100, 500, ON,
    400,2000,ON,
    300,1000,80,
    /******** ENDE *******/
};