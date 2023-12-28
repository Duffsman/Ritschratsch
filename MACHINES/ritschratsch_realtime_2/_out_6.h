/*

    DIGITAL OUTPUT

    Der Output kann verwendet werden um einen DC Motor oder Relais zu steuern.
    Man kann den Motor nur an oder aus machen, aber weder die Geschwindigkeit, noch die Richtung einstellen.

    PIN A6
*/

// JANKO MURMELBAHN
// Output aktivieren
#define OUTPUT_6
//  Modus festlegen, folgende Modi sind möglich: NORMAL, RANDOM, RANDOM_GRID
#define OUTPUT_6_MODE RANDOM
// minimale Dauer desZufallintervals
#define OUTPUT_6_RANDOM_MIN 2000
// maximale Dauer desZufallintervals
#define OUTPUT_6_RANDOM_MAX 6000
// Größe des zeitlichen Rasters für den RANDOM_GRID Modus in Milliskeunden (1 Sekunde = 1000 Millisekunden)
#define OUTPUT_6_GRID 125

// DAUER,  INTERVAL(Nur im Modus NORMAL, sonst 0), STÄRKE / GESCHWINDIGKEIT (0-100)
const uint16_t table_output_6[] PROGMEM = {
  /******* ANFANG *******/
  2000, 500, ON,
  1000, 500, ON,
  1500, 500, ON
  /******** ENDE *******/
};