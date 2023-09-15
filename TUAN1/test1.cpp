#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdio>
#include<stdlib.h>

using namespace std;
struct Node {
	int data;
	Node* next;
};

Node* CreateNode(int x) {
	Node* p;
	p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}
struct LinkedList
{
	Node* head;
	Node* tail;
};
void CreateList(LinkedList& l) {
	l.head = NULL;
	l.tail = NULL;
}

void AddHead(LinkedList& l, Node* p) {
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = p;
	}
	else {
		p->next = l.head;
		l.head = p;
	}
}
void AddTail(LinkedList& l, Node* p) {
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
	}
	else {
		l.tail->next = p;
		l.tail = p;
	}
}

void Nhap(LinkedList& l, int n) {
	for (int i = 0; i < n; i++) {
		int x;
		cout << " Nhap gia tri x ";
		cin >> x;
		CreateNode(x);
	}
}
void PrintList(LinkedList l) {
	if (l.head != NULL) {
		Node* p = l.head;
		while (p != NULL) {
			cout << p->data << ' ' << endl;
			p = p->next;
		}

	}
}
void Insert(LinkedList& l, Node* p, Node* q) {
	if (q != NULL) {
		p->next = q->next;
		q->next = p;
		if (q == l.tail) {
			l.tail = p;
		}
	}
	else {
		AddHead(l, p);
	}
}

Node* Count(LinkedList l, int k) {
	int count = 0;
	for (Node* p = l.head; p != NULL; p = p->next) {
		if (p->data == k) {
			count++;
		}
	}
	cout << " Gia tri xuat hien " << count << " lan " << endl;
	return NULL;
}
void reversed(LinkedList& l) {
	Node* current = l.head;
	Node* prev = NULL;
	Node* next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	l.head = prev;
}
void XoaDau(LinkedList& l) {
	Node* p = new Node;
	p = l.head;
	l.head = l.head->next;
	p->next = NULL;
	delete p;
}
void XoaCuoi(LinkedList& l)
{
	//duyet cac phan tu co trong danh sach
	for (Node* p = l.head; p != NULL; p = p->next)
	{
		//neu duyet den phan tu pTail cuoi trong danh sach
		if (p->next == l.tail)
		{
			//xoa phan tu cuoi
			delete p;
			//tro phan tu truoc phan tu cuoi ve NULL
			p->next = NULL;
			//thay doi lai phan tu cuoi pTail cua danh sach
			l.tail = p;
		}
	}
}
void XoaKhoaK(LinkedList l, int data) {
	//tao node p de luu tru phan tu truoc node k can xoa
	Node* p = new Node;
	//neu data dau vao bang voi pHead->data thi xoa dau
	if (l.head->data == data) {
		//goi ham xoa dau
		XoaDau(l);
		//ket thuc ham
		return;
	}
	//neu data bang voi pTail->data thi xoa cuoi
	if (l.tail->data == data) {
		//goi ham xoa cuoi
		XoaCuoi(l);
		//ket thuc ham
		return;
	}
	//duyet qua cac phan tu co trong danh sach
	for (Node* k = l.head; k != NULL; k = k->next) {
		//neu tim thay data trung voi k->data dang duyet
		if (k->data == data) {
			//gan con tro next cua node p bang con tro next cua node k
			p->next = k->next;
			//xoa di node k
			delete k;
			//ket thuc ham
			return;
		}
		//gan node p bang node k de node p luon la node dung truoc node k
		p = k;
	}
}
int main() {
	LinkedList list;
	CreateList(list);
	PrintList(list);
	int n;
	cout << " Nhap so gia tri ";
	cin >> n;
	Nhap(list, n);
	PrintList(list);
	int k;
	cout << " Nhap gia tri can tim " << endl;
	cin >> k;
	Count(list, k);
	int u;
	cout << " Nhap phan tu them vao dau danh sach lien ket " << endl;
	cin >> u;
	Node* p = new Node;
	p = CreateNode(u);
	AddHead(list, p);
	cout << "Danh sach lien ket khi them phan tu vao dau " << endl;
	PrintList(list);
	cout << " Nhap phan tu them vao cuoi danh sach lien ket " << endl;
	int j;
	cin >> j;
	p = CreateNode(j);
	AddTail(list, p);
	cout << "Danh sach lien ket khi them phan tu vao cuoi " << endl;
	PrintList(list);
	cout << "Danh sach lien ket khi dao nguoc " << endl;
	reversed(list);
	PrintList(list);
	cout << "Danh sach lien ket khi xoa dau " << endl;
	XoaDau(list);
	PrintList(list);
	cout << "Danh sach lien ket khi xoa cuoi " << endl;
	XoaCuoi(list);
	PrintList(list);
	int data;
	cout << " Nhap so can xoa " << endl;
	cin >> data;
	XoaKhoaK(list, data);
	cout << "Danh sach lien ket khi xoa phan tu k " << endl;
	PrintList(list);
	int x;
	cin >> x;
	int y;
	cin >> y;
	p = CreateNode(x);
	Node* q = new Node;
	q = CreateNode(y);
	Insert(list, p, q);
	PrintList(list);
	cout << endl;
}