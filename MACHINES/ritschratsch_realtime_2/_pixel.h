/* 

_____________________________________________
\                                            |
/   +–––––––+   +–––––––+   +–––––––+   +5V c|–––––––––––––––o 5V (+)
\   |       |   |       |   |       |        |
/   |   3   |   |   2   |   |   1   |    DI c|––––|220R|–––––o PIN 12
\   |       |   |       |   |       |        |
/   +–––––––+   +–––––––+   +–––––––+   GND c|–––––––––––––––o GND (-)
\____________________________________________|

Mit dem LED-Streifen kann man bunte Lichteffekte erzeugen, die ausgelöst werden, wenn die 
verschiedenen Motoren und Outputs aktiv sind. Damit das richtig funktioniert, muss bei NUM_PIXEL 
die Anzahlder LEDs auf dem Streifen eingetragen werden. Beim Anschließen muss man aufpassen, 
dass PIN 12 vom Arduino durch einen 220 Ohm Widerstand an DI vom LED-Streifen angeschlossen wird, 
nicht an DO! Außerdem muss der LED-Streifen auch noch mit Strom versorgt werden, das geht über 
den 5V (+) und GND (-) Anschluss.  

Wenn kein Lichteffekt aktiv ist leuchtet der LED-Streifen in der Grundfarbe (BASECOLOR).
Man kann für jeden Motor oder Output einstellen wie stark und schnell sein Lichteffekt 
die Grundfrabre verändert, wenn mehrere Lichteffekte gleichzeitig aktiv sind, beeinflussen
diese sich auch gegenseitig. So entsteht ein großes Farbspektakel!

*/

// pixel aktivieren
#define PIXEL
// Anzahl der pixel
#define NUM_PIXEL 65

#define PIXEL_BRIGHTNESS 150

#define PIXEL_SEGMENT_COUNT 3

// Grundfarbe einstellen
#define BASECOLOR 200


// from, to , basecolor
// from >= i <= to
uint16_t pixel_segments[] = {
    0,24,60,
    25,37,100,
    38,65,180
};

/** HINWEIS: ALLE ZAHLEN KÖNNEN ZWISCHEN 0 UND 255 LIEGEN **/


// Motor 1
#define MOTOR_1_PIXEL_COLOR 40
#define MOTOR_1_PIXEL_VARIATION  40
#define MOTOR_1_PIXEL_VARIATION_SPEED 12 
#define MOTOR_1_PIXEL_SEGMENT 0


// Motor 2
#define MOTOR_2_PIXEL_COLOR 60
#define MOTOR_2_PIXEL_VARIATION  100
#define MOTOR_2_PIXEL_VARIATION_SPEED 20
#define MOTOR_2_PIXEL_SEGMENT 1


// Servo 1
#define SERVO_1_PIXEL_COLOR 80
#define SERVO_1_PIXEL_VARIATION  140
#define SERVO_1_PIXEL_VARIATION_SPEED 10 
#define SERVO_1_PIXEL_SEGMENT 0


// Servo 2
#define SERVO_2_PIXEL_COLOR 100
#define SERVO_2_PIXEL_VARIATION  180
#define SERVO_2_PIXEL_VARIATION_SPEED 18 
#define SERVO_2_PIXEL_SEGMENT 0


// Servo 3
#define SERVO_3_PIXEL_COLOR 120
#define SERVO_3_PIXEL_VARIATION  220
#define SERVO_3_PIXEL_VARIATION_SPEED 14 
#define SERVO_3_PIXEL_SEGMENT 0


// Output 1
#define OUTPUT_1_PIXEL_COLOR 140
#define OUTPUT_1_PIXEL_VARIATION  20
#define OUTPUT_1_PIXEL_VARIATION_SPEED 22
#define OUTPUT_1_PIXEL_SEGMENT 0

// Output 2
#define OUTPUT_2_PIXEL_COLOR 160
#define OUTPUT_2_PIXEL_VARIATION  60
#define OUTPUT_2_PIXEL_VARIATION_SPEED 16
#define OUTPUT_2_PIXEL_SEGMENT 1

// Output 3
#define OUTPUT_3_PIXEL_COLOR 200
#define OUTPUT_3_PIXEL_VARIATION  100
#define OUTPUT_3_PIXEL_VARIATION_SPEED 4
#define OUTPUT_3_PIXEL_SEGMENT 2


// Output 4
#define OUTPUT_4_PIXEL_COLOR 220
#define OUTPUT_4_PIXEL_VARIATION  140
#define OUTPUT_4_PIXEL_VARIATION_SPEED 30
#define OUTPUT_4_PIXEL_SEGMENT 0

// Output 5
#define OUTPUT_5_PIXEL_COLOR 240
#define OUTPUT_5_PIXEL_VARIATION  150
#define OUTPUT_5_PIXEL_VARIATION_SPEED 30
#define OUTPUT_5_PIXEL_SEGMENT 1


// Output 6
#define OUTPUT_6_PIXEL_COLOR 220
#define OUTPUT_6_PIXEL_VARIATION  160
#define OUTPUT_6_PIXEL_VARIATION_SPEED 30
#define OUTPUT_6_PIXEL_SEGMENT 0