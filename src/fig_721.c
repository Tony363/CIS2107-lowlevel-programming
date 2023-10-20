#include <stdio.h>
#define SIZE 10

void copy1(char * const s1, const char * const s2);
void copy2(char *s1,const char*s2);

int main(){
    char string1[SIZE];
    char *string2 = "Hello World!";

    copy1(string1,string2);
    printf("string1 = %s\n",string1);

    char string3[SIZE];
    char string4[] = "Goodbye";

    copy2(string3,string4);
    printf("string3 = %s\n",string3);
    return 0;
}

void copy1(char * const s1, const char * const s2){
    for(size_t i = 0;(s1[i] = s2[i]) != '\0';++i){
        printf("%c %c\n",s1[i],s2[i]);
    };
}

void copy2(char *s1,const char*s2){
    for (;(*s1++ = *s2++) != '\0';){};
}