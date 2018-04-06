#include<bits/stdc++.h>
using namespace std;

#define size 10

struct Node
{
    string data;
    Node* next;
};
struct Node* head = NULL;

struct Prefix
{
    string predata;
    Prefix* nextpre;
};
struct Prefix* head2 = NULL;           

class Stack
{
    public :
    int count;
        Stack()
        {
            count = 0;
        }
    
    void push();
    void pop();
    void display();
    void prefix();
};

void Stack :: push()
{
    string data;
    if(count < size)
    {
        count++;
        Node* temp = new Node();
        cout<<"\nenter the data: ";
        cin>>data;
        
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    else
    {
        cout<<"stack is full\n";
    }
    
}
void Stack :: pop()
{
    if(count > 0)
    {    
        count--;
        Node* t = head;
        head = head->next;
        free(t);
    }
    else
    {
        cout<<"stack is empty\n";
    }
    
}

void Stack :: display()
{
    Node* t = head;
    while(t!=NULL)
    {
        cout<<t->data;
        t = t->next;
    }
    cout<<"\n";
}

void Stack :: prefix()
{
    Node* t = head;
    Prefix* p = prehead;
    
    while(t != NULL)
    {
        if(t->data == '+' || t->data == '-' || t->data == '*' || t->data == '/')
        {
            Prefix* temp = new Prefix();
            temp->predata = t->data;
            temp->nextpre = prehead;
            prehead = temp;
        }
        else
        {
            cout<<t->data;
        }
    }
    
    while(p != NULL)
    {
        cout<<p->predata;
        p = p->nextpre;
    }
}

int main()
{
    Stack s;
    int ch;
    
    do
    {
        cout<<"1:push\n2:pop\n3:display\n4:To prefix\n5:exit";
        cin>>ch;
        switch(ch)
        {
            case 1 : s.push();break;
            case 2 : s.pop();break;
            case 3 : s.display();break;
            case 4 : s.prefix();break;
            case 5 : break;
        }
    }
    while(ch!=4);
    return 0;
}













