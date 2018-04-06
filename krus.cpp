#include<bits/stdc++.h>
using namespace std;
struct nodes{
	int snode;
	int enode;
	int w;
}s[10];

class krus
{
	vector<pair<int,pair<int,int> > >v;
	int n,m,sum,parent[10];
	public:

	krus()
	{
			n=m=sum=0;
			for(int i=0;i<10;i++)
			{
				parent[i]=i;
			}
	}

	void read()
	{
		int a,b,c;
		cout<<"Enter Number of nodes";
		cin>>n;
		cout<<"Enter Number of edges";
		cin>>m;
		cout<<"Enter edge and weight";
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			v.push_back({c,{a,b}});
		}
	}
	int root(int a)
	{
		if(parent[a]!=a)
			parent[a]=root(parent[a]);
		return(parent[a]);
	}

	void cal()
	{
		sort(v.begin(), v.end());

		for(int i=0;i<m;i++)
		{
			int a,b;
			a=v[i].second.first;
			b=v[i].second.second;

			if(root(a)!=root(b))
			{
					sum=sum+v[i].first;
					parent[root(v[i].second.first)]=root(parent[v[i].second.second]);
					cout<<a<<" "<<b<<"\n";
			}
		}
		cout<<"\nsum is   "<<sum;
	}
};
int main()
{
	krus k;
	k.read();
	k.cal();
}
