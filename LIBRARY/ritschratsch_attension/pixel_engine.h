#ifndef _pixel_engine_h
#define _pixel_engine_h
#include "Arduino.h"
#include "FastLED.h"

class PixelEngine
{
private:
    CRGB *buffer;

    uint16_t buffer_size, buffer_center;
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
        for (uint16_t i = buffer_size - 1; i >= 1; i--)
        {
            buffer[i] = buffer[i - 1];
        }
        buffer[0] = Wheel(val);
    }

    void push_from_to(uint8_t val, uint16_t from, uint16_t to)
    {
        for (uint16_t i = to; i < from - 1; i++)
        {
            buffer[i] = buffer[i - 1];
        }
        buffer[from] = Wheel(val);
    }

    void push_from_to_center(uint8_t val, uint16_t from, uint16_t to)
    {
        uint16_t from_to_size = to - from;
        uint16_t center = from + (from_to_size) / 2;
        CRGB color = Wheel(val);

        for (uint16_t l = from, r = to - 1; l < center; l++, r--)
        {
            buffer[l] = buffer[l + 1];
            buffer[r] = buffer[r - 1];
        }
        buffer[center] = color;

        if (from_to_size & 0x01)  // size is odd
        {
            buffer[center-1] = color;
        }
    }

    void push_center(uint8_t val)
    {
        CRGB color = Wheel(val);
        for (uint16_t l = 0, r = buffer_size - 1; l < buffer_center; l++, r--)
        {
            buffer[l] = buffer[l + 1];
            buffer[r] = buffer[r - 1];
        }

        buffer[buffer_center] = color;
        if (!buffer_odd)
        {
            buffer[buffer_center - 1] = color;
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