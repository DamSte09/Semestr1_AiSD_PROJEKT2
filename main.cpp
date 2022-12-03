#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

//liczba elementow
const int N=15;

//Tworzenie zioru i wypelnianie go liczbami pseudolosowymi 0-10
void zbior(int d[])
{
	srand((unsigned)time(NULL));
	for(int i=1; i<=N; i++) d[i]=rand()%10;
}

//Budowanie kopca
void building_heap(int d[])
{
	int	i, j, k, x;
	for(int i=2; i<=N; i++)
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


int main()
{
	cout<<"Algorytm sortowania kopcowego\n";
	
	int d[N+1];

	zbior(d);
	building_heap(d);
	demoliting_heap(d);
	
	cout << endl << "Po sortowaniu:\n\n";
  
	for(int i = 1; i <= N; i++) cout << setw(2) << d[i];

	//Gotowe
	cout << endl << endl;
	return 0;
}