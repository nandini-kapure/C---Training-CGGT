// 3. Program to Find (a) size of each primitive data type and (b) range of each primitive type   
#include<stdio.h>
#include<limits.h>
#include<float.h>
#include<stdbool.h>

int main()
{
    printf("\nSize of int %d ", sizeof(int));
    printf("\nSize of char %d ", sizeof(char));
    printf("\nSize of bool %d ", sizeof(bool));
    printf("\nSize of float %d ", sizeof(float));
    printf("\nSize of double %d ", sizeof(double));
    printf("\nSize of pointer %d ", sizeof(int*));
    printf("\nRange of int is %d to %d ", INT_MIN, INT_MAX);
    printf("\nRange of char is %d to %d ", CHAR_MIN, CHAR_MAX);
    printf("\nRange of bool is 0 and 1 ");
    printf("\nRange of float is %e to %e ", FLT_MIN, FLT_MAX);
    printf("\nRange of double is %e to %e ", DBL_MIN, DBL_MAX);


    return 0;
}