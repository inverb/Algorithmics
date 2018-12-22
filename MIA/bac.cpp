#include<bits/stdc++.h>
using namespace std;

int tab[100009];
char tac[100009];

int main()
{
	ios_base::sync_with_stdio(0);
	ifstream bac;   
   	bac.open("C:\\Users\\Mateusz\\Desktop\\PIZZA\\testy\\bac10.in");
	bac>>tac;
	bac.close();
	int a=0;
	while(tac[a]!=0)
	{
		tab[a+1]=tac[a]-48;
		a++;
	}
	int b=1,c=0;
	while(b<=a)
	{
		c+=tab[b];
		tab[b]=c/4;
		c%=4;
		c*=10;
		b++;
	}
	b=1;
	while(tab[b]==0) b++;
	ofstream baca;
   	baca.open("C:\\Users\\Mateusz\\Desktop\\bac10.out");
	for(int i=b; i<=a; i++) baca<<tab[i];
	baca.close();
	return 0;
}


