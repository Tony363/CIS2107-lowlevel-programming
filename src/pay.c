#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
/*
Tony Siu
9/7/2023
CIS 2107
Lab 2: Paycheck and revenue
*/

int take_input(char* item){
    double input,frac_part,int_part;
    scanf("%lf",&input);
    frac_part = modf(input,&int_part);
    if (!(frac_part == 0.0)){
        printf("\t\tThis is not a valid %s\n\t\tPlease run the program again",item);
        exit(0);
    }
    if(input < 0){
        printf("\t\tThis is not a valid %s\n\t\tPlease run the program again",item);
        exit(0);
    } 
    return (int)input;
}



void pay(){
    int employee_num,hour_salary,weekly_time;
    float overtime_pay, regular_pay = 0;
    printf("\t\tEnter Employee Number: ");
    employee_num = take_input("Employee Number");
    printf("\t\tEnter Hourly Salary:");
    hour_salary = take_input("hourly salary amount");
    printf("\t\tEnter Weekly Time: ");
    weekly_time = take_input("weekly time worked");
    printf("\t\t========================\n");
    printf("\t\tEmployee Number #: %d\n",employee_num);
    printf("\t\tHourly Salary: $%lf\n",(double)hour_salary);
    printf("\t\tWeekly Time: %d\n",weekly_time);
    if (weekly_time > 40){
        regular_pay = (double)(hour_salary*40);
        overtime_pay = (double)(hour_salary*(weekly_time - 40)*1.5);
    } else{
        regular_pay = (double)(hour_salary*weekly_time);
    }
    printf("\t\tRegular Pay: $%lf\n",regular_pay);
    printf("\t\tOvertime Pay: $%lf\n",overtime_pay);
    printf("\t\tNet Pay: $%lf\n",overtime_pay + regular_pay);
    printf("\t\t========================");

    return;
}

int main(){
    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n\n");
    pay();
    printf("\n\nThank you for using \"TEMPLE HUMAN RESOURCES\")");
    return 0;
}