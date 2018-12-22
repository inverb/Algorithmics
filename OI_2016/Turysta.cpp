#include<bits/stdc++.h>
using namespace std;

vector<int> graf[2009], wyn[2009];
int col[2009], ma[2009], k;

int DFS(int u, int l)
{
	int a,b=0;
	col[u]=1;
	for(int i=0; i<graf[u].size(); i++)
	{
		int v=graf[u][i];
		if(col[v]==0)
		{
			a=DFS(v, l+1);
			b=max(a,b);
		}
	}
	if(l>ma[k])
	{
		ma[k]=l;
		wyn[k].clear();
		wyn[k].push_back(u);
		col[u]=0;
		return 1;
	}
	else if(b==1) wyn[k].push_back(u);
	col[u]=0;
	return b;
}

int main()
{
	int n,a;
	scanf("%d", &n);
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<i; j++)
		{
			scanf("%d", &a);
			if(a==0) graf[i].push_back(j);
			else graf[j].push_back(i);
		}
	}
	for(int i=1; i<=n; i++)
	{
		k=i;
		DFS(i,1);
	}
	for(int i=1; i<=n; i++)
	{
		printf("%d ", wyn[i].size());
		for(int j=wyn[i].size()-1; j>=0; j--) printf("%d ", wyn[i][j]);
		printf("\n");
	}
	return 0;
}
