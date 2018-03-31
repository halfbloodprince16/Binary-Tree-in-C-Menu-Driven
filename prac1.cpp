//Ques. Stack as adt using ll use this adt for conversion of infix to postfix , prefix and evlaute the postfix and prefix exrpession .
#include<bits/stdc++.h>
using namespace std;

#define size 10
struct Node
{
	char data;
	Node* link;
};
struct Node* head = NULL;
struct Node* headp = NULL;
class Stack
{
	public :
		int count;
		string expression;
		Stack()
		{
			count = 0;
		}
		void getexp();
		void push();
		string pop();
		void display();		
		void infixtopostfix();	
		
		bool CheckOperand(char);
		bool CheckOperator(char);
		int IsRightAssociative(char);
		int GetOperatorWeight(char);
		int HasHigherPrecedence(char,char);
};

void Stack :: getexp()
{
	cout<<"Enter Infix Expression \n";
	cin>>expression;
}

void Stack :: push()
{
	int i;
	if(count < size)
	{	
		count++;
		for(i = 0 ; expression[i] != '\0' ; i++)
		{
			Node* temp = new Node();
			temp->data = expression[i];
			temp->link = head;
			head = temp;
		}
				
	}
	else
	{
		cout<<"\nSorry Stack is Full Now\n";
		return;
	}
	
}

void Stack :: display()
{
	Node* t = head;
	
	
	while(t != NULL)
	{
		cout<<t->data;
		t = t->link;
	}
	cout<<"\n";
	//cout<<exp<<"\n";
}

string Stack :: pop()
{
	string x;
	if(count != 0)
	{
		count--;
		Node* top = head;
		head = head->link;
		x = top->data;
		free(top);
		return x;
	}
	else
	{
		cout<<"\nstack is empty\n";
		return 0;
	}
	
}

void Stack :: infixtopostfix()
{

	stack<char> S;
	string postfix = "";
	for(int i = 0;i< expression.length();i++) 
	{ 
		if(expression[i] == ' ' || expression[i] == ',') continue; 

		else if(CheckOperator(expression[i])) 
		{
			while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(),expression[i]))
			{
				postfix+= S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
	
		else if(CheckOperand(expression[i]))
		{
			postfix +=expression[i];
		}

		else if (expression[i] == '(') 
		{
			S.push(expression[i]);
		}

		else if(expression[i] == ')') 
		{
			while(!S.empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	cout<<"Postfix Expression = "<<postfix<<"\n";
	//expression evaluation
	cout<<"\nexpression evaluation is :";
	for(int i = 0 ; i < postfix.length() ; i++)
	{
	    if(postfix[i] != '+' && postfix[i] != '*' && postfix[i] != '-' && postfix[i] != '/' && postfix[i] != '^')
	    {
	        cout<<"\nenter a digit for: "<<postfix[i];
	        cin>>postfix[i];
	    }
	}
	cout<<endl;
	cout<<postfix;
	double ans=0;
	int v1=0,v2=0;
	
	// stack container
	cout<<endl;
	std::stack<int> a;
	cout<<"answer of evaluation : ";
	for(int i = 0 ; i < postfix.length() ; i++)
	{
	    if(postfix[i] <= '9' && postfix[i] >= '0')
	    {
	        a.push(postfix[i]);
	    }
	    else if(postfix[i] >=42 && postfix[i] <= 47 || postfix[i] == '^')
	    {
	        v1 = a.top();
	        a.pop();
	        
	        v2 = a.top();
	        a.pop();
	        switch(postfix[i])
	        {
	            case '+' : a.push(v2+v1);break;
	            case '-' : a.push(v2-v1);break;
	            case '*' : a.push(v2*v1);break;
	            case '/' : a.push(v2/v1);break;
	            
	        }
	        
	    }
	}
	
	while(!a.empty())
	{
	    cout<<a.top();
	    a.pop();
	}
	cout<<endl;
	return;
}


bool Stack :: CheckOperand(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}


bool Stack :: CheckOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;

	return false;

}


int Stack :: GetOperatorWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

 
int Stack :: HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);


	return op1Weight > op2Weight ?  true: false;
}

int main()
{
	int ch;
	Stack s;
	do
	{
		cout<<"0:enter expression\n1:push\n2:pop\n3:display\n4:infix to postfix\n5:exit\n";
		cin>>ch;
		switch(ch)
		{
			case 0: s.getexp();break;
			case 1: s.push();break;
			case 2: s.pop();break;
			case 3: s.display();break;
			case 4: s.infixtopostfix();break;
		}
	}
	while(ch!=5);
	return 0;
}
