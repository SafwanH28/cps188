#include <stdio.h>

double sumdiag(double arr[10][10])
{
	double sum = 0;
	
	sum = arr[0][0] + arr[1][1] + arr[2][2] + arr[3][3] + arr[4][4] + arr[5][5] + arr[6][6] + arr[7][7] + arr[8][8] + arr[9][9];
	
	return(sum);
}

double sumall(double arr[10][10])
{
	double sum=0;
	
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			sum = sum + arr[i][j]; } }
	
	return(sum);
}

double avright(double arr[10][10])
{
	double sum = 0;
	int j = 9;
	
	for(int i = 0; i < 10; ++i)
		sum = sum + arr[i][j];
	
	sum = sum / 10;
	
	return(sum);
}

double corners(double arr[10][10])
{
	double sum = 0;
	
	sum = arr[0][0] + arr[0][9] + arr[9][0] + arr[9][9];
	
	return(sum);
}

double largeanti(double arr[10][10])
{
	double array[10] = {arr[0][9], arr[1][8], arr[2][7], arr[3][6], arr[4][5], arr[5][4], arr[6][3], arr[7][2], arr[8][1], arr[9][0]};
	
	double large = array[0];
	
	for(int i = 1; i < 10; ++i){
		if(array[i] > large)
			large = array[i]; }
		
	
	return(large);
}