#ifndef WS2812_CONTROL_H
#define WS2812_CONTROL_H
#include <stdint.h>
#include "sdkconfig.h"
#define NUM_LEDS CONFIG_WS2812_NUM_LEDS

typedef union {
  struct __attribute__ ((packed)) {
    uint8_t r, g, b;
  };
  uint32_t num;
} rgbVal;

inline rgbVal makeRGBVal(uint8_t r, uint8_t g, uint8_t b)
{
  rgbVal v;

  v.r = r;
  v.g = g;
  v.b = b;
  return v;
}

// Setup the hardware peripheral. Only call this once.
void ws2812_control_init(void);

// Update the LEDs to the new state. Call as needed.
// This function will block the current task until the RMT peripheral is finished sending 
// the entire sequence.
void ws2812_write_leds(rgbVal *pixels);

#endif