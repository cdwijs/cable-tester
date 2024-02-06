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

    wait -> start [ label = "trigger" ];
    start -> scan [ label = "" ];
    scan -> wait  [ label = "done" ];
}
    \enddot
*/

#include <stdint.h> //for uint8_t

typedef enum
{
    ST_SAMP_WAIT = 0,

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
}TSAMPLER;

void samplerExecute(void);

#endif //SAMPLER_H
