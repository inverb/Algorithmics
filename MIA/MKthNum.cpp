#include<bits/stdc++.h>
using namespace std;

int tab[131200];
vector<int> drz[262500], pos[262500], v;
const int M=131071;

void make(int u)
{
	if(drz[u].size()==1) return;
	int mid,a,b;
	mid=(drz[u].size()-1)/2;
	a=pos[u][mid];
	for(int i=0; i<=mid; i++) pos[2*u].push_back(pos[u][i]);
	for(int i=mid+1; i<pos[u].size(); i++) pos[2*u+1].push_back(pos[u][i]);
	for(int i=0; i<drz[u].size(); i++)
	{
		b=drz[u][i];
		if(tab[b]<=a) drz[2*u].push_back(b);
		else drz[2*u+1].push_back(b);
	}
	make(2*u);
	make(2*u+1);
	return;
}

int bin(int u,int lo, int hi)
{
	vector<int>::iterator l,h,a;
	l=lower_bound(drz[u].begin(), drz[u].end(), lo);
	h=upper_bound(drz[u].begin(), drz[u].end(), hi);
	if(h==l)
	{
		if(l==drz[u].end()) return 0;
		a=upper_bound(drz[u].begin(), drz[u].end(),hi);
		if(l==a) return 0;
		if(*h!=hi) return 0;
		return 1;
	}
	return h-l;
}

void szuk(int u, int lo, int hi, int k)
{
	if(drz[u].size()==1)
	{
		printf("%d\n", tab[drz[u][0]]);
		return;
	}
	int a=bin(2*u,lo,hi);
	if(k>a) szuk(2*u+1,lo,hi,k-a);
	else szuk(2*u,lo,hi,k);
	return;
}

int main()
{
	int n,k,a,b,c;
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		v.push_back(tab[i]);
		drz[1].push_back(i);
	}
	sort(v.begin(), v.end());
	pos[1]=v;
	make(1);
	for(int i=1; i<=k; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		szuk(1,a,b,c);
	}
	return 0;
}
