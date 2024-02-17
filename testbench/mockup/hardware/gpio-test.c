#include "gpio-test.h"
#include "../unity/unity.h"
#include "gpio.h"

extern uint32_t theFakeCable[NUM_SCANNED_GPIOS];
extern uint32_t gpio_dirout_reg;
extern uint32_t gpio_output_reg;
extern uint32_t gpio_pullup_reg;
extern uint32_t gpio_pulldown_reg;

void gpioTest(void)
{
    uint8_t result = 0;
    result = gpio_get(0);

//basic situation, no cable
    for (int i = 0; i < NUM_SCANNED_GPIOS; ++i)
    {
        theFakeCable[i] = 0;
    }
//only input, pull down
    gpio_dirout_reg = 0;
    gpio_output_reg = 0;
    gpio_pullup_reg = 0;
    gpio_pulldown_reg = 0xffff;
    TEST_ASSERT_EQUAL_INT(0,gpio_get(0));
//only input, pull up:
    gpio_dirout_reg = 0;
    gpio_output_reg = 0;
    gpio_pullup_reg = 0xffff;
    gpio_pulldown_reg = 0;
    TEST_ASSERT_EQUAL_INT(1,gpio_get(0));
//output 0, pull up down does not matter:
    gpio_dirout_reg = 0xffff;
    gpio_output_reg = 0;
    gpio_pullup_reg = 0;
    gpio_pulldown_reg = 0;
    TEST_ASSERT_EQUAL_INT(0,gpio_get(0));
    gpio_dirout_reg = 0xffff;
    gpio_output_reg = 0;
    gpio_pullup_reg = 0xffff;
    gpio_pulldown_reg = 0;
    TEST_ASSERT_EQUAL_INT(0,gpio_get(0));
    gpio_dirout_reg = 0xffff;
    gpio_output_reg = 0x0;
    gpio_pullup_reg = 0;
    gpio_pulldown_reg = 0xffff;
    TEST_ASSERT_EQUAL_INT(0,gpio_get(0));
//output 1, pull up down does not matter:
    gpio_dirout_reg = 0xffff;
    gpio_output_reg = 0xffff;
    gpio_pullup_reg = 0;
    gpio_pulldown_reg = 0;
    TEST_ASSERT_EQUAL_INT(1,gpio_get(0));
    gpio_dirout_reg = 0xffff;
    gpio_output_reg = 0xffff;
    gpio_pullup_reg = 0xffff;
    gpio_pulldown_reg = 0;
    TEST_ASSERT_EQUAL_INT(1,gpio_get(0));
    gpio_dirout_reg = 0xffff;
    gpio_output_reg = 0xffff;
    gpio_pullup_reg = 0;
    gpio_pulldown_reg = 0xffff;
    TEST_ASSERT_EQUAL_INT(1,gpio_get(0));
//output is connected via a virtual cable
    //pin 0 connects to pin 4
    theFakeCable[0] = (1 << 4);
    gpio_dirout_reg = 0x0001; //assert pin 0
    gpio_output_reg = 0x0001; //assert pin 0
    gpio_pullup_reg = 0;
    gpio_pulldown_reg = 0xffff;
    for (int i = 0; i < NUM_SCANNED_GPIOS; ++i)
    {
        if (i == 0 || i == 4)
        {
            TEST_ASSERT_EQUAL_INT(1,gpio_get(i)); // i=0 from the output, i=4 from the virtual cable
        }
        else
        {
            TEST_ASSERT_EQUAL_INT(0,gpio_get(i));
        }
    }
//output is connected via a virtual cable
    for (int i = 0; i < NUM_SCANNED_GPIOS; ++i)
    {
        theFakeCable[i] = 1 << i;
    }
    //pin 3 connects to pin 4
    theFakeCable[3] |= (1 << 4);
    gpio_dirout_reg = 1 << 3;
    gpio_output_reg = 1 << 3;
    gpio_pullup_reg = 0;
    gpio_pulldown_reg = 0xffff;
    for (int i = 0; i < NUM_SCANNED_GPIOS; ++i)
    {
        if (i == 3 || i == 4)
        {
            TEST_ASSERT_EQUAL_INT(1,gpio_get(i)); // i=3 from the output, i=4 from the virtual cable
        }
        else
        {
            TEST_ASSERT_EQUAL_INT(0,gpio_get(i));
        }
    }
}
