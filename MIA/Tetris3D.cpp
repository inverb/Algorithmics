#include<bits/stdc++.h>
using namespace std;

const int M=1023;
int tab[2050][2050], tac[2050][2050], tad[2050][2050], tae[2050][2050], col[2050][2050], licz;

int maks(int a, int ac, int b, int bc, int u, int u1, int lo, int hi, int lop, int hip)
{
	int c=(lo+hi)/2,d=(lop+hip)/2,w=tab[u][u1];
	if(licz==col[u][u1])  return 0;
	col[u][u1]=licz;
	if(a>=hi || ac<=lo || b>=hip || bc<=lop) return 0;
	if(u>=1024 && u1>=1024) return tac[u][u1];
	if(a<=lo && ac>=hi && b<=lop && bc>=hip) return tac[u][u1];
	if(a<=lo && ac>=hi) w=max(w,tae[u][u1]);
	if(b<=lop && bc>=hip) w=max(w, tad[u][u1]);
	if(u<1024 && (a>lo || ac<hi)) w=max(w,max(maks(a, ac, b, bc, 2*u, u1, lo, c, lop, hip), maks(a, ac, b, bc, 2*u+1, u1, c, hi, lop, hip)));
	if(u1<1024 && (b>lop || bc<hip)) w=max(w,max(maks(a, ac, b, bc, u, 2*u1, lo, hi, lop, d), maks(a, ac, b, bc, u, 2*u1+1, lo, hi, d, hip)));
	return w;
}

void update(int a, int ac, int b, int bc, int u, int u1, int lo, int hi, int lop, int hip, int w)
{
	int c=(lo+hi)/2,d=(lop+hip)/2;
	if(licz==col[u][u1])  return;
	col[u][u1]=licz;
	if(a>=hi || ac<=lo || b>=hip || bc<=lop) return;
	if(tac[u][u1]<w) tac[u][u1]=w;
	if(a<=lo && ac>=hi && tad[u][u1]<w) tad[u][u1]=w;
	if(b<=lop && bc>=hip && tae[u][u1]<w) tae[u][u1]=w;
	if(a<=lo && ac>=hi && b<=lop && bc>=hip)
	{
		if(tab[u][u1]<w) tab[u][u1]=w;
		return;
	}
	if(u<1024 && (a>lo || ac<hi))
	{
		update(a, ac, b, bc, 2*u, u1, lo, c, lop, hip, w);
		update(a, ac, b, bc, 2*u+1, u1, c, hi, lop, hip, w);
	}
	if(u1<1024 && (b>lop || bc<hip))
	{
		update(a, ac, b, bc, u, 2*u1, lo, hi, lop, d, w);
		update(a, ac, b, bc, u, 2*u1+1, lo, hi, d, hip, w);
	}
	return;
}

int main()
{
    int D,S,n,a,b,c,d,e,f,wyn=0;
    scanf("%d%d%d", &D, &S, &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d%d%d", &a, &b, &e, &c, &d);
        licz++;
        f=maks(c, c+a, d, d+b, 1, 1, 0, M+1, 0, M+1);
        wyn=max(wyn,f+e);
        licz++;
        update(c, c+a, d, d+b, 1, 1, 0, M+1, 0, M+1, f+e);
    }
    printf("%d", wyn);
    return 0;
}
