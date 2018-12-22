#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a,b,c,d,e,mi=0,ma=0,x=0;
	long long wyn=0;
	long long y;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		b++;
		c--;
		d=a-x;
		mi-=d;
		ma+=d;
		mi=max(b,mi);
		ma=min(c,ma);
		if(mi<0)
		{
			e=-mi;
			if(e%2!=a%2) mi++;
		}
		else if(mi%2!=a%2) mi++;
		if(ma<0)
		{
			e=-ma;
			if(e%2!=a%2) ma--;
		}
		else if(ma%2!=a%2) ma--;
		x=a;
		if(mi>ma)
		{
			printf("NIE");
			return 0;
		}
	}
	d=m-x;
	mi-=d;
	ma+=d;
	if(mi<0)
	{
		e=-mi;
		if(e%2!=m%2) mi++;
	}
	else if(mi%2!=m%2) mi++;
	if(ma<0)
	{
		e=-ma;
		if(e%2!=m%2) ma--;
	}
	else if(ma%2!=m%2) ma--;
	if(mi>ma)
	{
		printf("NIE\n");
		return 0;
	}
	wyn=(m+mi)/2;
	printf("%lld", wyn);
	return 0;
}
