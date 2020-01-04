#include <iostream>
#include <stdlib.h>
using namespace std;

struct NODE
{
	int key;
	NODE* p_left;
	NODE* p_right;
	int height;
};

NODE* CreateNode(int data)
{
	NODE * p = new NODE;
	p->key = data;
	p->p_left = p->p_right = NULL;
	return p;
}

void rotateLeft(NODE *& p)
{
	NODE * q = p->p_right;
	if (q == NULL) return;
	p->p_right = q->p_left;
	q->p_left = p;
	p = q;
}

void rotateRight(NODE *& p)
{
	NODE * q = p->p_left;
	if (q == NULL) return;
	p->p_left = q->p_right;
	q->p_right = p;
	p = q;
}

int height(NODE * p)
{
	if (p == NULL) return 0;
	return (height(p->p_left) >= height(p->p_right) ? height(p->p_left) : height(p->p_right)) + 1;	
}

int CalDiffLeftToRight(NODE * p)
{
	return height(p->p_left) - height(p->p_right);
}

void balance(NODE *& p)
{
	if (CalDiffLeftToRight(p) > 1) { //Lech trai
		if (CalDiffLeftToRight(p->p_left) < 0) { // Lech trai-phai
			rotateLeft(p->p_left);
			rotateRight(p);
		}
		else { //Lech trai-trai
			rotateRight(p);
		}
	}
	else if (CalDiffLeftToRight(p) < -1) { //Lech phai
		if (CalDiffLeftToRight(p->p_right) < 0) { // Lech phai-trai
			rotateRight(p->p_right);
			rotateLeft(p);
		}
		else { //Lech phai-phai
			rotateLeft(p);
		}
	}
}

void Insert(NODE* &p_root, int x)
{
	if (p_root == NULL) {
		p_root = CreateNode(x);
		return;
	}
	if (x > p_root->key) {
		Insert(p_root->p_right, x);
	}
	else if (x < p_root->key) {
		Insert(p_root->p_left, x);
	}
	else {
		cout << "Da ton tai node mang gia tri nay";
	}
	return balance(p_root);
}

void Remove(NODE* &p_root, int x)
{
	if (p_root == NULL) {
		cout << "Khong tim thay node can xoa" << endl;
		return;
	}
	else if (x == p_root->key) {
		if (p_root->p_left == NULL) {
			p_root = p_root->p_right;
			return;
		}
		else if (p_root->p_right == NULL) {
			p_root = p_root->p_left;
			return;
		}
		else {
			NODE * temp = p_root->p_right;
			int k = 0;
			while (temp->p_left != NULL) {
				temp = temp->p_left;
				k++;
			}
			p_root->key = temp->key;
			if (k != 0) {
				NODE * p = p_root->p_right;
				while (p->p_left != temp) {
					p = p->p_left;
				}
				p->p_left = temp->p_right;
				return;
			}
			else {
				p_root->p_right = temp->p_right;
				return;
			}
			k = 0;
		}
	}
	else if (x > p_root->key) {
		Remove(p_root->p_right, x);
	}
	else {
		Remove(p_root->p_left, x);
	}
	balance(p_root);
}

bool IsBST(NODE* p_root)
{
	if (p_root == NULL) return true;
	else {
		IsBST(p_root->p_left);
		if (p_root->p_left != NULL && p_root->p_right != NULL) {
			if (p_root->p_left->key < p_root->key && p_root->key < p_root->p_right->key) {
				return true;
			}
			return false;
		}
		else if (p_root->p_left == NULL && p_root->p_right != NULL) {
			if (p_root->key < p_root->p_right->key) {
				return true;
			}
			return false;
		}
		else if (p_root->p_left != NULL && p_root->p_right == NULL) {
			if (p_root->key > p_root->p_left->key) {
				return true;
			}
			return false;
		}
		IsBST(p_root->p_right);
	}
	return false;
}

bool IsAVL(NODE* p_root)
{
	if (IsBST(p_root) == false) return false;
	if (p_root == NULL) return true;
	else {
		IsAVL(p_root->p_left);
		if (CalDiffLeftToRight(p_root) > 1 || CalDiffLeftToRight(p_root) < -1) {
			return false;
		}
		return true;
		IsAVL(p_root->p_right);
	}
}

void NLR(NODE* p_root) // Duyet truoc
{
	if (p_root == NULL) return;
	cout << p_root->key << endl;
	NLR(p_root->p_left);
	NLR(p_root->p_right);
}
	
void LNR(NODE* p_root) // Duyet giua
{
	if (p_root == NULL) return;
	LNR(p_root->p_left);
	cout << p_root->key << endl;
	LNR(p_root->p_right);
}

void LRN(NODE* p_root) // Duyet sau
{
	if (p_root == NULL) return;
	LRN(p_root->p_left);
	LRN(p_root->p_right);
	cout << p_root->key << endl;
}

void printGivenOrder(NODE * p, int h)
{
	if (p == NULL) return;
	if (h == 1) cout << p->key << endl;
	else if (h > 1) {
		printGivenOrder(p->p_left, h - 1);
		printGivenOrder(p->p_right, h - 1);
	}
}

void LevelOrder(NODE* p_root)
{
	int h = height(p_root);
	for (int i = 1; i <= height(p_root); i++) {
		printGivenOrder(p_root, i);
	}
}

int main()
{
	NODE * p = CreateNode(2);
	Insert(p, 3);
	Insert(p, 1);
	Insert(p, 5);
	Insert(p, 7);
	NLR(p);
	system("pause");
	return 0;
}