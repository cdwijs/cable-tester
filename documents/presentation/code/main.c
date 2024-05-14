#define TRUE 1
int main (void);

#define UNITTEST_ON_PC

#ifdef UNITTEST_ON_PC
int microcontrollermain (void)
{
    if (TRUE)
#else
int main (void)
{
    while (TRUE)
#endif
    {
        //omitted to fit on this slide
    }
}

#define NUM_CYCLES 10000
void test (void)
{
    for (int cycle = 0; cycle < NUM_CYCLES; ++cycle)
    {
        //force inputs and program state
        microcontrollermain();
        //check effects of the program
    }
}
