#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
std::vector<int>v;
std::vector<int>::iterator itr;

struct student
{
	int roll;
	string name;
};
struct student s[100]={};

void insert(int id)
{
	cout<<endl<<"Enter Your Name : ";cin>>s[id].name;
	cout<<"Enter Your Roll : ";cin>>s[id].roll;
}
void display()
{
	int i=0;
	cout<<endl<<"ID"<<setw(5)<<"Name"<<setw(5)<<"Roll";
	for(i = 1; i < 100 ; i++)
	{
		if(s[i].roll != 0)
		{
			cout<<endl<<i<<setw(5)<<s[i].name<<setw(5)<<s[i].roll<<endl;
		}
		
	}
}

int main(int argc, char const *argv[])
{
	int ch,i,j,k;
	int id=0;
	do
	{
		cout<<"1:Insert Records\n2:Display Records\n3:Display Hash Table";
		cin>>ch;
		switch(ch)
		{
			case 1:id++;
				   insert(id);break;
			case 2:display();break;
		}
	}
	while(ch!=4);
	return 0;
}