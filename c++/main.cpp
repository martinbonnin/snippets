#include <string.h>
#include <iostream>
#include <vector>

#pragma GCC diagnostics ignored "-Wshadow"
#define my_macro(a) (a << 1)
using namespace std;
using ::memset;
using ::my_macro;

void my_func()
{
        cout << "tpitpi";
        throw 20;
}

int main(int argc, char **argv)
{
        int a;
	
	memset(&a, 0xa, sizeof(a));

        std::cout << "Hello world\n";

        while (cin >> a)
            cout << a;

        try {
                my_func();
        } catch (int e) {
		cout << "exception:" << e;
        }
}

