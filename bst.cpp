#include"bits/stdc++.h"
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* root = NULL;

class bst
{
public:

	bst()
	{

	}
	Node* newnode(int data)
	{
		Node* temp = new Node();
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	Node* insert(Node* ptr,int data)
	{
		if(ptr == NULL)
		{
			root = newnode(data);
		}
		else if(ptr->data > data)
		{
			root->left = insert(root->left,data);
		}
		else
		{
			root->right = insert(root->right,data);
		}
		return root;
	}
};

int main(int argc, char const *argv[])
{
	bst b;
	root = b.insert(root,4);
	return 0;
}