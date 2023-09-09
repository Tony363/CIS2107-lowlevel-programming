#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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