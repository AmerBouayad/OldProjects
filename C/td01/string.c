// we need at least one header that defines size_t
// see http://en.cppreference.com/w/c/types/size_t for a list

#include<stdio.h>
#include <stdbool.h>

size_t strlen(const char *str)
{
    int i=0;

    while(*(str +i) != '\0') {
        i++;
    }
    return i;
}


int strcmp(const char *lhs, const char *rhs)
{
    unsigned i=0;
    int comparison = 0;

    do {
        comparison = *(lhs + i) - *(rhs + i);
        i++;
    }while (i < strlen(lhs) && i < strlen(rhs) && ! comparison);

    // if they're the same up to the length of the shorter one, we have to cmp lengths:
    if(! comparison) {
        // TODO: is it necessary to have a temp variable containing the length instead of making multiple calls ?
        if(strlen(lhs) < strlen(rhs)) {
            comparison = -1;
        } else if (strlen(lhs) > strlen(rhs)) {
            comparison = 1;
        } else {
            comparison = 0;
        }
    }

    return comparison;
}


void printStringComparison(const char *str, const char *str2)
{
    int comparison = strcmp(str, str2);
    if(comparison < 0) {
        printf("%s est avant %s\n", str, str2);
    } else if (comparison > 0){
        printf("%s est après %s\n", str, str2);
    } else {
        printf("%s et %s son les mêmes\n", str, str2);
    }
}


char *strcpy( char *restrict dest, const char *restrict src )
{
    int i=0;
    while (*(src +i) != '\0') {
        * (dest +i) = *(src + i);
        i++;
    }
    * (dest +i) = *(src + i); // copying the \0
    return dest;
}

char *strncpy(char *dest, const char *src, size_t count)
{
    int i=0;
    while (i < count && *(src + i) != '\0') {
        *(dest + i) = *(src + i);
        i++;
    }
    // filling with null chars if we didn't reach count
    while(i< count) {
        *(dest + i) = '\0';
        i++;
    }
    return dest;
}
// TODO: pourquoi pas un const char* pour dest puisqu'on ne peut de toute façon pas le modifier ?
char *strcat(char *dest, const char *src)
{
    char* bck = dest;
    while(*dest != '\0') {
        dest++;
    }
    while(*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return bck;
}

char *strncat(char *dest, const char *src, size_t count)
{
    int len = 0;
    char* bck = dest;
    while(*dest != '\0') {
        dest++;
    }
    while(*src != '\0' && len < count) {
        *dest = *src;
        src++;
        dest++;
        len++;
    }
    *dest = '\0';
    return bck;
}



// TODO: Do these sub  methods have to be in the .h ? (I'm using them as "private" methods)

// TODO: check if the token can be \0
bool isDelim(char c, const char *delim) {
    while (*delim != '\0' && c != *delim) {
        delim++;
    }
    if (*delim == '\0') {
        return false;
    }
    return true;
}
char * findNextDelim(char *str, const char *delim) {
    while (*str != '\0' && ! isDelim(*str, delim)) {
        str++;
    }
    return str;
}


char *strtok(char *str, const char *delim)
{
    // TODO: faut-il bien utiliser un static ?
    // this will save the position of the next token found by a previous call:
    static char *savedToken;
    char * tokenBeginning;

    if (str == NULL) {
        str = savedToken;
    }

    if (str == NULL) {
        return NULL;
    }

    // we will search for the first caracter that is not contained in delim:
    while (*str != '\0' && isDelim(*str, delim)) {
        str++;
    }
    // if we reached the end of str, there are only delimiters, and no token:
    if (*str == '\0') {
        return NULL;
    }
    // else, we have the beginning of our token:
    tokenBeginning = str;
    str = findNextDelim(str, delim);
    // if there are no delimiter after the first token, there is no more token for the next call:
    if (*str == '\0') {
        savedToken = NULL;
    } else {
        *str = '\0';
        savedToken = str + 1;
    }
    return tokenBeginning;
}



char * strempty(char *input)
{
    char *bck = input;
    for (int i = 0; i < strlen(input); ++i) {
        *input = '\0';
        input++;
    }
    return bck;
}
