/* File   : datediff.c
 * Name   : 
 * Id     :
 * Team   : AMERICA
 * Members: Paulo Lemus, Kevin Liu, Christpoher A
 */

#include <stdio.h>
#include "julian.h"


int main(){

    printf("                 __  __  ___  __            \n");
    printf("  /\\   |\\    /| |   |  |  |  |     /\\    \n");
    printf(" /--\\  | \\  / | |-- |__|  |  |    /--\\   \n");
    printf("/    \\ |  \\/  | |__ | \\  _|_ |__ /    \\ \n\n");
    printf("Welcome to TEAM AMERICA's date difference premier experience!");
    printf("\nThis program will calculate the difference between two dates.");
    printf("\nYou can enter your starting and ending dates below.\n");

    while(1){
        char c;
        int s_day, s_month, s_year;
        int e_day, e_month, e_year;
        int chk1, chk2, chk3, chk4, chk5, chk6;

        printf("\nEnter starting date (mm dd yyyy): ");
        if(chk1 = scanf("%d", &s_month) == EOF) break;
        if(chk2 = scanf("%d", &s_day)   == EOF) break;
        if(chk3 = scanf("%d", &s_year)  == EOF) break;
        if(chk1 || chk2 || chk3){
            printf("\nAn invalid value was entered. Try again");
            while(c = getchar() != '\n' && c != EOF);
            continue;
        }

        printf("\nEnter ending date (mm dd yyyy): ");
        if(chk4 = scanf("%d", &e_month) == EOF) break;
        if(chk5 = scanf("%d", &e_day)   == EOF) break;
        if(chk6 = scanf("%d", &e_year)  == EOF) break;
        if(chk4 || chk5 || chk6){
            printf("\nAn invalid value was entered. Try again");
            while(c = getchar() != '\n' && c != EOF);
            continue;
        }
        printf("\nSuccess!\n");

    }
    printf("\n\nGoodbye!\n\n");
    return 0;
}
