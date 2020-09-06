#include <stdlib.h>
#include <stdio.h>
#include "mathesi.h"
#include "array.h"
#include "string.h"

void testAll()
{
    // Ex 1.2:

    printf("\n Ex 1.2: \n");

    int min = 200;
    int max = 349;
    printf("Les nombres compris entre %d et %d: \n", min, max);
    for(int i=min; i< max;i++) {
        if(isPrime(i)) {
            printf(" %d ", i);
        } else {
            printf("  .  ");
        }
        if((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    // Ex 1.3:

    printf("\n Ex 1.3: \n");

    printPrimeFactor(126, false);
    printPrimeFactor(126, true);
    printPrimeFactor(1, true);
    printPrimeFactor(1, false);


    // Ex 1.4:

    printf("\n Ex 1.4: \n");

    printf("gcd(423, 135): %d\n", gcd(423, 135));


    // Ex 1.5:

    printf("\n Ex 1.5: \n");

    int col = 3;
    int row = 6;

    int a_start = 423;
    int b_start = 135;

    int a_inc = 3;
    int b_inc = 5;

    int a = a_start;
    int b = b_start;

    for(int i=0; i<row; i++) {
        for (int j = 0; j < col; ++j) {
            if (j != 0)
                printf(" | ");
            printf("gcd(%d, %d = %2d)", a, b, gcd(a,b));
            b -= b_inc;
        }
        b = b_start;
        a += a_inc;
        printf("\n");
    }

    // Ex 1.7:

    printf("\n Ex 1.7: \n");

    int len = 5;
    int tab[] =  {1, -5, 3, 9, -1};
    int initialTab[len];
    for (int i = 0; i < len; ++i) {
        initialTab[i] = tab[i];
    }

    printf("initial array: ");
    arrayIntPrint(tab, len);

    printf("sorted ascending: ");
    arrayIntSort(tab, len, true);
    arrayIntPrint(tab, len);

    printf("sorted descending: ");
    arrayIntSort(tab, len, false);
    arrayIntPrint(tab, len);

    // Ex 1.8:

    printf("\n Ex 1.8: \n");

    printf("sorted ascending with qsort: ");
    qsort(tab, len, sizeof(int), compare_ints_ascending);
    arrayIntPrint(tab, len);

    printf("sorted descending with qsort: ");
    qsort(tab, len, sizeof(int), compare_ints_descending);
    arrayIntPrint(tab, len);

    printf("sorted ascending mod 3 with qsort: ");
    qsort(tab, len, sizeof(int), compare_ints_ascending_mod3);
    arrayIntPrint(tab, len);

    // Ex 1.9:

    printf("\n Ex 1.9: \n");

    for (int i = 0; i < len; ++i) {
        tab[i] = initialTab[i];
    }

    printf("initial array: ");
    arrayIntPrint(tab, len);

    printf("sorted ascending with arrayIntSortGeneric: ");
    arraySortGeneric(tab, len, (int(*)(const int*, const int*))compare_ints_ascending);
    arrayIntPrint(tab, len);

    printf("sorted descending with arrayIntSortGeneric: ");
    arraySortGeneric(tab, len, (int(*)(const int*, const int*))compare_ints_descending);
    arrayIntPrint(tab, len);

    printf("sorted ascending mod 3 with arrayIntSortGeneric: ");
    arraySortGeneric(tab, len, (int(*)(const int*, const int*))compare_ints_ascending_mod3);
    arrayIntPrint(tab, len);

    // Ex 1.10:

    printf("\n Ex 1.10: \n");

    printf("strlen:\n");

    const char *str = "machaine";
    const char *maChaineNulle = "ma\0ChaineNulle";
    printf("\"%s\" est une chaine de longeur: %d\n", str, strlen(str)); // TODO: printing a size_t as int !!
    printf("\"%s\" est une chaine de longeur: %d\n", maChaineNulle, strlen(maChaineNulle));

    printf("strcmp:\n");

    const char *str2 = "z'une chaine";
    const char *str3 = "Ah! une chaine!";
    const char *str4 = "machaine";
    const char *str5 = "machaine2";
    const char *str6 = "machain";

    printStringComparison(str, str2);
    printStringComparison(str, str3);
    printStringComparison(str, str4);
    printStringComparison(str, str5);
    printStringComparison(str, str6);

    printf("\nstrcpy:\n");

    const char *restrict maChaineRestrict = "maChaineRestrict";
    // TODO: check if the copy really is restrict
    // TODO: what if it's not restrict here and it is in the function protoype ?
    char copyRestrict [strlen(maChaineRestrict)+1];
    strcpy(copyRestrict, maChaineRestrict);
    printf("La chaine originale est:\n%s\nLa chaine copiée est:\n%s\n", maChaineRestrict, copyRestrict);


    printf("\nstrncpy:\n");

    char copy2 [strlen(maChaineRestrict)+1];
    printf("La chaine \"%s\" fait %zu caractère. Ceux-ci seront tous copiés.\n", maChaineRestrict, strlen(maChaineRestrict));
    strncpy(copy2, maChaineRestrict, strlen(maChaineRestrict)+1);
    printf("Résultat:\n%s\n", copy2);

    char copy3 [strlen(maChaineRestrict)+1];
    int count = 5;
    strncpy(copy3, maChaineRestrict, count);
    printf("Résultat si je copie seulement les %d premiers caractères (chaine peut-être non zéro terminée!!):\n%s\n", count, copy2);

    count = 20;
    char copy4 [count+1];
    strncpy(copy2, maChaineRestrict, count);
    // copy2 should have multiple null characters at its end
    printf("Résultat si je demande de copier %d caractères:\n%s\n", count, copy2);

    printf("\nstrcat:\n");

    char toCat [30*sizeof(char)];
    strcpy(toCat, "début chaine");
    printf("Résultat de la concaténation de \"%s\" et \"%s\":\n", toCat, str);
    strcat(toCat,str);
    printf("%s\n", toCat);

    printf("\nstrncat:\n");

    count = 5;
    strempty(toCat);
    strcpy(toCat, "début chaine");
    printf("Résultat de la concaténation de \"%s\" et des %d premiers caractères de \"%s\":\n", toCat, count, str);
    strncat(toCat,str, count);
    printf("%s\n", toCat);

    printf("\nstrtok:\n");

    char input[] = " ;  A bird;came down the.walk";
    printf("Parsing the input string '%s'\n", input);
    char *token = strtok(input, " ;.");
    while(token) {
        puts(token);
        token = strtok(NULL, " ;.");
    }

    printf("Contents of the input string now: '");
    for(size_t n = 0; n < sizeof input; ++n)
        input[n] ? printf("%c", input[n]) : printf("\\0");
    puts("'");

}
