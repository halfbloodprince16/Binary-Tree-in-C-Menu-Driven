#include"bits/stdc++.h"
using namespace std;

struct node
{
	string name;
	int data;
	node *next;
};
struct node *head = NULL;

void insert()
{
	int cond;
	string name;

	cout<<"Nam-Cond(1,2,3)";
	cin>>name>>cond;

	node* temp = new node();
	temp->name = name;
	temp->data = cond;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		if(head->data > temp->data)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			node *curr = head;
			while(curr->data <= temp->data)
			{
				if(curr->next == NULL || curr->next->data > temp->data)
					break;
				curr = curr->next;
			}
			temp->next = curr->next;
			curr->next = temp;
		}
	}
}

void display()
{
	node* curr = head;
	while(curr != NULL)
	{
		cout<<endl<<curr->name<<" "<<curr->data;
		curr = curr->next;
	}
}

void dequeue()
{
	node* curr = head;
	head = curr->next;
	free(curr);
}
int main(int argc, char const *argv[])
{
	int ch;
	do
	{
		cout<<"1:insert\n2:display\n3:dequeue";
		cin>>ch;
		switch(ch)
		{
			case 1 : insert();break;
			case 2 : display();break;
			case 3 : dequeue();break;
		}
	}
	while(ch!=4);
	return 0;
}