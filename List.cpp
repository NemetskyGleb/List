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
	Clear();
	delete head;
	delete tail;
}
List & List::operator=(List& S){
	if (this != &S)
	{
		Clear();
		Node* p;
		for (p = S.head->next; p != S.tail; p = p->next)
			AddToTail(p->Key());
	}
	return *this;
}
void List::AddAfter(int k, Node *pr){
	Node* q = new Node;
	q->key = k;
	q->next = pr->next;
	pr->next = q;
}
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
	Node* q = S.head->next;
	while (q != S.tail)
	{
		AddToHead(q->key);
		q = q->next;
	}
}
void List::AddToTail(List& S){
	Node* q = S.head->next;
	while (q != S.tail)
	{
		AddToTail(q->key);
		q = q->next;
	}
}
void List::AddAfter(List S, Node *pr){
	Node* q = S.head->next;
	while (q != S.tail){
		AddAfter(q->key, pr);
		pr = pr->next;
	}
}
void List::Del(Node *p){
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
} //удаление узла p
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
	else {
		std::cout << "Position not found" << std::endl;
		return 0;
	}
}
void List::DelHead(){
	Del(head->next);
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
void List::Clear(){
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
Node* List::Max(){
	Node *max = nullptr;
	Node *q = head->next;
	if (q != tail) { max = q; q = q->next; }
	while (q != tail){
		if (max->key < q->key) max = q;
		q = q->next;
	}
	return max;
}
Node* List::Min(){
	Node *min = nullptr;
	Node *q = head->next;
	if (q != tail) { 
		min = q; q = q->next;
	}
	while (q != tail){
		if (min->key > q->key) min = q;
		q = q->next;
	}
	return min;
}
bool List::IsEmpty(){
	if (head->next == tail) return true;
	return false;
}
bool List::IsNotEmpty(){
	if (head->next == tail) return true;
	return false;
}
bool List::operator==(List S){
	Node* t = head->next;
	Node* q = S.head->next;
	while (t->key == q->key && t != tail && q != S.tail){
		t = t->next; 
		q = q->next;
	}
	if (t == tail && q == S.tail) return true;
	else return false;
}
bool List::operator!=(List S){
	if (*this == S) return false;
	else return true;
}
void List::Scan(){
		int n;
		int key;
		std::cout << "Enter N = ";
		std::cin >> n;
		Clear();
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