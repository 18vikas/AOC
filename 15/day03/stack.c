#include<stdio.h>
#define OPT 4

void menu();
void brake();

int main()
{
    char* top = NULL;

    menu();
    return 0;
}

void menu()
{
    //change OPT value as well
    int choice;
    char* options[OPT] = {"exit","push","pop","show"};

    brake(); printf("|\tMenu\t\t|\n"); brake();

    for(int i = 0; i < OPT; i++)
        printf("| %d.\t%s\t\t|\n",i,options[i]);
    brake();

    printf("\t\t\t"); 
    brake(); 
    printf("\t\t\t|\tCHOICE:"); 
    scanf("%d",&choice);
}

void brake()
{
    int i=1, size=8*3;
    printf("+");
    while(i < size)
    {
        printf("=");
        i++;
    }
    printf("+");
    printf("\n");
}
