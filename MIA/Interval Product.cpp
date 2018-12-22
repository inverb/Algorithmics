#include<bits/stdc++.h>
using namespace std;

int tab[262150], M=131071;

void dod(int a, int u)
{
	if(a>0) tab[u]=1;
	else if(a==0) tab[u]=0;
	else tab[u]=-1;
	u/=2;
	while(u>0)
	{
		tab[u]=tab[2*u]*tab[2*u+1];
		u/=2;
	}
	return;
}

int licz(int a, int b, int u, int lo, int hi)
{
	if(a==lo && b==hi) return tab[u];
	if(a>b) return 1;
	if(u>M) return tab[u];
	int mid=(lo+hi)/2;
	return licz(a,min(b,mid),2*u,lo,mid)*licz(max(a,mid+1),b,2*u+1,max(lo,mid+1),hi);
}

int main()
{
	int n,k,a,b,d,e,f;
	char c;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d", &k);
		for(int i=1; i<=M; i++) tab[i]=1;
		for(int i=n+M+1; i<262144; i++) tab[i]=1;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &a);
			dod(a,i+M);
		}
		for(int i=1; i<=k; i++)
		{
			scanf("%s", &c);
			scanf("%d%d", &a, &b);
			if(c=='C') dod(b,a+M);
			else
			{
				d=licz(a+M,b+M,1,M+1,2*M+1);
				if(d==0) printf("0");
				else if(d>0) printf("+");
				else printf("-");
			}
		}
		printf("\n");
	}
	return 0;
}
