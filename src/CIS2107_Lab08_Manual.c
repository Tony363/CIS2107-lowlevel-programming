/*
 * Name:	XXX	XXXX 
 * Section:	XX 
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[],int len);
void endsWithed(char *string[],int len);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f\n", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered","WTF"}; // need sentinal value!!!!
    int len = sizeof(series)/sizeof(series[0]);
    startsWithB(series,len);

    //test for endsWithed
    endsWithed(series,len);

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {
    // printf("%s\n",strupr(temp));
    // printf("%s\n",strlwr(temp));
    for (int i = 0; s[i] != '\0'; i++) {
        printf("%c",toupper(s[i]));
    }
    puts("");
    for (int i = 0; s[i] != '\0'; i++) {
        printf("%c",tolower(s[i]));
    }
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    return (int)(atof(s1) + atof(s2) + atof(s3) + atof(s4));
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    return (float)(atof(s1) + atof(s2) + atof(s3) + atof(s4));
}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    int result = strcmp(s1,s2);
    char *s = (result == 0)? "Strings are equal": (result < 0)? "String 1 is less than String 2":"String 1 is greater than String 2";
    puts(s);
}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
    int result = strncmp(s1,s2,n);
    char *s = (result == 0)? "Strings are equal": (result < 0)? "String 1 is less than String 2":"String 1 is greater than String 2";
    puts(s);
}

//6.(Random Sentences) 
void randomize(void) {
    char *article[] = {"the", "a", "one", "some", "any"};
    char *noun[] = {"boy","girl","dog","town","car"};
    char *verb[] = {"drove","jumped","ran","walked","skipped"};
    char *preposition[] = {"to","from","over","under","on"};
    char f_article[10] = "",first_char;
    for (int i = 0;i < 20;i++) {
        strcpy(f_article,article[rand()%5]);
        f_article[0] = toupper(f_article[0]);
        printf("%s %s %s %s %s %s.\n",f_article,noun[rand()%5],verb[rand()%5],preposition[rand()%5],article[rand()%5],noun[rand()%5]);
    }
    puts("");
}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
    // int area_code = 0,exchange = 0,line = 0;
    // sscanf(num,"(%d) %d-%d",&area_code,&exchange,&line);
    // printf("%d%d%d\n",area_code,exchange,line);
    int tokens[3] = {0}, i = 0;
    char *temp = "";
    int token = atoi(strtok(num,"() -"));
    tokens[0] = token;
    while ((temp = strtok(NULL, "() -")) != NULL) {
        tokens[++i] = atoi(temp);
    }    
    char phone_number[12]= "";
    sprintf(phone_number,"%d %d%d",tokens[0],tokens[1],tokens[2]);
    puts(phone_number);
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    char* token;
    char* stack[5];
    int top = -1; // top of stack

    // Tokenize the string and push words onto the stack
    token = strtok(text, " ");
    while (token != NULL) {
        stack[++top] = token;
        token = strtok(NULL, " ");
    }

    // Pop words from the stack and print them
    printf("Reversed order of substrings: ");
    while (top >= 0) {
        printf("%s ", stack[top--]);
    }
    printf("\n");
}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
    int count = 0;
    const char *temp = line;
    while ((temp = strstr(temp, sub)) != NULL) {
        count++;
        temp += strlen(sub);  // Move past the found occurrence
    }
    return count;
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
    int count = 0;
    const char *temp = line;
    while ((temp = strchr(temp, c)) != NULL) {
        count++;
        temp++;
    }
    return count;
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    int counts[26] = {0};
    for (int i = 0; string[i] != '\0'; i++) {
        char ch = tolower(string[i]);
        if ('a' <= ch && ch <= 'z') {
            counts[ch - 'a']++;
        }
    }
    puts("Letter | Frequency");
    puts("-------+----------");

    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            printf("   %c   | %d\n", 'a' + i, counts[i]);
        }
    }
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
    int count = 0;
    char *token = strtok(string," \n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[],int len) {
    // char buf[20];
    // strcpy(buf,(char *)string);
    // int len = strlen((char *)string) - 1;
    // int len = sizeof(string)/sizeof(string[0]);
    // printf("%d\n",len);
    for (int i = 0; i < len; i++) {
        if (tolower(string[i][0]) == 'b') {
            puts(string[i]);
        }
    }
    puts("");
}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[],int len) {
    int stringlength = 0;
    // len = sizeof(string)/sizeof(string[0]);
    // printf("%d\n",len);

    for (int i = 0; i < len; i++) {
        stringlength = strlen(string[i]);
        if (tolower(string[i][stringlength-1]) == 'd' && tolower(string[i][stringlength - 2]) == 'e') {
            puts(string[i]);
        }
    }
    puts("");
}