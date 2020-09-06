#ifndef STRING_H
#define STRING_H

size_t strlen (const char *str);
int strcmp( const char *lhs, const char *rhs );
void printStringComparison(const char *str, const char *str2);

char *strcpy( char *restrict dest, const char *restrict src );
char *strncpy( char *restrict dest, const char *restrict src, size_t count );
char *strcat( char *dest, const char *src );
char *strncat( char *dest, const char *src, size_t count);
char *strtok( char *str, const char *delim );
void checkStrtok(char* input, char *delim);
char* strempty(char * input);
#endif // STRING_H
