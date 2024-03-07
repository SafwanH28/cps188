#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const int TOTAL_DAYS = 366;
const char *DATA_FILE = "data.txt";
const char *DATA_FILE2 = "data2019.txt";

//Function to get average (Question 1)
double get_avg(double Lake[])
{
    double temp, total;
    total = 0;
    temp = 0;
    for (int i = 0; i < TOTAL_DAYS; i++)
    {
        temp = temp + Lake[i];
    }

    total = temp / TOTAL_DAYS;
    return (total);
}

//Function to get average (Question 9)
double get_avg2(double Lake[])
{
    double temp, total;
    total = 0;
    temp = 0;
    for (int i = 0; i < 365; i++)
    {
        temp = temp + Lake[i];
    }

    total = temp / 365;
    return (total);
}

//Function finds highest value from the given input(the averages) to find hottest lake 
char *get_max(double average_sup, double average_mich, double average_huron, double average_erie, double average_ont, double average_clr)
{
    char *warmest;
    if (average_sup > average_mich, average_sup > average_huron, average_sup > average_erie, average_sup > average_ont, average_sup > average_clr)
    {
        warmest = "Lake Superior";
    }
    else if (average_mich > average_sup, average_mich > average_huron, average_mich > average_erie, average_mich > average_ont, average_mich > average_clr)
    {
        warmest = "Lake Michigan";
    }
    else if (average_huron > average_mich, average_huron > average_sup, average_huron > average_erie, average_huron > average_ont, average_huron > average_clr)
    {
        warmest = "Lake Huron";
    }
    else if (average_erie > average_mich, average_erie > average_huron, average_erie > average_sup, average_erie > average_ont, average_erie > average_clr)
    {
        warmest = "Lake Erie";
    }
    else if (average_ont > average_mich, average_ont > average_huron, average_ont > average_erie, average_ont > average_sup, average_ont > average_clr)
    {
        warmest = "Lake Ontario";
    }
    else
    {
        warmest = "Lake St Clair";
    }
    return (warmest);
}

//Function finds lowest value from the given input(the averages) to find coldest lake 
char *get_min(double average_sup, double average_mich, double average_huron, double average_erie, double average_ont, double average_clr)
{
    char *coldest;
    if (average_sup < average_mich, average_sup < average_huron, average_sup < average_erie, average_sup < average_ont, average_sup < average_clr)
    {
        coldest = "Lake Superior";
    }
    else if (average_mich < average_sup, average_mich < average_huron, average_mich < average_erie, average_mich < average_ont, average_mich < average_clr)
    {
        coldest = "Lake Michigan";
    }
    else if (average_huron < average_mich, average_huron < average_sup, average_huron < average_erie, average_huron < average_ont, average_huron < average_clr)
    {
        coldest = "Lake Huron";
    }
    else if (average_erie < average_mich, average_erie < average_huron, average_erie < average_sup, average_erie < average_ont, average_erie < average_clr)
    {
        coldest = "Lake erie";
    }
    else if (average_ont < average_mich, average_ont < average_huron, average_ont < average_erie, average_ont < average_sup, average_ont < average_clr)
    {
        coldest = "Lake Ontario";
    }
    else
    {
        coldest = "Lake St Clair";
    }
    return (coldest);
}

//Function compares each average to the total average to see if the given average is higher or lower than the total average
char *compare(double Lake, double total_avg)
{
    char *result;
    if (Lake > total_avg)
    {
        result = "HIGHER";
    }
    else
    {
        result = "LOWER";
    }
    return (result);
}

//Function takes in day (1-366) and converts it to month-date format
void date_conversion(int day, int result[])
{
    int total_days = 0;
    int month, date;
    int days_in_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < 12; i++)
    {
        total_days = total_days + days_in_month[i];
        if (day <= total_days)
        {
            month = i + 1;
            date = day - (total_days - days_in_month[i]);
            break;
        }
    }
    result[0] = month;
    result[1] = date;
}

//Function specifially finds the name of the month when given a number value for the month (ex.1=Jan 2=Feb etc) 
char *name_of_month(int month)
{
    if (month == 1)
        return "January";
    if (month == 2)
        return "February";
    if (month == 3)
        return "March";
    if (month == 4)
        return "April";
    if (month == 5)
        return "May";
    if (month == 6)
        return "June";
    if (month == 7)
        return "July";
    if (month == 8)
        return "August";
    if (month == 9)
        return "September";
    if (month == 10)
        return "October";
    if (month == 11)
        return "November";
    if (month == 12)
        return "December";
}

//Function finds the warmest day for each lake
double find_warmest_day(double lake[], int dates[], int *total_dates)
{
    double hottest = lake[0];
    int num_days = 0;
    for (int i = 0; i < 366; i++)
    {
        if (hottest < lake[i])
        {
            hottest = lake[i];
        }
    }

    for (int i = 0; i < 366; i++)
    {
        if (lake[i] == hottest)
        {
            dates[num_days] = i;
            num_days++;
        }
    }
    *(total_dates) = num_days;
    return (hottest);
}

//Function finds the coldest day for each lake
double find_coldest_day(double lake[], int dates[], int *total_dates)
{
    double coldest = lake[0];
    int num_days = 0;
    for (int i = 0; i < 366; i++)
    {
        if (coldest > lake[i])
        {
            coldest = lake[i];
        }
    }

    for (int i = 0; i < 366; i++)
    {
        if (lake[i] == coldest)
        {
            dates[num_days] = i;
            num_days++;
        }
    }
    *(total_dates) = num_days;
    return (coldest);
}

//Function finds the warmest lakes name
char *find_warmest_lake_name(double lake, double lake2, double lake3, double lake4, double lake5, double lake6)
{
    char *name;
    if (lake > lake2, lake > lake3, lake > lake4, lake > lake5, lake > lake6)
    {
        name = "Lake Superior";
    }
    else if (lake2 > lake, lake2 > lake3, lake2 > lake4, lake2 > lake5, lake2 > lake6)
    {
        name = "Lake Michigan";
    }
    else if (lake3 > lake2, lake3 > lake, lake3 > lake4, lake3 > lake5, lake3 > lake6)
    {
        name = "Lake Huron";
    }
    else if (lake4 > lake2, lake4 > lake3, lake4 > lake, lake4 > lake5, lake4 > lake6)
    {
        name = "Lake Erie";
    }
    else if (lake5 > lake2, lake5 > lake3, lake5 > lake4, lake5 > lake, lake5 > lake6)
    {
        name = "Lake Ontario";
    }
    else
    {
        name = "Lake St Clair";
    }
    return (name);
}

//Function finds the coldest lakes name
char *find_coldest_lake_name(double lake, double lake2, double lake3, double lake4, double lake5, double lake6)
{
    char *name;
    if (lake < lake2, lake < lake3, lake < lake4, lake < lake5, lake < lake6)
    {
        name = "Lake Superior";
    }
    else if (lake2 < lake, lake2 < lake3, lake2 < lake4, lake2 < lake5, lake2 < lake6)
    {
        name = "Lake Michigan";
    }
    else if (lake3 < lake2, lake3 < lake, lake3 < lake4, lake3 < lake5, lake3 < lake6)
    {
        name = "Lake Huron";
    }
    else if (lake4 < lake2, lake4 < lake3, lake4 < lake, lake4 < lake5, lake4 < lake6)
    {
        name = "Lake Erie";
    }
    else if (lake5 < lake2, lake5 < lake3, lake5 < lake4, lake5 < lake, lake5 < lake6)
    {
        name = "Lake Ontario";
    }
    else
    {
        name = "Lake St Clair";
    }
    return (name);
}

//Function finds the warmest lakes temp
double find_warmest_lake_temp(double lake, double lake2, double lake3, double lake4, double lake5, double lake6)
{
    double temp[6];
    temp[0] = lake;
    temp[1] = lake2;
    temp[2] = lake3;
    temp[3] = lake4;
    temp[4] = lake5;
    temp[5] = lake6;
    // printf("\n\n%lf\n\n", lake);
    // printf("\n\n%lf\n\n", lake2);
    // printf("\n\n%lf\n\n", lake3);
    // printf("\n\n%lf\n\n", lake4);
    // printf("\n\n%lf\n\n", lake5);
    // printf("\n\n%lf\n\n", lake6);

    double hottest = temp[0];
    int num_days = 0;
    for (int i = 0; i < 6; i++)
    {
        // printf("\n\n%lf\n\n", temp[i]);
        if (hottest < temp[i])
        {
            hottest = temp[i];
        }
    }
    return (hottest);
}

//Function finds the coldest lakes temp
double find_coldest_lake_temp(double lake, double lake2, double lake3, double lake4, double lake5, double lake6)
{
    double temp[6];
    temp[0] = lake;
    temp[1] = lake2;
    temp[2] = lake3;
    temp[3] = lake4;
    temp[4] = lake5;
    temp[5] = lake6;

    double coldest = temp[0];
    int num_days = 0;
    for (int i = 0; i < 6; i++)
    {
        if (coldest > temp[i])
        {
            coldest = temp[i];
        }
    }
    return (coldest);
}

//Function finds the number of days you can swim in the lake
int swimdays(double lake[])
{
    int count = 0;
    for (int i = 0; i < 366; i++)
    {
        {
            if (lake[i] > 20)
                count++;
        }
    }
    return (count);
}

//Function finds the number of days the lake is frozen
int frozendays(double lake[])
{
    int count = 0;
    for (int i = 0; i < 366; i++)
    {
        {
            if (lake[i] < 0)
                count++;
        }
    }
    return (count);
}

//Function finds summer average of the lake
double get_summer_avg(double lake[])
{
    double temp, total;
    total = 0;
    temp = 0;
    for (int i = 171; i < 265; i++)
    {
        temp = temp + lake[i];
    }

    total = temp / 94;
    return (total);
}

//Function finds winter average of the lake
double get_winter_avg(double lake[])
{
    double temp, total, temp2;
    total = 0;
    temp = 0;
    temp2 = 0;
    for (int i = 0; i < 79; i++)
    {
        temp = temp + lake[i];
    }
    for (int i = 354; i < 366; i++)
    {
        temp2 = temp2 + lake[i];
    }

    total = (temp + temp2) / 91;
    return (total);
}

//Sorting algo used to sort lakes from warmest to coldest in Q5/Q6
void sort_avg(double avg1, double avg2, double avg3, double avg4, double avg5, double avg6, double sorted_avg[], bool desc)
{
    double inf = 999999;
    if (desc)
    {
        inf = -999999;
    }
    double temp_arr[6];
    temp_arr[0] = avg1;
    temp_arr[1] = avg2;
    temp_arr[2] = avg3;
    temp_arr[3] = avg4;
    temp_arr[4] = avg5;
    temp_arr[5] = avg6;
    double largest = avg1;
    int largest_idx = 0;
    for (int i = 0; i < 6; i++)
    {
        double largest = inf;
        for (int j = 0; j < 6; j++)
        {
            if (desc)
            {
                if (temp_arr[j] > largest)
                {
                    largest = temp_arr[j];
                    largest_idx = j;
                }
            }
            else
            {
                if (temp_arr[j] < largest)
                {
                    largest = temp_arr[j];
                    largest_idx = j;
                }
            }
        }
        sorted_avg[5 - i] = largest;
        temp_arr[largest_idx] = inf;
    }
}

//Main function which calculates everything using the functions above
int main(void)
{
    //Opening file
    FILE *ptr;
    ptr = fopen(DATA_FILE, "r");

    // Defining variables
    double sup[TOTAL_DAYS], mich[TOTAL_DAYS], huron[TOTAL_DAYS], erie[TOTAL_DAYS], clr[TOTAL_DAYS], ont[TOTAL_DAYS];
    double average_sup, average_mich, average_huron, average_erie, average_ont, average_clr, total_avg;
    int hottest_dates[TOTAL_DAYS], coldest_dates[TOTAL_DAYS];
    double hottest_temp, coldest_temp;
    char *hottest_lake;
    char *coldest_lake;
    char *above_avg_lake;
    int year[TOTAL_DAYS], day[TOTAL_DAYS], done;
    int year2[TOTAL_DAYS], day2[TOTAL_DAYS];
    done = 1;

    //For loop statement to read file values and store them
    for (int i = 0; i < TOTAL_DAYS; i++)
    {
        done = fscanf(ptr, "%d", &year[i]);
        done = fscanf(ptr, "%d", &day[i]);
        done = fscanf(ptr, "%lf", &sup[i]);
        done = fscanf(ptr, "%lf", &mich[i]);
        done = fscanf(ptr, "%lf", &huron[i]);
        done = fscanf(ptr, "%lf", &erie[i]);
        done = fscanf(ptr, "%lf", &ont[i]);
        done = fscanf(ptr, "%lf", &clr[i]);
    }

    //Closing the file
    fclose(ptr);

    // Question 1 -----------------------------------------------------------------------------------------------------------------------------
    printf("\nQuestion 1\n");

    //Getting the average of each lake
    average_sup = get_avg(sup);
    average_mich = get_avg(mich);
    average_huron = get_avg(huron);
    average_erie = get_avg(erie);
    average_ont = get_avg(ont);
    average_clr = get_avg(clr);
    printf("\nThe average of Lake Superior is %.2lf°C\n", average_sup);
    printf("The average of Lake Michigan is %.2lf°C\n", average_mich);
    printf("The average of Lake Huron is %.2lf°C\n", average_huron);
    printf("The average of Lake Erie is %.2lf°C\n", average_erie);
    printf("The average of Lake Ontario is %.2lf°C\n", average_ont);
    printf("The average of Lake St. Clair is %.2lf°C\n", average_clr);

    //Finding total avg
    total_avg = (average_sup + average_mich + average_huron + average_erie + average_ont + average_clr) / 6;
    printf("The average of all 6 lakes together is %.2lf°C\n", total_avg);

    // Question 2 -----------------------------------------------------------------------------------------------------------------------------
    printf("\nQuestion 2\n");

    //Finding hottest/coldest lake
    hottest_lake = get_max(average_sup, average_mich, average_huron, average_erie, average_ont, average_clr);
    coldest_lake = get_min(average_sup, average_mich, average_huron, average_erie, average_ont, average_clr);
    printf("\nthe hottest lake is %s\n", hottest_lake);
    printf("the coldest lake is %s\n", coldest_lake);
    
    //Finding if lakes avg temp is above or below total avg
    above_avg_lake = compare(average_sup, total_avg);
    printf("\nThe average temparature of Lake Superior is %s than the average of all lakes combined\n", above_avg_lake);
    above_avg_lake = compare(average_mich, total_avg);
    printf("The average temparature of Lake Michigan is %s than the average of all lakes combined\n", above_avg_lake);
    above_avg_lake = compare(average_huron, total_avg);
    printf("The average temparature of Lake Huron is %s than the average of all lakes combined\n", above_avg_lake);
    above_avg_lake = compare(average_erie, total_avg);
    printf("The average temparature of Lake Erie is %s than the average of all lakes combined\n", above_avg_lake);
    above_avg_lake = compare(average_ont, total_avg);
    printf("The average temparature of Lake Ontario is %s than the average of all lakes combined\n", above_avg_lake);
    above_avg_lake = compare(average_clr, total_avg);
    printf("The average temparature of Lake St. Clair is %s than the average of all lakes combined\n", above_avg_lake);

    // Question 3 -----------------------------------------------------------------------------------------------------------------------------
    printf("\nQuestion 3\n");

    int total_hottest_days_sup, total_hottest_days_mich, total_hottest_days_huron, total_hottest_days_erie, total_hottest_days_ont, total_hottest_days_clr;
    int total_coldest_days_sup, total_coldest_days_mich, total_coldest_days_huron, total_coldest_days_erie, total_coldest_days_ont, total_coldest_days_clr;

    //Finding date and temp for warmest and coldest days of each lake
    // lake superior
    double hottest_temp_sup, coldest_temp_sup;
    int hottest_dates_sup[TOTAL_DAYS], coldest_dates_sup[TOTAL_DAYS];
    hottest_temp_sup = find_warmest_day(sup, hottest_dates_sup, &total_hottest_days_sup);
    coldest_temp_sup = find_coldest_day(sup, coldest_dates_sup, &total_coldest_days_sup);
    printf("\nLake Superior was the hottest on: ");
    for (int i = 0; i < total_hottest_days_sup; i++)
    {
        int temp_res[2];
        char *final_string;
        date_conversion(hottest_dates_sup[i], temp_res);
        printf(name_of_month(temp_res[0]));
        printf(" %d", temp_res[1]);
        if (i != total_hottest_days_sup - 1)
            printf(", ");
    }
    printf(" and its temparature was %.2lf°C", hottest_temp_sup);
    printf("\n");
    printf("Lake Superior was the coldest on: ");
    for (int i = 0; i < total_coldest_days_sup; i++)
    {
        int temp_res[2];
        char *final_string;
        date_conversion(coldest_dates_sup[i], temp_res);
        printf(name_of_month(temp_res[0]));
        printf(" %d", temp_res[1]);
        if (i != total_coldest_days_sup - 1)
            printf(", ");
    }
    printf(" and its temparature was %.2lf°C", coldest_temp_sup);
    printf("\n");

    // lake michigan
    double hottest_temp_mich, coldest_temp_mich;
    int hottest_dates_mich[TOTAL_DAYS], coldest_dates_mich[TOTAL_DAYS];
    hottest_temp_mich = find_warmest_day(mich, hottest_dates_mich, &total_hottest_days_mich);
    coldest_temp_mich = find_coldest_day(mich, coldest_dates_mich, &total_coldest_days_mich);
    printf("Lake Michigan was the hottest on: ");
    for (int i = 0; i < total_hottest_days_mich; i++)
    {
        int temp_res[2];
        date_conversion(hottest_dates_mich[i], temp_res);
        printf(name_of_month(temp_res[0]));
        printf(" %d", temp_res[1]);
        if (i != total_hottest_days_mich - 1)
            printf(", ");
    }
    printf(" and its temparature was %.2lf°C", hottest_temp_mich);
    printf("\n");
    printf("Lake Michigan was the coldest on: ");
    for (int i = 0; i < total_coldest_days_mich; i++)
    {
        int temp_res[2];
        date_conversion(coldest_dates_mich[i], temp_res);
        printf(name_of_month(temp_res[0]));
        printf(" %d", temp_res[1]);
        if (i != total_coldest_days_mich - 1)
            printf(", ");
    }
    printf(" and its temparature was %.2lf°C", coldest_temp_mich);
    printf("\n");

    // lake huron
    double hottest_temp_huron, coldest_temp_huron;
    int hottest_dates_huron[TOTAL_DAYS], coldest_dates_huron[TOTAL_DAYS];
    hottest_temp_huron = find_warmest_day(huron, hottest_dates_huron, &total_hottest_days_huron);
    coldest_temp_huron = find_coldest_day(huron, coldest_dates_huron, &total_coldest_days_huron);
    printf("Lake Huron was the hottest on: ");
    for (int i = 0; i < total_hottest_days_huron; i++)
    {
        int temp_res[2];
        date_conversion(hottest_dates_huron[i], temp_res);
        printf(name_of_month(temp_res[0]));
        printf(" %d", temp_res[1]);
        if (i != total_hottest_days_huron - 1)
            printf(", ");
    }
    printf(" and its temparature was %.2lf°C", hottest_temp_huron);
    printf("\n");
    printf("Lake Huron was the coldest on: ");
    for (int i = 0; i < total_coldest_days_huron; i++)
    {
        int temp_res[2];
        date_conversion(coldest_dates_huron[i], temp_res);
        printf(name_of_month(temp_res[0]));
        printf(" %d", temp_res[1]);
        if (i != total_coldest_days_huron - 1)
            printf(", ");
    }
    printf(" and its temparature was %.2lf°C", coldest_temp_huron);
    printf("\n");

    // lake erie
    double hottest_temp_erie, coldest_temp_erie;
    int hottest_dates_erie[TOTAL_DAYS], coldest_dates_erie[TOTAL_DAYS];
    hottest_temp_erie = find_warmest_day(erie, hottest_dates_erie, &total_hottest_days_erie);
    coldest_temp_erie = find_coldest_day(erie, coldest_dates_erie, &total_coldest_days_erie);
    printf("Lake Erie was the hottest on: ");
    for (int i = 0; i < total_hottest_days_erie; i++)
    {
        int temp_res[2];
        date_conversion(hottest_dates_erie[i], temp_res);
        printf(name_of_month(temp_res[0]));
        printf(" %d", temp_res[1]);
        if (i != total_hottest_days_erie - 1)
            printf(", ");
    }
    printf(" and its temparature was %.2lf°C", hottest_temp_erie);
    printf("\n");
    printf("Lake Erie was the coldest on: ");
    for (int i = 0; i < total_coldest_days_erie; i++)
    {
        int temp_res[2];
        date_conversion(coldest_dates_erie[i], temp_res);
        printf(name_of_month(temp_res[0]));
        printf(" %d", temp_res[1]);
        if (i != total_coldest_days_erie - 1)
            printf(", ");
    }
    printf(" and its temparature was %.2lf°C", coldest_temp_erie);
    printf("\n");

    // lake ontario
    double hottest_temp_ont, coldest_temp_ont;
    int hottest_dates_ont[TOTAL_DAYS], coldest_dates_ont[TOTAL_DAYS];
    hottest_temp_ont = find_warmest_day(ont, hottest_dates_ont, &total_hottest_days_ont);
    coldest_temp_ont = find_coldest_day(ont, coldest_dates_ont, &total_coldest_days_ont);
    printf("Lake Ontario was the hottest on: ");
    for (int i = 0; i < total_hottest_days_ont; i++)
    {
        int temp_res[2];
        date_conversion(hottest_dates_ont[i], temp_res);
        printf(name_of_month(temp_res[0]));
        printf(" %d", temp_res[1]);
        if (i != total_hottest_days_ont - 1)
            printf(", ");
    }
    printf(" and its temparature was %.2lf°C", hottest_temp_ont);
    printf("\n");
    printf("Lake Ontario was the coldest on: ");
    for (int i = 0; i < total_coldest_days_ont; i++)
    {
        int temp_res[2];
        date_conversion(coldest_dates_ont[i], temp_res);
        printf(name_of_month(temp_res[0]));
        printf(" %d", temp_res[1]);
        if (i != total_coldest_days_ont - 1)
            printf(", ");
    }
    printf(" and its temparature was %.2lf°C", coldest_temp_ont);
    printf("\n");

    // lake st clair
    double hottest_temp_clr, coldest_temp_clr;
    int hottest_dates_clr[TOTAL_DAYS], coldest_dates_clr[TOTAL_DAYS];
    hottest_temp_clr = find_warmest_day(clr, hottest_dates_clr, &total_hottest_days_clr);
    coldest_temp_clr = find_coldest_day(clr, coldest_dates_clr, &total_coldest_days_clr);
    printf("Lake St Clair was the hottest on: ");
    for (int i = 0; i < total_hottest_days_clr; i++)
    {
        int temp_res[2];
        date_conversion(hottest_dates_clr[i], temp_res);
        printf(name_of_month(temp_res[0]));
        printf(" %d", temp_res[1]);
        if (i != total_hottest_days_clr - 1)
            printf(", ");
    }
    printf(" and its temparature was %.2lf°C", hottest_temp_clr);
    printf("\n");
    printf("Lake St Clair was the coldest on: ");
    for (int i = 0; i < total_coldest_days_clr; i++)
    {
        int temp_res[2];
        date_conversion(coldest_dates_clr[i], temp_res);
        printf(name_of_month(temp_res[0]));
        printf(" %d", temp_res[1]);
        if (i != total_coldest_days_clr - 1)
            printf(", ");
    }
    printf(" and its temparature was %.2lf°C", coldest_temp_clr);
    printf("\n");

    // Question 4 -----------------------------------------------------------------------------------------------------------------------------
    printf("\nQuestion 4\n");

    char *name;
    double hottest_temp_ovr;
    //Finding lake name and temp of the hottest temp recorded
    name = find_warmest_lake_name(hottest_temp_sup, hottest_temp_mich, hottest_temp_huron, hottest_temp_erie, hottest_temp_ont, hottest_temp_clr);
    hottest_temp_ovr = find_warmest_lake_temp(hottest_temp_sup, hottest_temp_mich, hottest_temp_huron, hottest_temp_erie, hottest_temp_ont, hottest_temp_clr);
    printf("\nThe hottest temparature was in %s, on ", name);
    if (hottest_temp_ovr == hottest_temp_sup)
    {
        for (int i = 0; i < total_hottest_days_sup; i++)
        {
            int temp_res[2];
            date_conversion(hottest_dates_sup[i], temp_res);
            printf(name_of_month(temp_res[0]));
            printf(" %d", temp_res[1]);
            if (i != total_hottest_days_sup - 1)
                printf(", ");
        }
    }
    if (hottest_temp_ovr == hottest_temp_mich)
    {
        for (int i = 0; i < total_hottest_days_mich; i++)
        {
            int temp_res[2];
            date_conversion(hottest_dates_mich[i], temp_res);
            printf(name_of_month(temp_res[0]));
            printf(" %d", temp_res[1]);
            if (i != total_hottest_days_mich - 1)
                printf(", ");
        }
    }
    if (hottest_temp_ovr == hottest_temp_huron)
    {
        for (int i = 0; i < total_hottest_days_huron; i++)
        {
            int temp_res[2];
            date_conversion(hottest_dates_huron[i], temp_res);
            printf(name_of_month(temp_res[0]));
            printf(" %d", temp_res[1]);
            if (i != total_hottest_days_huron - 1)
                printf(", ");
        }
    }
    if (hottest_temp_ovr == hottest_temp_erie)
    {
        for (int i = 0; i < total_hottest_days_erie; i++)
        {
            int temp_res[2];
            date_conversion(hottest_dates_erie[i], temp_res);
            printf(name_of_month(temp_res[0]));
            printf(" %d", temp_res[1]);
            if (i != total_hottest_days_erie - 1)
                printf(", ");
        }
    }
    if (hottest_temp_ovr == hottest_temp_ont)
    {
        for (int i = 0; i < total_hottest_days_ont; i++)
        {
            int temp_res[2];
            date_conversion(hottest_dates_ont[i], temp_res);
            printf(name_of_month(temp_res[0]));
            printf(" %d", temp_res[1]);
            if (i != total_hottest_days_ont - 1)
                printf(", ");
        }
    }
    if (hottest_temp_ovr == hottest_temp_clr)
    {
        for (int i = 0; i < total_hottest_days_clr; i++)
        {
            int temp_res[2];
            date_conversion(hottest_dates_clr[i], temp_res);
            printf(name_of_month(temp_res[0]));
            printf(" %d", temp_res[1]);
            if (i != total_hottest_days_clr - 1)
                printf(", ");
        }
    }
    printf(" and its temparature was %.2lf°C", hottest_temp_ovr);

    double coldest_temp_ovr;
    //Finding lake name and temp of the coldest temp recorded
    name = find_coldest_lake_name(coldest_temp_sup, coldest_temp_mich, coldest_temp_huron, coldest_temp_erie, coldest_temp_ont, coldest_temp_clr);
    coldest_temp_ovr = find_coldest_lake_temp(coldest_temp_sup, coldest_temp_mich, coldest_temp_huron, coldest_temp_erie, coldest_temp_ont, coldest_temp_clr);
    printf("\nThe coldest temparature was in %s, on ", name);
    if (coldest_temp_ovr == coldest_temp_sup)
    {
        for (int i = 0; i < total_coldest_days_sup; i++)
        {
            int temp_res[2];
            date_conversion(coldest_dates_sup[i], temp_res);
            printf(name_of_month(temp_res[0]));
            printf(" %d", temp_res[1]);
            if (i != total_coldest_days_sup - 1)
                printf(", ");
        }
    }
    if (coldest_temp_ovr == coldest_temp_mich)
    {
        for (int i = 0; i < total_coldest_days_mich; i++)
        {
            int temp_res[2];
            date_conversion(coldest_dates_mich[i], temp_res);
            printf(name_of_month(temp_res[0]));
            printf(" %d", temp_res[1]);
            if (i != total_coldest_days_mich - 1)
                printf(", ");
        }
    }
    if (coldest_temp_ovr == coldest_temp_huron)
    {
        for (int i = 0; i < total_coldest_days_huron; i++)
        {
            int temp_res[2];
            date_conversion(coldest_dates_huron[i], temp_res);
            printf(name_of_month(temp_res[0]));
            printf(" %d", temp_res[1]);
            if (i != total_coldest_days_huron - 1)
                printf(", ");
        }
    }
    if (coldest_temp_ovr == coldest_temp_erie)
    {
        for (int i = 0; i < total_coldest_days_erie; i++)
        {
            int temp_res[2];
            date_conversion(coldest_dates_erie[i], temp_res);
            printf(name_of_month(temp_res[0]));
            printf(" %d", temp_res[1]);
            if (i != total_coldest_days_erie - 1)
                printf(", ");
        }
    }
    if (coldest_temp_ovr == coldest_temp_ont)
    {
        for (int i = 0; i < total_coldest_days_ont; i++)
        {
            int temp_res[2];
            date_conversion(coldest_dates_ont[i], temp_res);
            printf(name_of_month(temp_res[0]));
            printf(" %d", temp_res[1]);
            if (i != total_coldest_days_ont - 1)
                printf(", ");
        }
    }
    if (coldest_temp_ovr == coldest_temp_clr)
    {
        for (int i = 0; i < total_coldest_days_clr; i++)
        {
            int temp_res[2];
            date_conversion(coldest_dates_clr[i], temp_res);
            printf(name_of_month(temp_res[0]));
            printf(" %d", temp_res[1]);
            if (i != total_coldest_days_clr - 1)
                printf(", ");
        }
    }
    printf(" and its temparature was %.2lf°C\n", coldest_temp_ovr);

    // Question 5 -----------------------------------------------------------------------------------------------------------------------------
    printf("\nQuestion 5\n");

    double summer_average_sup, summer_average_mich, summer_average_huron, summer_average_erie, summer_average_ont, summer_average_clr;
    //Finding summer averages
    summer_average_sup = get_summer_avg(sup);
    summer_average_mich = get_summer_avg(mich);
    summer_average_huron = get_summer_avg(huron);
    summer_average_erie = get_summer_avg(erie);
    summer_average_ont = get_summer_avg(ont);
    summer_average_clr = get_summer_avg(clr);
    printf("\nLake Superior summer average is %.2lf°C\n", summer_average_sup);
    printf("Lake Michigan summer average is %.2lf°C\n", summer_average_mich);
    printf("Lake Huron summer average is %.2lf°C\n", summer_average_huron);
    printf("Lake Erie summer average is %.2lf°C\n", summer_average_erie);
    printf("Lake Ontario summer average is %.2lf°C\n", summer_average_ont);
    printf("Lake St. Clair summer average is %.2lf°C\n\n", summer_average_clr);

    double sorted_avg[6];
    //Sorting and printing lakes from warmest to coldest
    printf("Based on the summer temperatures the warmest to coldest lakes are:\n");
    bool desc = false;
    sort_avg(summer_average_sup, summer_average_mich, summer_average_huron, summer_average_erie, summer_average_ont, summer_average_clr, sorted_avg, desc);
    for (int i = 0; i < 6; i++)
    {
        if (sorted_avg[i] == summer_average_sup)
            printf("Lake Superior\n");
        else if (sorted_avg[i] == summer_average_mich)
            printf("Lake Michigan\n");
        else if (sorted_avg[i] == summer_average_huron)
            printf("Lake Huron\n");
        else if (sorted_avg[i] == summer_average_erie)
            printf("Lake Erie\n");
        else if (sorted_avg[i] == summer_average_ont)
            printf("Lake Ontario\n");
        else if (sorted_avg[i] == summer_average_clr)
            printf("Lake St Clair\n");
    }

    // Question 6 -----------------------------------------------------------------------------------------------------------------------------
    printf("\nQuestion 6\n");

    double winter_average_sup, winter_average_mich, winter_average_huron, winter_average_erie, winter_average_ont, winter_average_clr;
    //Finding winter averages of all lakes
    winter_average_sup = get_winter_avg(sup);
    winter_average_mich = get_winter_avg(mich);
    winter_average_huron = get_winter_avg(huron);
    winter_average_erie = get_winter_avg(erie);
    winter_average_ont = get_winter_avg(ont);
    winter_average_clr = get_winter_avg(clr);
    printf("\nLake Superior winter average is %.2lf°C\n", winter_average_sup);
    printf("Lake Michigan winter average is %.2lf°C\n", winter_average_mich);
    printf("Lake Huron winter average is %.2lf°C\n", winter_average_huron);
    printf("Lake Erie winter average is %.2lf°C\n", winter_average_erie);
    printf("Lake Ontario winter average is %.2lf°C\n", winter_average_ont);
    printf("Lake St. Clair winter average is %.2lf°C\n\n", winter_average_clr);

    double sorted_avg_winter[6];
    //Sorting and printing lakes from warmest to coldest
    printf("Based on the winter temperatures the warmest to coldest lakes are:\n");
    desc = false;
    sort_avg(winter_average_sup, winter_average_mich, winter_average_huron, winter_average_erie, winter_average_ont, winter_average_clr, sorted_avg_winter, desc);
    for (int i = 0; i < 6; i++)
    {
        if (sorted_avg_winter[i] == winter_average_sup)
            printf("Lake Superior\n");
        else if (sorted_avg_winter[i] == winter_average_mich)
            printf("Lake Michigan\n");
        else if (sorted_avg_winter[i] == winter_average_huron)
            printf("Lake Huron\n");
        else if (sorted_avg_winter[i] == winter_average_erie)
            printf("Lake Erie\n");
        else if (sorted_avg_winter[i] == winter_average_ont)
            printf("Lake Ontario\n");
        else if (sorted_avg_winter[i] == winter_average_clr)
            printf("Lake St Clair\n");
    }

    // Question 7 -----------------------------------------------------------------------------------------------------------------------------
    printf("\nQuestion 7\n");

    int swimdays_sup, swimdays_mich, swimdays_huron, swimdays_erie, swimdays_ont, swimdays_clr;
    //Finding number of days you can swim in each lake
    swimdays_sup = swimdays(sup);
    printf("\nThe number of days you can swim in Lake Superior is %d\n", swimdays_sup);
    swimdays_mich = swimdays(mich);
    printf("The number of days you can swim in Lake Michigan is %d\n", swimdays_mich);
    swimdays_huron = swimdays(huron);
    printf("The number of days you can swim in Lake Huron is %d\n", swimdays_huron);
    swimdays_erie = swimdays(erie);
    printf("The number of days you can swim in Lake Erie is %d\n", swimdays_erie);
    swimdays_ont = swimdays(ont);
    printf("The number of days you can swim in Lake Ontario is %d\n", swimdays_ont);
    swimdays_clr = swimdays(clr);
    printf("The number of days you can swim in Lake St. Clair is %d\n", swimdays_clr);

    // Question 8 -----------------------------------------------------------------------------------------------------------------------------
    printf("\nQuestion 8\n");

    int frozendays_sup, frozendays_mich, frozendays_huron, frozendays_erie, frozendays_ont, frozendays_clr;
    //Finding number of days lakes are frozen
    frozendays_sup = frozendays(sup);
    printf("\nThe number of days Lake Superior is frozen is %d\n", frozendays_sup);
    frozendays_mich = frozendays(mich);
    printf("The number of days Lake Michigan is frozen is %d\n", frozendays_mich);
    frozendays_huron = frozendays(huron);
    printf("The number of days Lake Huron is frozen is %d\n", frozendays_huron);
    frozendays_erie = frozendays(erie);
    printf("The number of days Lake Erie is frozen is %d\n", frozendays_erie);
    frozendays_ont = frozendays(ont);
    printf("The number of days Lake Ontario is frozen is %d\n", frozendays_ont);
    frozendays_clr = frozendays(clr);
    printf("The number of days Lake St. Clair is frozen is %d\n", frozendays_clr);

    // Question 9 -----------------------------------------------------------------------------------------------------------------------------
    printf("\nQuestion 9\n");

    double sup2[TOTAL_DAYS], mich2[TOTAL_DAYS], huron2[TOTAL_DAYS], erie2[TOTAL_DAYS], clr2[TOTAL_DAYS], ont2[TOTAL_DAYS];
    double average_sup2, average_mich2, average_huron2, average_erie2, average_ont2, average_clr2, total_avg2;
    
    //Opening second file
    FILE *ptr2;
    ptr2 = fopen(DATA_FILE2, "r");

    //for loop to read/store values
    for (int i = 0; i < TOTAL_DAYS; i++)
    {
        done = fscanf(ptr2, "%d", &year2[i]);
        done = fscanf(ptr2, "%d", &day2[i]);
        done = fscanf(ptr2, "%lf", &sup2[i]);
        done = fscanf(ptr2, "%lf", &mich2[i]);
        done = fscanf(ptr2, "%lf", &huron2[i]);
        done = fscanf(ptr2, "%lf", &erie2[i]);
        done = fscanf(ptr2, "%lf", &ont2[i]);
        done = fscanf(ptr2, "%lf", &clr2[i]);
    }

    //Closing second file
    fclose(ptr2);

    //Finding average lake temps for all lakes 2019
    average_sup2 = get_avg2(sup2);
    average_mich2 = get_avg2(mich2);
    average_huron2 = get_avg2(huron2);
    average_erie2 = get_avg2(erie2);
    average_ont2 = get_avg2(ont2);
    average_clr2 = get_avg2(clr2);
    //Printing 2020 averages alongside 2019 average to compare them
    printf("\t\t\t\t\t\t2020 Values\t\t\t\t\t2019 values", average_sup, average_sup2);
    printf("\nLake Superior\t\t\t%.2lf°C\t\t\t\t\t\t%.2lf°C\n", average_sup, average_sup2);
    printf("Lake Michigan\t\t\t%.2lf°C\t\t\t\t\t\t%.2lf°C\n", average_mich, average_mich2);
    printf("Lake Huron\t\t\t\t%.2lf°C\t\t\t\t\t\t%.2lf°C\n", average_huron, average_huron2);
    printf("Lake Erie\t\t\t\t%.2lf°C\t\t\t\t\t\t%.2lf°C\n", average_erie, average_erie2);
    printf("Lake Ontario\t\t\t%.2lf°C\t\t\t\t\t\t%.2lf°C\n", average_ont, average_ont2);
    printf("Lake St. Clair\t\t\t%.2lf°C\t\t\t\t\t\t%.2lf°C\n", average_clr, average_clr2);

    total_avg2 = (average_sup2 + average_mich2 + average_huron2 + average_erie2 + average_ont2 + average_clr2) / 6;
    printf("Average of lakes\t\t%.2lf°C\t\t\t\t\t\t%.2lf°C\n", total_avg, total_avg2);

    return (0);
}