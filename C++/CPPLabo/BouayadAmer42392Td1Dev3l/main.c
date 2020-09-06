#include <stdio.h>
#include "mathesi.h"

int main(int argc, char *argv[])
{
    printf("Laboratoire de C/C++:\n");
    printf("=====================\n");
    unsigned int nb=5;
    //printf("%4d\n",nb);

    //printf("%d\n",isPrime(nb));

    //affPrime(200,349);

    //printPrimeFactor(nb,true);

    //unsigned a = 1071;
    //unsigned b = 1029;
    //printf("gcd(%d,%d) = %d \n",a, b, gcd(a,b));

    //td1ex5();

    //const int data[5] = {2, 1, 7, 3, 5};
    //arrayIntPrint(data, nb);

    //int data[5] = {7, 8, 9, 22, 24};
    //arrayIntSort(data, nb, false);

    //int ints[] = { -2, 99, 0, -743, 2, 4 };
    //int size = sizeof ints / sizeof *ints;
    //1.8-a
    //qsort(ints, size, sizeof(int), compare_ints)
    //1.8-b
    //qsort(ints, size, sizeof(int), compare_intsDec);
    //1.8-c
    //qsort(ints, size, sizeof(int), compare_intsMod3);

    //arrayIntPrint(ints, size);

    //const char str[] = "How many characters does this string contain?";
    //printf("without null character: %zu\n", strlen(str));
    //printf("with null character:    %zu\n", sizeof str);


    //1.10) strcmp
    const char* string = "Hello World!";
    demo(string, "Hello!");
    demo(string, "Hello");
    demo(string, "Hello there");
    demo("Hello, everybody!" + 12, "Hello, somebody!" + 11);
    return 0;

    //1.10)strcat:  Concaténation de 2 chaînes de char (copie la deuxième chaîne de char à la suite de la première)
    //     strncat: Copie n nombres de char de la 2ème chaîne de char à la suite de la première

    //1.10)strtok(exemple, " "): coupe la chaine de

}
