// C program to find diameter, circumference and area of a circle using functions

#include <stdio.h>
#include <ctype.h>

#define PI 3.1415

// Your Function prototypes should be listed first*/
float diameter(float radius);
float circumference(float radius);
float area(float radius);
int isVowel(char c);
int isIsoceles(int s1,int s2,int s3);
int sumRange(int a,int b);

int main() {
    float radius, dia, circ, ar;
    /* Reads radius of the circle from user */

    printf("Enter radius of the circle: ");
    scanf("%f", &radius);

    dia = diameter(radius);                //Call diameter function
    circ = circumference(radius);               //Call circumference function
    ar = area(radius);                        //Call area function

    printf("Diameter of the circle = %.2f units\n", dia);
    printf("Circumference of the circle = %.2f units\n", circ);
    printf("Area of the circle = %.2f sq. units\n", ar);
    printf("SUM RANGE %d\n",sumRange(0,10));
    printf("IS VOWEL %d %d %d\n",isVowel('a'),isVowel('A'),isVowel('+'));
    printf("IS ISOCELES %d %d %d %d\n",isIsoceles(1,2,3),isIsoceles(1,1,3),isIsoceles(1,2,2),isIsoceles(1,1,1));
    return 0;
}

// Your Function implementations should be listed last*/
float diameter(float radius){
    return 2 * radius;
}
// diameter function: Find the diameter of a circle whose radius is given. Remember diameter = 2 * Radius
float circumference(float radius){
    return 2 * PI * radius;
}
// circumference function: Find circumference of the circle whose radius is given. Remember circumference = 2 * PI * Radius

float area(float radius){
    return PI * radius * radius;
}
// area function: Find area of the circle whose radius is given. Remember Area = PI * Radius2

int isIsoceles(int s1,int s2,int s3){
    if (s1 == s3 == s3)
        return 0;
    return (s1 == s2) ^ (s1 == s3) ^ (s2 == s3);
}


int isVowel(char c){
    return isalpha(c);
}

int sumRange(int a,int b){
    if (b < a){
        puts("error message");
        return -1;
    }
    int sum = 0;
    for (; a <= b; a++){
        sum += a;
    }
    return sum;  
}