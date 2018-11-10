#ifndef REVERSESTRING
#define REVERSESTRING
#include <iostream>

void reverseString( std::string &str ){
	char tmp;
	short int j = str.size() - 1;
	for( short int i = 0; i <= j; ++i, --j ){
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}


#endif // REVERSESTRING
