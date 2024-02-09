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

#define  NUM_SCANNED_GPIOS 23

typedef enum
{
    ST_SAMP_WAIT = 0,
    ST_SAMP_SCAN,
}TSAMPLERSTATE;


typedef struct
{
    uint8_t trigger: 1;
}TSAMPLERFLAGS;

typedef struct
{
    TSAMPLERSTATE           state;
    TSAMPLERFLAGS           flags;
    uint8_t                 index;
    uint32_t                measurements[NUM_SCANNED_GPIOS]; //todo: replace by 2d array
}TSAMPLER;

void samplerExecute(void);

#endif //SAMPLER_H
