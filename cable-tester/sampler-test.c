#include "sampler-test.h"
#include "../unity/unity.h"

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

    samplerExecute(); //to be able to set a breakpoint there
}
