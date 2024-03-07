#include <stdio.h>
#include <math.h>

//Function that determines min medium and high number
int Function(int a, int b, int c, int* highNum, int* lowNum, int* midNum){
	if (a > b && a > c) {
	*(highNum) = a; }
	else if (a < b && a < c) {
	*(lowNum) = a; }
	else {
	*(midNum) = a; }
	
	if (b > a && b > c) {
	*(highNum) = b; }
	else if (b < a && b < c) {
	*(lowNum) = b; }
	else {
	*(midNum) = b; }
	
	if (c >= b && c >= a) {
	*(highNum) = c; }
	else if (c < b && c < a) {
	*(lowNum) = c; }
	else {
	*(midNum) = c; }
	
	if (a == b) {
		if (a > c) {
			*(highNum) = a;
			*(midNum) = a; }
		else {
			*(lowNum) = a;
			*(midNum) = a; }
		}
		
	if (a == c) {
		if (c > b) {
			*(highNum) = c;
			*(midNum) = c; }
		else {
			*(lowNum) = c;
			*(midNum) = c; }
		}
	if (b == c) {
		if (b > a) {
			*(highNum) = b;
			*(midNum) = b; }
		else {
			*(lowNum) = b;
			*(midNum) = b; }
		}
	
	return (0);
}

//Main program
int main(void) {
//Declaring variables
	int a, b, c, result, highNum, midNum, lowNum;
//Asking for user input (3 real numbers)
	printf("Enter your 1st number ");
	scanf("%d", &a);
	printf("Enter your 2nd number ");
	scanf("%d", &b);
	printf("Enter your 3rd number ");
	scanf("%d", &c);
//Calling function
	result = Function(a, b, c, &highNum, &lowNum, &midNum );
//Printing results
	printf("%d\n", lowNum); 
	printf("%d\n", midNum); 
	printf("%d\n", highNum); 

	return (0);
}
