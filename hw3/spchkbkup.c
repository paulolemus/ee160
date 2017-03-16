/* File : spchk.c
 * Name : Paulo Lemus
 * Login: plemus
 * TEAM : AMERICA
 * Members: Paulo, Kevin, Christpoher
 */

#include <stdio.h>
#include "letters.h"


int main() {

    char peek;
    char token;
    peek = getchar();

    // Clear leading whitespace for first word
    while( is_delimiter(peek) && peek != EOF ) peek = getchar();


    // Primary evaluation loop
    while( peek != EOF ) {

        int valid = 1;

        // Parse in word until you hit a delimiter
        // It guarentee prints all characters
        ///////////////////////////////////////////////////////////
        if(!is_vowel(peek) && !is_h_consonant(peek)) valid = 0;

        while( !is_delimiter(peek) ) {
            token = peek;
            peek = getchar();
            printf("%c", token);

            // Check condition 1
            if(!is_vowel(token) && !is_h_consonant(token)) valid = 0;
            // Check condition 3
            if(is_h_consonant(token) && is_h_consonant(peek)) valid = 0;
        }
        // Check condition 2
        if(valid && !is_vowel(token)) valid = 0;
        ////////////////////////////////////////////////////////////

        // Sign the word printed above as valid or invalid
        if(valid) printf("\t - valid  \n");
        else      printf("\t - invalid\n");

        // Clear 
        while( is_delimiter(peek) && peek != EOF ) peek = getchar();
    }
    return 0;
}

int eval_word(char peek) {
    char token;
    int valid = 1;

    if(!is_vowel(peek) && !is_h_consonant(peek)) valid = 0;

    while( !is_delimiter(peek) ) {
        token = peek;
        peek = getchar();
        printf("%c", token);

        // Check condition 1
        if(!is_vowel(token) && !is_h_consonant(token)) valid = 0;
        // Check condition 3
        if(is_h_consonant(token) && is_h_consonant(peek)) valid = 0;
    }
    // check condition 2
    if(valid && !is_vowel(token)) valid = 0;

    return valid;
}
