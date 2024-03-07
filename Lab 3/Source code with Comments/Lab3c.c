#include <stdio.h>
#include <math.h>

int main (void){
	// declaring variables
	double quizes[10];
	double lowest, mid, exam, total, quiz_avg, final;
	
	//Asking for user inputs
	printf("Please enter your quiz 1 grade: ");
	scanf ("%lf", &quizes[0]);
	printf("Please enter your quiz 2 grade: ");
	scanf ("%lf", &quizes[1]);
	printf("Please enter your quiz 3 grade: ");
	scanf ("%lf", &quizes[2]);		
	printf("Please enter your quiz 4 grade: ");
	scanf ("%lf", &quizes[3]);		
	printf("Please enter your quiz 5 grade: ");
	scanf ("%lf", &quizes[4]);		
	printf("Please enter your quiz 6 grade: ");
	scanf ("%lf", &quizes[5]);		
	printf("Please enter your quiz 7 grade: ");
	scanf ("%lf", &quizes[6]);		
	printf("Please enter your quiz 8 grade: ");
	scanf ("%lf", &quizes[7]);		
	printf("Please enter your quiz 9 grade: ");
	scanf ("%lf", &quizes[8]);		
	printf("Please enter your quiz 10 grade: ");
	scanf ("%lf", &quizes[9]);
	printf("Please enter your midterm grade: ");
	scanf ("%lf", &mid);		
	printf("Please enter your final exam grade: ");
	scanf ("%lf", &exam);		
	
	// Finding lowest quiz score
	total = 0;
	lowest = quizes[0];
	for (int i = 0; i < 10; i++){
		if (lowest > quizes[i]){
			lowest = quizes[i];
		}
		total =  total + quizes[i];
	}
	
	// Finding quiz avarage
	quiz_avg = (((total - lowest) / 9) * 10);
	
	//Calculating final score using if else statements
	if (mid >= exam) {
		final = (0.25*quiz_avg)+(0.35*mid)+(0.40*exam);
		} else {
			final = (0.25*quiz_avg)+(0.25*mid)+(0.50*exam); 
			}
	// Displaying final grade
	printf("Your final grade is %.2lf", final);
		
	return(0);
}

