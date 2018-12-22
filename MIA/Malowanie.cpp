#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, int> par;
priority_queue<par, vector<par>, greater<par> > q;
vector<par> v;
vector<long long> tab;
long long n,k;

void solve()
{
	long long a,b,wyn=0;
	tab.resize(k+9,0);
	for(int i=1; i<=k; i++)
	{
		cin>>a>>b;
		v.push_back(par(a,i+k));
		v.push_back(par(b,i));
	}
	v.push_back(par(0,0));
	v.push_back(par(n,k+1));
	sort(v.begin(), v.end());
	for(int i=1; i<v.size(); i++)
	{
		if(v[i].first!=v[i-1].first) wyn+=v[i].first-v[i-1].first;
		if(v[i].second>k) tab[v[i].second-k]=wyn;
		else wyn=min(wyn,tab[v[i].second]-1);
	}
	cout<<wyn;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	long long a,b,wyn=0;
	par p;
	cin>>n>>k;
	if(k<100000)
	{
		solve();
		return 0;
	}
	tab.resize(k+1,0);
	for(int i=1; i<=k; i++)
	{
		cin>>a>>b;
		q.push(par(a,i+k));
		tab[i]=b;
	}
	b=0;
	q.push(par(n,2*k+1));
	while(true)
	{	p=q.top();
		q.pop();
		if(p.first!=b) wyn+=p.first-b;
		b=p.first;
		if(p.second>k)
		{
			q.push(par(tab[p.second-k], p.second-k));
			tab[p.second-k]=wyn;
		}
		else wyn=min(wyn,tab[p.second]-1);
		if(p.second==2*k+1) break;
	}
	cout<<wyn;
	return 0;
}
