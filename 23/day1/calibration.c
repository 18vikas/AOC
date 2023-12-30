#include<stdio.h>
#include<string.h>

//buffer size
#define MAX_LENGTH 100

//check if a ascii character is a numeral
int isnum(char ascii)
{
	if(ascii <= '9' && ascii >= '0')
	{
		return 1;
	} 
	
	return 0;
}

//convert ascii numeral => integer
int numWhat(char ascii)
{
	switch(ascii)
	{
		case '0': return 0; 
		case '1': return 1; 
		case '2': return 2; 
		case '3': return 3; 
		case '4': return 4; 
		case '5': return 5; 
		case '6': return 6; 
		case '7': return 7; 
		case '8': return 8; 
		default: return 9; 
	}
}

//program specific function
//Gets the first int and the last int in the str (single digits)
//makes it into a two digit number with digits arranged respectively
int extract(char buff[100])
{
	//self explainatory
	int len = strlen(buff);
	int tens;
	int units;
	
	//tens place or linear search
	for (int i = 0; i < len; i++)
	{
		//check if a char is numeric
		if (isnum(buff[i] ) )
		{
			//convet ascii to int
			tens = numWhat(buff[i] );
			break;
		}
	}

	//units place or stack search	
	for (int i = len - 1; i >= 0; i--)
	{
		//react if a numeral encountered
		if (isnum(buff[i] ) )
		{
			//convet ascii to int
			units = numWhat(buff[i] );
			break;
		}
	}
	return tens * 10 + units;
}

int main(void)
{
	//1. a = linear search for a digit
	//2. b = stack search for a digit
	//conditions
	//3. sum = 0 
	//4. sum += 10*a+b
	//file i/o


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
		sum += extract(buffer);
	}

	printf("sum : %d\n",sum);
	
	fclose(f);
	
	return 0;
}
