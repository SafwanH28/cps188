#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define SIZE 500

// int strip(string)
// {
//     char modString

//     return (modString)
// }


int main(void)
{
    char input[SIZE];
    printf("Input your string ");
    fgets(input, SIZE, stdin);
	input[strlen(input)-1] = '\0';
    printf("%s", input);


//    if()
//    {
//        printf("%c", &reverse)
//    }


    return (0);
}
