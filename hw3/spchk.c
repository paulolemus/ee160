/*      File:   spchk.c
 *      By:     Kevin Liu
 *      Login:  liukevin
 *      Team:   AMERICA
 *      Members:Paulo, Christopher      */

#include <stdio.h>
#include "letters.h"

int main()
{
    /*  declare & initialize variables  */
    char ch, ch_last;
    int inword, correct;
    correct = TRUE;
    inword = FALSE;

    while((ch = getchar()) != EOF)
    {   
        /*  at the beginning of a word  */
        if(!inword && !delimitp(ch))
            inword = TRUE;

        /*  at the end of a word  */
        else if(inword && delimitp(ch))
        {
            inword = FALSE;

            /*  checks if ends with a vowel & if other standards are correct  */
            if(is_vowel(ch_last) && correct)
            {
                printf("\tVALID");
                /*  reset (condition update)  */
                correct = TRUE;
                ch_last = ' ';
            }

            else //if spelling error present 
            {
                printf("\tINVALID");
                /*  reset (condition update)  */
                correct = TRUE;
                ch_last = ' ';
            }

            putchar('\n'); //make new line for each word
        }   

        /*  prints characters in word  */
        if(inword)
        {
            /*  checks if 2 consonant next to each other */
            if(is_h_consonant(ch) && is_h_consonant(ch_last))
                correct = FALSE; 
            ch_last = ch; //save previous character
            putchar(ch); //print out word
        }
    }
    return 0;
}
