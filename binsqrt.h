/*
	Library name: <binsqrt.h>
        Author: Rub!ck


        Description:
	*Binary finding sqrt from long long int.


	Example:
	int main(void) {
		printf("Sqrt from %lld:  %lld\n", 9999 * 9999, bin_sqrt(9999 * 9999));
		// output:
		// 99980001
		// 9999
		return(0);
	}
*/



#ifndef BIN_SQRT
#define BIN_SQRT

#define BIG_INT long long int


BIG_INT bin_sqrt(const BIG_INT x) {
	static BIG_INT key_min[2] = {0, -1};
	BIG_INT key_max = x;
	static BIG_INT key_middle[2];


	while ((key_min[0] <= key_max) && (key_min[0] * key_min[0] != x)) {

		key_middle[0] = (key_min[0] + key_max) / 2;
		key_middle[1] = key_middle[0] * key_middle[0];


		if (key_middle[1] > x)
			key_max = key_middle[0] - 1;
		else
			key_min[0] = key_middle[0] + (key_middle[0] < x);
	}

	return key_min[(key_min[0] * key_min[0] != x)];
}



#endif // BIN_SQRT
