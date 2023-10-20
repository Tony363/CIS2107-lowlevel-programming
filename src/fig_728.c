#include <stdio.h>
#include <stdlib.h>

void func1(int a);
void func2(int b);
void func3(int c);


int main(){
    void (**f)(int) = malloc(3 * sizeof(void*));
    f[0] = func1;
    f[1] = func2;
    f[2] = func3;
    puts("Enter a number between 0 and 2, 3 to the end: ");
    int choice = 0;
    while (scanf("%d",&choice) == 1 && choice >= 0 && choice < 3){
        f[choice](choice);
        puts("Enter a number between 0 and 2, 3 to the end: ");
    }
    free(f);
    puts("Program execution completed.");
    return 0;
}

void func2(int b){
    printf("You entered %d so function 2 was called\n\n",b);
}

void func1(int a){
    printf("You entered %d so function 1 was called\n\n",a);
}

void func3(int c){
    printf("You entered %d so function 3 was called\n\n",c);
}