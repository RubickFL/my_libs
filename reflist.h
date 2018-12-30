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
#define REFLIST



template<typename TMP>
class RefList {
public:
	RefList<TMP>* next;
	TMP content;

	RefList(TMP a) {
                content = a;
        }


	~RefList() {
		if (next != NULL)
                        delete next;
	}


	void newElement(TMP a) {
		RefList<TMP>* p = this;
		while (p->next != NULL)
			p = p->next;
		p->next = new RefList<TMP>(a);
	}
};



#endif // REFLIST
