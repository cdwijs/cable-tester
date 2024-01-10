#include <pico/stdlib.h> //for gpio_put and sleep_ms
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void samplerExecute(void)
{
    gpio_put(LED_PIN, 1);
    sleep_ms(100);
}