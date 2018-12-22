#include<bits/stdc++.h>
using namespace std;

const int M=1048575;
int tab[2097200], tac[2097200]; //drzewo maksimow i poprawek

int maks(int a, int b, int u, int lo, int hi)
{
	if(b<a) return (-1<<30);
	if(a==lo && b==hi) return tab[u];
	int c=(lo+hi)/2,d,e;
	d=maks(a, min(b,c), 2*u, lo, c);
	e=maks(max(a,c+1), b, 2*u+1, c+1, hi);
	return max(max(d,e), tac[u]);
}

void update(int a, int b, int u, int lo, int hi, int w)
{
	if(b<a) return;
	if(a==lo && b==hi)
	{
		tab[u]=tac[u]=w;
		return;
	}
	int c=(lo+hi)/2;
	tac[2*u]=max(tac[2*u], tac[u]);
	tac[2*u+1]=max(tac[2*u+1], tac[u]);
	tac[u]=0;
	update(a, min(b,c), 2*u, lo, c, w);
	update(max(a,c+1), b, 2*u+1, c+1, hi, w);
	tab[u]=max(tab[2*u], tab[2*u+1]);
	return;
}

int main()
{
	int a,b,c,d,n;
	scanf("%d%d", &d, &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d", &a, &b);
		c=maks(b+M+1, a+b+M, 1, M+1, 2*M+1);
		update(b+M+1, a+b+M, 1, M+1, 2*M+1, c+1);
	}
	c=maks(M+1,2*M+1,1,M+1, 2*M+1);
	printf("%d", c);
	return 0;
}
