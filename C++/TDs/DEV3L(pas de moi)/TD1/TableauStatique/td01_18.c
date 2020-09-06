
int compareCroissant (void const *a, void const *b)
{
    int const *pa = a;
    int const *pb = b;

    return *pa - *pb;
}


int compareDecroissant (void const *a, void const *b)
{
    int const *pa = b;
    int const *pb = a;

    return *pa - *pb;
}
