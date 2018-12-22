#include<bits/stdc++.h>
using namespace std;

ifstream tak;
ofstream nie;

string s;
int tab[109][109];

void solve()
{
	int n,w=0,a,b;
	tak>>n;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) tab[i][j]=0;
	for(int i=1; i<=n; i++)
	{
		tak>>s;
		for(int j=0; j<n; j++)
		{
			if(s[j]=='#')
			{
				tab[i][j+1]=1;
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(tab[i][j+1]==1)
			{
				if(i>1)
				{
					if(tab[i-1][j+1]==0)
					{
						w++;
						tab[i-1][j+1]=2;
					}
				}
				if(i<n)
				{
					if(tab[i+1][j+1]==0)
					{
						w++;
						tab[i+1][j+1]=2;
					}
				}
				if(j>0)
				{
					if(tab[i][j]==0)
					{
						w++;
						tab[i][j]=2;
					}
				}
				if(j<n-1)
				{
					if(tab[i][j+2]==0)
					{
						w++;
						tab[i][j+2]=2;
					}
				}
			}
		}
	}
	for(int i=1; i<=5; i++) tak>>a;
	tak>>b;
	for(int i=1; i<=2; i++) tak>>a;
	nie<<w<<" "<<w*b<<"\n";
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(tab[i][j]==2) nie<<"6 "<<i<<" "<<j<<"\n";
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	tak.open("C:\\Users\\Mateusz\\Desktop\\testdata\\ksw10.in");
	nie.open("C:\\Users\\Mateusz\\Desktop\\outs\\ksw10.out");
	int t;
	tak>>t;
	while(t--) solve();
	tak.close();
	nie.close();
	return 0;
}
