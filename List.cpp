#include "List.h"
List::List()
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
}
List::List(int n) //формирует список из n случайных чисел
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
	int x, i;
	for (i = 0; i<n; i++)
	{
		x = rand() % 20;
		AddToTail(x);
	}
}
List::List(int *a, int n){} //формирует список из массива n чисел
List::List(List& S){}
List::~List(){}
List & List::operator=(List &S){}
void List::AddAfter(int k, Node *pr){} //добавление узла после pr
void List::Del(Node *p){} //удаление узла p
Node * List::Max(){} //нахождение max эл-та списка
void List::Scan(int){}
std::istream& operator>> (std::istream& r, List &S){}