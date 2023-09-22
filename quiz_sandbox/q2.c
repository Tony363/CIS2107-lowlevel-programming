#include <stdio.h>
/*
Write a C program to find the sum of odd 
and even numbers from 1 to N. 

Below are two possible demos.
*/

int sum_odd(int max_num);
int sum_even(int max_num);
void to_date(int num);

int main(){
    int max_num;
    puts("Enter a number: ");
    scanf("%d",&max_num);
    printf("%d\n",max_num);
    printf("sum of all odd numbers: %d\n",sum_odd(max_num));
    printf("sum of all even numbers: %d\n",sum_even(max_num));
    to_date(375);
    return 0;
}

int sum_odd(int max_num){
    int sum = 0;
    for (unsigned int i = 1; i <= max_num; i++){
        if (i % 2)
            sum += i;
    }
    return sum;
}

int sum_even(int max_num){
    int sum = 0;
    for (unsigned int i = 1; i <= max_num; i++){
        if (!(i % 2))
            sum += i;
    }
    return sum;
}

void to_date(int num){
    int year,week,day;
    year = num / 365;
    week = (num - (year * 365)) / 7;
    day = num - (year * 365) - (week * 7);
    printf("%d/%d/%d",year,week,day);   
}