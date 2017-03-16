/*      File:   letters.h
 *      By:     Kevin Liu
 *      Login:  liukevin
 *      Team:   AMERICA
 *      Members:Paulo, Christopher  */

/*  utility functions declarations  */
#ifndef EE_HW3_LETTER_H_
#define EE_HW3_LETTER_H_


#define IS_UPPER(c) (c >= 'A' && c <= 'Z')
#define FLUSH while(getchar() != '\n');
#define TRUE 1
#define FALSE 0

int is_vowel(char);
/*  checks if character is a vowel  */

int is_h_consonant(char);
<<<<<<< HEAD
/*  checks if character is a consonant  */

int delimitp(char);
/*  checks if character is blank space or punctutation  */
=======
/*  checks if consonant  */

int is_delimiter(char);
/*  checks if is delimeter */


#endif
>>>>>>> c2a636d9f262d5ac44465a7110eaf9d6e3b7ea65
