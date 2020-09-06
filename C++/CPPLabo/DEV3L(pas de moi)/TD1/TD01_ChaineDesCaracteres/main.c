

#include "chaines.h"

int main(void)
{
    char ch1 [] = "hello";
    char ch2 [] = "aaaaa";
    char ch3 [] ="";

    printf("----STRLEN----\n");
    printf("%u\n", strlen(ch1));
    printf("%u\n", strlen(ch2));
    printf("%u\n", strlen(ch3));
    printf("\n----STRLEN-H----\n");
    printf("%u\n", strlenH(ch1));
    printf("%u\n", strlenH(ch2));
    printf("%u\n", strlenH(ch3));
    printf("\n----STCMP----\n");
    printf("hch1>ch3 =%i",strcmp(ch1,ch3));
    printf("\nch1 < ch2 =%i",strcmp(ch1,ch2));
    printf("\n%i\n",strcmp(ch1,ch1));


    printf("\n----STCMP-H----\n");
    printf("hch1>ch3 =%i",strcmpH(ch1,ch3));
    printf("\nch1 < ch2 =%i",strcmpH(ch1,ch2));
    printf("\n%i\n",strcmpH(ch1,ch1));

    char chCopy1[strlenH(ch1)+1]; // to accomodate fot the null temrinator
    printf("\n----STRCPY----\n");
    strcpy(chCopy1, ch1);
    printf("ch1 = %s, chCopy1 =%s\n",ch1,chCopy1);

    char chCopyH1[strlenH(ch1)+1]; // to accomodate fot the null temrinator
    printf("\n----STRCPY-H----\n");
    strcpyH(chCopyH1, ch1);
    printf("ch1 = %s, chCopy1 =%s\n",ch1,chCopyH1);

    //************************************************
    printf("\n----STRCAT----\n");
    char str[50] = "Hello ";
    char str2[50] = "World!";
    strcat(str, str2);
    strcat(str, " ...");
    strcat(str, " Goodbye World!");
    printf("string : %s\n", str);

    printf("\n----STRCAT-H----\n");
    char strH[50] = "Hello ";
    char str2H[50] = "World!";
    strcatH(strH, str2H);
    strcatH(strH, " ...");
    strcatH(strH, " Goodbye World!");
    printf("string : %s\n", strH);

    //************************************************
    printf("\n----STRNCAT----\n");

    char strn[50] = "Hello ";
    char strn2[50] = "World!";
    strncat(strn, strn2, 10);
    strncat(strn, " Goodbye World!", 3);

    printf("string : %s\n", strn);

    printf("\n----STRNCAT-H----\n");

    char strnH[50] = "Hello ";
    char strn2H[50] = "World!";
    strncatH(strnH, strn2H, 10);
    strncatH(strnH, " Goodbye World!", 3);
    printf("string : %s\n", strnH);

    return 0;
}

