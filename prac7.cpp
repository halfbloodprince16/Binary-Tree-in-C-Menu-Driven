#include"bits/stdc++.h"
using namespace std;
typedef  pair<int, int> iPair;
vector< pair<int, iPair> >v;
std::vector<pair<int,pair<int,int>>>::iterator itr,it,iit;
int rt1=0,rt2=0;
class Kruskal
{
public:
	int a,b,x[100][100];//size of matrix;
	int weight;
	Kruskal()
	{
		a = b = 0;
		x[100][100]={};
		weight=0;
	}
	void getmatrix()
	{
		cout<<endl<<"Enter the Row and Column Size of Adjacency Matrix";
		cin>>a>>b;
		int i,j;
		cout<<endl<<"Enter the Weight of the edges if there is no edge then enter 0";
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				cin>>x[i][j];
			}
		}

		cout<<endl<<"The Graph entered is"<<endl;
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				cout<<i<<"-"<<j<<" "<<x[i][j]<<endl;
			}

		}

	}
	void MST();
	int checkpath(int,int);
};
void Kruskal :: MST()
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if(x[i][j] != 0)
			{
				v.push_back({x[i][j],{i,j}});
			}
		}

	}
	
	sort(v.begin(),v.end());
	//sort successful
	cout<<endl<<"Graph After sorting turns out to be:"<<endl;
	for(itr = v.begin();itr != v.end() ; itr++)
	{
		cout<<itr->second.first<<"-"<<itr->second.second<<" "<<itr->first<<endl;
	}
	//pick the first one as root
	int cnt=0;
	int chk=0;
	itr = v.begin();
	rt1 = itr->second.first;
	rt2 = itr->second.second;
	cout<<rt1<<rt2;
	/*super core code is here my algo fuck you bitch*/
	while(cnt < a-1)
	{
		
	}
	cout<<endl<<"Weight:"<<weight;

}



int main(int argc, char const *argv[])
{
	Kruskal kobj;
	kobj.getmatrix();
	kobj.MST();
	return 0;
}