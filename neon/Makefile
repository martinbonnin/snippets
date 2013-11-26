CC=/usr/local/home/martin/toolchains/arm-linux-androideabi-4.6/bin/arm-linux-androideabi-gcc
CFLAGS=-mfpu=neon -march=armv7-a -I/tmp/tmp.ffmpeg.PHRpQX/armeabi-v7a/

neon: main.o dsp.o 
	$(CC) -o neon main.o dsp.o
	
dsp.o: dsp.S
	$(CC) $(CFLAGS) -c -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	rm neon *.o
