#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 9001

int main()
{
    FILE* f = NULL;

    f = fopen("values.txt", "r");

    if(f == NULL)
    {
        printf("Error while file handling\n");
        return 1;
    }

    char buffer[MAX_LENGTH];

    while(fgets(buffer, sizeof(buffer), f) != NULL)
    {
        char plane[4500][4500];
        int n = strlen(buffer);
        int x=0, y=0;

    }

    fclose(f);

    return 0;
}
