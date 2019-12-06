#pragma once
class Node
{
	int key;
	Node *prev, *next;
public:
	Node()
	{
		key = -1; prev = nullptr; next = nullptr;
	}
	Node(int k, Node *Pr, Node *Nxt)
	{
		key = k; prev = Pr; next = Nxt;
	}
	int &Key() { return key; }
	friend class List;
};