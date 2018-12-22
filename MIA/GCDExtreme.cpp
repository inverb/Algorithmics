#include<bits/stdc++.h>
using namespace std;

long long tab[1000009], sit[1000009], euk[1000009];
vector<int> v,v1;

void pre()
{
    int a,d,e;
    long long b,c;
    for(int i=2; i<=1000000; i++) if(sit[i]==0) for(int j=2*i; j<=1000000; j+=i) if(sit[j]==0) sit[j]=i;
    for(int i=2; i<=1000000; i++)
    {
        if(sit[i]==0)
        {
            euk[i]=i-1;
            continue;
        }
        v1.push_back(-1);
        b=1;
        a=i;
        while(sit[a]!=0)
        {
            v1.push_back(sit[a]);
            a/=sit[a];
        }
        v1.push_back(a);
        sort(v1.begin(), v1.end());
        d=v1[1];
        a=1;
        for(int j=2; j<v1.size(); j++)
        {
            if(v1[j]!=v1[j-1])
            {
                b*=euk[d];
                d=v1[j];
                a=0;
            }
            else d*=v1[j];
        }
        if(a==1)
        {
            e=v1.size()-1;
            e=d/v1[e];
            b=d-e;
        }
        else b*=euk[d];
        v1.clear();
        euk[i]=b;
    }
    for(int i=1; i<=1000000; i++)
    {
    	tab[i]+=tab[i-1];
    	for(int j=i; j<=1000000; j+=i) tab[j]+=i*euk[j/i];
    }
    return;
}

int main()
{
    int n;
    pre();
    scanf("%d", &n);
    while(n!=0)
    {
        printf("%lld\n", tab[n]);
        scanf("%d", &n);
    }
    return 0;
}
