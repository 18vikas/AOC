#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 250
	
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
		case '9': return 9; 
		default: return (int)ascii; 
	}
}

int power(int base, int expo)
{
	if(expo == 0) 
		return 1;
	else 	
		return base * power(base,expo-1);	 
}

int num(char* numstr)
{
	int len = strlen(numstr);
	int num = 0;
	
	for (int i = 0; i < len; i++)
	{
		num += numWhat(numstr[i]) * power(10, len -1 -i);
	}
	return num;
}

int minpow(char* rounds)
{
	int r = 0, g = 0, b = 0;
	char* val = strtok(rounds, " ");
	char* color = strtok(NULL, " ");
	while(val != NULL)
	{	
		if(color[0] == 'b') 
		{
			if(num(val) > b) b = num(val);
		}
		else if(color[0] == 'g')
		{
			if(num(val) > g) g = num(val);
		}
		else
		{
			if(num(val) > r) r = num(val);
		}

		val = strtok(NULL, " ");
		color = strtok(NULL, " ");
	}
	return r * b * g;
	
}

int main(void)
{

//	1. checkN(buffer) return goal;
//	2. parse with colors and goals;
//	3. check conditions and return;
		
	
	FILE* f;
	int sum = 0;
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
		char* goal = strtok(buffer,":");
		char* nxt = strtok(NULL,":");
			
		sum += minpow(nxt);
	}

	printf("sum : %d\n",sum);
	
	fclose(f);
	
	return 0;
}
