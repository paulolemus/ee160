/*      File:   spchk.h
 *      By:     Paulo Lemus
 *      Login:  plemus
 *      Team:   AMERICA
 *      Members: Paulo, Christopher, Kevin  
 */


/* This file contains the complete declaration and definition of 
 * functions that are used in the spchk.c driver file.
 */

#ifndef EE_HW3_SPCHK_H_
#define EE_HW3_SPCHK_H_

/* A function that will print a single word and return
 * 1 if the word fits the hawaiian grammar or return 0
 * if it does not.
 * This function evaluates input from stdin, given the first
 * letter of the character. It also updated the given character
 * so that there is no change of losing the EOF character
 */
int eval_word(char*);

#endif
