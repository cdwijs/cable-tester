/**
 * Copyright (c) 2023 Cdwijs
 *
 * SPDX-License-Identifier: GPL2+/LGPL2+
 */

#include <stdio.h> //for serial communication via USB
#include <pico/stdlib.h>

#include "sampler.h"

int main() 
{
    stdio_init_all(); //for serial communication via USB
    printf("Hello Timer!\n");
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