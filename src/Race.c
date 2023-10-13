//CIS2017 Lab7: Race
//The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
//generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
//controlled using the sleep() function. Sometimes it takes a while due to slippage.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define INT_MIN 1
#define INT_MAX 10

int randomNumberGenerator();
void tortMove(int *tPtr,int move);
void hareMove(int *hPtr,int move);
void printRace(int hPos,int tPos,char* track);
int min(int Pos, int incre);

int main(){
    srand((unsigned)time(NULL));

    int hPos = 1;						//hare start position is 1, cannot slip past 1
    int tPos = 1;						//tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	//the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	//the spacing is modeled after the sample

    char *track = (char *)malloc(70 * sizeof(char));
    memset(track,' ',70);
    track[69] = '\0';

    int move = randomNumberGenerator();
    while(hPos != 70 && tPos != 70){
        // sleep(1);						//slows down the race
        hareMove(&hPos,move);
        tortMove(&tPos,move);
        printRace(hPos,tPos,track);
        puts("");
        move = randomNumberGenerator();
    }
    if (hPos == tPos == 70)
        puts("\tRace Draw");
    else if (hPos == 70)
        puts("\tHare wins. Yuch.");
    else if (tPos == 70)
        puts("\tTORTOISE WINS!!! YAY!!!");
}

// out of bounds handler
int min(int Pos,int incre){
    return ((Pos + incre) > 70) ? 70 - Pos : incre;    
}

//Prints the position of the H and T
void printRace(int hPos,int tPos,char* track){
    if (hPos == tPos){
        puts("\tOUCH!");
        return;
    }
    track[hPos-1] = 'H';
    track[tPos-1] = 'T';
    printf("\t%s\n",track);
    track[hPos-1] = ' ';
    track[tPos-1] = ' ';
}

//Controls the tortoise movement
void tortMove(int *tPtr,int move){
    if (1 <= move && move <= 5)
        *tPtr += min(*tPtr,3);
    else if (6 <= move && move <= 7)
        *tPtr -= min(*tPtr,6);
    else
        *tPtr += min(*tPtr,1);
}

//Controls the hare movement
void hareMove(int *hPtr,int move){
    if (1 <= move && move <= 2)
        *hPtr += min(*hPtr,0);
    if (3 <= move && move <=4)
        *hPtr += min(*hPtr,9);
    else if (5 == move)
        *hPtr -= min(*hPtr,12);
    else if (6 <= move && move <= 8)
        *hPtr += min(*hPtr,1);
    else
        *hPtr += min(*hPtr,2);
}

//Generates random number from 1-10
int randomNumberGenerator(void){
    return (rand() % INT_MAX) + INT_MIN;
}
