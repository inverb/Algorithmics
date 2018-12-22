#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int tab[1000001];

void ms(int left, int right)
{
	if(left+1==right)return;
	int x=(left+right)/2;
	ms(left, x);
	ms(x , right);
	int r=right;
	int w=left;
	int v=x;
	vector<int> p;
	while( w<x || v<r )
	{
		if( w<x && v<r )
		{
			
		}
		else if( w<x && v>=r )
		{
			
		}
		else if( w>=x && v<r )
		{
			while(v<r)
			{
				
			} 
		}
		
	}
	
}

int main()
{
	int n;
	int tab[ n ];
	for( int i=1; i<=n; i++)
	{
		scanf("%d", tab[i]);
	}
	ms(1, n);
	
	
}
