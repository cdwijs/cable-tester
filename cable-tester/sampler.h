#ifndef SAMPLER_H
#define SAMPLER_H

/** \page main
    Sampler \n
    \dot
digraph
{
    node [shape=record, color=red];
    edge [arrowhead=open,color=green];

    rankdir="TD"

    ST_SAMP_WAIT -> ST_SAMP_SCAN [ label = "trigger" ];
    ST_SAMP_SCAN -> ST_SAMP_WAIT  [ label = "done" ];
}
    \enddot
*/

#include <stdint.h> //for uint8_t
#include <pico/stdlib.h> //pulls in gpio.h for NUM_SCANNED_GPIOS

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

typedef struct
{
    TSAMPLERSTATE           state;
    TSAMPLERFLAGS           flags;
    uint8_t                 index;
    uint32_t                measurements[NUM_SCANNED_GPIOS];
}TSAMPLER;

void samplerExecute(void);
void setbit (uint8_t x,uint8_t y,uint8_t value);
uint8_t getbit (uint8_t x,uint8_t y);

#endif //SAMPLER_H
