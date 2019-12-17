#pragma once
#include "Node.h"
#include <iostream>
class List
{
private:
	Node *head, *tail;
public:
	List();
	List(int n); //��������� ������ �� n ��������� �����
	List(int *a, int n); //��������� ������ �� ������� n �����
	List(List&);
	~List();
	List& operator= (List &);

	void AddAfter(int k, Node *pr); //���������� ���� ����� pr
	void AddToHead(int k);  //���������� ��-�� � ������
	void AddToTail(int k);  //���������� ��-�� � �����
	void AddAfter(List S, Node *pr); //���������� ������ S ����� pr
	void AddToHead(List&);  //���������� ������ � ������
	void AddToTail(List&);  //���������� ������ � �����

	void Del(Node *p); //�������� ���� p
	void DelHead();    //�������� ������
	void DelTail();    //�������� ������
	void Clear();
	Node* FindKey(int k); //����� �� �����
	Node* operator[] (int pos);

	bool IsEmpty();
	bool IsNotEmpty();
	bool operator== (List);
	bool operator!= (List);

	Node* Max();  //���������� max ��-�� ������
	Node* Min();  //���������� min ��-�� ������

	void Scan();
	void Print();

	friend std::ostream& operator<< (std::ostream& r, List& S);
	friend std::istream& operator>> (std::istream &r, List& S);

};
