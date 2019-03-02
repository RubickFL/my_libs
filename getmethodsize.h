/*
	*Copyright (c) 2019 <Rubick>
	*Function gets pointer to else method and returns method size by bytes

	*Usage:
	*int size = getMethodSize((unsigned char*) &myFunction);
*/


#ifndef GMS
#define GMS
#define ret 0xc3


long long int getMethodSize(unsigned char* method) {
	register long long int counter = 1;

	for (; *method != ret; ++counter) {
		method += 0x01;
	}

	return counter;
}

#endif // GMS
