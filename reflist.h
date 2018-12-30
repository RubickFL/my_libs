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
