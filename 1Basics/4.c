//  4. Program to calculate total elapsed time by the program and a function used in the program (i.e., the time taken to process the set of statements within a function/program) and print source code along with the total elapsed time. 
#include <stdio.h>
#include <time.h>
#include <math.h>

int main() {
    float y;
    clock_t time_req;

    time_req = clock();
    for (int i = 0; i < 100000; i++) {
        y = log(pow(i, 5));
    }
    time_req = clock() - time_req;
    printf("Using pow function, it took %f seconds\n", (float)time_req / CLOCKS_PER_SEC);

    time_req = clock();
    for (int i = 0; i < 100000; i++) {
        y = log(i * i * i * i * i);
    }
    time_req = clock() - time_req;
    printf("Without using pow function, it took %f seconds\n", (float)time_req / CLOCKS_PER_SEC);

    return 0;
}
