#include<bits/stdc++.h>
using namespace std;

ifstream tak;
ofstream nie;

int tab[1000009][4][109], n, M, A, B, C;
string s;

void solve()
{
	int a,b,c,d,wyn=0,sum;
	tak>>n>>M>>A>>B>>C;
	tak>>s;
	for(int i=0; i<=s.size()+1; i++) for(int j=1; j<=3; j++) for(int k=0; k<=100; k++) tab[i][j][k]=0;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='A')
		{
			a=1;
			b=2;
			c=3;
			sum=A;
		}
		else if(s[i]=='B')
		{
			a=2;
			b=1;
			c=3;
			sum=B;
		}
		else
		{
			a=3;
			b=1;
			c=2;
			sum=C;
		}
		d=0;
		for(int j=0; j<=100; j++)
		{
			d=max(d,tab[i][b][j]);
			tab[i+1][b][j]=tab[i][b][j];
			d=max(d,tab[i][c][j]);
			tab[i+1][c][j]=tab[i][c][j];
		}
		tab[i+1][a][sum]=d+sum;
		for(int j=1; j<=100; j++)
		{
			if(tab[i][a][j]==0) continue;
			if(j+sum<M) tab[i+1][a][j+sum] = tab[i][a][j] + j+sum;
			else tab[i+1][a][M] = max(tab[i+1][a][M], tab[i][a][j] + M);
		}
	}
	for(int i=1; i<=3; i++) for(int j=0; j<=100; j++) if(tab[s.size()][i][j]>wyn) wyn=tab[s.size()][i][j];
	nie<<wyn<<"\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	tak.open("C:\\Users\\Mateusz\\Desktop\\testdata\\sta10.in");
	nie.open("C:\\Users\\Mateusz\\Desktop\\outs\\sta10.out");
	int t;
	tak>>t;
	while(t--) solve();
	tak.close();
	nie.close();
	return 0;
}
