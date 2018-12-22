#include<bits/stdc++.h>
using namespace std;

vector<int> v, v2;
vector<long long> v1;

int main()
{
	int n,q,d,e,f,m;
	long long a=0,b,c,g;
	scanf("%d%d", &n, &q);
	m=n-1;
	for(int i=0; i<n; i++)
	{
		scanf("%lld", &b);
		v.push_back(b);
		b=b*i;
		a=a+b;
		a=a%m;
	}
	if(a!=0)
	{
		for(int i=n-1; i>=1; i--)
		{
			b=v[i];
			b=b*i;
			if(a>=b)
			{
				a-=b;
				v[i]=0;
			}
			else
			{
				b=a/i;
				a-=b*i;
				v[i]-=b;
			}
			if(a==0) break;
		}
	}
	b=0;
	d=0;
	for(int i=0; i<n; i++)
	{
		if(v[i]!=0) d=i;
		b+=v[i];
		if(i==0) b--;
		v1.push_back(b);
		v2.push_back(d);
	}
	for(int i=1; i<=q; i++)
	{
		long long x;
		scanf("%lld", &x);
		long long y;
		if(x>b)
		{
			printf("-1\n");
			continue;
		}
		d=0;
		e=n-1;
		while(d<e)
		{
			f=(d+e)/2;
			g=v1[f];
			if(x>g) d=f+1;
			else e=f;
		}
		printf("%d\n", v2[e]);
	}
	return 0;
}
