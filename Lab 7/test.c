#include <stdio.h>
#include <string.h>
int
main (void)
{
	char city[20], city2[20];
	
	printf ("What is the capital of Canada? ");
	fgets (city, 20, stdin);
	printf ("What is the capital of Argentina? ");
	fgets (city2, 20, stdin);

	// \n kept at end if input smaller than array size
   // replace it with \0
	city[strlen(city)-1] = '\0';
	city2[strlen(city2)-1] = '\0';

	printf ("\nThe capital of Canada is: %s.", city);
	printf ("\nThe capital of Argentina is: %s.", city2);
	return (0);
}

