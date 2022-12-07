#include <stdio.h>
#include <cstdio>

int main()
{
	char text[10]={'\0'};
	int size=0;
	char c=0;
	int i=0;
	int  ilosc_a=0, spaces=0;
	int decyzja=1;
	
	while(decyzja==1)
	{	
		i=0;
		c=0;
		text[10]={'\0'};
		ilosc_a=0; spaces=0; size=0;
		puts("wprowadz tekst");
		printf("%c %d", c, c);
		putchar('\n');
		while(c!='\n') {
			c=getchar();
			text[i]=c;
			i++;
		}
		
		if(i>10)
		{
			puts("wprowadzony tekst jest za dlugi");
		} 
		else
		{
			puts(text);
			i=0;
			while(text[i])
			{
				if(text[i])
				{
					size++;
					if(text[i]=='a') ilosc_a++;
					if(text[i]==' ') spaces++;
				}
				i++;
			}
			
			printf("Dlugosc tekstu:	%d\n", size);
			printf("Liczba liter 'a': %d\n", ilosc_a);
			printf("Liczba spacji:	%d\n", spaces);
		}
		puts("Jesli chcesz kontynuowac wpisz 1");
		scanf("%d", &decyzja);

	}

	return 0;
}
