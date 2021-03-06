/*      File   : letters.c
 *      By     : Kevin Liu / Christopher
 *      Login  : liukevin  / camendol
 *      Team   : AMERICA
 *      Members: Paulo, Christopher  
 */

/*  utility function declaration  */

#include <ctype.h>
#include "letters.h"

int is_vowel(char ch)
{
    if(IS_UPPER(ch)) //change uppercase to lowercases
        ch += 32;

    switch(ch) //checks ch is a vowel
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': return TRUE;
        default: return FALSE;
    }
}

int is_h_consonant(char ch)
{
    if(IS_UPPER(ch)) //changes uppercase to lowercase
        ch += 32;

    switch(ch) //checks ch is a consonant
    {
        case 'h':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'p':
        case 'w':
        case '`': return TRUE;
        default: return FALSE;
    }
}

int is_delimiter(char ch)
{
    // considers any non-letter 
    // character (or Okina) as a delimiter
    return !(isalpha(ch) || ch == '`');
}

int delimitp(char ch)
{
    switch(ch) // Checks if ch is any symbol below
    {
        case ' ':
        case '\n':
        case '\t':
        case ',':
        case '!':
        case '"':
        case '.': return TRUE;
        default: return FALSE;
    }
}
