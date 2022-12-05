#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;


//Tworzenie zioru i wypelnianie go liczbami pseudolosowymi 0-10
void randArray(int tab[], int n)
{
	cout<<"\nPrzed sortowaniem:\n\n";
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++) 
	{
		tab[i]=rand()%10;
		cout << setw(2) << tab[i];
	}
	cout<<endl;
}

// To find gap between elements
int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap*10)/13;
 
    if (gap < 1)
        return 1;
    return gap;
}

// Sortowanie grzebieniowe
void combSort(int* tab, int size)
{
   int gap=size, tmp;
   bool swapped=true;
   while (gap>1 || swapped) { // jesli gap = 1 i nie dokonano zamiany - wyjscie z petli     
      gap=getNextGap(gap);
      swapped=false;
      for ( int i=0; i+gap<size; ++i ) // wykonuj od 0 do ostatniego elementu tablicy
	  { 
        if ( tab[i + gap] < tab[i] ) 
		{   // porownanie elementow odleglych o rozpietosc
            swap(tab[i], tab[i+gap]); // zamiana elementow
            swapped = true;
        }
      }
   }
}


int main()
{
	int n;
	cout<<"Podaj dlugosc tablicy: ";
	cin>>n;
	int tab[n];
	randArray(tab, n);
	cout<<endl<<endl;
	combSort(tab, n);
	cout << endl << "Po sortowaniu:\n\n";
	for(int i = 0; i < n; i++) cout << setw(2) << tab[i];	
	cout << endl << endl;
	return 0;
}