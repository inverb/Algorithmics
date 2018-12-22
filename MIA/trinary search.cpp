#include<bits/stdc++.h>
using namespace std;

inline void solve()
{
	double a,b,x1,x2,x3,x4,y1,y2,xl,xp,y,w1,w2,w3,w4,c;
	scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &x1, &y1, &x2, &y2);
	if(x2<x1)
	{
		swap(x1,x2);
		swap(y1,y2);
	}
	x3=-1000.00000;
	x4=1000.000000;
	y=-(x3*x3)+(a*x3)+b;
	w3=sqrt((x1-x3)*(x1-x3)+(y1-y)*(y1-y))+sqrt((x2-x3)*(x2-x3)+(y2-y)*(y2-y));
	y=-(x4*x4)+(a*x4)+b;
	w4=sqrt((x1-x4)*(x1-x4)+(y1-y)*(y1-y))+sqrt((x2-x4)*(x2-x4)+(y2-y)*(y2-y));
	while(abs(x4-x3)>0.00001)
	{
		c=(x4-x3)/3;
		xl=x3+c;
		xp=xl+c;
		y=-(xl*xl)+(a*xl)+b;
		w1=sqrt((x1-xl)*(x1-xl)+(y1-y)*(y1-y))+sqrt((x2-xl)*(x2-xl)+(y2-y)*(y2-y));
		y=-(xp*xp)+(a*xp)+b;
		w2=sqrt((x1-xp)*(x1-xp)+(y1-y)*(y1-y))+sqrt((x2-xp)*(x2-xp)+(y2-y)*(y2-y));
		if(w3<=w1)
		{
			x4=xl;
			w4=w1;
		}
		else if(w2>=w4)
		{
			x3=xp;
			w3=w2;
		}
		else if(w1==w2)
		{
			x3=xl;
			w3=w1;
			x4=xp;
			w4=w2;
		}
		else if(w1<w2)
		{
			x4=xp;
			w4=w2;
		}
		else
		{
			x3=xl;
			w3=w1;
		}
	}
	y=-(x4*x4)+(a*x4)+b;
	if(abs(y)<0.00001) y=0.00000;
	printf("%.5lf %.5lf\n", x4, y);
	return;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}
