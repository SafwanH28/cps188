#include <stdio.h>
#include <math.h>

int main (void){
	//Variable declaration
	double weight, height, BMI;
	char* class;
		
	//Asking for user inputs and getting height and weight
	printf("Please enter your weight: ");
	scanf ("%lf", &weight);
	printf("Please enter your height: ");
	scanf ("%lf", &height);
	
	// BMI calculation	
	BMI = (weight/(height*height));
	
	// If else statement to set classification
	if(BMI < 18.5) {
		class = "Underweight";
	} else if (BMI >= 18.5 && BMI < 25){ 
		class = "Normal";
	} else if (BMI >= 25 && BMI < 30){ 
		class = "Overweight";
	} else if (BMI >= 30){ 
		class = "Obese";
	}
	
	//Display result	
	printf ("Your BMI value is %.2lf, which classifies you as %s", BMI, class);
	
	return(0);
}
