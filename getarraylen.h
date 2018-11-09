/*
	Library name: <getarraylen.h>
        Author: Rub!ck


        Description:
	*Just use the function getArrayLen( any_type_array ) and it returns you array lenght.
*/




#ifndef GETARRAYLEN
#define GETARRAYLEN

template <typename TMP>
short int getArrayLen( TMP &array ){
	return sizeof(array) / sizeof(array[0]);
}

#endif //GETARRAYLEN
