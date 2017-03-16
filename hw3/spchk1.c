/* File   : spchk1.c
 * Name   : Paulo Lemus
 * Login  : plemus
 * TEAM   : AMERICA
 * Members: Paulo, Kevin, Christpoher
 */

#include <stdio.h>
#include "spchk1.h"
#include "letters.h"

/* Evaluate a single word on stdin */
int eval_word(char* peek) {

    char token;
    int valid = 1;

    // Start of word - must start with a vowel or consonant
    if(!is_vowel(*peek) && !is_h_consonant(*peek)) valid = 0;

    // Intermediate characters
    while( !is_delimiter(*peek) ) {
        token = *peek;
        *peek = getchar();
        putchar(token);

        // Check for valid hawaiian grammar vowel or consonant
        if(!is_vowel(token) && !is_h_consonant(token)) valid = 0;
        // Check for repeating consonants
        if(is_h_consonant(token) && is_h_consonant(*peek)) valid = 0;
    }
    // End of word - check for vowel
    if(valid && !is_vowel(token)) valid = 0;

    // 1 if hawaiian, 0 if not
    return valid;
}
