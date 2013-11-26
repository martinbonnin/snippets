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
	
ADB_DIR=/data/martin/

transfer:
	adb push liba.so $(ADB_DIR)/liba.so
	adb push libb.so $(ADB_DIR)libb.so
	adb push c $(ADB_DIR)/c
