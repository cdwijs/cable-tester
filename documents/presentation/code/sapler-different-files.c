#include <stdint.h> //for uint8_t
#include <pico/stdlib.h> //pulls in gpio.h for NUM_SCANNED_GPIOS
#include "../../testbench/unity/unity.h"

//sampler.h holds the definition of TSAMPLER
typedef struct
{ //omitted to fit on this slide
    uint32_t                measurements[NUM_SCANNED_GPIOS];
}TSAMPLER;
void setbit (uint8_t x,uint8_t y,uint8_t value); //and the setbit prototype

//sampler.c holds the acual data and a pointer to the data:
TSAMPLER mySamplerData;
TSAMPLER* const mySampler = &mySamplerData;
void setbit (uint8_t x,uint8_t y,uint8_t value) //and the setbit function
{ //omitted to fit on this slide

}

//sampler-test.h holds a second reference to the data and pointer
extern TSAMPLER mySamplerData;
extern TSAMPLER* const mySampler;
void test (void); //and the prototype to the test function

//sampler-test.c holds the test function:
void test (void)
{ //omitted to fit on this slide
    TEST_ASSERT_EQUAL_INT(1,mySampler->measurements[1]);
}
