
#include"bits/stdc++.h"
using namespace std;
std::stack<string>s;

class Expression
{
public:
	string post;
	Expression()
	{
		post={};
	}
	void getexp()
	{
		cin>>post;
	}
	bool isOperand(char x)
	{
	   return (x >= 'a' && x <= 'z') ||
	          (x >= 'A' && x <= 'Z');
	}
	string conv()
	{

	    for (int i=0; post[i]!='\0'; i++)
	    {
	        if (isOperand(post[i]))
	        {
	           string op(1, post[i]);
	           s.push(op);
	        }
	
	        else
	        {
	            string op1 = s.top();
	            s.pop();
	            string op2 = s.top();
	            s.pop();
	            s.push("(" + op2 + post[i] +
	                   op1 + ")");
	        }
	    }
	    return s.top();
	}
};

int main(int argc, char const *argv[])
{
	Expression e;
	e.getexp();
	string in = e.conv();
	cout<<in;
	
	return 0;
}