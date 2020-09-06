#include "tests.h"
#include <stdio.h>
#include "mathesi.h"
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

void printUsage()
{
    printf("usage: number\n options: -v show the long format");
}

bool isUnsigned(char * string)
{
    while (*string != '\0')
    {
        if (! isdigit(*string))
        {
            return false;
        }
        string++;
    }
    return true;
}

bool isOption(char * string)
{
    if (*string == '-' && *(string + 1) == 'v')
    {
        return true;
    }

    return false;
}

int main(int argc, char * argv[])
{
    testAll();

//    if (argc > 3 || argc < 2)
//    {
//        printUsage();
//    }

//    if (argc == 2)
//    {
//        if (isUnsigned(argv[1]))
//            printPrimeFactor(atoi(argv[1]), true);
//        else
//        {
//            printUsage();
//            exit(-1);
//        }
//    }

//    if (argc == 3)
//    {
//        if (isUnsigned(argv[1]) && isOption(argv[2]))
//        {
//            printPrimeFactor(atoi(argv[1]), false);
//        }
//        else if ( isOption(argv[1]) && isUnsigned(argv[2]))
//        {
//            printPrimeFactor(atoi(argv[2]), false);
//        }
//        else
//        {
//            printUsage();
//            exit(-1);
//        }
//    }



    return 0;
}

