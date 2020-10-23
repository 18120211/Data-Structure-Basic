#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct NODE {
	int key;
	NODE* pNext;
};
struct List {
	NODE* pHead;
	NODE* pTail;
};

List* createList()
{
	List *l = new List;
	l->pHead = l->pTail = NULL;
	return l;
}

NODE* createNode(int data)
{
	NODE *p = new NODE;
	p->key = data;
	p->pNext = NULL;
	return p;
}

bool addHead(List* &L, int Data)
{
	NODE *p = createNode(Data);
	if (p == NULL) {
		return false;
	}
	if (L->pHead = NULL) {
		L->pHead = L->pTail = p;
	}
	else {
		p->pNext = L->pHead;
		L->pHead = p;
	}
	return true;
}

bool addTail(List* &L, int Data)
{
	NODE *p = createNode(Data);
	if (p == NULL) {
		return false;
	}
	if (L->pHead == NULL) {
		L->pHead = L->pTail = p;
	}
	else {
		L->pTail->pNext = p;
		L->pTail = p;
	}
	return true;
}

void removeHead(List* &L)
{
	NODE *p = L->pHead;
	L->pHead = L->pHead->pNext;
	delete(p);
}

void removeTail(List* &L)
{
	NODE *p = L->pHead;
	while (p != NULL) {
		if (p->pNext = L->pTail) {
			NODE *q = L->pTail;
			L->pTail = p;
			delete(q);
			return;
		}
		p = p->pNext;
	}
}

void removeAll(List* &L)
{
	NODE *p = L->pHead;
	while (p != NULL) {
		NODE *q = p;
		p = p->pNext;
		delete(q);
	}
}

void printList(List* L)
{
	NODE *p = L->pHead;
	while (p != NULL) {
		cout << p->key << " ";
		p = p->pNext;
	}
}

int countElements(List* L)
{
	int count = 0;
	NODE *p = L->pHead;
	while (p != NULL) {
		count++;
		p = p->pNext;
	}
	return count;
}

List* reverseList(List* L)
{
	List *L2 = createList();
	NODE *p = L->pHead, *p2 = L2->pHead;
	int a[100];
	int n = countElements(L);
	int count = 0;
	while (p != NULL) {
		a[count] = p->key;
		p = p->pNext;
		count++;
	}
	for (int i = 0; i < n; i++) {
		addTail(L2, a[i]);
	}
	return L2;
}

void removeDuplicate(List* &L)
{
	NODE *p;
	for (p = L->pHead; p != NULL; p = p->pNext) {
		for (NODE *q = p->pNext; q != NULL; q = q->pNext) {
			if (q->key == p->key) {
				for (NODE *k = L->pHead; k != NULL; k = k->pNext) {
					if (k->pNext == q) {
						k->pNext = q->pNext;
						break;
					}
				}
			}
		}
	}
}

bool removeElement(List* &L, int key)
{
	if (L->pHead->key == key) {
		NODE *temp = L->pHead;
		L->pHead = L->pHead->pNext;
		delete(temp);
	}
	NODE *p = L->pHead;
	for (p; p != NULL; p = p->pNext) {
		if (p->key == key) {
			for (NODE *q = L->pHead; q != NULL; q = q->pNext) {
				if (q->pNext == p) {
					q->pNext = p->pNext;
					break;
				}
			}
		}
	}
	return true;
}

int main()
{
	List *L = createList();
	addTail(L, 3);
	addTail(L, 3);
	addTail(L, 3);
	addTail(L, 3);
	addTail(L, 1);
	/*addTail(L, 1);
	addTail(L, 4);
	addTail(L, 5);*/
	removeElement(L, 3);
	printList(L);
	system("pause");
	return 1;
}