#include<bits/stdc++.h>
using namespace std;

double dz[500009], wyn[500009];
vector<int> graf[500009];

inline void DFS(int u)
{
	double a=0,b,c;
	if(graf[u].size()==0)
	{
		wyn[u]=1;
		return;
	}
	for(int i=0; i<graf[u].size(); i++)
	{
		int v=graf[u][i];
		DFS(v);
		dz[u]+=dz[v]+1;
	}
	for(int i=0; i<graf[u].size(); i++)
	{
		int v=graf[u][i];
		b=wyn[v];
		c=(dz[v]+1)/dz[u];
		b=min(b,c);
		a=max(a,b);
	}
	wyn[u]=a;
	return;
}

int main()
{
	int a,n;
	double w=0, k;
	scanf("%d%lf", &n, &k);
	for(int i=2; i<=n; i++)
	{
		scanf("%d", &a);
		graf[a].push_back(i);
	}
	DFS(1);
	for(int i=1; i<=n; i++) if(dz[i]+1>k) w=max(w,wyn[i]);
	printf("%.8lf", w);
	return 0;
}
