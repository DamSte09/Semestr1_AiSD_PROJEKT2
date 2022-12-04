#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

//liczba elementow
const int N=10;

//Tworzenie zioru i wypelnianie go liczbami pseudolosowymi 0-10
void zbior(int tab[])
{
	cout<<"\nPrzed sortowaniem:\n\n";
	srand((unsigned)time(NULL));
	for(int i=1; i<=N; i++) 
	{
		tab[i]=rand()%10;
		cout << setw(2) << tab[i];
	}
	cout<<endl;
}

//Budowanie kopca
void building_heap(int d[])
{
	int	i, j, k, x;
	for(int i=1; i<=N; i++)
	{
		j=i; k=j/2;
	    x=d[i];
	    while((k>0) && (d[k]<x))
	    {
	    	d[j]=d[k];
	    	j=k; k=j/2;
	    }
	    d[j]=x;
	}
}

//rozbieranie kopca
void demoliting_heap(int d[])
{
	int	m, i, j, k, x;
	for(int i=N; i>1; i--)
	{
		swap(d[1], d[i]);
		j=1; k=2;
		while(k<i)
		{
   			if((k+1<i) && (d[k+1]>d[k]))
    		m=k+1;
    		else
    		m=k;
    		if(d[m]<=d[j]) break;
    		swap(d[j], d[m]);
    		j=m; k=j+j;
		}
	}
}

void combSort(int* tab, int size)
{
   int gap = size, tmp;
   bool swapped = true;
   while (gap > 1 || swapped){ // jeśli gap = 1 i nie dokonano zamiany - wyjście z pętli     
      gap = gap * 10 / 13;
      if(gap==0)
            gap=1;
      swapped = false;
      for ( int i = 0; i + gap < size; ++i ) { // wykonuj od 0 do ostatniego elementu tablicy
         if ( tab[i + gap] < tab[i] ) {   // porównanie elementów odległych o rozpiętość
            tmp = tab[i];                 // zamiana elementów
            tab[i] = tab[i + gap];
            tab[i + gap] = tmp;
            swapped = true;
           }
      }
   }
}

int main()
{
	
	int tab[N+1];
	zbior(tab);
	cout << endl;
	cout<<"Algorytm sortowania kopcowego\n";
	building_heap(tab);
	demoliting_heap(tab);
	cout << endl << "Po sortowaniu:\n\n";
	for(int i = 1; i <= N; i++) cout << setw(2) << tab[i];
	
	cout<<endl<<endl;
	cout<<"Algorytm sortowania grzebieniowego\n";
	combSort(tab, N);
	cout << endl << "Po sortowaniu:\n\n";
	for(int i = 1; i <= N; i++) cout << setw(2) << tab[i];
	
	//Gotowe
	cout << endl << endl;
	return 0;
}