#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int validate_pin(double frac_part,int input){
    return (input == 3014);
}

int validate_menu(double frac_part,int input){
    return (frac_part == 0 && input > 0 && input < 5);
}

int validate_withrawal(double frac_part,int input){
    return (frac_part == 0 && input > 0 && input < 1000 && input % 20 == 0);
};

int validate_deposit(double frac_part,int input){
    return (frac_part == 0 && input > 0 && input < 10000);
}

double prompt_input(char* prompt_message, int (*return_check)(double,int)){
    double frac_part,int_part,input = 0.0;
    int prompts_num = 0;
    printf("%s",prompt_message);
    while (scanf("%lf",&input) == 1 && prompts_num < 3){
        frac_part = modf(input,&int_part);
        if (return_check(frac_part,input))
            return input;
        printf("Invalid input. Please Try again.\n");
        prompts_num++;
    };
    printf("Invalid input for 3 consecutive times - Exiting...\n");
    exit(0);
    return 1;
};

void balance(double money){
    printf("Your current Balance is - %lf\n",money);
};

double cash_withdrawal(double cur_balance,double money_withdrawn){
    cur_balance = cur_balance - money_withdrawn;
    balance(cur_balance);
    return cur_balance;
};

double cash_deposition(double cur_balance, double money_deposit){
    cur_balance = cur_balance + money_deposit;
    balance(cur_balance);
    return cur_balance;
};

void quit(int transactions){
    printf("Your number of transactions are %d \nThank you for using the ATM\n",transactions);
    exit(0);
};

void menu(int trans_num,int nana_pin,double cur_trans_value,double init_balance,int (*return_check)(double,int)){    
    return_check = validate_menu;
    char *menu_prompt = "Please enter your command\n\tEnter 1 for cash withdrawal\n\tEnter 2 for cash deposition\n\tEnter 3 to check balance\n\tEnter 4 to exit\n";
    int choice = (int)prompt_input(menu_prompt,return_check);

    while (choice){
        if (choice == 1){
            return_check = validate_withrawal;
            init_balance = cash_withdrawal(init_balance,prompt_input("Please enter amount to withdraw: ",return_check));
        }
        if (choice == 2){
            return_check = validate_deposit;
            init_balance = cash_deposition(init_balance,prompt_input("Please enter amount to deposit: ",return_check));
        }
        if (choice == 3){
            balance(init_balance);
            trans_num--;
        }
        if (choice == 4)
            quit(trans_num);
        trans_num ++;
        return_check = validate_menu;
        choice = (int)prompt_input(menu_prompt,return_check);
    };
};

int main (int argc, char const *argv[]){
    int trans_num = 0;
    int nana_pin = 3014;
    double cur_trans_value = 0;
    double init_balance = 5000;
    int (*return_check)(double,int) = validate_pin;
    prompt_input("Please enter your pin # to continue ",return_check);
    menu(trans_num,nana_pin,cur_trans_value,init_balance,return_check);
    return 0;
}