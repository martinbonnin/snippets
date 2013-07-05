#include "stdio.h"

#define VIDEOPLAYER_ERROR_MACRO(error, code)  error = code,
enum {
#include "errors.h"
};
#undef VIDEOPLAYER_ERROR_MACRO

#define VIDEOPLAYER_OK_STR "roptoto"


#define VIDEOPLAYER_ERROR_MACRO(error, code)  [error] = error ## _STR,
const char *tata[] = {
#include "errors.h"
};
#undef VIDEOPLAYER_ERROR_MACRO

const char *toto[] = 
{
    [VIDEOPLAYER_OK] = "toto",
};

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)
#define HEADER(dir) dir##header
#define NSV_INCLUDE_DIR(header) </usr/include/ header >

#include NSV_INCLUDE_DIR(elf.h)
#include </usr/include/regex.h>
int main (int argc, char **argv) {
    
    printf("%s", NSV_INCLUDE_DIR(elf.h));
    return 1;
}

