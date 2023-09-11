#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int take_input(char* item,char* interface){
    double input,frac_part,int_part;
    scanf("%lf",&input);
    frac_part = modf(input,&int_part);
    if (!(frac_part == 0.0) ^ input < 0 || (!(frac_part == 0.0) && input < 0)){ // if the input is not an integer
        printf("\t\tThis is not a valid %s\n\t\tPlease run the program again\n",item);
        printf("\nThank you for using %s \n\n",interface);
        exit(0);
    }
    return (int)input;
}

// get discount for a given quantity
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