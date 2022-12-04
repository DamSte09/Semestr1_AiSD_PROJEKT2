#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;


//Tworzenie tablicy i wypelnianie jej liczbami pseudolosowymi od 0 do 10
// Oraz wypisywanie jej
void randArray(int arr[], int N)
{
	cout<<"Przed sortowaniem:\n";
	srand((unsigned)time(NULL));
	for(int i=0; i<N; i++)
	{
		arr[i]=rand()%10;
		cout << setw(2) << arr[i];
	}
	cout<<endl;
}

// Do ulozenia poddrzewa zakorzenionego w wezle i
// ktory jest indeksem w arr[].
// N jest rozmiarem tablicy
void heapify(int arr[], int N, int i)
{
    // Zainicjowanie najwiekszego jako korzenia
    int largest=i;
    // lewy potomek = 2*i + 1
    int l=2*i+1;
    // prawy potomek = 2*i + 2
    int r=2*i+2;
    // Jesli lewy potomek jest wiekszy niz korzen
    if (l<N && arr[l]>arr[largest])
        largest=l;
    // Jesli prawy potomek jest wiekszy niz korzen
    // do tej pory
    if (r<N && arr[r]>arr[largest])
        largest=r;
    // Jesli najwiekszy nie jest korzeniem
    if (largest!=i)
	{
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Glowna funkcja wykonujaca sortowanie kopcowe
void heapSort(int arr[], int N)
{
 
    // Budowanie kopca (rearrange array)
    for (int i=N/2-1; i>=0; i--)
        heapify(arr, N, i);
    // Wyodrebnij element jeden po drugim z kopca
    for (int i=N-1; i>0; i--) 
	{
        // Przeniesienie korzenia na koniec
        swap(arr[0], arr[i]);
        // Wywolanie max heapify na zredukowanym kopcu
        heapify(arr, i, 0);
    }
}
 
// Funkcja do wypisywania posortowanej tablicy n wymiarowej
void printArray(int arr[], int N)
{
    for (int i=0; i<N; i++)
        cout << setw(2) << arr[i];
    cout << endl;
}


int main()
{
	int n;
	cout<<"Podaj rozmiar tablicy ktora bedzie wylosowana: ";
	cin>>n;
    int arr[n];
    // Wywolanie funkcji tab
 	randArray(arr, n);
    // Wywolanie funkcji heapSort
    heapSort(arr, n);
    cout << "Po sortowaniu\n";
    printArray(arr, n);
    return 0;
}
