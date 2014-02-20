/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Returns a heap-allocated string with length n, with
// the given string in the middle, surrounded by fillchar.
//
// For example, if s is allen, n is 10 and fillchar is .
// the result is ..allen... 

char *center(char s*, int n, char fillchar)
{   int i;
    char * final;
    size_t len = strlen(s);

    final = (char *) malloc(sizeof(char)*(n+1));

    int len_fill_str = (n - len)/2;

    char fill_str[len_fill_str];
    int j;
    for (j=0; j<=len_fill_str; j++) {
        fill_str[j] = fillchar;
    }
    strcpy(final, fill_str);
    strcat(final, s);
    strcat(final, fill_str);


    puts(final);
    return NULL;
}


int main (int argc, char *argv[])
{
    char *s = center("Software", 30, '.');
    printf("%s\n", s);

    char *s2 = center("Systems", 31, '-');
    printf("%s\n", s2);

    char *s3 = center("Spring 2014", 32, '*');
    printf("%s\n", s3);

    char *s4 = center("Exam 1", 33, '^');
    printf("%s\n", s4);

    return 0;
}
