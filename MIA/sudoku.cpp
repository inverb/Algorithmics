#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int tab[90];
vector<vector<int> > v1;
queue<int> kol;
int n,m;

void czyt()
{
	printf("Wpisz liczby wierszami, zaczynajac o lewego gornego rogu. Gdy kratka jest pusta wpisuj 0.\n");
	for(int i=1; i<=81; i++){
		scanf("%d", &tab[i]);
		if(tab[i]==0) n++;	
	}
	return;
}

void solve()
{
	for
	
	while(n--)
	{
		
	}
}

void wypisz()
{
	for(int i=1; i<=81; i++)
	{
		printf(" %d ", tab[i]);
		if(i==81) break;
		if(i%9==0)
		{
			int j=i/9;
			printf("\n------------------------------------\n");
			if(j%3==0) printf("------------------------------------\n");
		}
		else if(i%3==0) printf("||");
		else printf("|");
	}
	
	return;
}

int main()
{
	czyt();
	solve();
	wypisz();
	return 0;
}
