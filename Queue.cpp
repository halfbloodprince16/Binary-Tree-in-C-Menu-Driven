#include<bits/stdc++.h>
using namespace std;
#define size 10

struct Node
{
    int data;
    Node* link;
};
struct Node* front = NULL;
struct Node* rear = NULL;

class Queue
{
    public :
        int count;
        Queue()
        {
            count = 0;
        }
        
        void enqueue();
        void dequeue();
        void display();
};
void Queue :: enqueue()
{
    int data;
    cout<<"enter data: ";
    cin>>data;
    
    Node* temp = new Node();
    temp->data = data;
    temp->link = NULL;
    if(front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    
    rear->link = temp;
    rear = temp;
    
}
void Queue :: dequeue()
{
    Node* t = front;
    front = front->link;
    free(t);
}
void Queue :: display()
{
    Node* t = front;
   
    while(t != NULL)
    {
        cout<<t->data<<"->";
        t = t->link;
        
    }
    cout<<"\n";
}

int main()
{
    int ch;
    Queue s;
    do
    {
        cout<<"1:enqueue\n2:dequeue\n3:display\n4:exit";
        cin>>ch;
        switch(ch)
        {
            case 1 : s.enqueue();break;
            case 2 : s.dequeue();break;
            case 3 : s.display();break;
            case 4 : break;
        }
    }
    while(ch!=4);
    return 0;
}




















