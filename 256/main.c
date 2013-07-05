#include <stdint.h>
#include <stdio.h>

int main(int argc, char **argv[]) 
{
    int a1, a2;
    
    for (a1 = 0; a1 <= 255; a1++) {
#if 0   
        int p = (a1 * 256 + 127) / 255;
        int q = (a1 + (a1 >> 7));

        printf("a1=%d, p=%d, q=%d\n", a1, p, q);
        if (p != q) {
            printf("graaa\n");
        }
#else
        for (a2 = 0; a2 <= 255; a2++) {
            int p = a1 * ((a2 * 256 + 127) / 255);
            int q = a1 * (a2 + (a2 >> 7));
            
            if (p != q) {
                printf("a1=%3d, a2=%3d, p=%3d, q=%3d\n", a1, a2, p, q);
            }
        }  
#endif
    }
    
    return 0;
}
