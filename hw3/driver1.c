/*      File:   driver1.c
 *      By:     Kevin Liu
 *      Login:  liukevin
 *      Team:   AMERICA
 *      Members:Paulo, Christopher  */

/*  driver to test program function  */

#include "letters.h"
#include <stdio.h>

int main()
{
    printf("Checking Characters in Written Hawaiian...\n");
    printf("Enter a character (EOF to quit): ");
    for(char ch = getchar(); ch != EOF; ch = getchar())
    {
        if(is_vowel(ch))
        {
            printf("%c is a vowel\n", ch);
            FLUSH;
        }
        else if(is_h_consonant(ch))
        {
            printf("%c is a consonant\n", ch);
            FLUSH;
        }
        else if(!(is_vowel(ch) && is_h_consonant(ch)))
        {
            printf("%c is not in the written Hawaiian language\n", ch);
            FLUSH;
        }
        printf("Enter a character (EOF to quit): ");
    }
    return printf("\nGoodbye!\n");
}
