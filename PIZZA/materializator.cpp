#include<bits/stdc++.h>
using namespace std;

ifstream tak;
ofstream nie;

int c,b,a,k;
int fig[109][109][109], lin[109][109];
string s;

void solve()
{
	int d,e,f,g;
	tak>>a>>b>>c>>k;
	for(int i=0; i<=c+1; i++) for(int j=0; j<=b+1; j++) for(int l=0; l<=a+1; l++) fig[i][j][l]=0;
	for(int j=0; j<=b+1; j++) for(int l=0; l<=a+1; l++) lin[j][l]=0;
	for(int i=1; i<=c; i++)
	{
		for(int j=1; j<=b; j++)
		{
			tak>>s;
			for(int l=0; l<s.size(); l++)
			{
				if(s[l]=='#')
				{
					fig[i][j][l+1]=1;
					lin[j][l+1]++;
				}
			}
		}
	}
	d=e=f=0;
	for(int i=1; i<=b; i++)
	{
		for(int j=1; j<=a; j++)
		{
			if(f<lin[i][j])
			{
				d=i;
				e=j;
				f=lin[i][j];
			}
		}
	}
	for(int i=1; i<=c; i++) fig[i][d][e]=1;
	if(k>=2)
	{
		if(d==b) for(int i=1; i<=c; i++) fig[i][d-1][e]=1;
		else for(int i=1; i<=c; i++) fig[i][d+1][e]=1;
	}
	if(k>=3)
	{
		if(e==a) for(int i=1; i<=c; i++) fig[i][d][e-1]=1;
		else for(int i=1; i<=c; i++) fig[i][d][e+1]=1;
	}
	for(int i=1; i<=c; i++)
	{
		for(int j=1; j<=b; j++)
		{
			if(j%2==1)
			{
				for(int l=1; l<=a; l++)
				{
					if(fig[i][j][l]==1) nie<<"E\n";
					if(l!=a) nie<<"M 1 0\n";
				}
			}
			else
			{
				for(int l=a; l>=1; l--)
				{
					if(fig[i][j][l]==1) nie<<"E\n";
					if(l!=1) nie<<"M -1 0\n";
				}
			}
			if(j!=b) nie<<"M 0 1\n";
		}
		if(b%2==0) for(int j=b; j>=2; j--) nie<<"M 0 -1\n";
		else
		{
			for(int j=b; j>=2; j--) nie<<"M 0 -1\n";
			for(int j=a; j>=2; j--) nie<<"M -1 0\n";
		}
		if(i!=c) nie<<"N\n";
		else nie<<"C\n";
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	tak.open("C:\\Users\\Mateusz\\Desktop\\testdata\\mat10.in");
	nie.open("C:\\Users\\Mateusz\\Desktop\\outs\\mat10.out");
	int t;
	tak>>t;
	while(t--) solve();
	tak.close();
	nie.close();
	return 0;
}
