#include <stdio.h>
#include "h.h"
#include <dlfcn.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    void *lib = dlopen("liba.so", RTLD_NOW);
    if (lib == NULL) {
        printf("%s\n", dlerror());
        exit(1);
    }
    
    void (*a1)(void);
    
    a1 = dlsym(lib, "a1");
    if (a1 == NULL) {
        printf("cannot find a1\n");
    }
    
    a1();
    return 0;
}
