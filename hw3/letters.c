/*      File:   charutil.c
 *      By:     Kevin Liu
 *      Login:  liukevin
 *      Team:   AMERICA
 *      Members:Paulo, Christopher  */

/*  utility function declaration  */

#include "charutil.h"

int is_vowel(char)
{
    if(IS_UPPER(char)) //change uppercase to lowercases
        char -= 32;

    switch(char) //checks char is a vowel or not
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': return TRUE;
        default: return FALSE;
    }
}

int is_h_consonant(char)
{
    if(IS_UPPER(char)) //changes uppercase to lowercase
        char -= 32;
    switch(char)
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
