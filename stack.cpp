#include"bits/stdc++.h"
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;

void push(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = head;
	head = temp;
}

void pop()
{
	Node* top = head;
	head = head->next;
	free(top);
}
int top()
{
	Node* top = head;
	return top->data;
}

int main(int argc, char const *argv[])
{
	push(10);
	push(11);
	cout<<top();
	pop();
	cout<<top();
	return 0;
}