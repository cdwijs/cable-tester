#include <stdint.h> //for uint8_t
#include <pico/stdlib.h> //pulls in gpio.h for NUM_SCANNED_GPIOS
#include "../../testbench/unity/unity.h"
typedef enum
{
    ST_SAMP_WAIT = 0,
    ST_SAMP_SCAN,
}TSAMPLERSTATE;

typedef struct
{
    uint8_t trigger: 1;
    uint8_t storereference: 1;
}TSAMPLERFLAGS;
void test (void);
void setbit (uint8_t x,uint8_t y,uint8_t value);

//sampler.h for the definition of TSAMPLER
typedef struct
{
    TSAMPLERSTATE           state;
    TSAMPLERFLAGS           flags;
    uint8_t                 index;
    uint32_t                measurements[NUM_SCANNED_GPIOS];
}TSAMPLER;
//sampler.c holds the acual data and a pointer to the data:
TSAMPLER mySamplerData;
TSAMPLER* const mySampler = &mySamplerData;
//sampler-test.h holds a second reference to the data and the pointer
extern TSAMPLER mySamplerData;
extern TSAMPLER* const mySampler;

//the function being tested (in sampler.c)
void setbit (uint8_t x,uint8_t y,uint8_t value)
{
    if (x >= NUM_SCANNED_GPIOS || y >= NUM_SCANNED_GPIOS)
    {
        return;
    }
    if (value)
    {
        mySampler->measurements[y] |= (1 << x);
    }
    else
    {
        mySampler->measurements[y] &= ~(1 << x);
    }
}

//testfunction (in sampler-test.c)
void test (void)
{
    int y = 0;
    mySampler->measurements[y] = 0;
    setbit(0,y,1);
    TEST_ASSERT_EQUAL_INT(1,mySampler->measurements[y]);
}
