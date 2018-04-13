//prims algo
#include"bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef  pair<int, int> ipair;
std::vector<pair<int,ipair>>v;
std::vector<pair<int,pair<int,int>>>::iterator itr,it;

const int N = 1e6 + 2;

class krus
{
public:
	int cnt;
	krus()
	{
		cnt=0;
	}	
	void insert();
	void display();
	void ssort();
	void mst();
	bool isaldone();
};

void krus :: insert()
{
	int n;
	int a,b,c;
	cout<<"Enter no. of edges";
	cin>>n;
	cnt=n;
	cout<<"Enter first edge then second then weight";
	while(n)
	{
		cin>>a>>b>>c;
		v.push_back({c,{a,b}});
		n--;
	}
}

void krus :: display()
{
	int n = cnt;
	for(itr = v.begin() ; itr != v.end() ; itr++)
	{
		cout<<endl<<itr->second.first<<"-"<<itr->second.second<<"-->"<<itr->first;
		n--;
	}
}

void krus :: ssort()
{
	sort(v.begin(),v.end());
}

bool krus :: isaldone()
{
	int flg=0;
	for(itr = v.begin() ; itr != v.end() ; itr++)
	{
		if(itr->first != 0)
		{
			flg = 1;
			return false;
		}
		else
		{
			flg = 0;
		}
	}
	if(flg == 0)
	{
		return true;
	}
}

void krus :: mst()
{
	int rt1,rt2,ans=0;
	itr = v.begin();
	rt1 = itr->second.first;

	while(isaldone()==false)
	{
		for(itr = v.begin() ; itr != v.end() ; itr++)
		{
			if(itr->second.first == rt1)
			{
				cout<<endl<<itr->second.first<<"-"<<itr->second.second<<"-->"<<itr->first;
				ans += itr->first;
				itr->first = 0;

				for(it = v.begin() ; it != v.end() ; it++)
				{
					if(it->second.second == itr->second.first && it->second.first == itr->second.second)
					{
						it->first = 0;
					}
				} 
				rt1 = itr->second.second;
			}
		}
	}
	cout<<endl<<ans;
}

int main(int argc, char const *argv[])
{
	krus k;
	k.insert();
	k.display();
	k.ssort();
	k.display();
	k.mst();
	return 0;
}