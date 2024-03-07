#include <stdio.h>
#include <math.h>

int main(void)
{
  //Opening file
  FILE *ptr;
  ptr = fopen("L4_data.txt", "r");

  //Defining variables
  int empId, shift;
  double wage, pay;
  int done = 1;

  //Printing top headers
  printf("Employee Id \t Total Hours \t Gross Pay \n\n");

  //While statement to scan first 3 columns
  while (done == 1)
  {
    int total;
    total = 0;

    done = fscanf(ptr, "%d", &empId);
    done = fscanf(ptr, "%d", &shift);
    done = fscanf(ptr, "%lf", &wage);

    //For loop to scan and calculate total hours
    for (int i = 0; i < shift; i++)
    {
      int temp;
      done = fscanf(ptr, "%d", &temp);
      total = total + temp;
    }
    //Calculating Gross pay
    if (total <= 15)
    {
      pay = wage * total;
    }
    else if (total <= 25)
    {
      pay = wage * total * 1.05;
    }
    else
    {
      pay = wage * total * 1.1;
    }

    //Printing final results
    if (done == 1)
    {
      printf("%d \t\t %d \t\t %.2lf\n", empId, total, pay);
    }
  }

  return (0);
}
