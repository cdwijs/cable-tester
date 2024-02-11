#include "sampler-test.h"
#include "../unity/unity.h"
#include "utils.h" //for FALSE and TRUE
#include "../mockup/hardware/gpio.h" //for gpio regs

//uint32_t samplerSimulatePins(void);

void samplerTest(void)
{
    for (int y = 0; y < NUM_SCANNED_GPIOS; ++y)
    {
        mySampler->measurements[y] = 0;
        setbit(0,y,1);
        TEST_ASSERT_EQUAL_INT(1,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(1,y,1);
        TEST_ASSERT_EQUAL_INT(2,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(2,y,1);
        TEST_ASSERT_EQUAL_INT(4,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(3,y,1);
        TEST_ASSERT_EQUAL_INT(8,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(4,y,1);
        TEST_ASSERT_EQUAL_INT(0x10,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(5,y,1);
        TEST_ASSERT_EQUAL_INT(0x20,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(6,y,1);
        TEST_ASSERT_EQUAL_INT(0x40,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(7,y,1);
        TEST_ASSERT_EQUAL_INT(0x80,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(8,y,1);
        TEST_ASSERT_EQUAL_INT(0x0100,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(9,y,1);
        TEST_ASSERT_EQUAL_INT(0x0200,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(10,y,1);
        TEST_ASSERT_EQUAL_INT(0x0400,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(11,y,1);
        TEST_ASSERT_EQUAL_INT(0x0800,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(12,y,1);
        TEST_ASSERT_EQUAL_INT(0x1000,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(13,y,1);
        TEST_ASSERT_EQUAL_INT(0x2000,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(14,y,1);
        TEST_ASSERT_EQUAL_INT(0x4000,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(15,y,1);
        TEST_ASSERT_EQUAL_INT(0x8000,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(16,y,1);
        TEST_ASSERT_EQUAL_INT(0x10000,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(17,y,1);
        TEST_ASSERT_EQUAL_INT(0x20000,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(18,y,1);
        TEST_ASSERT_EQUAL_INT(0x40000,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(19,y,1);
        TEST_ASSERT_EQUAL_INT(0x80000,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(20,y,1);
        TEST_ASSERT_EQUAL_INT(0x100000,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(21,y,1);
        TEST_ASSERT_EQUAL_INT(0x200000,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
        setbit(22,y,1);
        TEST_ASSERT_EQUAL_INT(0x400000,mySampler->measurements[y]);
        mySampler->measurements[y] = 0;
    }
    for (int y = 0; y < NUM_SCANNED_GPIOS; ++y)
    {
        mySampler->measurements[y] = 0;
        for (int x = 0; x < NUM_SCANNED_GPIOS+10; ++x)
        {
            setbit(x,y,1);
        }
        TEST_ASSERT_EQUAL_INT(0x7FFFFF,mySampler->measurements[y]);
    }
    for (int y = 0; y < NUM_SCANNED_GPIOS+10; ++y)
    {
        for (int x = 0; x < NUM_SCANNED_GPIOS+10; ++x)
        {
            setbit(x,y,0);
        }
    }
    for (int y = 0; y < NUM_SCANNED_GPIOS; ++y)
    {
        TEST_ASSERT_EQUAL_INT(0,mySampler->measurements[y]);
    }

    mySampler->measurements[0] = 0;
    for (int x = 0; x < 255; ++x)
    {
        setbit(x,0,1);
    }
    TEST_ASSERT_EQUAL_INT(0x7FFFFF,mySampler->measurements[0]);

//now test the getter as well

    for (int y = 0; y < NUM_SCANNED_GPIOS; ++y)
    {
        for (int x = 0; x < NUM_SCANNED_GPIOS; ++x)
        {
            mySampler->measurements[y] = 0;
            uint8_t stimulus = 1;
            uint8_t result = 0;
            setbit(x,y,stimulus);
            result = getbit(x,y);
            TEST_ASSERT_EQUAL_INT(stimulus,result);
            stimulus = 0;
            setbit(x,y,stimulus);
            result = getbit(x,y);
            TEST_ASSERT_EQUAL_INT(stimulus,result);
        }
    }

    for (int i = 0; i < NUM_SCANNED_GPIOS; ++i)
    {
        theFakeCable[i] = 0;
    }
    for (int i = 0; i < NUM_SCANNED_GPIOS; ++i)
    {
        theFakeCable[i] = 1 << i;
    }

    theFakeCable[0] = 1 << 5;
    theFakeCable[1] = 1 << 2;
    theFakeCable[2] = 1 << 9;
    theFakeCable[3] = 1 << 12;
    theFakeCable[4] = 1 << 7;
    theFakeCable[5] = 1 << 1;
    theFakeCable[6] = 1 << 3;
    theFakeCable[7] = 1 << 4;
    theFakeCable[8] = 1 << 10;

    mySampler->flags.trigger = TRUE;
    for (int cyle = 0; cyle < NUM_SCANNED_GPIOS*2; ++cyle)
    {
        samplerExecute();
    }
    //now it should be ready for the next scan cycle
    //now fakecable should be the same as the measured cable
}

/*
uint32_t samplerSimulatePins(void)
{
    uint32_t result = 0;
    for (int x = 0; x < NUM_SCANNED_GPIOS; ++x)
    {
        if(gpio_dirout_reg & (1 << x))
        { //direct output, pullup/downs don't matter
            if ( gpio_output_reg & (1 << x))
            {
                result |= (1 << x);
            }
            else
            {
                result &= ~(1 << x);
            }
        }
        else
        { //input, first apply the pull up/down
            if ( gpio_pullup_reg & (1 << x))
            {
                result |= (1 << x);
            }
            if ( gpio_pulldown_reg & (1 << x))
            {
                result &= ~(1 << x);
            }

            //now apply the virtual cable here
            if ()
                }

    }
    return result;
}*/
