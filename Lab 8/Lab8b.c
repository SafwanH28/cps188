#include <stdio.h>
#include "mylibrary.h"

int 
main (void)
{
	// Variable declarations
	double array1[10][10], array2[5], result1, result2, result3, result4, result5;
	
	// Opens the file containing the numbers
	FILE *ptr;
	ptr = fopen("L8_real.txt", "r");
	
	// Reading the values and inputting them into variables
	while (!(feof (ptr))){ 
		for(int c = 0; c < 10; ++c){
			for(int d = 0; d < 10; ++d){		
				fscanf (ptr, "%lf", &array1[c][d]); } } } 
	
	// Calling the functions
	result1 = sumdiag(array1);
	result2 = sumall(array1);
	result3 = avright(array1);
	result4 = corners(array1);
	result5 = largeanti(array1); 
	
	// Opening the binary file that values will be written into
	FILE *binary_file;
	binary_file = fopen("results.bin", "wb");
	
	// Writing the values into a binary file
	fwrite (&result1, sizeof(result1), 1, binary_file);
	fwrite (&result2, sizeof(result2), 1, binary_file);
	fwrite (&result3, sizeof(result3), 1, binary_file);
	fwrite (&result4, sizeof(result4), 1, binary_file);
	fwrite (&result5, sizeof(result5), 1, binary_file);
	
	// Closing the binary file
	fclose(binary_file);
	
	// Opening the binary file that the values will be read from
	FILE *binary_file2;
	binary_file2 = fopen("results.bin", "rb");
	
	// Reading values and storing them
	fread (&array2, sizeof(array2), 10, binary_file2);
	
	// Printing all the values
	printf ("\nThe sum of the values in the diagonal (from [0][0] to [9][9]) is %5.1lf.\n", array2[0]);
	printf ("The sum of all of the values is %5.1lf.\n", array2[1]);
	printf ("The average of the last column is %5.1lf.\n", array2[2]);
	printf ("The sum of the 4 corners is %5.1lf.\n", array2[3]);
	printf ("The largest value in the antidiagonal (from [0][9] to [9][0]) is %5.1lf.\n", array2[4]);
	
	// Closing the binary file
	fclose(binary_file2);
	
	return(0);

return(0);
}