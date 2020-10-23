#include <stdlib.h>
#include <iostream>
using namespace std;

struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
};

NODE* CreateNode(int data)
{
	NODE * newNode = new NODE;
	newNode->key = data;
	newNode->p_left = newNode->p_right = NULL;
	return newNode;
}

void NLR(NODE* p_root)
{
	if (p_root == NULL) return;
	cout << p_root->key << endl;
	NLR(p_root->p_left);
	NLR(p_root->p_right);
}

void LNR(NODE* p_root)
{
	if (p_root == NULL) return;
	NLR(p_root->p_left);
	cout << p_root->key << endl;
	NLR(p_root->p_right);
}

void LRN(NODE* p_root)
{
	if (p_root == NULL) return;
	NLR(p_root->p_left);
	NLR(p_root->p_right);
	cout << p_root->key << endl;
}

NODE* Search(NODE* p_root, int x)
{
	if (p_root == NULL) return NULL;
	if (p_root->key == x) return p_root;
	else if (x > p_root->key) Search(p_root->p_right, x);
	else if (x < p_root->key) Search(p_root->p_left, x);
}

int Height(NODE* p_root)
{
	if (p_root == NULL) return 0;
	return Height(p_root->p_left) > Height(p_root->p_right) ? Height(p_root->p_left) : Height(p_root->p_right) + 1;
}

void Insert(NODE* &p_root, int x)
{
	if (p_root == NULL) {
		p_root = CreateNode(x);
		return;
	}
	else if (x > p_root->key) {
		Insert(p_root->p_right, x);
	}
	else if (x == p_root->key) {
		return;
	}
	else {
		Insert(p_root->p_left, x);
	}
}

NODE *& TimNodeTraiNhatBenPhai(NODE * curNode, int data)
{
	while (curNode->p_left != NULL) {
		curNode = curNode->p_left;
	}
	return curNode;
}

void Remove(NODE* &p_root, int x)
{
	if (p_root == NULL) {
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

int CountNode(NODE* p_root)
{
	if (p_root == NULL)
		return 0;
	return (CountNode(p_root->p_left) + CountNode(p_root->p_right)) + 1;
	
}

int main()
{
	return 0;
}