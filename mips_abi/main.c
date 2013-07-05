extern int printf(const char *fmt, ...);

int function1(int a)
{
    int b = 3;
        
    return a + b;
}

void function2(int c)
{
    printf("%d\n", function1(5));
}
