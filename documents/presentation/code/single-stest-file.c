#include "../../testbench/unity/unity.h"
#define UNITTEST_ON_PC

//fake-everything.h
void functionsFromALotOfIncludedFiles(void);
void evenMoreFunctionsFromALotOfIncludedFiles(void);

//fake-everything.c
void functionsFromALotOfIncludedFiles(void) {}
void evenMoreFunctionsFromALotOfIncludedFiles(void) {}

#ifdef UNITTEST_ON_PC
    #include "fake-everything.h"
#else
    #include "many-many-include-files.h"
#endif

void notInterestingFunction(void)
{
    functionsFromALotOfIncludedFiles();
    evenMoreFunctionsFromALotOfIncludedFiles();
}

int functionWeWantToTest()
{
    int result = 5; //result of interesting calculations
    return result;
}

//test.c
void test(void)
{
    TEST_ASSERT_EQUAL_INT(5,functionWeWantToTest());
}
