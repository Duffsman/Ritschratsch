#ifndef _rira_engine_h
#define _rira_engine_h

#include "action_sequencer.h"
#include "pixel_engine.h"
// table values
#define FWD 0
#define BWD 1
#define NONE 0
#define ON 100

// #include "_motor_1.h"
// #include "_motor_2.h"
// #include "_out_1.h"
// #include "_out_2.h"
// #include "_out_3.h"
// #include "_out_4.h"
// #include "_servo_1.h"
// #include "_servo_2.h"
// #include "_servo_3.h"
// #include "_pixel.h"

//****************************************************** PINS

static const uint8_t NEOPIXEL_PIN = 12;

static const uint8_t MOTOR_1_A = 2;
static const uint8_t MOTOR_1_B = 4;
static const uint8_t MOTOR_1_SPEED = 3;

static const uint8_t MOTOR_2_A = 9;
static const uint8_t MOTOR_2_B = 10;
static const uint8_t MOTOR_2_SPEED = 11;

static const uint8_t SERVO_1_PIN = A1; // A0;
static const uint8_t SERVO_2_PIN = A2; // A1;
static const uint8_t SERVO_3_PIN = A3; // A2;

static const uint8_t OUT_1 = 5;
static const uint8_t OUT_2 = 6;
static const uint8_t OUT_3 = 7;
static const uint8_t OUT_4 = 8;

riMotor motor_1;
riMotor motor_2;

Servo _servo_1;
Servo _servo_2;
Servo _servo_3;

riServo servo_1;
riServo servo_2;
riServo servo_3;

riOutput output_1;
riOutput output_2;
riOutput output_3;
riOutput output_4;

#define ACTION_COUNT 9
ActionSequencer *actions[9];

CRGB leds[NUM_PIXEL];
PixelEngine pixel;
#define LED_FRAMERATE 16
#define LED_FRAME_INTERVAL 1000 / LED_FRAMERATE
#define LED_UPDATERATE 100
#define LED_UPDATE_INTERVAL 1000 / LED_UPDATERATE

void start_rira()
{
    Serial.begin(19200);

    motor_1.init(MOTOR_1_A, MOTOR_1_B, MOTOR_1_SPEED);
    motor_1.set_sequencer(MOTOR_1_MODE, MOTOR_1_RANDOM_MIN, MOTOR_1_RANDOM_MAX, MOTOR_1_GRID);
    motor_1.set_table(table_motor_1, sizeof(table_motor_1));
    actions[0] = &motor_1;
#ifdef MOTOR_1
    motor_1.set_led(WAVE_SIN, MOTOR_1_PIXEL_VARIATION, MOTOR_1_PIXEL_COLOR, MOTOR_1_PIXEL_VARIATION_SPEED);
    motor_1.start();
#endif

    motor_2.init(MOTOR_2_A, MOTOR_2_B, MOTOR_2_SPEED);
    motor_2.set_sequencer(MOTOR_2_MODE, MOTOR_2_RANDOM_MIN, MOTOR_2_RANDOM_MAX, MOTOR_2_GRID);
    motor_2.set_table(table_motor_2, sizeof(table_motor_2));
    actions[1] = &motor_2;
#ifdef MOTOR_2
    motor_2.set_led(WAVE_TRI, MOTOR_2_PIXEL_VARIATION, MOTOR_2_PIXEL_COLOR, MOTOR_2_PIXEL_VARIATION_SPEED);
    motor_2.start();
#endif

    servo_1.init(_servo_1, SERVO_1_PIN);
    servo_1.set_sequencer(SERVO_1_MODE, SERVO_1_RANDOM_MIN, SERVO_1_RANDOM_MAX, SERVO_1_GRID);
    servo_1.set_table(table_servo_1, sizeof(table_servo_1));
    actions[2] = &servo_1;
#ifdef SERVO_1
    servo_1.set_led(WAVE_SAW, SERVO_1_PIXEL_VARIATION, SERVO_1_PIXEL_COLOR, SERVO_1_PIXEL_VARIATION_SPEED);
    servo_1.start();
#endif

    servo_2.init(_servo_2, SERVO_2_PIN);
    servo_2.set_sequencer(SERVO_2_MODE, SERVO_2_RANDOM_MIN, SERVO_2_RANDOM_MAX, SERVO_2_GRID);
    servo_2.set_table(table_servo_2, sizeof(table_servo_2));
    actions[3] = &servo_2;
#ifdef SERVO_2
    servo_2.set_led(WAVE_SQU, SERVO_2_PIXEL_VARIATION, SERVO_2_PIXEL_COLOR, SERVO_2_PIXEL_VARIATION_SPEED);
    servo_2.start();
#endif

    servo_3.init(_servo_3, SERVO_3_PIN);
    servo_3.set_sequencer(SERVO_3_MODE, SERVO_3_RANDOM_MIN, SERVO_3_RANDOM_MAX, SERVO_3_GRID);
    servo_3.set_table(table_servo_3, sizeof(table_servo_3));
    actions[4] = &servo_3;
#ifdef SERVO_3
    servo_3.set_led(WAVE_SAW, SERVO_3_PIXEL_VARIATION, SERVO_3_PIXEL_COLOR, SERVO_3_PIXEL_VARIATION_SPEED);
    servo_3.start();
#endif

    output_1.init(OUT_1, true);
    output_1.set_sequencer(OUTPUT_1_MODE, OUTPUT_1_RANDOM_MIN, OUTPUT_1_RANDOM_MAX, OUTPUT_1_GRID);
    output_1.set_table(table_output_1, sizeof(table_output_1));
    actions[5] = &output_1;
#ifdef OUTPUT_1
    output_1.set_led(WAVE_SQU, OUTPUT_1_PIXEL_VARIATION, OUTPUT_1_PIXEL_COLOR, OUTPUT_1_PIXEL_VARIATION_SPEED);
    output_1.start();
#endif

    output_2.init(OUT_2, true);
    output_2.set_sequencer(OUTPUT_2_MODE, OUTPUT_2_RANDOM_MIN, OUTPUT_2_RANDOM_MAX, OUTPUT_2_GRID);
    output_2.set_table(table_output_2, sizeof(table_output_2));
    actions[6] = &output_2;
#ifdef OUTPUT_2
    output_2.set_led(WAVE_SIN, OUTPUT_2_PIXEL_VARIATION, OUTPUT_2_PIXEL_COLOR, OUTPUT_2_PIXEL_VARIATION_SPEED);
    output_2.start();
#endif

    output_3.init(OUT_3, false);
    output_3.set_sequencer(OUTPUT_3_MODE, OUTPUT_3_RANDOM_MIN, OUTPUT_3_RANDOM_MAX, OUTPUT_3_GRID);
    output_3.set_table(table_output_3, sizeof(table_output_3));
    actions[7] = &output_3;
#ifdef OUTPUT_3
    output_3.set_led(WAVE_SAW, OUTPUT_3_PIXEL_VARIATION, OUTPUT_3_PIXEL_COLOR, OUTPUT_3_PIXEL_VARIATION_SPEED);
    output_3.start();
#endif

    output_4.init(OUT_4, false);
    output_4.set_sequencer(OUTPUT_4_MODE, OUTPUT_4_RANDOM_MIN, OUTPUT_4_RANDOM_MAX, OUTPUT_4_GRID);
    output_4.set_table(table_output_4, sizeof(table_output_4));
    actions[8] = &output_4;
#ifdef OUTPUT_4
    output_4.set_led(WAVE_TRI, OUTPUT_4_PIXEL_VARIATION, OUTPUT_4_PIXEL_COLOR, OUTPUT_4_PIXEL_VARIATION_SPEED);
    output_4.start();
#endif

#ifdef PIXEL
    for (uint8_t i = 0; i < ACTION_COUNT; i++)
    {
        actions[i]->set_led_updaterate(LED_UPDATERATE);
    }

    FastLED.addLeds<WS2812B, NEOPIXEL_PIN, RGB>(leds, NUM_PIXEL);
    FastLED.setBrightness(150);
    pixel.init(leds, NUM_PIXEL);
#endif
}

void update_rira()
{
    for (uint8_t i = 0; i < ACTION_COUNT; i++)
    {
        if (actions[i]->get_is_active())
        {
            actions[i]->update();
        }
    }

#ifdef PIXEL
    static uint32_t led_update_timestamp = 0;
    static uint16_t base_oscillation = 0;
    static int led_sum = 0;
    if (millis() >= led_update_timestamp)
    {
        led_update_timestamp = millis() + LED_UPDATE_INTERVAL;
        uint8_t active_count = 1;
        for (uint8_t i = 0; i < ACTION_COUNT; i++)
        {
            if (actions[i]->get_led_is_acive())
            {
                active_count++;
                led_sum += actions[i]->next_led_sample();
            }
        }
        led_sum /= active_count;
        base_oscillation += 5;
        uint8_t out = led_sum + 128 + BASECOLOR + (sine(base_oscillation >> 3) >> 4);

        pixel.push_center(int8_t(out));
    }

    static uint32_t led_frame_timestamp = 0;
    if (millis() > led_frame_timestamp)
    {
        led_frame_timestamp = millis() + LED_FRAME_INTERVAL;
        FastLED.show();
    }
#endif
}

#endif