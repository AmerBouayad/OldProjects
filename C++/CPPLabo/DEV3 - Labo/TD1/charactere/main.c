#include <stdio.h>
#include <charactere.h>

int main()
{
    //const char c[] = "Combien de charactere dans cette phrase ?";
    //printf("%d\n", nbChar(c));
    //const char* string = "Hello World!";
    //compareChar(string, "Hello");

    char *src = "Take the test.";
    src[0] = 'M' ;
    char dst[strlen(src) + 1];
    strcpy(dst, src);
    dst[0] = 'M';
    printf("src = %s\ndst = %s\n", src, dst);

    //char str[50] = "Hello ";
    //char str2[50] = "World!";
    //strcat(str,str2);
    //strcat(str, " ... ");
    //strcat(str, " Goodbye World");
    //printf("%s\n", str);
    return 0;
}
