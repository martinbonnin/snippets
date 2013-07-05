#include <cstdio>

class A {
	public:
	virtual void toto(void) throw(int);
};

void A::toto(void) throw(int)
{
	printf("toto A");
}

class B: public A {
	public:
	void tota(void);
};

void B::tota(void)
{
	printf("toto B");
}

int main(int argc, char **argv) 
{
	B b;
	b.toto();

	return 0;
}
