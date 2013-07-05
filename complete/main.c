#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *dir;
    char buf[1024];
    if (argc < 2) {
        printf("%s [directory]\n", argv[0]);
        exit(1);
    }
    
    dir = argv[1];
    
    if (getcwd(buf, sizeof(buf)) == NULL) {
        printf("cannot get cwd\n");
        exit(2);
    }
    
    printf("cwd:      %s\n", buf);    
    printf("chdir to: %s\n", dir);
    if (chdir(dir) != 0) {
        printf("cannot chdir\n");
        exit(3);
    }

    if (getcwd(buf, sizeof(buf)) == NULL) {
        printf("cannot get cwd\n");
        exit(2);
    }
    printf("cwd:      %s\n", buf);        

    return 0;
}
