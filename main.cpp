#include "List.h"
#include <iostream>

int main(){
	using namespace std;
	List S1;
	S1.AddToHead(1);
	S1.AddToTail(10);
	cout << "S1: ";
	S1.Print();
	List S2(5);
	cout << "S2: " << S2;
	Node* q = S2.Max();
	cout << "Max in S2: " << q->Key() << endl;
	q = S2.Min();
	cout << "Min in S2: " << q->Key() << endl;
	q = S2[2];
	cout << "2-nd(3) element in S2:  " << q->Key() << endl;
	q = S2[6];
	cout << "6 position in S2: " << q->Key() << endl;
	S2.DelTail();
	cout << "S2 after delete tail: " << S2;
	List S3 = S1;
	S3.AddToHead(2);
	cout << "S3 == S1 : " << std::endl;
	(S3 == S1) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
	q = S3.FindKey(15);
	cout << "S3.FindKey(15):  ";
	if (q == NULL) cout << "Element is not found" << endl;
	else cout << q->Key();
	cout << S3;
	S3.DelHead();
	q = S3.FindKey(10);
	if (q == NULL) cout << "Element is not found" << endl;
	else S3.Del(q);
	cout << "S3: " << S3;
	if (S3.IsEmpty()) cout << "S3 is empty" << endl;
	else cout << "S3 isn't empty " << endl;
	int a[6];
	for (int i = 0; i < 6; i++)
		a[i] = rand() % 20;
	List S4(a, 6);
	cout << "S4: " << S4;
	q = S4.FindKey(2);
	if (q == 0) S4.AddToHead(2);
	else S4.Del(q);
	cout << "S4: " << S4;
	List S5 = S2;
	cout << "S5: " << S5;
	q = S5.FindKey(4);
	cout << "Element 4 in S5?" << endl;
	if (q == 0) S5.AddToTail(4);
	else S5.Del(q);
	cout << "S5: " << S5;
	S5.Clear();
	S5.Scan();
	cout << "S4 == S5 : ";
	(S4 == S5) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
	S5.AddToTail(S4);
	cout << "S5.AddToTail(S4): " << S5;
	S5.AddToHead(S1);
	cout << "S5.AddToHead(S1):  " << S5;
	cin.get();
	return 0;
}