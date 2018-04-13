#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<queue>
#include<stack>
#include<bits/stdc++.h>

using namespace std;

class node
{
   public:
	 char data;
	 node *left,*right;
	 node()
	 {
	 	left=right=NULL;
	 }
	 node(char c)
	 {
	    	data= c;
	    	left=right=NULL;
	 }
};

class exptree
{
   public:
   	 node *createpost(char []);
   	 node *createpre(char []);
   	 void preorder(node *root);
   	 void inorder(node *root);
   	 void postorder(node *root);
   	 void nonrecpreorder(node *root);
   	 void nonrecinorder(node *root);
   	 void nonrecpostorder(node *root);
};

node *exptree::createpost(char exp[])
{
	node *root,*p,*q,*r;
	char c;
	stack<node *> s;
	int i;
	for(i=0;exp[i]!='\0';i++)
	{
		c=exp[i];
		if(isalnum(c))
		{
			p=new node(c);
			s.push(p);
		}
		else
		{
			q=s.top();
			s.pop();
			r=s.top();
			s.pop();
			p=new node(c);
			p->left=r;
			p->right=q;
			s.push(p);
		}
	}
	root=s.top();s.pop();
	return root;
}
node *exptree::createpre(char exp[])
{
	
	node *pp,*qq,*rr,*root1;
	int i,l;
	char c;
	std::stack<node *> ss;
	l=strlen(exp);
	for(i=l;i>=0;i--)
	{
		c=exp[i];
		if(isalnum(c))
		{
			cout<<"HI";
			pp=new node(c);
			ss.push(pp);
		}
		else
		{
			qq=ss.top();
			ss.pop();
			rr=ss.top();
			ss.pop();
			pp=new node(c);
			pp->left=qq;
			pp->right=rr;
			ss.push(pp);
		}
	}
	root1=ss.top();
	ss.pop();
	return root1;
}

void exptree::preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"\n";
		preorder(root->left);
		preorder(root->right);
	}
}
void exptree::inorder(node *root)
{
	if(root!=NULL)
	{
		preorder(root->left);
		cout<<root->data<<" ";
		preorder(root->right);
	}
}
void exptree::postorder(node *root)
{
	if(root!=NULL)
	{
		preorder(root->left);
		preorder(root->right);
		cout<<root->data<<" ";
	}
}
void exptree::nonrecpreorder(node *root)
{
	node *p;
	p=root;
	stack<node *> s;
	while(p!=NULL)
	{
	  cout<<p->data<<" ";
	  s.push(p);
	  p=p->left;
	}
	while(!s.empty())
	{
		p=s.top();
		s.pop();
		p=p->right;
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			s.push(p);
			p=p->left;
		}
	}
}
void exptree::nonrecinorder(node *root)
{
	node *p=root;
	stack<node *> s;
	while(p!=NULL)
	{
		s.push(p);
		p=p->left;
	}
	while(!s.empty())
	{
		p=s.top();
		s.pop();
		cout<<p->data<<" ";
		p=p->right;
		while(p!=NULL)
		{
		  	s.push(p);
		  	p=p->left;
		}
	}
}
void exptree::nonrecpostorder(node *root)
{
	node *p=root;
	stack<node *> s,w;
	while(p!=NULL)
	{
		s.push(p);w.push(NULL);
		p=p->left;
	}
	while(!s.empty())
	{
		p=s.top();
		s.pop();
		if(w.top()=NULL)
		{
		     w.pop();
			s.push(p);w.push((node *)1);
			p=p->right;
			while(p!=NULL)
			{
				s.push(p);
				w.push(NULL);
				p=p->left;
			}
		}
		else
			cout<<p->data<<" ";
	}
}

int main()
{
	exptree t;
	node *root=NULL,*root1=NULL;
	char exp[30];
	int ch,a;
	do
	{
		cout<<"\n1.To create Exp tree for postfix exp\n2.To create Exp tree for prefix exp\n3.To perform recursive traversal\n4.To perform non-recursive traversal\n5.Exit";
		cout<<"\nEnter Choice: ";
		cin>>ch;
		switch(ch)
		{
		 case 1:
		 	cout<<"\nEnter postfix expression";
		 	cin>>exp;
		 	root=t.createpost(exp);
		 	break;
		 case 2:
		 	cout<<"\nEnter prefix expression";
		 	cin>>exp;
		 	root1 = t.createpre(exp);
		 	break;
		 case 3:
		 	cout<<"\n1.Preorder\n2.Inorder\n3.postorder";
		 	cin>>a;
		 	if(a==1)
		 		t.preorder(root);
		 	else if(a==2)
		 		t.inorder(root);
		 	else if(a==3)
		 		t.postorder(root);
		 	else
		 		cout<<"\nTry Again";
		 	break;
		 case 4:
		 	cout<<"\n1.nonrecPreorder\n2.nonrecInorder\n3.nonrecpostorder";
		 	cin>>a;
		 	if(a==1)
		 		t.nonrecpreorder(root);
		 	else if(a==2)
		 		t.nonrecinorder(root);
		 	else if(a==3)
		 		t.nonrecpostorder(root);
		 	else
		 		cout<<"\nTry Again";
		 	break;
		 default:
		   	cout<<"\nWrong Choice";
		   	break;
		}
	}while(ch!=5);

}
