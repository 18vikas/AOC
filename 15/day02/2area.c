#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 100

int convert_to_int(char* numstr);
int volume(int l, int w, int h);
int ribbon_req(int l, int w, int h);

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
        sum += volume(l,w,h);
        sum += ribbon_req(l,w,h);
        //printf("l: %d,w: %d,h: %d,total ribbon: %d",l,w,h,sum);
        //break;
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

int volume(int l, int w, int h)
{
    return l * w * h;
}
int ribbon_req(int l, int w, int h)
{
    if(l <= w && h <= w) return 2*l + 2*h;
    else if(w <= h && l <= h) return 2*l + 2*w;
    else return 2*w + 2*h;
}
