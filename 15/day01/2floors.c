#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 8000
int main()
{
    //self explainatory
    int sum = 0;

    FILE* f;
    f = fopen("values.txt","r");

    //react if file is not found or unable to open 
    if (f == NULL)
    {
        printf("Error while handling the file\n");
        return 1;
    }

    //config max len acc. to the max chars possible in a single line
    char buffer[MAX_LENGTH];

    //self explainatory
    while(fgets(buffer, sizeof(buffer), f) != NULL)
    {
        int n = strlen(buffer);
        printf("n = %d \n", n);
        for(int i = 0; i < n; i++)
        {
            if(buffer[i] == '(') sum++;
            else if(buffer[i] == ')') sum--;
            else printf("something went wrong\n");

            if(sum == -1) printf("i: %d\n", i+1);
                }
    }

    printf("sum : %d\n",sum);

    fclose(f);

    return 0;
}
