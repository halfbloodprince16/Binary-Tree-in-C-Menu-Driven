#include"bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
};
node* root = NULL;
node* p = NULL;
node* rt = NULL;
class BT
{

public :
    
    node* newnode(int data)
    {

        node *temp = new node();
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    node* display(node* ptr, int level)
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
    int depth(node *ptr)
    {
        int hl,hr;
        if(ptr==NULL)
        {
            return(0);
        }
        if(ptr->left == NULL && ptr->right ==NULL)
        {
            return(0);
        }
        hl=depth(ptr->left);
        hr=depth(ptr->right);
        if(hl>hr)
            return(hl+1);
        return(hr+1);
    }

    int count(node *ptr)
    {
        int i;
        if(ptr==NULL)
        {
            return(0);
        }
        if(ptr->left == NULL || ptr->right ==NULL)
        {
            return(1);
        }
        i=count(ptr->left)+count(ptr->right);
        cout<<ptr->left->data<<','<<ptr->right->data;
        return(i);
    }
    node* copy(node* ptr)
    {
        node *p;
        p=NULL;
        if(ptr !=NULL)
        {
            p= new node;
            p->data = ptr->data;
            p->left = copy(ptr->left);
            p->right = copy(ptr->right);
        }
        return(p);
    }
   
};

int main()
{
    BT s;
    int ch=0,cnt=0,i,j,k,flg=0;
    int ent;
    int data,dep=0,x=0;
    char dir;
    
    do
    {
        cout<<"**********Main Menu***********"<<endl;
        cout<<"1:Insert New Node\n2:Display\n3:Depth of Tree\n4:Display Leaf Node\n5:Copy of Tree\n";
        cin>>ch;
        switch(ch)
        {
            case 1 :if(cnt == 0)
                    {
                        cout<<endl<<"Enter the Root Node Data";
                        cin>>data;
                        root = s.newnode(data);      
                        cout<<root->data;        
                        cnt = 1;      
                        rt = root;   
                    } 
                    else if(cnt > 0)
                    {
                        while(flg==0)
                        {
                            cout<<"Press L/R w.r.t to root";
                            cin>>dir;
                            if(dir == 'l')
                            {
                                if(root->left == NULL)
                                {
                                    cout<<endl<<"Enter the Node Data";
                                    cin>>data;
                                    root->left = s.newnode(data);
                                    cout<<root->left->data;
                                    flg=1;
                                }
                                else
                                {
                                    root = root->left;
                                }
                                
                            }
                            else if(dir=='r')
                            {
                                if(root->right == NULL)
                                {
                                    cout<<endl<<"Enter the Node Data";
                                    cin>>data;
                                    root->right = s.newnode(data);
                                    flg=1;
                                }
                                else
                                {
                                    root = root->right;
                                }
                            }
                            
                        }
     
                    }
                    flg=0;
                    root = rt;
                    break;
            case 2 : s.display(root,1);
                     break;
            case 3 : dep = s.depth(root);
                     cout<<"Depth of Tree :"<<dep;
                     cout<<endl;
                     break;
            case 5 : p = s.copy(root);
                     s.display(p,1);
                     break;
            case 4 : x = s.count(root);
                     cout<<x;
                     break;
        }
    }
    while(ch!=6);
    return 0;
}
