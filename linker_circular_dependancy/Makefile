#CC=gcc
CC=arm-linux-androideabi-gcc

all:
	$(CC) -c -fPIC a.c
	$(CC) -c -fPIC b.c
	$(CC) -o libb.so -shared b.o
	$(CC) -o liba.so -shared a.o -L. -lb
	$(CC) -o c c.c -ldl

clean:
	rm -rf *.o *.so a.out c
	
transfer:
	adb push liba.so /tmp/liba.so
	adb push libb.so /tmp/libb.so
	adb push c /tmp/c
