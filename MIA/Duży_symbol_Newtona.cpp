#include<bits/stdc++.h>
using namespace std;

long long pow(long long a, long long q, long long p)
{
	if(q==0) return 1;
	if(q%2==1)
	{
		long long b=pow(a,q-1,p);
		b=(b*a)%p;
		return b;
	}
	long long b=pow(a,q/2,p);
	b=(b*b)%p;
	return b;
}

void solve()
{
	long long n,k,p,a=1,b,c,d=0,e=0;
	scanf("%lld%lld%lld", &n, &k, &p);
	k=min(k,n-k);
	for(int i=2; i<=k; i++)
	{
		if(i%p!=0) a=(a*i)%p;
		else
		{
			c=i;
			while(c%p==0)
			{
				c/=p;
				d++;
			}
			a=(a*c)%p;
		}
	}
	a=pow(a,p-2,p);
	for(int i=n-k+1; i<=n; i++)
	{
		if(i%p!=0) a=(a*i)%p;
		else
		{
			c=i;
			while(c%p==0)
			{
				c/=p;
				e++;
			}
			a=(a*c)%p;
		}
	}
	if(e>d) printf("0\n");
	else printf("%lld\n", a);
	return;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}
