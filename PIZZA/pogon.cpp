#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

ifstream tak;
ofstream nie;

typedef pair<char,int> par;
vector<int> poz,trap,wyn;
vector<par> wyp;
int tab[10009][10009], ojc[10009][10009], n, m;

void wypisz(int a, int x)
{
	int b=n;
	while(a>0)
	{
		if(ojc[a][b]==b-1)
		{
			wyn.push_back(trap[a]);
			b--;
		}
		a--;
	}
	wyn.push_back(x);
	int c=0,d,y=wyn.size()-2,e,f=poz.size()-1;
	while(y>=0)
	{
		e=wyn[y]-wyn[y+1];
		if(e>0) wyp.push_back(par('P', e));
		c+=2*e;
		d=wyn[y]-poz[f]-1;
		if(d!=c)
		{
			wyp.push_back(par('S',d-c));
			c=d;
		}
		wyp.push_back(par('X',0));
		y--;
		f--;
	}
	nie<<wyp.size()<<"\n";
	for(int i=0; i<wyp.size(); i++)
	{
		if(wyp[i].f=='X') nie<<"X\n";
		else nie<<wyp[i].f<<" "<<wyp[i].s<<"\n";
	}
	return;
}

void solve()
{
	int a,b,c,d,e,M;
	tak>>n>>m>>a;
	for(int i=0; i<=m; i++) for(int j=0; j<=m; j++) tab[i][j]=ojc[i][j]=1<<30;
	tab[0][0]=0;
	poz.clear();
	trap.clear();
	wyn.clear();
	wyp.clear();
	poz.push_back(0);
	trap.push_back(a);
	for(int i=1; i<=n; i++)
	{
		tak>>b;
		poz.push_back(b);
	}
	for(int i=1; i<=m; i++)
	{
		tak>>b;
		if(b>=a) trap.push_back(b);
	}
	m=trap.size()-1;
	M=m-n;
	for(int i=1; i<=m; i++)
	{
		b=max(0,i-M);
		c=trap[i]-trap[i-1];
		for(int j=i; j>=b; j--)
		{
			d=tab[i-1][j]+2*c;
			if(d>=trap[i]-poz[poz.size()-1-j]) d=1<<30;
			if(j==0) e=1<<30;
			else
			{
				e=tab[i-1][j-1]+2*c;
				if(e>=trap[i]-poz[poz.size()-j]) e=1<<30;
				else e=trap[i]-poz[poz.size()-j]-1;
			}
			if(d==1<<30 && d==e) continue;
			if(d<=e)
			{
				tab[i][j]=d;
				ojc[i][j]=j;
			}
			else
			{
				tab[i][j]=e;
				ojc[i][j]=j-1;
			}
		}
		if(tab[i][n]!=1<<30)
		{
			wypisz(i,a);
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	tak.open("C:\\Users\\Mateusz\\Desktop\\testdata\\pog10.in");
	nie.open("C:\\Users\\Mateusz\\Desktop\\outs\\pog10.out");
	int t;
	tak>>t;
	while(t--) solve();
	tak.close();
	nie.close();
	return 0;
}
