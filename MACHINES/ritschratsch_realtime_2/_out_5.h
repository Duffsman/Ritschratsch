/*

    DIGITAL OUTPUT

    Der Output kann verwendet werden um einen DC Motor oder Relais zu steuern.
    Man kann den Motor nur an oder aus machen, aber weder die Geschwindigkeit, noch die Richtung einstellen.

    PIN A4
*/
// NUSSKNACKER & EISBECHER
// Output aktivieren
  #define OUTPUT_5
//  Modus festlegen, folgende Modi sind möglich: NORMAL, RANDOM, RANDOM_GRID
#define OUTPUT_5_MODE RANDOM
// minimale Dauer desZufallintervals
#define OUTPUT_5_RANDOM_MIN 4000
// maximale Dauer desZufallintervals
#define OUTPUT_5_RANDOM_MAX 10000
// Größe des zeitlichen Rasters für den RANDOM_GRID Modus in Milliskeunden (1 Sekunde = 1000 Millisekunden)
#define OUTPUT_5_GRID 125

// DAUER,  INTERVAL (Nur im Modus NORMAL, sonst 0), STÄRKE / GESCHWINDIGKEIT (0-100)
const uint16_t table_output_5[] PROGMEM = {
    /******* ANFANG *******/
    3500, 4000, ON,
   
    /******** ENDE *******/
};