#include<iostream>

using namespace std;

int tab[ 1001 ][ 1001 ];

int main()
{
	int c,a,b;
	string A,B;
	cin>>c;
	for (int h=1; h<=c; h++)
	{	
		cin>>a>>A>>b>>B;
		for( int i=0; i<=a; i++)
		{
			for(int j=0; j<=b; j++)
			{
				tab[ i ][ j ]=0;
			}
		}
		for(int i=1; i<=a; i++)
		{
			for(int j=1; j<=b; j++ )
			{
				if(A[i]==B[j])
				{
					tab[ i ][ j ]=tab[ i-1 ][ j-1 ]+1;
				}
				else
				{
					if(tab[ i-1 ][ j ]>tab[ i ][ j-1 ])
					{
						tab[ i ][ j ]= tab[ i-1 ][ j ];
					}
					else {
						tab[ i ][ j ]= tab[ i ][ j-1 ];
					}
				}
			}
		}
		cout<<tab[a][b]<<"\n";
	}
		for(int i=0; i<=a; i++)
		{
			for(int j=0; j<=b; j++ )
			{
				cout<<tab[ i ][ j ];

			}
		}
}
			

