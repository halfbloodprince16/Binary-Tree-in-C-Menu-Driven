#include"bits/stdc++.h"
using namespace std;

struct node
{
    int info;
    struct node *left;
    struct node *right;
}*root;
 
 
class BST
{
    public:
        void insert(node *, node *);
        node *copy(node *ptr);
        void display(node *, int);
        int count(node *ptr);
        int depth(node *ptr);
        BST()
        {
            root = NULL;
        }
};


void BST::insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<endl;
        cout<<"Root Node is Added"<<endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout<<endl;
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);
        }
        else
        {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<endl;
            cout<<"Node Added To Left"<<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<endl;
            cout<<"Node Added To Right"<<endl;
            return;
        }
    }
}
 

void BST::display(node *ptr, int level)
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
        cout<<ptr->info;
        display(ptr->left, level+1);
    }
}
node *BST::copy(node *ptr)
{
    node *p;
    p=NULL;
    if(ptr !=NULL)
    {
        p= new node;
        p->info = ptr->info;
        p->left = copy(ptr->left);
        p->right = copy(ptr->right);
    }
    return(p);
}


int BST::count(node *ptr)
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
    cout<<ptr->left->info<<','<<ptr->right->info;
    return(i);
}


int BST::depth(node *ptr)
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


int main()
{
    int choice,num,a,b;
    BST bst;
    node *temp;
    while (1)
    {
        cout<<endl;
        cout<<endl;
        cout<<"Operations on Binary Tree"<<endl;
        cout<<endl;
        cout<<"1.Insert Element "<<endl;
        cout<<"2.Copy of Tree"<<endl;
        cout<<"3.Display Number of Leaf Nodes"<<endl;
        cout<<"4.Display Tree"<<endl;
        cout<<"5.Depth of Tree"<<endl;
        cout<<"6.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            temp = new node;
            cout<<"Enter the number to be inserted : ";
            cin>>temp->info;
            bst.insert(root, temp);
            break;
        case 2:
            bst.copy(root);
            cout<<"Copy of Tree";
            bst.display(root,1);
            cout<<endl;
            break;
        case 3:
            cout<<endl;
            cout<<" Leaf Nodes Are:-\t";
            a=bst.count(root);
            cout<<endl;
            cout<<"Number of Leaf Nodes:-\t";
            cout<<a;
            cout<<endl;
            break;
        case 4:
            cout<<"Display BST:"<<endl;
            bst.display(root,1);
            cout<<endl;
            break;
        case 5:
            cout<<endl;
            cout<<"Depth of Tree is:-\t";
            b=bst.depth(root);
            cout<<b;
            cout<<endl;
            break;
        case 6:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
