#include "unit_test_framework.h"
 
TEST_CASE(test_addition) {
    int result = 2 + 3;
    ASSERT_EQ(5, result);
    return 1;
}
 
TEST_CASE(test_subtraction) {
    int result = 10 - 4;
    ASSERT_EQ(6, result);
    return 1;
}
 
TEST_CASE(test_multiplication) {
    int result = 3 * 3;
    ASSERT_EQ(9, result);
    return 1;
}
 
int main() {
    RUN_TEST(test_addition);
    RUN_TEST(test_subtraction);
    RUN_TEST(test_multiplication);
    printf("All tests passed.\n");
    return 0;
}