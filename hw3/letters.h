/*      File:   letters.h
 *      By:     Kevin Liu
 *      Login:  liukevin
 *      Team:   AMERICA
 *      Members:Paulo, Christopher  */

/*  utility functions declarations  */

#define IS_UPPER(c) (c >= 'A' && c <= 'Z')
#define FLUSH while(getchar() != '\n');
#define TRUE 1
#define FALSE 0

int is_vowel(char);
/*  checks if character is a vowel  */

int is_h_consonant(char);
/*  checks if character is a consonant  */

int delimitp(char);
/*  checks if character is blank space or punctutation  */
