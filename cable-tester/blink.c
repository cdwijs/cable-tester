/**
 * Copyright (c) 2023 Cdwijs
 *
 * SPDX-License-Identifier: GPL2+/LGPL2+
 */

//#include "pico/stdlib.h"
#include <pico/stdlib.h>

#include "sampler.h"

int main() 
{
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) 
    {
        samplerExecute();
        gpio_put(LED_PIN, 0);
        sleep_ms(400);
    }
}
