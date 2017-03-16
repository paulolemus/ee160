/*      File   : driver1.c
 *      By     : Christopher
 *      Login  : camendol
 *      Team   : AMERICA
 *      Members: Paulo, Christopher, Kevin 
 */

/*  driver to test program functions in letter.h  */

#include "letters.h"
#include <stdio.h>

int main()
{
    char c;

    // Initialization, do not enter loop with 
    // uninitialized character
    printf("Enter a letter: ");
    c = getchar();

    // Loop to test "is_vowel" and "is_h_consonant" from letter.h.
    // Loop ends upon EOF entry, otherwise will evaluate any char entered.
    while(c != EOF) {


        if(is_vowel(c)) printf("%c is a vowel\n", c);
        else if(is_h_consonant(c)) printf("%c is a consonant\n", c);
        else printf("%c is not a hawaiian letter\n", c);

        // Clear input til '\n' to prevent extra loops
        FLUSH;

        // set up next loop
        printf("Enter letter: ");
        c = getchar();
    }
    printf("\n\nGoodbye!\n\n");
    return 0;
}
