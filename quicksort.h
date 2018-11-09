/*
	Library name: <quicksort.h>
        Author: Rub!ck


        Description:
	*Just use quickSort( array_of_signed_elements, 0, count_of_array ) and the function sort it very fast!
*/




#ifndef QUICKSORT
#define QUICKSORT

void swap( int *a, int *b ){
    int t = *a;
    *a = *b;
    *b = t;
}




short int partition( int *arr, short int low, short int high ){
    unsigned short int pivot = arr[high];
    short int i = ( low - 1 );

    for( short int j = low; j <= high - 1; ++j ){
        if( arr[j] <= pivot ){
            ++i;
            swap( &arr[i], &arr[j] );
        }
    }
    swap( &arr[i + 1], &arr[high] );
    return( i + 1 );
}




void quickSort( int *arr, short int low, short int count ){
    if( low < count ){
        short int pi = partition( arr, low, count );
        quickSort( arr, low, pi - 1 );
        quickSort( arr, pi + 1, count );
    }
}

#endif //QUICKSORT
