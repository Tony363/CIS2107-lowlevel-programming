#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "includes/payrev.h"
/*
Tony Siu
9/7/2023
CIS 2107
Lab 2: Paycheck and revenue
*/


void revenue(){
    float item_price,quanity,discount_percent;
    printf("\t\tEnter item price: ");
    item_price = take_input("item price");
    printf("\t\tEnter quanity: ");
    quanity = take_input("quantity order");
    printf("\n");
    printf("\t\tThe item price is: $%lf\n",item_price);
    printf("\t\tThe order is: %d items(s)\n",(int)quanity);
    printf("\t\tThe cost is: $%lf\n",item_price*quanity);
    discount_percent = discount(quanity);
    printf("\t\tThe discount is: %lf%%\n",discount_percent*100);
    printf("\t\tThe total is: %lf\n",(item_price*quanity)-(discount_percent*item_price*quanity));
}

int main(){
    printf("Welcome to \"TEMPLE\" store\n\n");
    revenue();
    printf("\nThank you for using \"TEMPLE\" store\n\n");
    return 0;
}