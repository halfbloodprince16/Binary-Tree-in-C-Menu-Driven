#include"bits/stdc++.h"
using namespace std;

struct node
{
	char c;
	node* left;
	node* right;
};


struct node* root = NULL;

node* insert()
{
	std::stack<node* >s;
	string str;
	cout<<"Enter a Postfix exprssn";
	cin>>str;
	int i,j;
	node *a,*b;
	for(i=0;i<str.length();i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			node *p = new node();
			p->c = str[i];
			s.push(p);
		}
		else
		{
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();
			node *p = new node();
			p->c = str[i];
			p->left = a;
			p->right = b;
			s.push(p);
		}
	}
	root = s.top();
	return root;
}

void display(node* ptr,int level)
{
	int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level; i++)
                cout<<"       ";
        }
        cout<<ptr->c;
        display(ptr->left, level+1);
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
	int ch;
	do
	{
		cout<<"1:insert\n2:display";
		cin>>ch;
		switch(ch)
		{
			case 1:root = insert();break;
			case 2:display(root,1);break;
		}
	}
	while(ch!=3);
	return 0;
}