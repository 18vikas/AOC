#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 100

int convert_to_int(char* numstr);
int area(int l, int w, int h);
int small_surface_area(int l, int w, int h);

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
        int l = convert_to_int(strtok(buffer, "x"));
        int w = convert_to_int(strtok(NULL, "x"));
        int h = convert_to_int(strtok(NULL, "x"));
        sum += area(l,w,h);
        sum += small_surface_area(l,w,h);
    }           

    printf("sum : %d\n",sum);

    fclose(f);

    return 0;
}

int convert_to_int(char* num_str)
{
    int n = strlen(num_str);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        switch(num_str[i])
        {
            case '0': sum = sum * 10 + 0; break; 
            case '1': sum = sum * 10 + 1; break;
            case '2': sum = sum * 10 + 2; break;
            case '3': sum = sum * 10 + 3; break;
            case '4': sum = sum * 10 + 4; break;
            case '5': sum = sum * 10 + 5; break;
            case '6': sum = sum * 10 + 6; break;
            case '7': sum = sum * 10 + 7; break;
            case '8': sum = sum * 10 + 8; break;
            case '9': sum = sum * 10 + 9; break;
            default: break;
        }
    }
    return sum;
}

int area(int l, int w, int h)
{
    return 2*l*w + 2*h*w + 2*l*h;
}
int small_surface_area(int l, int w, int h)
{
    int foo = l*w;
    int bar = h*w;
    int baz = l*h;

    if(foo <= bar && foo <= baz) return foo;
    else if(baz <= bar && baz <= foo) return baz;
    else  return bar;
}
