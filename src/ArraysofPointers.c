/* 
Name: Tony Siu
Date: 10/6/2021
Course: CSI2107 
HW#: Lab 05: ““Arrays of Pointers to Functions” 

Objective: To design and implement array of function pointer. 

The purpose of this program is to modify existing code related to exam selecting 
grades for individual students in a 2D matrix and determining the minimum, maximum, and each average. 

// Each of the functions has also been modified to allow for a
// menu-driven interface. This interface is an array of pointers to the functions.

*/

#include <stdio.h>
#include <stdlib.h>

int student, exams = 0;
typedef void (*menu_choice)(int,int,int**);

void printArray(int students, int exams, int**grades);
void minimum(int students, int exams, int**grades);
void maximum(int students, int exams, int**grades);
void average(int students, int exams, int **grades);
void menu(void);
void deallocate_array(int **arr, int row);

int** get_array(int row,int col);

int main()
{
    puts("Let's enter student grades\n");
    printf("%s","\tHow many students? ");
    scanf("%d",&student);
    printf("%s","\tHow many exams? ");
    scanf("%d",&exams);
    int** studentGrades = get_array(student,exams);
    puts("");
    // void (*processGrades[4])(int, int, int**) = {printArray,minimum,maximum,average};
    // void *(*processGrades)(int, int, int**) = NULL;
    // processGrades = (void *(*)(int, int, int**))malloc(4 * sizeof(void *));
    menu_choice processGrades[4] = {printArray,minimum,maximum,average};
    size_t choice = 0;
    menu();
    while(scanf("%lu",&choice) == 1 && choice != 4){
        if (choice < 0 || choice > 4){
            puts("Invalid entry\n");
            menu();
            continue;
        }
        // (*(processGrades + choice))(student,exams,studentGrades);
        processGrades[choice](student,exams,studentGrades);
        menu();
    }
    puts("exiting program...");
    deallocate_array(studentGrades,student);
    // free(processGrades);
    return 0;
}

void printArray(int students, int exams, int**grades){ //int grades[students][exams]
    printf("\t\t ");    
    for (size_t i = 0; i < students; i++)
        printf("[%lu] ",i);
    puts("");

    for (size_t i = 0; i < student; i++){
        printf("studentGrades[%lu]",i);
        for (size_t j = 0; j < exams; j++){
            printf("  %2d",grades[i][j]);
        }
        puts("");
    }
    puts("");
}
void minimum(int students, int exams, int **grades){
    int lowGrade = 100;
    for (size_t i = 0; i < students; i++){
        for (size_t j = 0; j < exams; j++){
            if(grades[i][j] < lowGrade)
                lowGrade = grades[i][j];
        }
    }
    printf("Lowest grade: %d\n\n",lowGrade);
}
void maximum(int students, int exams, int **grades){
    int highGrade = 0;
    for (size_t i = 0; i < students; i++){
        for (size_t j = 0; j < exams; j++){
            if(grades[i][j] > highGrade)
                highGrade = grades[i][j];
        }
    }
    printf("Highest grade: %d\n\n",highGrade);
}
void average(int students, int exams, int **grades){
    double total = 0;
    for (size_t i = 0; i < students; i++){
        for (size_t j = 0; j < exams; j++){
            total += (double)grades[i][j];
        }
        printf("The average grade for student %lu is %.2lf\n",i,total/exams);
        total = 0;
    }
    puts("");
}

void menu(void){
    puts("Enter a choice:");
    puts("\t0\tPrint the array of grades");
    puts("\t1\tFind the minimum grade");
    puts("\t2\tFind the maximum grade");
    puts("\t3\tPrint the average on all tests for each student");
    puts("\t4\tEnd Program");
}

int** get_array(int row,int col){
    int input = 0;
    int **array = (int **)malloc(row * sizeof(int *));

    for (size_t i = 0; i < row; i++){
        array[i] = (int *)malloc(col * sizeof(int));
        for (size_t j = 0; j < col; j++){
            printf("\tEnter Student [%lu] Exam [%lu] ",i,j);
            scanf("%d",&input);
            array[i][j] = input;
        }
    }
    return array;
}

void deallocate_array(int **arr, int row){
    for (size_t i = 0; i < row; i++){
        free(arr[i]);
    }
    free(arr);
}