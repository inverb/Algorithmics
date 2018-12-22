#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef pair<long long, long long> par;
par sta[100009];
vector<par> wie;
set<par> s;

long long sortuj(const par &a, const par &b, const par &c)
{
	par p1,p2;
	p1.f=b.f-a.f;
	p1.s=b.s-a.s;
	p2.f=c.f-a.f;
	p2.s=c.s-a.s;
  	return p1.f*p2.s-p1.s*p2.f;
}

int main()
{
	int n,m,a;
	par p,P,p0,p1,p2,sty;
	long long le=-1, pr=-1;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%lld %lld", &sta[i].f, &sta[i].s);
	scanf("%d", &m);
	for (int i=0; i<m; i++)
	{
		scanf("%lld %lld", &P.f, &P.s);
		wie.push_back(P);
	}
	wie.push_back(wie.front());
	P=sta[0];
	p0=wie[m-1];
	for(int i=0; i<m; i++)
	{
		p1=wie[i];
		p2=wie[i+1];
		if(sortuj(p0,p1,P)<0 && sortuj(p1,p2,P)>=0) pr=i;
        if(sortuj(p0,p1,P)>=0 && sortuj(p1,p2,P)<0) le=i;
		p0=p1;
	}
	sty.f=le;
	sty.s=pr;
	p1=p2=sta[0];
	for(int i=1; i<n; i++)
	{
		p0=sta[i];
		if(sortuj(P,wie[sty.f],sta[i])>=0 || sortuj(P,wie[sty.s],sta[i])<=0) s.insert(sta[i]);
		else if(sortuj(P,wie[sty.f],sta[i])<0 && sortuj(P,wie[sty.s],sta[i])>0 && sortuj(wie[sty.f],wie[sty.s],sta[i])<=0) s.insert(sta[i]);
		if(sortuj(P,wie[sty.f],p0)>=0)
		{
			while(true)
			{
                if(le==0) a=m-1;
                else a=le-1;
				if(sortuj(wie[a],wie[le],p0)<=0)
				{
			  		le=a;
			  		p1=p0;
				} 
				else break;
			}
			if(sortuj(p1,wie[le],p0)>0) p1=p0;
		}
		if(sortuj(P,wie[sty.s],p0)<=0)
		{
			while(true)
			{
				a=(pr+1)%m;
				if(sortuj(wie[pr],wie[a],p0)<=0)
				{
			  		pr=a;
			  		p2=p0;
				} 
				else break;
			}
			if(sortuj(p2,wie[pr],p0)<0) p2=p0;
		}
	}
	for(int i=0; i<n; i++)
	{
		p=sta[i];
		if(sortuj(p1,wie[le],p)>=0) s.insert(p);
		else if(sortuj(p1,P,p)>=0 && sortuj(P,wie[le],p)>=0) s.insert(p);
		if(sortuj(p2,wie[pr],p)<=0) s.insert(p);
		else if(sortuj(P,p2,p)>=0 && sortuj(wie[pr],P,p)>=0) s.insert(p);
	}
	s.erase(P);
	printf("%d", s.size());
	return 0;
}
