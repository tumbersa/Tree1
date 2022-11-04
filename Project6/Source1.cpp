#include <iostream>
using namespace std;
using tElem = int;
struct Tree {
	tElem key;
	Tree* left= nullptr, * right= nullptr;
};

bool isEmpty(Tree* root) {
	return root == nullptr;
}

void push(int a, Tree*& t)
{
	if (isEmpty(t))                   
	{
		t = new Tree;               
		t->key = a;                
		t->left = t->right = nullptr;   
		return;                         
	}
	if (a > t->key) push(a, t->right); 
	if (a< t->key) push(a, t->left);
	if (a == t->key) return;                 
}
void printlev(Tree* t) {
	while (t->left) {
		t = t->left;
	}
	cout << "leftmost list " << t->key << endl;
}


void print(Tree* t, int u=0)
{
	if (t == NULL) return;                 
	else 
	{
		print(t->left, ++u);    
		cout << u-1 <<" level  ";
		cout << t->key << endl;           
		u--;
	}
	print(t->right, ++u);
}


int heigh(Tree* root)
{
	if (root == NULL) {
		return 0;
	}
	else if (root->left == NULL && root->right == NULL) {
		return 0;
	}
	else if (heigh(root->left) > heigh(root->right))
		return heigh(root->left) + 1;
	else
		return heigh(root->right) + 1;

}

Tree* search(Tree* root, tElem x) {
	Tree* pv = root, * prev;
	bool found = false;
	while (pv && !found) {
		prev = pv;
		if (pv->key == x)
			found = true;
		else if (x < pv->key)
			pv = pv->left;
		else pv = pv->right;
	}
	if (found) return pv;
}
int main() {
	Tree* root = nullptr;

	for (int i = 0; i < 5; i++) {
		push(i, root);
		push(-i, root);
	}
	Tree* boot = search(root, -2);
	print(boot);
	printlev(root);
	print(root);
	cout<<heigh(root);
}