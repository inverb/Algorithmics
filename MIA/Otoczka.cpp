#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef pair<int,int> wie;
vector<wie> v,v1,v2;
int yy,xx;

bool cmp(wie w1,wie w2)
{
    int x1=w1.f, y5=w1.s, x2=w2.f, y2=w2.s, x3, y3, x4, y4;
    x3=y3=x4=y4=0;
    long long x=x2-x1, y=y3-y5, z=y2-y5, v=x3-x1, x0=x2-x1, y0=y4-y5, z0=y2-y5, v0=x4-x1;
    x*=y;
    z*=v;
    x-=z;
    x0*=y0;
    z0*=v0;
    x0-=z0;
    if(x0>0) return 1;
    if(x0<0) return 0;
    x1=w1.f*w1.f;
    y5=w1.s*w1.s;
    x1+=y5;
    x2=w2.f*w2.f;
    y2=w2.s*w2.s;
    x2+=y2;
    x1-=x2;
    if(x1>0) return 0;
    else return 1;
}

void solve()
{
    int n,a,b,c,d;
    wie w;
    double o;
    yy=1000000001;
    xx=1000000001;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d", &a, &b);
        if(b<yy)
        {
            if(yy!=1000000001) v.push_back(wie(xx,yy));
            xx=a;
            yy=b;
        }
        else if(b==yy && a<xx)
        {
            if(yy!=1000000001) v.push_back(wie(xx,yy));
            xx=a;
            yy=b;
        }
        else v.push_back(wie(a,b));
    }
    for(int i=0; i<v.size(); i++)
    {
    	v[i].f-=xx;
    	v[i].s-=yy;
    }
    for(int i=0; i<v.size(); i++)
    {
        if(v[i].f>=0) v1.push_back(v[i]);
        else v2.push_back(v[i]);
    }
    v.clear();
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    for(int i=0; i<v1.size(); i++) v.push_back(v1[i]);
    for(int i=0; i<v2.size(); i++) v.push_back(v2[i]);
    for(int i=0; i<v.size(); i++)
    {
    	v[i].f+=xx;
    	v[i].s+=yy;
    }
	w.f=xx;
    w.s=yy;
    wie w1,w2;
    vector<wie> kol;
    kol.push_back(w);
    for(int i=0; i<v.size(); i++)
    {
        w=v[i];
        if(kol.size()<2) w1=v[v.size()-1];
        else w1=kol[kol.size()-2];
        w2=kol[kol.size()-1];
        int x1=w1.f, y5=w1.s, x2=w2.f, y2=w2.s, x3=w2.f, y3=w2.s, x4=w.f, y4=w.s;
        long long x=x2-x1, y=y3-y5, z=y2-y5, r=x3-x1, x0=x2-x1, y0=y4-y5, z0=y2-y5, v0=x4-x1;
        x*=y;
        z*=r;
        x-=z;
        x0*=y0;
        z0*=v0;
        x0-=z0;
        while(x0<=0)
        {
            kol.pop_back();
            if(kol.size()<2) break;
            w2=w1;
            w1=kol[kol.size()-2];
            x1=w1.f;
            y5=w1.s;
            x2=w2.f;
            y2=w2.s;
            x3=w2.f;
            y3=w2.s;
            x=x2-x1;
            y=y3-y5;
            z=y2-y5;
            r=x3-x1;
            x0=x2-x1;
            y0=y4-y5;
            z0=y2-y5;
            v0=x4-x1;
            x*=y;
            z*=r;
            x-=z;
            x0*=y0;
            z0*=v0;
            x0-=z0;
        }
        kol.push_back(w);
    }
    w=kol[0];
    w1=kol[kol.size()-2];
    w2=kol[kol.size()-1];
    int x1=w1.f, y5=w1.s, x2=w2.f, y2=w2.s, x3=w2.f, y3=w2.s, x4=w.f, y4=w.s;
    long long x=x2-x1, y=y3-y5, z=y2-y5, r=x3-x1, x0=x2-x1, y0=y4-y5, z0=y2-y5, v0=x4-x1;
    x*=y;
    z*=r;
    x-=z;
    x0*=y0;
    z0*=v0;
    x0-=z0;
    while(x0<=0)
    {
        kol.pop_back();
        if(kol.size()<2) break;
        w2=w1;
        w1=kol[kol.size()-2];
        x1=w1.f;
        y5=w1.s;
        x2=w2.f;
        y2=w2.s;
        x3=w2.f;
        y3=w2.s;
        x=x2-x1;
        y=y3-y5;
        z=y2-y5;
        r=x3-x1;
        x0=x2-x1;
        y0=y4-y5;
        z0=y2-y5;
        v0=x4-x1;
        x*=y;
        z*=r;
        x-=z;
        x0*=y0;
        z0*=v0;
        x0-=z0;
    }
    yy=1000000001;
    xx=1000000001;
    for(int i=0; i<kol.size(); i++)
    {
        if(xx>kol[i].f)
        {
            a=i;
            xx=kol[i].f;
            yy=kol[i].s;
        }
        else if(xx==kol[i].f && yy>kol[i].s)
        {
            a=i;
            xx=kol[i].f;
            yy=kol[i].s;
        }
    }
    for(int i=a; i<kol.size(); i++) printf("%d %d\n", kol[i].f, kol[i].s);
    for(int i=0; i<a; i++) printf("%d %d\n", kol[i].f, kol[i].s);
    v.clear();
    v1.clear();
    v2.clear();
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        printf("Case #%d\n", i);
        solve();
    }
    return 0;
}
