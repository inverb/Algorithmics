#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;

int tab[10];
int n;

void pisz()
{
	int a=1;
	printf(" 1 | 2 | 3\n-----------\n 4 | 5 | 6\n-----------\n 7 | 8 | 9\n\n\n");
	for(int i=1; i<=9; i++)
	{
		if(tab[i]==0) printf("   ");
		else if(tab[i]==1) printf(" X ");
		else printf(" O ");
		if(i%3!=0) printf("|");
		else
		{
			if(i==9) printf("\n\n\n");
			else printf("\n-----------\n");
		}
	}
	return;
}

int spr()
{
	for(int i=1; i<=3; i++)
	{
		if(tab[i]==tab[i+3] && tab[i]==tab[i+6] && tab[i]!=0) return tab[i];
		int a=3*(i-1)+1;
		if(tab[a]==tab[a+1] && tab[a]==tab[a+2] && tab[a]!=0) return tab[a];
	}
	if(tab[1]==tab[5] && tab[1]==tab[9] && tab[1]!=0) return tab[1];
	if(tab[3]==tab[5] && tab[3]==tab[7] && tab[3]!=0) return tab[3];
	return 0;
}

void dodaj()
{
	int a;
	if(tab[1]==1 && tab[2]==1 && tab[3]==0) tab[3]=2;
	else if(tab[1]==1 && tab[2]==0 && tab[3]==1) tab[2]=2;
	else if(tab[1]==0 && tab[2]==1 && tab[3]==1) tab[1]=2;
	else if(tab[4]==1 && tab[5]==1 && tab[6]==0) tab[6]=2;
	else if(tab[4]==1 && tab[5]==0 && tab[6]==1) tab[5]=2;
	else if(tab[4]==0 && tab[5]==1 && tab[6]==1) tab[4]=2;
	else if(tab[7]==1 && tab[8]==1 && tab[9]==0) tab[9]=2;
	else if(tab[7]==1 && tab[8]==0 && tab[9]==1) tab[8]=2;
	else if(tab[7]==0 && tab[8]==1 && tab[9]==1) tab[7]=2;
	else if(tab[1]==1 && tab[4]==1 && tab[7]==0) tab[7]=2;
	else if(tab[1]==1 && tab[4]==0 && tab[7]==1) tab[4]=2;
	else if(tab[1]==0 && tab[4]==1 && tab[7]==1) tab[1]=2;
	else if(tab[2]==1 && tab[5]==1 && tab[8]==0) tab[8]=2;
	else if(tab[2]==1 && tab[5]==0 && tab[8]==1) tab[5]=2;
	else if(tab[2]==0 && tab[5]==1 && tab[8]==1) tab[2]=2;
	else if(tab[3]==1 && tab[6]==1 && tab[9]==0) tab[9]=2;
	else if(tab[3]==1 && tab[6]==0 && tab[9]==1) tab[6]=2;
	else if(tab[3]==0 && tab[6]==1 && tab[9]==1) tab[3]=2;
	else if(tab[1]==1 && tab[5]==1 && tab[9]==0) tab[9]=2;
	else if(tab[1]==1 && tab[5]==0 && tab[9]==1) tab[5]=2;
	else if(tab[1]==0 && tab[5]==1 && tab[9]==1) tab[1]=2;
	else if(tab[3]==1 && tab[5]==1 && tab[7]==0) tab[7]=2;
	else if(tab[3]==1 && tab[5]==0 && tab[7]==1) tab[5]=2;
	else if(tab[3]==0 && tab[5]==1 && tab[7]==1) tab[3]=2;
	else
	{
		while(true)
		{
			a=rand();
			a%=9;
			a++;
			if(tab[a]==0)
			{
				tab[a]=2;
				break;
			}
		}
	}
	return;
}

int main()
{
	int m,k=0;
	srand(time(NULL));
	pisz();
	printf("Jestes X. ");
	for(int i=1; i<=5; i++)
	{
		printf("Wpisz numer pola, ktore chcesz skreslic: ");
		scanf("%d", &n);
		if(tab[n]!=0)
		{
			printf("\n Zle skreslenie. ");
			continue;
		}
		tab[n]=1;
		k++;
		m=spr();
		printf("\n\n\n");
		if(m!=0) break;
		if(k==9) break;
		dodaj();
		k++;
		m=spr();
		if(m!=0) break;
		pisz();
	}
	pisz();
	if(m==1)
	{
		printf("GRATULACJE! WYGRALES!\nAby zagrac jeszcze raz wcisnij '1', aby wyjsc wcisnij '0': ");
		scanf("%d", &n);
		if(n==1) cout << ShellExecute( NULL, "open", "C:\\Users\\Mateusz\\Desktop\\szko³a kochane LOXIV\\informatyka\\C++\\zagrajmy_w_mala_gre.exe",
		NULL, NULL, SW_SHOWNORMAL ) << endl;
	}
	else if(m==2)
	{
		printf("PRZEGRALES.\nAby zagrac jeszcze raz wcisnij '1', aby wyjsc wcisnij '0': ");
		scanf("%d", &n);
		if(n==1) cout << ShellExecute( NULL, "open", "C:\\Users\\Mateusz\\Desktop\\szko³a kochane LOXIV\\informatyka\\C++\\zagrajmy_w_mala_gre.exe",
		NULL, NULL, SW_SHOWNORMAL ) << endl;
	}
	else if(m==0)
	{
		printf("REMIS.\nAby zagrac jeszcze raz wcisnij '1', aby wyjsc wcisnij '0': ");
		scanf("%d", &n);
		if(n==1) cout << ShellExecute( NULL, "open", "C:\\Users\\Mateusz\\Desktop\\szko³a kochane LOXIV\\informatyka\\C++\\zagrajmy_w_mala_gre.exe",
		NULL, NULL, SW_SHOWNORMAL ) << endl;
	}
	return 0;
}
