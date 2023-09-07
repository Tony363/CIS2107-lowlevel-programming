#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
/*
Tony Siu

*/

int take_input(){
    char *invalid = "\t\tThis is not a valid input\n\t\tPlease run the program again";
    double input,frac_part,int_part;
    scanf("%lf",&input);
    frac_part = modf(input,&int_part);
    if (!(frac_part == 0.0)){
        printf("%s",invalid);
        exit(0);
    }
    if(input < 0){
        printf("%s",invalid);
        exit(0);
    } 
    return (int)input;
}

double discount(int quantity){
    if (quantity > 1 && quantity <= 49)
        return 0.0;
    else if (quantity > 50 && quantity < 99)
        return 0.1;
    else if (quantity > 100 && quantity < 149)
        return 0.15;
    else if (quantity >= 150)
        return 0.25;
    return 0.0;
}

void revenue(){
    float item_price,quanity,discount_percent;
    printf("\t\tEnter item price: ");
    item_price = take_input();
    printf("\t\tEnter quanity: ");
    quanity = take_input();
    printf("\n");
    printf("\t\tThe item price is: $%lf\n",item_price);
    printf("\t\tThe order is: %d\n items(s)",(int)quanity);
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