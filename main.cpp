#include "List.h"
#include <iostream>

int main(){
	using namespace std;
	List L(10);
	cout << L;
	List A(11);
	L.AddToTail(A);
	cout << L;
	List B(2);
	B.AddToHead(2);
	cout << B;
	cout << B;
	if (B.IsEmpty()) std::cout << "true"; else std::cout << "false";
	cin.get();
	return 0;
}