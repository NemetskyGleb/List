#include "List.h"
List::List()
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
}
List::List(int n) //��������� ������ �� n ��������� �����
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
List::List(int *a, int n){} //��������� ������ �� ������� n �����
List::List(List& S){}
List::~List(){}
List & List::operator=(List &S){}
void List::AddAfter(int k, Node *pr){} //���������� ���� ����� pr
void List::Del(Node *p){} //�������� ���� p
Node * List::Max(){} //���������� max ��-�� ������
void List::Scan(int){}
std::istream& operator>> (std::istream& r, List &S){}