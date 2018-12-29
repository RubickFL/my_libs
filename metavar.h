#ifndef META_VARIABLE
#define META_VARIABLE


typedef union{
	char CHAR;
	char* C_STR;
	double REAL;

} Variable_union;



class MetaVariable{
private:
	Variable_union uni;

public:
	double to_double(){
		return uni.REAL;
	}

	int to_int(){
		return to_double();
	}

	char to_char(){
		return uni.CHAR;
	}

	char* to_c_str(){
		return uni.C_STR;
	}

	bool to_bool(){
		return to_double();
	}


	void operator =(double a){
		uni.REAL = a;
	}

	void operator =(int a){
		uni.REAL = a;
	}

	void operator =(char a){
                uni.CHAR = a;
        }

	void operator =(char* a){
                uni.C_STR = a;
        }

	void operator =(bool a){
		uni.REAL = a;
	}
};


#endif
