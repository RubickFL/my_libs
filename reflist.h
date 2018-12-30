/*
	Library name: <reflist.h>
	Author: Rub!ck

	Description:
	Referense List heap data struct with smart destructor

	Example:
	int main(void) {
		RefList<int> *rl = new RefList<int>(100);
		rl->newElement(-100);
		delete rl;
	}
*/



#ifndef REFLIST
#define REFLIST RefList<TMP>



template<typename TMP>

class RefList {
public:
	// headder
	REFLIST* next;
	TMP content;



	// construct and smart destruct
	RefList(TMP a) {
                content = a;
        }


	~RefList() {
		if (next != NULL)
                        delete next;
	}



	// iterators
	REFLIST* first() {
                return this;
        }


	REFLIST* last() {
		REFLIST* p = first();
                while (p->next != NULL)
                        p = p->next;
		return p;
	}



	// elements methods
	int count() {
		REFLIST* p = first();
		int i = 1;
                for (;p->next != NULL; ++i)
                        p = p->next;

		return i;
	}


	void add(TMP a) {
		(last())->next = new REFLIST(a);
	}


	REFLIST* at(int index) {
		REFLIST* p = first;
		for (;index > 0 && p->next != NULL; --index) {
			p = p->next;
		}

		if (index == 0)
			return p;

		return NULL;
	}


	REFLIST* findElement(REFLIST* elem) {
		REFLIST* p = first();
                while (p->next != elem && p->next != NULL)
                        p = p->next;

                if (p == elem)
			return p;

		return NULL;
	}


	REFLIST* findContent(TMP a) {
		REFLIST* p = first();
                while (p->next != NULL && p->content != a)
                        p = p->next;

		if (p->content == a)
                	return p;

		return NULL;
	}
};



#endif // REFLIST
