#pragma once
#include "Node.h"
#include <iostream>
class List
{
private:
	Node *head, *tail;
public:
	List();
	List(int n); //формирует список из n случайных чисел
	List(int *a, int n); //формирует список из массива n чисел
	List(List&);
	~List();
	List& operator= (List &);

	void AddAfter(int k, Node *pr); //добавление узла после pr
	void AddToHead(int k);  //добавление эл-та в голову
	void AddToTail(int k);  //добавление эл-та в хвост
	void AddAfter(List S, Node *pr); //добавление списка S после pr
	void AddToHead(List&);  //добавление списка в голову
	void AddToTail(List&);  //добавление списка в хвост

	void Del(Node *p); //удаление узла p
	void DelHead();    //удаление головы
	void DelTail();    //удаление хвоста
	void Clear();
	Node* FindKey(int k); //поиск по ключу
	Node* operator[] (int pos);

	bool IsEmpty();
	bool IsNotEmpty();
	bool operator== (List);
	bool operator!= (List);

	Node* Max();  //нахождение max эл-та списка
	Node* Min();  //нахождение min эл-та списка

	void Scan();
	void Print();

	friend std::ostream& operator<< (std::ostream& r, List& S);
	friend std::istream& operator>> (std::istream &r, List& S);

};
