#include<bits/stdc++.h>
using namespace std;

vector<long long> v;
long long tab[100009];

int main()
{
    long long n,t,a,b,c,w=1;
    scanf("%lld%lld", &n, &t);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &a, &b);
        v.push_back(a+b*t);
    }
    tab[1]=v[0];
    for(int i=1; i<v.size(); i++)
    {
        a=1;
        b=w;
        while(a<b)
		{
			c=(a+b)/2;
			if(tab[c]>=v[i]) a=c+1;
			else b=c;
        }
        if(a==w && tab[a]>=v[i])
        {
        	w++;
        	tab[w]=v[i];
        }
        else tab[a]=v[i];
    }
    printf("%lld", w);
    return 0;
}

