#include <stdio.h>
#include <math.h>


int main(void)
{
    //Opening file
    FILE *ptr;
    ptr = fopen("data3.txt", "r");

    //Defining variables
    double min, max;
    int count, done;
    done = 1;


    //While statement to read file values

    done = fscanf(ptr, "%d", &count);
    done = fscanf(ptr, "%lf", &min);
    done = fscanf(ptr, "%lf", &max);

    double values[count], normalized[count];

    //For loop reading xi
    for (int i = 0; i < count; i++)
    {
        done = fscanf(ptr, "%lf", &values[i]);
    }

    //Finding Xhigh and Xlow
    double minxi, maxxi;
    minxi = values[0];
    maxxi = values[0];

    //For loop to find the values
    for (int i = 0; i < count; i++)
    {
        if (values[i] < minxi)
        {
            minxi = values[i];
        }
        if (values[i] > maxxi)
        {
            maxxi = values[i];
        }

    }

    //Normalizing values and printing final results
    printf("Values\t\tNormalized Values\n-----------------------------\n");

    for (int i = 0; i < count; i++)
    {
        normalized[i] = min + (values[i] - minxi) * (max - min) / (maxxi - minxi);
        printf("%.2lf\t\t%.2lf\n", values[i], normalized[i]);
    }

    return (0);
}
