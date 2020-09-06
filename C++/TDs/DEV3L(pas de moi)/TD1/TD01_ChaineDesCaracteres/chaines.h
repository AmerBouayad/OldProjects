#ifndef STRLEN_H
#define STRLEN_H
#include <stdio.h>
#include <string.h>

size_t strlenH(const char *str);

int strcmpH(const char *str1, const char *str2);
char *strcpyH( char *restrict str2, const char *restrict str1);
char * strcatH(char *dest, const char *src);
char * strncatH(char *dest, const char *src, size_t count);
#endif // STRLEN_H
