#include <stdio.h>

int main(void) {
    int age = 5, tom = 0, jerry = 0;
    int* aPtr = &age;
    tom = (*aPtr)++;              // post associativity  is left to right 
    printf("\n%d", age);          // by the way post is higher than pre
    printf("\n%d", tom);

    age = 55;
    jerry = ++(*aPtr);            // pre associativity  is right to left
    printf("\n%d", age);
    printf("\n%d", jerry);
    return 0;
}