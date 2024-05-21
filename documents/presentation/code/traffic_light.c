#include <stdint.h>
#include "../unity/unity.h"

/** \page main
    Traffic Light state machine \n
    \dot
digraph
{
    ST_GREEN [label = "green"];
    ST_ORANGE [label = "orange"];
    ST_RED [label = "red"];

    ST_GREEN -> ST_ORANGE [label = " 1 minute"];

    ST_ORANGE -> ST_RED [label = " 10 seconds"];

    ST_RED -> ST_GREEN [label = " 50 seconds"];
}
    \enddot
*/

typedef enum
{
    ST_GREEN = 0,
    ST_ORANGE,
    ST_RED,
}TLIGHTSTATE;

typedef struct
{
    TLIGHTSTATE state;
    uint8_t     timer;
}TLIGHT;

TLIGHT myLightData;
TLIGHT* const myLight = &myLightData;

#define TIME_ORANGE 10
#define TIME_RED 10
#define TIME_GREEN 10

void LightExecute (void)
{
    switch (myLight->state)
    {
        case ST_GREEN:
        {
            if (myLight->timer == 0)
            {
                myLight->timer = TIME_ORANGE;
                myLight->state = ST_ORANGE;
            }
            break;
        }
        case ST_ORANGE:
        {
            if (myLight->timer == 0)
            {
                myLight->timer = TIME_RED;
                myLight->state = ST_RED;
            }
            break;
        }
        case ST_RED:
        {
            if (myLight->timer == 0)
            {
                myLight->timer = TIME_GREEN;
                myLight->state = ST_GREEN;
            }
            break;
        }
    }
    if (myLight->timer)
    {
        myLight->timer--;
    }
}

void LightTest(void)
{
    myLight->state = ST_GREEN;
    myLight->timer = 1;
    LightExecute();
    TEST_ASSERT_EQUAL_INT(ST_GREEN,myLight->state); //first the non transition
    TEST_ASSERT_EQUAL_INT(1,myLight->timer); //timer has not been set

    myLight->state = ST_GREEN;
    myLight->timer = 0;
    LightExecute();
    TEST_ASSERT_EQUAL_INT(ST_ORANGE,myLight->state); //transition
    TEST_ASSERT_EQUAL_INT(TIME_ORANGE,myLight->timer);

    //repeat for orange and red states
}
