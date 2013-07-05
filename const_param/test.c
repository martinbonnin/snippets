#include <stdlib.h>
#include <stdio.h>


/*    void fun(const char (*p)[6])
    {
        printf("%s", p[0]);
    }

    int main(int argc, char *argv[])
    {
        char a[6] = "hello";
        char (*c)[6];
        
        c = &a;
        
        fun(c);
    }*/
    
    
/*void fun(const char **p)
{
    printf("%s", *p);
}

int main(int argc, char *argv[])
{
    char a[6] = "hello";
    char *b;
    char **c;
    
    b = a;
    c = &b;    
    fun(c);
}*/
void func(int (*ip)[3]) {
    printf("Value: %d\n", ip[1][1]);
}

int main() {
    int i[3][3] = { {0, 1, 2} , {3, 4, 5}, {6, 7, 8} };
    func(i);
    return 0;
}

