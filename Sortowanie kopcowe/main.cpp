#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <fstream>
using namespace std;


//Tworzenie tablicy oraz wypisywanie jej
void inputArray(int arr[], long int size) {
	//cout<<"Przed sortowaniem:\n";
	fstream inFile;
	inFile.open("tablica.txt");
	
	//srand((unsigned)time(NULL));
	for(int i=0; i<size; i++) {
		//arr[i]=rand()%1000;	//wypelnianie jej liczbami pseudolosowymi od 0 do 1000
		inFile>>arr[i];
		cout << setw(2) << arr[i];
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
 
// Wypisywanie posortowanej tablicy n wymiarowej
void printArray(int arr[], int size) {
	ofstream wyjscie;
	wyjscie.open("wyjscie.txt");
    for (int i=0; i<size; i++)
    {
        cout << setw(5) << arr[i];
        //wyjscie<< arr[i]<<" ";
    }
    cout << endl;
    wyjscie.close();
}


int main() {
	clock_t start, stop;
	double czas;
	int n;
	cout<<"Podaj rozmiar losowanej: ";
	cin>>n;
    int arr[n];
    // Losowanie tablicy
 	inputArray(arr, n);
 	start=clock();
    // Wywolanie funkcji heapSort
    heapSort(arr, n);
    stop=clock();
    czas = (double)(stop - start)/CLOCKS_PER_SEC;
    cout << "Po sortowaniu\n";
    //Wypisanie posortowanej tablicy
    printArray(arr, n);
    //printf("%.30f", czas);
    return 0;
}
