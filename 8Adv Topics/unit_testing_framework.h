#ifndef UNIT_TEST_FRAMEWORK_H
#define UNIT_TEST_FRAMEWORK_H
 
#include <stdio.h>
#include <stdlib.h>
 
#define TEST_CASE(name) int name()
#define RUN_TEST(test) \
    do { \
        printf("Running " #test "... "); \
        if (test()) { \
            printf("PASSED\n"); \
        } else { \
            printf("FAILED\n"); \
            exit(1); \
        } \
    } while (0)
 
#define ASSERT_EQ(expected, actual) \
    do { \
        if ((expected) != (actual)) { \
            printf("Assertion failed: Expected %d, got %d\n", (expected), (actual)); \
            return 0; \
        } \
    } while (0)
 
#endif