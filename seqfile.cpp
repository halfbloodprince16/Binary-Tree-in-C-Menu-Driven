#include"bits/stdc++.h"
using namespace std;

std::fstream fin , fout;

class file
{
public:
	string name;
	int roll;
	file()
	{
		name={};
		roll=0;
	}
	void insert();
	void display();
	void search();
	void del();
};

void file :: insert()
{
	cin>>name;
	cin>>roll;

	fout.open("abc.txt",ios::app);
	fout<<name<<setw(5);
	fout<<roll<<endl;
	fout.close();
}
void file :: display()
{
	fin.open("abc.txt",ios::out);
	int i=0;
	while(!fin.eof())
	{
		fin>>name>>roll;
		cout<<name<<roll;
		i++;
	}
	fin.close();
}

void file :: search()
{
	
}

void file :: del()
{
	
}

int main(int argc, char const *argv[])
{
	int ch;
	int i,j,k;
	int n=0;
	file f;
	do
	{
		cout<<"1:Insert\n2:Display\n3:Search\n4:Delete";
		cin>>ch;
		switch(ch)
		{
			case 1 : f.insert();break;
			case 2 : f.display();break;
			/*case 3 : search();break;
			case 4 : del();break;*/
		}
	}
	while(ch!=5);
	return 0;
}