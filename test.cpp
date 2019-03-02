#include "aes.h"
#include <stdio.h>
using namespace std;

#define LEN 128

int main() {
	uint8_t key[32];
	for (register short i = 0; i < 32; ++i)
		key[i] = 'A';


	uint8_t buf[LEN];
	for (register short i = 0; i < LEN; ++i)
                buf[i] = '|';
	printf("%s\n", buf);

	uint8_t* initedKey = aes::initKey(key);

	for(register short i = 0; i < LEN; i += 16) {
		aes::encrypt(buf + (LEN-(LEN-i)), buf + (LEN-(LEN-i)), initedKey);
	}
	printf("%s\n", buf);

	for(register short i = 0; i < LEN; i += 16) {
                aes::decrypt(buf + (LEN-(LEN-i)), buf + (LEN-(LEN-i)), initedKey);
        }
        printf("%s\n", buf);
}
