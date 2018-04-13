//BT
#include "bits/stdc++.h"
using namespace  std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};
struct Node* root = NULL;
struct Node* rt = NULL;

class BT
{
public:
	BT()
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
	void display(Node* p,int level);
};

void BT :: display(Node* ptr,int level)
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
        cout<<ptr->data;
        display(ptr->left, level+1);
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
	BT k;
	int ch;
	int cnt=0,i,j,flg=0;
	int data;
	char c;
	do
	{
		cout<<"1:insert\n2:display\n3:exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1 :if(cnt == 0)
					{
						cout<<endl<<"Enter root node : ";
						cin>>data;
						root = k.newnode(data);
						cnt++;
						rt = root;
					}
					else
					{
						while(flg==0)
						{
							cout<<endl<<"l:left\nr:right";
							cin>>c;
							if(c == 'l')
							{
								if(root->left == NULL)
								{
									cout<<endl<<"Enter the Node Data";
                                    cin>>data;
                                    root->left = k.newnode(data);
                                    flg=1;
								}
								else
								{
									root = root->left;
								}

							}
							else if(c=='r')
                            {
                                if(root->right == NULL)
                                {
                                    cout<<endl<<"Enter the Node Data";
                                    cin>>data;
                                    root->right = k.newnode(data);
                                    flg=1;
                                }
                                else
                                {
                                    root = root->right;
                                }
                            }
                            
						}
						
						
					}
					root = rt;
					flg=0;break;
			case 2 : k.display(root,1);
                     break;
		}
	}
	while(ch!=3);
	return 0;
}
