#include "sampler.h"
#include <pico/stdlib.h> //for gpio_put and sleep_ms
const uint LED_PIN = PICO_DEFAULT_LED_PIN;



TSAMPLER mySamplerData;
TSAMPLER* const mySampler = &mySamplerData;

void samplerExecute(void)
{
    switch(mySampler->state)
    {
        case ST_SAMP_WAIT:
        {
            if (mySampler->flags.trigger)
            {
                for (int i = 0; i < NUM_SCANNED_GPIOS; ++i)
                {
                    gpio_init(i);
                    gpio_set_dir(i,GPIO_IN);
                }
                mySampler->index = 0;
                gpio_set_dir(mySampler->index,GPIO_OUT);
                gpio_put(mySampler->index,1); //todo: add pull down
                mySampler->state = ST_SAMP_SCAN;
            }
            break;
        }
        case ST_SAMP_SCAN:
        {
            //sample the inputs here
            if (mySampler->index >= NUM_SCANNED_GPIOS)
            {
                //do something cool with the measurements
                mySampler->state = ST_SAMP_WAIT;
            }
            else
            {
                for (int i = 0; i < NUM_SCANNED_GPIOS; ++i)
                {
                    if (gpio_get(i))
                    {
                        mySampler->measurements[mySampler->index] |= (2^i); //setbit, todo: replace by 2d array
                    }
                    else
                    {
                        mySampler->measurements[mySampler->index] &= ~(2^i); //clearbit
                    }
                }
                gpio_set_dir(mySampler->index,GPIO_IN);
                mySampler->index++;
                gpio_set_dir(mySampler->index,GPIO_OUT);
                gpio_put(mySampler->index,1);
            }
            break;
        }
    }
    //gpio_put(LED_PIN, 1); //todo: segfaults on PC
    sleep_ms(100);
}
