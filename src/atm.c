#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Tony Siu
9/14/2023
CIS 2107
Lab 3: ATM
*/

typedef unsigned int (*validate)(double,unsigned int);

unsigned int validate_pin(double frac_part,unsigned int input){
    return (input == 3014);
}

unsigned int validate_menu(double frac_part,unsigned int input){
    return (frac_part == 0 && input > 0 && input < 5);
}

unsigned int validate_withrawal(double frac_part,unsigned int input){
    unsigned int check =(frac_part == 0 && input > 0 && input <= 1000 && input % 20 == 0);
    if (!check)
        printf("%s","\tWithdrawal amount must be in 20 dollar bill\n\tTotal amount must not exceed 1000\n");
    return check;
};

unsigned int validate_deposit(double frac_part,unsigned int input){
    unsigned int check = (frac_part == 0 && input > 0 && input < 10000);
    if (!check)
        printf("%s","\tDeposit amount must not exceed 10000\n");
    return check;
}

unsigned int validate_receipt(double frac_part,unsigned int input){
    return (frac_part == 0 && (input == 2 || input == 1));
}

void quit(unsigned int trans_num){
    printf("Your number of transactions is %d \nThank you for using the ATM\n",trans_num);
    exit(0);
};

double prompt_input(char* prompt_message,unsigned int (*return_check)(double,unsigned int)){
    double frac_part,int_part,input = 0.0;
    int prompts_num = 0;
    printf("%s",prompt_message);
    while (scanf("%lf",&input) == 1 && prompts_num < 3){
        frac_part = modf(input,&int_part);
        if (return_check(frac_part,input))
            return input;
        printf("%s","\tInvalid input. Please Try again.\n");
        prompts_num++;
    };
    printf("%s","\tInvalid input for 3 consecutive times - Exiting...\n");
    exit(0);
    return 1;
};

void balance(double money){
    printf("Your current Balance is - %lf\n",money);
};

double cash_withdrawal(double cur_balance,int choice, validate *process){
    double money_withdrawn = prompt_input("Please enter amount to withdraw: ",process[choice]);
    cur_balance = cur_balance - money_withdrawn;
    choice = (unsigned int)prompt_input("Would you like to receive a receipt\n\tEnter [1] for Yes\n\tEnter [2] for No\n",process[4]);
    if (choice == 1)
        printf("%s","\tPrinting your receipt...\n\n");
    balance(cur_balance);
    return cur_balance;
};

double cash_deposition(double cur_balance, int choice,validate *process){
    double money_deposit = prompt_input("Please enter amount to deposit: ",process[choice]);
    cur_balance = cur_balance + money_deposit;
    choice = (unsigned int)prompt_input("Would you like to receive a receipt\n\tEnter [1] for Yes\n\tEnter [2] for No\n",process[4]);
    if (choice == 1)
        printf("%s","\tPrinting your receipt...\n\n");
    balance(cur_balance);
    return cur_balance;
};

void menu(
    int trans_num,
    int nana_pin,
    double cur_trans_value,
    double init_balance,
    validate *process
){    
    char *menu_prompt = "Please enter your command\n\tEnter 1 for cash withdrawal\n\tEnter 2 for cash deposition\n\tEnter 3 to check balance\n\tEnter 4 to exit\n";
    unsigned int choice = (unsigned int)prompt_input(menu_prompt,process[3]);

    while (choice != 4){
        if (choice == 1){
            init_balance = cash_withdrawal(init_balance,choice,process);
        }
        if (choice == 2){
            init_balance = cash_deposition(init_balance,choice,process);
        }
        if (choice == 3){
            balance(init_balance);
            trans_num--;
        }
        trans_num ++;
        choice = (unsigned int)prompt_input(menu_prompt,process[3]);
    };
    quit((unsigned int)trans_num);
};

int main (int argc, char const *argv[]){
    /*
    run from CIS2107-lowlevel-programming directory
    gcc -o executables/atm -g src/atm.c  -lm
    */
    int trans_num = 0;
    double cur_trans_value = 0;
    double init_balance = 5000;
    const unsigned int nana_pin = 3014;
    validate process[5] = {
        validate_pin,
        validate_withrawal,
        validate_deposit,
        validate_menu,
        validate_receipt
    };

    prompt_input("Please enter your pin # to continue ",process[0]);
    menu(trans_num,nana_pin,cur_trans_value,init_balance,process);
    return 0;
}