#include <stdlib.h>
#include <stdio.h>

static int array[] = {0,2,4,5,6,7,8,9,10};

#if 0
int _search(int *v, int what, int left, int right) 
{
    int middle = (left + right) >> 1;

    printf("[%d - %d - %d]\n", left, middle, right);

    if (left > right)
        return -1;

    if (v[middle] == what) {
        return middle;
    } else if (v[middle] < what) {
        return _search(v, what, middle + 1, right);
    } else {
        return _search(v, what, left, middle - 1);
    }

    return -1;
}
#else
int _search(int *v, int what, int left, int right) 
{
    int middle;
    while (left <= right) {
        middle = (left + right) >> 1;
        printf("%d - %d - %d\n", left, middle, right);
        if (v[middle] == what) {
            return middle;
        } else if (v[middle] < what) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    
    return left;
}

#endif

int main(int argc, char **argv)
{
    int what = 3;
    printf("index of %d: %d\n", what, _search(array, what, 0, 3));
    printf("index of %d: %d\n", what, _search(array, what, 0, 4));

    what = 1;
    printf("index of %d: %d\n", what, _search(array, what, 0, 3));
    printf("index of %d: %d\n", what, _search(array, what, 0, 4));

    what = 13;
    printf("index of %d: %d\n", what, _search(array, what, 0, 3));
    printf("index of %d: %d\n", what, _search(array, what, 0, 4));
    
    return 0;
}
