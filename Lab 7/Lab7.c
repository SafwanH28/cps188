#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
//Defining size for array
#define SIZE 500

//Strip function to get rid of spaces and punctuation and change all lettters to lowercase
void strip (char original[], char stripped[])
{
	int i, j;
    //j is the counter for the new string
    j=0;
    
    for (i=0; i<=strlen(original); ++i)
    {
		// Gets rid of spaces and punctualtion by sending char to new string only if letter or number
        if(isalnum(original[i]) || original[i]=='\0')
			{
				stripped[j] = original[i];
				j=j+1;
            }
            
    }
    //Making all characters lowercase   
	for (i=0; i<=strlen(original); ++i)
	{
		stripped[i] = tolower(stripped[i]);
	}
}

//Reverse function to reverse the string 
void reverse (char original[], char reversed[])
{
    int orgLast = strlen(original);
    int revLast = strlen(reversed);
    if (orgLast>0)
    {
        reversed[revLast] = original[orgLast-1];
        original[orgLast-1] = '\0';
        reverse(original, reversed);
    }

}
	
//Main code
int main(void)
{
//Declaring variables
    char input[SIZE], output[SIZE], output2[SIZE], reversed[SIZE];
    for(int i=0; i<SIZE; ++i)
    {
		input[i] = '\0';
		output[i] = '\0';
		reversed[i] = '\0';
		output2[i] = '\0';
	}
	
	//Asking user for input and scanning for user input
    printf("Input your string ");
    fgets(input, SIZE, stdin);
	input[strlen(input)-1] = '\0';
    //Calling strip function
    strip(input, output);
    //Copying output variable
    for(int j=0; j<SIZE; ++j)
    {
		output2[j] = output[j];
	}
	//Calling reverse function
    reverse(output, reversed);
    //Printing Original, stripped and reversed strings
    printf("\nOriginal String: %s\n", input);
    printf("Stripped string: %s\n", output2);
    printf("Reversed string: %s\n\n", reversed);
    
    //If else statement to determine if its a palindrome and to prin
    if(strcmp(output2, reversed)==0)
    {
        printf("This is a palindrome");
    }
    else
    {
		printf("This is not a palindrome");
	 }


    return (0);
}
