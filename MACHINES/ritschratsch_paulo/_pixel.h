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
#define NUM_PIXEL 50


/** HINWEIS: ALLE ZAHLEN KÖNNEN ZWISCHEN 0 UND 255 LIEGEN **/

// Grundfarbe einstellen
#define BASECOLOR 123


// Motor 1
#define MOTOR_1_PIXEL_COLOR 243
#define MOTOR_1_PIXEL_VARIATION  80
#define MOTOR_1_PIXEL_VARIATION_SPEED 12

// Motor 2
#define MOTOR_2_PIXEL_COLOR 145
#define MOTOR_2_PIXEL_VARIATION  191
#define MOTOR_2_PIXEL_VARIATION_SPEED 40

// Servo 1
#define SERVO_1_PIXEL_COLOR 80
#define SERVO_1_PIXEL_VARIATION  140
#define SERVO_1_PIXEL_VARIATION_SPEED 24

// Servo 2
#define SERVO_2_PIXEL_COLOR 100
#define SERVO_2_PIXEL_VARIATION  180
#define SERVO_2_PIXEL_VARIATION_SPEED 15 

// Servo 3
#define SERVO_3_PIXEL_COLOR 120
#define SERVO_3_PIXEL_VARIATION  220
#define SERVO_3_PIXEL_VARIATION_SPEED 14 

// Output 1
#define OUTPUT_1_PIXEL_COLOR 40
#define OUTPUT_1_PIXEL_VARIATION  50
#define OUTPUT_1_PIXEL_VARIATION_SPEED 80

// Output 2
#define OUTPUT_2_PIXEL_COLOR 160
#define OUTPUT_2_PIXEL_VARIATION  60
#define OUTPUT_2_PIXEL_VARIATION_SPEED 16

// Output 3
#define OUTPUT_3_PIXEL_COLOR 200
#define OUTPUT_3_PIXEL_VARIATION  100
#define OUTPUT_3_PIXEL_VARIATION_SPEED 24

// Output 4
#define OUTPUT_4_PIXEL_COLOR 220
#define OUTPUT_4_PIXEL_VARIATION  140
#define OUTPUT_4_PIXEL_VARIATION_SPEED 30
