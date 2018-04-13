#include"bits/stdc++.h"
using namespace std;



class file
{
private:
	string name;
	int id,roll,cnt;
	fstream fin,fout;
public:
	file()
	{
		name={};
		id = roll = cnt = 0;
		fout.open("rec.txt",ios::out);
	    fout.close();
	}

	void insert()
	{
		fout.open("rec.txt",ios::app);
			cout<<"name-roll";
			cin>>name>>roll;
			fout<<endl<<id<<" "<<roll<<" "<<name;
			cnt++;
		fout.close();
	}
	void display()
	{
		fin.open("rec.txt",ios::in);
			while(!fin.eof())
			{
				fin>>id>>roll>>name;
				cout<<endl<<id<<" "<<roll<<" "<<name;	
			}
		fin.close();
	}
	void del()
	{
		int r;
		cout<<"Enter the roll to delete";
		cin>>r;
		fin.open("rec.txt",ios::in);
			while(!fin.eof())
			{
				fin>>id>>roll>>name;
				if(roll != r)
				{
					fout.open("temp.txt",ios::app);
						fout<<id<<roll<<name;
					fout.close();
				}
			}
		fin.close();
		fin.open("temp.txt",ios::in);
		fout.open("student.txt",ios::out);
		while(!fin.eof())
		{
			fin>>id>>roll>>name;
			fout<<id<<roll<<name;

		}
		fin.close();
		fout.close();
	}
};

int main(int argc, char const *argv[])
{
	file f;
	int ch;
	do
	{
		cout<<endl<<"1:insert-2:display";
		cin>>ch;
		switch(ch)
		{
			case 1:f.insert();break;
			case 2:f.display();break;
			case 3:f.del();
		}
	}
	while(ch!=4);
	return 0;
}