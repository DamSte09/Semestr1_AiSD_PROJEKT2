#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

const int N=10;

//Tworzenie zioru i wypelnianie go liczbami pseudolosowymi 0-10
void zbior(int tab[])
{
	cout<<"\nPrzed sortowaniem:\n\n";
	srand((unsigned)time(NULL));
	for(int i=0; i<N; i++) 
	{
		tab[i]=rand()%10;
		cout << setw(2) << tab[i];
	}
	cout<<endl;
}

// Sortowanie grzebieniowe
void combSort(int* tab, int size)
{
   int gap = size, tmp;
   bool swapped = true;
   while (gap > 1 || swapped){ // jesli gap = 1 i nie dokonano zamiany - wyjscie z petli     
      gap = gap * 10 / 13;
      if(gap==0)
            gap=1;
      swapped = false;
      for ( int i = 0; i + gap < size; ++i ) { // wykonuj od 0 do ostatniego elementu tablicy
         if ( tab[i + gap] < tab[i] ) {   // porownanie elementow odleglych o rozpietosc
            tmp = tab[i];                 // zamiana elementow
            tab[i] = tab[i + gap];
            tab[i + gap] = tmp;
            swapped = true;
           }
      }
   }
}


int main()
{
	int tab[N];
	zbior(tab);
	cout<<endl<<endl;
	cout<<"Algorytm sortowania grzebieniowego\n";
	combSort(tab, N);
	cout << endl << "Po sortowaniu:\n\n";
	for(int i = 0; i < N; i++) cout << setw(2) << tab[i];	
	cout << endl << endl;
	return 0;
}