#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <fstream>

using namespace std;

//Tworzenie zioru i wypelnianie go liczbami pseudolosowymi 0-10
void inputArray(int tab[], int size) {
	fstream inFile;
	inFile.open("tablica.txt");
	cout<<"\nPrzed sortowaniem:\n\n";
	//srand((unsigned)time(NULL));
	for(int i=0; i<size; i++) {
		//tab[i]=rand()%1000;
		inFile>>tab[i];
		cout << setw(5) << tab[i];
	}
	cout<<endl;
	inFile.close();
}

// Funkcja znajdujaca odstep miedzy elementami
int getNextGap(int gap) {
    // Zmiejszanie sie odstepu przez wspolczynnik
    gap=(gap*10)/13;
    if (gap < 1)
        return 1;
    return gap;
}

// Sortowanie grzebieniowe
void combSort(int* tab, int size) {
   int gap=size, tmp;
   bool swapped=true;	//zainicjowanie zmiennej prawda/falsz
   while (gap!=1 || swapped) {      // jesli gap=1 lub nie dokonano zamiany - wyjscie z petli
      gap=getNextGap(gap);
      swapped=false;
      // wykonuje od 0 do ostatniego elementu tablicy
      for (int i=0; i+gap<size; i++) {  
        if (tab[i + gap] < tab[i]) { // porownanie elementow odleglych o rozpietosc
            swap(tab[i], tab[i+gap]); // zamiana elementow 
            swapped = true;
        }
      }
   }
}

int main()
{
	clock_t start, stop;
	double czas;
	int n;
	cout<<"Podaj dlugosc tablicy: ";
	cin>>n;
	int tab[n];
	inputArray(tab, n);
	cout<<endl<<endl;
	start=clock();
	//Wywolanie funkcji
	combSort(tab, n);
	stop=clock();
	cout << endl << "Po sortowaniu:\n\n";
	czas = (double)(stop - start)/CLOCKS_PER_SEC;
	cout<<endl<< "czas: "<< czas;
	for(int i = 0; i < n; i++) cout << setw(5) << tab[i];	
	cout << endl << endl;
	return 0;
}