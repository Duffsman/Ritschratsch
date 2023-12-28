/*

    DIGITAL OUTPUT

    Der Output kann verwendet werden um einen DC Motor oder Relais zu steuern.
    Man kann den Motor nur an oder aus machen, aber weder die Geschwindigkeit, noch die Richtung einstellen.

    PIN 7
*/

// JANKO KANNE
// Ausgang aktivieren
#define OUTPUT_3
//  Modus festlegen, folgende Modi sind möglich: NORMAL, RANDOM, RANDOM_GRID
#define OUTPUT_3_MODE NORMAL
// minimale Dauer desZufallintervals
#define OUTPUT_3_RANDOM_MIN 4000
// maximale Dauer desZufallintervals
#define OUTPUT_3_RANDOM_MAX 9000
// Größe des zeitlichen Rasters für den RANDOM_GRID Modus in Milliskeunden (1 Sekunde = 1000 Millisekunden)
#define OUTPUT_3_GRID 125

// DAUER,  PAUSE DANNACH (Nur im Modus NORMAL, sonst 0), STÄRKE / GESCHWINDIGKEIT (0-100)
const uint16_t table_output_3[] PROGMEM = {
  /******* ANFANG *******/
  3000, 3500, ON,
  3000, 3500, ON,
  3000, 3500, ON,
  3000, 6500, ON,


  /******** ENDE *******/
};