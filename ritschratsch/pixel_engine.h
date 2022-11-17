#ifndef _pixel_engine_h
#define _pixel_engine_h
#include "Arduino.h"
#include "FastLED.h"

class PixelEngine
{
private:
    CRGB *buffer;

    uint8_t buffer_size, buffer_center;
    bool buffer_odd = false;

public:
    void init(CRGB *buffer, uint8_t buffer_size)
    {
        this->buffer = buffer;
        this->buffer_size = buffer_size;
        buffer_center = buffer_size / 2;
        if (buffer_size & 0x01)
        {
            buffer_odd = true;
        }
    }

    void push(uint8_t val)
    {
        for (uint8_t i = buffer_size - 1; i >= 1; i--)
        {
            buffer[i] = buffer[i - 1];
        }
        buffer[0] = Wheel(val);
    }

    void push_center(uint8_t val)
    {
        CRGB color = Wheel(val);
        for (uint8_t l = 0, r = buffer_size - 1; l < buffer_center; l++, r--)
        {
            buffer[l] = buffer[l + 1];
            buffer[r] = buffer[r - 1];
        }

        buffer[buffer_center] = color;
        if (!buffer_odd)
        {
            buffer[buffer_center-1] = color;
        }
    }

    CRGB Wheel(byte WheelPos)
    {
        WheelPos = 255 - WheelPos;
        if (WheelPos < 85)
        {
            return CRGB(byte(255 - WheelPos * 3), 0, byte(WheelPos * 3));
        }
        if (WheelPos < 170)
        {
            WheelPos -= 85;
            return CRGB(0, byte(WheelPos * 3), byte(255 - WheelPos * 3));
        }
        WheelPos -= 170;
        return CRGB(byte(WheelPos * 3), byte(255 - WheelPos * 3), 0);
    }
};

#endif