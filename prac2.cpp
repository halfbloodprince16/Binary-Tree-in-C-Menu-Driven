#include"bits/stdc++.h"
using namespace std;
typedef pair<int,string>ipair;
priority_queue<ipair>p;

int main(int argc, char const *argv[])
{
	p.push({1,"vighnesh"});
	for(int i = 0 ;i<p.size();i++)
	{
		cout<<p->first;
	}
	return 0;
}