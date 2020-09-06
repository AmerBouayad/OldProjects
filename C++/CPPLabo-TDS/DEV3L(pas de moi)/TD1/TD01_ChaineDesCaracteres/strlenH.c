#include "chaines.h"

size_t strlenH(const char *str)
{
    size_t cpt = 0;
    for(; str[cpt] !=0; ++cpt){
    }
    return cpt;
}

int strcmpH(const char *str1, const char *str2)
{
        unsigned i =0;
        while (i < strlenH(str1) && str1[i]==str2[i]){
            ++i;
        }
        if(str1[i]==str2[i]){
            return 0;
        }else if(str1[i]>str2[i]){
            return 1;
        }else{
            return -1;
        }
}

char *strcpyH( char *restrict str2, const char *restrict str1)
{

    for (unsigned i =0; i <= strlenH(str1); ++i){
        str2[i] = str1[i];
    }
    return str2;
}

char * strcatH(char *dest, const char *src)
{
    size_t sizeStr = strlenH(dest);
    size_t sizeStr2 = strlenH(src);
    for (unsigned i = 0; i < sizeStr2; ++i)
    {
        dest[sizeStr+i] = src[i];
    }
    dest[sizeStr+sizeStr2+1] = 0;
    return dest;
}

char * strncatH(char *dest, const char *src, size_t count)
{
    size_t sizeStr = strlenH(dest);
    size_t sizeStr2 = strlenH(src);
    sizeStr2 = sizeStr2 < count? sizeStr2 : count;
    for (unsigned i = 0; i < sizeStr2; ++i)
    {
        dest[sizeStr+i] = src[i];
    }
    dest[sizeStr+sizeStr2+1] = 0;
    return dest;
}
