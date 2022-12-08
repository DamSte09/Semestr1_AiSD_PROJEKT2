#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <fstream>

using namespace std;


//Tworzenie tablicy oraz wypisywanie jej
void inputArray(int arr[],int tab[], int size) {
	cout<<"Przed sortowaniem:\n";
	fstream inFile;
	inFile.open("tablica.txt");

	//srand((unsigned)time(NULL));
	//for(int i=size-1; i>=0; i--) {
	for(int i=0; i<size; i++) {
		//arr[i]=rand()%1000;	//wypelnianie jej liczbami pseudolosowymi od 0 do 1000
		inFile>>arr[i];
		//if(i>size/2){
		//arr[i]=i;
		tab[i]=arr[i];
		//}
		//else {
		//	arr[i]=rand()%1000;
		//tab[i]=arr[i];
		//}
		cout << setw(5) << arr[i];
	}
	cout<<endl;
	inFile.close();
}

// Ulozenie poddrzewa zakorzenionego w wezle i
// ktory jest indeksem w arr[].
// N jest rozmiarem tablicy
void heapify(int arr[], int size, int i) {
    int largest=i;	// Zainicjowanie largest jako korzenia
    int left=2*i+1;	// lewy potomek = 2*i + 1
    int right=2*i+2;// prawy potomek = 2*i + 2
    // Jesli lewy potomek jest wiekszy niz korzen
    if (left<size && arr[left]>arr[largest])
        largest=left;
    // Jesli prawy potomek jest wiekszy niz korzen
    if (right<size && arr[right]>arr[largest])
        largest=right;
    // Jesli najwiekszy nie jest korzeniem
    if (largest!=i)
	{
        swap(arr[i], arr[largest]);
        // Rekursywne kopcowanie
        heapify(arr, size, largest);
    }    
}
 
// Glowna funkcja wykonujaca sortowanie kopcowe
void heapSort(int arr[], int size) {
    // Budowanie kopca
    for (int i=size/2-1; i>=0; i--)
        heapify(arr, size, i);
    // Wyodrebnianie elementu jeden po drugim z kopca
    for (int i=size-1; i>0; i--) 
	{
        // Przeniesienie korzenia na koniec
        swap(arr[0], arr[i]);
        // Wywolanie max heapify na zredukowanym kopcu
        heapify(arr, i, 0);
    }
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

// Wypisywanie posortowanej tablicy n wymiarowej
void printArray(int arr[],int tab[], int size, double czas1, double czas2) {
	ofstream wyjscie1, wyjscie2;
	wyjscie1.open("wyjscie1.txt");
	wyjscie2.open("wyjscie2.txt");
	
	cout<<"Po sortowaniu: \n";
    for (int i=0; i<size; i++)
    {
        cout << setw(5) << arr[i];
        wyjscie1<< arr[i]<<" ";
    }
    cout << endl;
    for (int i=0; i<size; i++)
    {
        //cout << setw(5) << arr[i];
        wyjscie2<< tab[i]<<" ";
    }
    cout << endl;
    //wyjscie1<< "\nCzas: "<<czas1<<" s";
    putchar('\n');
    //wyjscie2<< "\nCzas: "<< czas2<<" s";
    wyjscie1.close();
    wyjscie2.close();
}


int main() {
	clock_t start1, stop1, start2, stop2;
	double czas1, czas2;
	int n;
	cout<<"Podaj rozmiar wprowadzonej tablicy: ";
	cin>>n;
	cout<<endl;
    int arr[n], tab[n];
    // Losowanie tablicy
 	inputArray(arr, tab, n);
 	
 	start1=clock();
    // Wywolanie funkcji heapSort
    heapSort(arr, n);
    stop1=clock();
    
    start2=clock();
	//Wywolanie funkcji combsort
	combSort(tab, n);
	stop2=clock();
	
    czas1 = (double)(stop1 - start1)/CLOCKS_PER_SEC;
    czas2 = (double)(stop2 - start2)/CLOCKS_PER_SEC;
    
    //cout << "Po sortowaniu\n";
    //Wypisanie posortowanej tablicy
    printArray(arr,tab, n, czas1, czas2);
    cout<<endl;
    printf("Czas sortowania kopcowego: %.30f s", czas1);
    putchar('\n');
    printf("Czas sortowania grzebieniowego: %.30f s", czas2);
    return 0;
}