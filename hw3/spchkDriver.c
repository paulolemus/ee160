/* File   : spchkDriver.c
 * Name   : Paulo Lemus
 * Login  : plemus
 * TEAM   : AMERICA
 * Members: Paulo, Kevin, Christpoher
 */

/* This is an alternative version of spchk. 
 * Please refer to spchk.c for our primary code
 */

#include <stdio.h>
#include "spchk1.h"
#include "letters.h"


int main() {

    char token;
    token = getchar();

    // Clear leading whitespace for first word
    while( is_delimiter(token) && token != EOF ) token = getchar();


    // Primary evaluation loop
    while( token != EOF ) {

        /* This function eval_word parses in a word until
         * a white space is reached. The return value is 1
         * if the word fits hawaiian grammar, 0 otherwise.
         * It updates the character peek with the last character
         * parsed, so that there is no chance of losing the EOF character.
         */
        int valid = eval_word(&token);

        // Sign the word printed above as valid or invalid
        if(valid) printf("\t - VALID  \n");
        else      printf("\t - INVALID\n");

        // Clear trailing whitespace, get first character of next word
        // in peek.
        while( is_delimiter(token) && token != EOF ) token = getchar();
    }
    return 0;
}
