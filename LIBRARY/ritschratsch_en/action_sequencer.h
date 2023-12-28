#ifndef _action_sequencer_h
#define _action_sequencer_h

#include "Arduino.h"
#include "Servo.h"
#include "waves.h"

#define LO_BYTE(a) *((uint8_t *)&a)
#define HI_BYTE(a) *(((uint8_t *)&a) + 1)

#define NORMAL 0
#define RANDOM 1
#define RANDOM_GRID 2

// sequencer table value idx offset
#define INTERVAL 0
#define PAUSE 1
// MOTOR
#define MOTOR_SPEED 2
#define MOTOR_DIRECTION 3
// SERVO
#define SERVO_POSITION 1
// OUTPUT
#define OUTPUT_VALUE 2

#define WAVE_SIN 0
#define WAVE_SAW 1
#define WAVE_TRI 2
#define WAVE_SQU 3

class LedWave
{

private:
    uint8_t amplitude = 0, offset = 0, incr = 0;
    uint16_t duration = 0, updaterate = 0;

    uint8_t amp = 0, waveform = 0;
    uint16_t t = 0, dur = 0, amp_step = 0;

public:
    void set_led_updaterate(uint16_t updaterate)
    {
        this->updaterate = updaterate;
    }

    void set_led( uint8_t waveform, uint8_t amplitude, uint8_t offset, uint8_t incr)
    {
        this->waveform = waveform;
        this->amplitude = amplitude;
        this->offset = offset;
        this->incr = incr;
    }

    void trigger_led()
    {
        t = 0;
        amp = amplitude;
        dur = 0;
    }

    int8_t next_led_sample()
    {
        t += incr;
        dur++;
        if (dur > amp_step)
        {
            amp--;
            dur = 0;
        }
        uint8_t wave = 0;
        switch (waveform)
        {
        case WAVE_SIN:
            wave = sine(t);
            break;

        case WAVE_SAW:
            wave = saw(t);
            break;

        case WAVE_TRI:
            wave = triangle(t);
            break;

        case WAVE_SQU:
            wave = square(uint8_t(t));
            break;

        default:
            break;
        }

        uint16_t val = wave * amp;
        val = HI_BYTE(val);
        return val + offset;
    }

    bool get_led_is_acive()
    {
        return amp;
    }

protected:
    void set_led_duration(uint16_t d)
    {
        duration = d;
        duration = duration / (1000 / updaterate);
        amp_step = duration / amplitude;
        duration = amplitude * amp_step; // correct for division error
    }
};

class ActionSequencer : public LedWave
{

protected:
    uint8_t values_per_step, pause_offset, interval_offset;

private:
    const uint16_t *data;
    uint16_t size, current_step, step_count, range_min, range_max;
    uint32_t timestamp = 0;
    uint32_t step_end_timestamp = 0;
    bool next_step = false;
    bool step_end = false;

    bool is_active = false;

    uint8_t mode = 0; // TABLE, RANDOM, RANDOM + QUANTIZED
    uint16_t quantization_interval = 125;

    uint16_t next_interval()
    {
        uint16_t interval = 0;
        switch (mode)
        {
        case NORMAL:
            interval = pgm_read_word(&data[current_step * values_per_step + pause_offset]);
            break;
        case RANDOM:
            interval = random(range_min, range_max);
            break;

        case RANDOM_GRID:
            interval = random(range_min, range_max);
            interval /= quantization_interval;
            interval *= quantization_interval;
            break;

        default:
            break;
        }

        return interval;
    }

public:
    void set_table(const uint16_t *data, uint16_t data_size) //, uint8_t values_per_step, uint8_t pause_offset, uint8_t interval_offset)
    {
        this->data = data;
        // this->values_per_step = values_per_step;
        // this->pause_offset = pause_offset;
        // this->interval_offset = interval_offset;
        size = data_size / 2;
        step_count = size / values_per_step;
    }

    void start()
    {
        is_active = true;
        current_step = 0;
        timestamp = millis() + next_interval(); // pgm_read_word(&data[INTERVAL]);
        uint16_t interval = pgm_read_word(&data[interval_offset]);
        step_end_timestamp = interval;

        next_step = true;
        step_end = false;
    }

    void set_sequencer(uint8_t mode, uint16_t range_min, uint16_t range_max, uint16_t quantization_interval)
    {
        this->mode = mode;
        this->range_min = range_min;
        this->range_max = range_max;
        this->quantization_interval = quantization_interval;
    }

    void update()
    {

        next_step = false;
        if (millis() > timestamp)
        {
            current_step++;
            if (current_step >= step_count)
            {
                current_step = 0;
            }
            uint16_t interval = next_interval();
            Serial.println(interval);
            timestamp += interval; // pgm_read_word(&data[idx + INTERVAL]);
            next_step = true;
            step_end = false;
            step_end_timestamp = millis() + get_value(interval_offset); // pgm_read_word(&data[idx + interval_offset]);
        }

        if (millis() > step_end_timestamp)
        {
            step_end = true;
        }

        on_step();
        on_end();
    }

    bool get_is_active()
    {
        return is_active;
    }

protected:
    virtual void on_step() = 0;

    virtual void on_end() = 0;

    bool step()
    {
        return next_step;
    }

    bool end()
    {
        return step_end;
    }

    uint16_t get_value(uint8_t type)
    {
        uint16_t idx = current_step * values_per_step;
        idx += type;
        return pgm_read_word(&data[idx]);
    }
};

class riMotor : public ActionSequencer
{
private:
    uint8_t A, B, S;

    void set(uint8_t speed, uint8_t dir)
    {

        int duty_cycle = map(speed, 0, 100, 0, 255);
        duty_cycle = constrain(duty_cycle, 0, 255);
        analogWrite(S, duty_cycle);
        if (dir == 0)
        {
            digitalWrite(A, LOW);
            digitalWrite(B, HIGH);
        }
        else
        {
            digitalWrite(A, HIGH);
            digitalWrite(B, LOW);
        }
    }

public:
    void init(uint8_t A, uint8_t B, uint8_t S)
    {
        this->A = A;
        this->B = B;
        this->S = S;
        pinMode(A, OUTPUT);
        pinMode(B, OUTPUT);
        pinMode(S, OUTPUT);
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(S, LOW);

        values_per_step = 4;
        pause_offset = 1;
        interval_offset = 0;
    }

    void on_step()
    {
        if (step())
        {
            trigger_led();
            set_led_duration(get_value(interval_offset));
            uint8_t speed = get_value(MOTOR_SPEED);
            uint8_t dir = get_value(MOTOR_DIRECTION);
            set(speed, dir);
        }
    }

    void on_end()
    {
        if (end())
        {
            set(0, 0);
        }
    }
};

class riServo : public ActionSequencer
{
private:
    Servo servo;
    uint8_t pin;

public:
    void init(Servo &servo, uint8_t pin)
    {
        this->servo = servo;
        this->pin = pin;
        servo.attach(pin);

        values_per_step = 2;
        interval_offset = 0;
        pause_offset = 0;
    }

    void on_step()
    {
        if (step())
        {
            set_led_duration(400);
            trigger_led();
            uint8_t pos = uint8_t(get_value(SERVO_POSITION));
            servo.write(pos);
        }
    }

    void on_end()
    {
        return;
    }
};

class riOutput : public ActionSequencer
{
private:
    uint8_t pin, has_pwm;

public:
    void init(uint8_t pin, uint8_t has_pwm)
    {
        this->pin = pin;
        this->has_pwm = has_pwm;
        pinMode(pin, OUTPUT);
        values_per_step = 3;
        interval_offset = 0;
        pause_offset = 1;
    }

    void on_step()
    {
        if (step())
        {
            trigger_led();
            set_led_duration(get_value(interval_offset));
            uint8_t value = uint8_t(get_value(OUTPUT_VALUE));
            if (has_pwm)
            {
                int duty_cycle = map(value, 0, 100, 0, 255);
                duty_cycle = constrain(duty_cycle, 0, 255);
                analogWrite(pin, duty_cycle);
            }
            else
            {
                digitalWrite(pin, HIGH);
            }
        }
    }

    void on_end()
    {
        if (end())
        {
            digitalWrite(pin, LOW);
        }
    }
};

#endif