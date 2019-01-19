/*
        Library name: <reversestring.h>
        Author: Rub!ck


        Description:
        Just use function reverseString(string) and it reverse it!


        Example:
        int main(void) {
                string str = "EXAMPLE";
		cout << "Reverse 'example' is: " << reverseString(str) << endl;
                return 0;
        }
*/



#ifndef REVERSESTRING
#define REVERSESTRING
#include <iostream>

void reverseString( std::string &str ){
	register char tmp;
	register short int j = str.size() - 1;
	for (register short int i = 0; i < j; ++i, --j) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}


#endif // REVERSESTRING
