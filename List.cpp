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
List::List(int *a, int n){
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
	for (int i = 0; i < n; i++)
		AddToTail(a[i]);
} //формирует список из массива n чисел
List::List(List& S){
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
	Node *p;
	for (p = S.head->next; p != S.tail; p = p->next)
		AddToTail(p->Key());
}
List::~List(){
	Node* temp = head;
	head = head->next;
	while (head)
	{
		delete temp;
		temp = head;
		head = head->next;
	}
}
List & List::operator=(List& S){
	if (this != &S)
	{
		Del();
		Node* p;
		for (p = S.head->next; p != S.tail; p = p->next)
			AddToTail(p->Key());
	}
	return *this;
}
//void List::AddAfter(int k, Node *pr){}

void List::AddToHead(int k){
	Node *temp = new Node(k, head, head->next);
	head->next->prev = temp;
	head->next = temp;
}
void List::AddToTail(int k){
		Node* temp = new Node(k, tail->prev, tail);
		tail->prev->next = temp;
		tail->prev = temp;
}
void List::AddToHead(List& S){
	Node* p;
	for (p = S.head->next; p != S.tail; p = p->next)
		AddToTail(p->Key());
}
void List::AddToTail(List& S){
	Node* p;
	for (p = S.tail->prev; p != S.head; p = p->prev)
		AddToHead(p->Key());
}
//void List::AddAfter(int k, Node *pr){} //добавление узла после pr
//void List::Del(Node *p){} //удаление узла p
Node* List::FindKey(int k){
	if (head == NULL){
		std::cout << "List is empty" << std::endl;
		return NULL;
	}	
	Node *temp;
	for (temp = head->next; temp && temp->Key() != k; temp = temp->next);
	return temp;
}
Node* List::operator[] (int pos) {
	if (pos >= 0)
	{
		Node* temp = head->next;
		for (int i = 0; i != pos && temp != tail; temp = temp->next, i++);
		return temp;
	}
}
void List::DelHead(){
	Node *q = head->next;
	if (q != tail)
	{
		head->next = q->next;
		q->next->prev = head;
		delete q;
	}
}
void List::DelTail(){
	Node *q = tail->prev;
	if (q != head)
	{
		q->prev->next = tail;
		tail->prev = q->prev;
		delete q;
	}
}
void List::Del(){
	Node *q = head->next, *p;
	head->next = tail;
	tail->prev = head;
	while (q != tail)
	{
		p = q;
		q = q->next;
		delete p;
	}
}
//Node * List::Max(){} //нахождение max эл-та списка
bool List::IsEmpty(){
	if (head->next->next == NULL) return true;
	return false;
}
bool List::IsNotEmpty(){
	if (head->next->next == NULL) return false;
	return true;
}
void List::Scan(){
		int n;
		int key;
		std::cout << "Enter N = ";
		std::cin >> n;
		Del();
		for (int i = 0; i < n; i++)
		{
			std::cout << "Enter key = ";
			std::cin >> key;
			AddToTail(key);
		}
		std::cin.get();
}
std::istream& operator>> (std::istream& r, List &S){
	S.Scan();
	return r;
}
void List::Print(){
	Node* temp;
	for (temp = head->next; temp != tail; temp = temp->next)
		std::cout << temp->Key() << "  ";
	std::cout << std::endl;
}
std::ostream& operator<<(std::ostream& r, List& S){
	S.Print();
	return r;
}