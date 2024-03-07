#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Declaring struct
struct address_t
{
    char name[15];
    int addr[4];
};

// Localnet function to find same networks
int localnet(struct address_t addr1, struct address_t addr2)
{
    return (addr1.addr[0] == addr2.addr[0] && addr1.addr[1] == addr2.addr[1]);
}


// Main function
int main(void)
{

    struct address_t ipaddr[300];

    //Opening file
    FILE *ptr;
    ptr = fopen("L8_ip.txt", "r");
    int done = 1;
    char string1[500], string2[15];
    int result, result2, total;
    total = 0;
    
    //Reading values into variables
    for (int i = 0; i < 300; i++)
    {
        done = fscanf(ptr, "%s %s", string1, string2);
        result = strcmp(string1, "0.0.0.0");
        result2 = strcmp(string2, "sentinel");

        strcpy(ipaddr[i].name, string2);

        char *tempstr = strtok(string1, ".");
        for (int j = 0; j < 4; j++)
        {
            int tempint = atoi(tempstr);
            ipaddr[i].addr[j] = tempint;
            tempstr = strtok(NULL, ".");
        }

        total++;

        if (result == 0 && result2 == 0)
        {
            break;
        }
    }

    // Finding and printing which servers are on the same local network
    for (int i = 0; i < total; i++)
    {
        for (int j = i + 1; j < total; j++)
        {
            int res = localnet(ipaddr[i], ipaddr[j]);
            if (res)
            {
                printf("Servers %s and %s are on the same local network.\n", ipaddr[i].name, ipaddr[j].name);
            }
        }
    }

    // Printing the addresses of all the servers 
    printf("\nAll Servers:\n");
    for (int i = 0; i < total; i++)
    {
        printf("%d.%d.%d.%d %s\n", ipaddr[i].addr[0], ipaddr[i].addr[1], ipaddr[i].addr[2], ipaddr[i].addr[3], ipaddr[i].name);
    }

    // Closing the file
    fclose(ptr);

    return (0);
}A