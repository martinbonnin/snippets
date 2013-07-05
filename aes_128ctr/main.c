#include <openssl/aes.h>
#include <openssl/crypto.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

static const uint8_t _key[] = 
{
0x4c, 0xda, 0xd6, 0x21, 0xc6, 0x8f, 0xbb, 0xd2,
0x85, 0xc3, 0x63, 0x73, 0x7f, 0x96, 0x6f, 0x1e
};

inline int c2hex (int c)
{
    c -= '0';
    if (c > 9)
	c += '0' - 'A' + 10;
    return c & 15;
}

inline int hex2c (int c)
{
    if ((c &= 15) < 10)
	return '0' + c;
    else
	return 'A' + c - 10;
}

int hex2bin (const char *phex, unsigned char *pbin, int size)
{
    int i;

    for (i = 0; i < size; i++, phex += 2, pbin++) {
    	*pbin = (unsigned char)(c2hex (phex[0]) * 16 + c2hex (phex[1]));
    }

    return i;
}

int main(int argc, char **argv) 
{
    unsigned char in[4096];
    unsigned char out[4096];
    int ret;
    AES_KEY key;
	unsigned char ivec[AES_BLOCK_SIZE] = {0};
	unsigned char ecount_buf[AES_BLOCK_SIZE] = {0};
	unsigned int num = 0;

    if (argc < 2) {
        printf("%s iv, where iv is the hex representation of the iv\n", argv[0]);
        exit(1);
    }
    
    if (strlen(argv[1]) != 2 * AES_BLOCK_SIZE) {
        printf("The iv must be 16 bytes long\n");
        exit(1);
    }
    
    hex2bin(argv[1], ivec, AES_BLOCK_SIZE);
    
    AES_set_encrypt_key(_key, 128, &key); 
    
    while ((ret = read(0, in, 4096)) > 0) {
        AES_ctr128_encrypt(in, out, ret, &key, ivec, ecount_buf, &num);
        write(1, out, ret);
    }
    
    return 0;    
}
