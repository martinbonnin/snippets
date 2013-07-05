#include <stdio.h>
#define VP_VERSION_MAJOR 0
#define VP_VERSION_MINOR 00

#define MAKE_STRING(x) #x
#define MAKE_VERSION_STRING(major, minor) MAKE_STRING(major ## minor)
#define MAKE_VERSION_STRING2(major, minor) MAKE_VERSION_STRING(major,minor)
/*
 *  * As long as versions stay 1 digit for the major and 2 for the minor,
 *   * it should be safe to use strcmp to compare 2 versions
 *    */
#define VP_VERSION_STRING MAKE_VERSION_STRING2(VP_VERSION_MAJOR, VP_VERSION_MAJOR) 

int main(int argc, char **argv)
{
	printf("toto: %s\n", VP_VERSION_STRING);
	return 0;
}
