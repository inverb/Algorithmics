#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef pair<int,int> par;
vector<par> v[30];
int tab[30][30], tac[2000009], pot[30];

int main()
{
	int n,m,a,b,c,d,e,wyn=0;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back(par(b,c));
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) scanf("%d", &tab[i][j]);
	pot[1]=1;
	for(int i=2; i<=21; i++) pot[i]=2*pot[i-1];
	for(int i=1; i<=pot[n+1]-1; i++)
	{
		a=i;
		b=0;
		e=0;
		for(int j=1; j<=20; j++) if(pot[j]&a) e++;
		for(int j=1; j<=20; j++)
		{
			if(pot[j]&a)
			{
				c=a-pot[j];
				d=tac[c]+tab[j][e];
				b=max(b,d);
			}
		}
		d=0;
		for(int j=0; j<v[e].size(); j++) if(b>=v[e][j].f) d+=v[e][j].s;
		b+=d;
		tac[a]=b;
		wyn=max(wyn,b);
	}
	printf("%d", wyn);
	return 0;
}
