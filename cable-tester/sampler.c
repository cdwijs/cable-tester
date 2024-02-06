#include "sampler.h"
#include <pico/stdlib.h> //for gpio_put and sleep_ms
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

TSAMPLER mySamplerData;
const TSAMPLER *mySampler = &mySamplerData;

void samplerExecute(void)
{
    switch(mySampler->state)
    {
        case ST_SAMP_WAIT:
        {
            break;
        }
    }
    gpio_put(LED_PIN, 1);
    sleep_ms(100);
}
