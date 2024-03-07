#include <stdio.h>
#include <math.h>

int main (void){
	//Vaiable declaration
	char gender, fit, enter;
	int age;
	double MHR, RHR, INTEN, THR;
	
	// Asking for user inputs and getting values
	printf("Please enter your gender (M or F): ");
	scanf ("%c", &gender);
	printf("Please enter your age: ");
	scanf ("%d", &age);
	printf("Please enter your resting heart rate: ");
	scanf ("%lf", &RHR);
	printf("Please enter your fitness level (L, M or H): ");
	scanf (" %c", &fit);
		

	// If else statements to select MHR formula
	if(gender == 'M') {
		MHR = 203.7/(1+exp(0.033 * (age - 104.3)));
	} else { 
		MHR = 190.2/(1+exp(0.0453 * (age - 107.5)));	
	}
	
	// If else statements to set fitness level 	
	if(fit == 'L') {
		INTEN = 0.55;
	} else if (fit == 'M'){ 
		INTEN = 0.65;
	} else if (fit == 'H'){ 
		INTEN = 0.8;
	}

	// Calculating final values
	THR = ((MHR - RHR) * INTEN + RHR);
	printf("Your Training Heart Rate is: %lf", THR);
	
	
	return(0);
}
