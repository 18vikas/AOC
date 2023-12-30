#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 200
//  gcc Gear.c

struct NO_ { int pos_str; int digits; int value; };

//numwhat implementation
int str_to_num(char ascii_num)
{
    switch(ascii_num)
    {
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return 0;
    }
}

//return a struct with pos_str, digits LONG, value
struct NO_ search(char* str)
{
    //init
    struct NO_ srch;
    srch.digits = 0;
    srch.value = 0;

    int n = strlen(str);
    for(int i = 0; i < n; i++)
    {
        //check if #
        if(str[i] >= '0' && str[i] <= '9')
        {
            srch.pos_str = i;
            //convert #
            while(str[i + srch.digits] >= '0' && str[i + srch.digits] <= '9')
            {
                int value = str_to_num(str[i + srch.digits]);
                srch.value = srch.value * 10 + value;
                srch.digits++;
            }
            //return struct 
            return srch;
        }
    }
    return srch;
}

//return 1 if special char found
int check(char c)
{
    if(c != '.' && !(c >= '0' && c <= '9')) return 1;
    else return 0;
}

//return an int i.e. sum of all the possible parts
int extract(char* x, char* y)
{
    //printf("\t new extract for line : %c ...\n", x[0]);
    int sum_of_line = 0, before = 0, after = 0;
    struct NO_ n = search(x);

    //comapre 1st with 2nd
    while(n.value != 0)
    {
        int trigger = 0; before = 0;

        //init
        if(n.pos_str > 1) before = n.pos_str - 1;
        after = n.pos_str + n.digits;

        //within x
        trigger += check(x[before]) + check(x[after]);
        //printf("triggeraftercheckinx:%d", trigger);

        //within y
        for(; before <= after; before++)
        {
            trigger += check(y[before]);
        }
        //printf("triggeraftercheckiny:%d", trigger);

        //validation
        if(trigger)
        {
            //printf("\tpart : %d\n", n.value);
            sum_of_line += n.value;
            //printf("Sum of lIne : %d \n", sum_of_line);

            //earse the extracted val
            while(n.digits != 0)
            {
                n.digits--;
                x[n.digits + n.pos_str] = '.';
            }
        }
        //printf("x:%s", x);
        //printf("y:%s", y);


        //update for nxt round
        before--; x = &x[before]; y = &y[before];
        //printf("updated\n");
        //printf("x:%s", x);
        //printf("y:%s", y);
        n = search(x);
    }

    //return sum of line
    return sum_of_line;
}


int main()
{
	//config max len acc. to the max chars possible in a single line
        char temp_buffer[MAX_LENGTH];
	char buffer[MAX_LENGTH];
	int sum = 0;
	FILE* f;

	f = fopen("values.txt","r");
	
	//react if file is not found or unable to open 
	if (f == NULL)
	{
		//printf("Error while handling the file\n");
		return 1;
	}
	
        fgets(buffer, sizeof(buffer), f);
        strcpy(temp_buffer, buffer);
        //init
	
        //debug values 
        int debug = 0;

	//self explainatory
	while(fgets(buffer, sizeof(buffer), f) != NULL )
	{
		//sum += extract(buffer);
                //printf("Main-while\n");
                //printf("%s%s\n\n",temp_buffer,buffer);

                //w.r.t. temp
                //printf("Main-while-extract-0\n");
                int one = extract(temp_buffer, buffer);
                //sum += extract(temp_buffer, buffer);
                //printf("sum : %d\n", sum);

                //debug

                //w.r.t. buff
                //sum += extract(buffer, temp_buffer);
                int two = extract(buffer, temp_buffer);
                sum += one + two;
                //printf("Main-while-extract-1\n");

                //update
                strcpy(temp_buffer, buffer);
                //printf("Main-while-strcpy\n");

                //debug
                debug++;
                //printf("Main-while-debug\n");
                printf("%d.) sum : %d\n", debug, one+two);

	}

	fclose(f);
	printf("sum : %d\n",sum);
        printf("debug: %d\n", debug);
	
	return 0;
}
