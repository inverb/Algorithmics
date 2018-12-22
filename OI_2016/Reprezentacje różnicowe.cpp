#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef pair<int,int> par;
typedef pair<int,par> para;
int tab[55] = { 1, 2, 4, 8, 16, 21, 42, 51, 102, 112, 224, 235, 470, 486, 972, 990, 1980, 2002, 4004, 4027, 8054, 8078, 16156, 16181, 32362, 32389, 64778,
				64806, 129612, 129641, 259282, 259313, 518626, 518658, 1037316, 1037349, 2074698, 2074734, 4149468, 4149505, 8299010, 8299049, 16598098,
				16598140, 33196280, 33196324, 66392648, 66392693, 132785386, 132785432, 265570864, 265570912, 531141824, 531141876, 1062283752 };
vector<para> v;

inline void prep()
{
	v.push_back(para(0,par(0,0)));
	for(int i=0; i<55; i++) for(int j=i+1; j<55; j++) v.push_back(para(tab[j]-tab[i], par(i+1, j+1)));
	sort(v.begin(), v.end());
	
	return;
}

int main()
{
	prep();
	int n,a,b,c,d;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a);
		b=0;
		c=v.size()-1;
		while(b<c)
		{
			d=(b+c)/2;
			if(v[d].f>=a) c=d;
			else b=d+1;
		}
		if(v[c].f==a) printf("%d %d\n", v[c].s.s, v[c].s.f);
		else
		{
			a-=b;
			a*=2;
			printf("%d %d\n", 56+a, 55+a);
		}
	}
	return 0;
}
