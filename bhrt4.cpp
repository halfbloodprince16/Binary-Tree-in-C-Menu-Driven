/*
Construct and expression tree from postfix/prefix expression and perform recursive 
and non- recursive In-order, pre-order and post-order traversals.
*/
#include "iostream"
using namespace std;

struct tnode
{
	char x;
	tnode *left ,*right ;
};

struct snode //stack ka node
{
	tnode *val;
	snode *next;
};

class stacku
{
	snode *top;  // jab jab stack ka node banega .. tab tab tree ka node banega .. 
	public :
		stacku()
		{
			top =NULL;
		}
		
		
		int empty()
		{
			if(top ==NULL)
				return 0;
			return 1;	
		}
		
		void push (tnode *x)
		{
			snode *temp = new(snode) ;
			temp->val = x;
			temp->next = top;   //stack ke top mai laga rhe hai
			
			top =temp;     
			
		}
		
		tnode *pop ( )
		{
			tnode *temp = top->val ;
			
			top = top ->next;
			return temp ;
			
		}
		void display(tnode* ptr,int level);
		
		
};

void pre(tnode *temp)
{
	if(temp==NULL)
	return ;
	cout<< temp ->x;
	pre(temp->left);
	pre(temp->right);
}

void post(tnode *temp)
{
	if(temp==NULL)
	return ;
	post(temp->left);
	post(temp->right);
	cout<<temp->x;
	
}

void stacku :: display(tnode* ptr,int level)
{
	int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == top)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level; i++)
                cout<<"       ";
        }
        cout<<ptr->x;
        display(ptr->left, level+1);
    }
    cout<<endl;
}

int main()
{
	stacku st;
	tnode  *t1 , *t2 ;
	int i =0;
	
	string s;
	cin>>s;
	
	while (s[i]!='\0')
	{
		if(isalnum(s[i]))
		{
			tnode *temp =new (tnode) ;
			temp -> x = s[i];
			temp -> left = NULL;
			temp -> right =NULL;
			st.push(temp);
		}
		else
		{
			t2 = st.pop();
			t1 = st.pop();
			tnode *temp = new(tnode);
				temp -> x = s[i];
			temp -> left = t1;
			temp -> right =t2;
			st.push(temp);
		}
		
		
		
		i++;
		
	}
	display(top,1);
	
	tnode *top  = st.pop();
	cout<<"Preorder \n";
	pre(top);
	
	cout<<"PostOrder \n ";
	post(top);
	
	
	
	return 0;
}
