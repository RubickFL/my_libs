/*
	Library name: <cachelinesize.h>
        Author: Rub!ck


        Description:
	*Just use the function getArrayLen( any_type_array ) and it returns you array lenght.


	Example:
	int main(void) {
		int arr[100];
		cout << "Arr len: " << getArrayLen(arr) << endl;
	}
*/




#ifndef GETARRAYLEN
#define GETARRAYLEN

template <typename TMP>
short int getArrayLen( TMP &array ){
	return sizeof(array) / sizeof(array[0]);
}

#endif //GETARRAYLEN
