#include<stdio.h>
#include<string.h>

// for buffer size
#define MAX_LENGTH 100

//check if the accii character is a number
int isnum(char ascii)
{
	if(ascii <= '9' && ascii >= '0')
	{
		return 1;
	} 
	
	return 0;
}

int isnumStr(char txt[MAX_LENGTH], int dir)
{
	int len = strlen(txt);
	
	if (dir == -1)
	{
		// for searching in reverse
		for (int i = len-4; i >= 0; i--) 
		{
			//one
			if (txt[i] == 'o' 
				&& txt[i+1] == 'n' 
				&& txt[i+2] == 'e' ) return 1;
			//two three		
			if (txt[i] == 't')
			{
				if (txt[i+1] == 'w' 
					&& txt[i+2] == 'o' ) return 2;
				if (txt[i+1] == 'h' 
					&& txt[i+2] == 'r' 
					&& txt[i+3] == 'e' 
					&& txt[i+4] == 'e') return 3;
			}
			//four five
			if (txt[i] == 'f')
			{
				if (txt[i+1] == 'o' 
					&& txt[i+2] == 'u' 
					&& txt[i+3] == 'r') return 4;
				if (txt[i+1] == 'i' 
					&& txt[i+2] == 'v' 
					&& txt[i+3] == 'e') return 5;
			}
			//six seven
			if (txt[i] == 's')
			{
				if (txt[i+1] == 'i' 
					&& txt[i+2] == 'x' ) return 6;
				if (txt[i+1] == 'e' 
					&& txt[i+2] == 'v' 
					&& txt[i+3] == 'e' 
					&& txt[i+4] == 'n') return 7;
			}
			//eight
			if (txt[i] == 'e'
				&& txt[i+1] == 'i' 
				&& txt[i+2] == 'g' 
				&& txt[i+3] == 'h' 
				&& txt[i+4] == 't') return 8;
			//nine
			if (txt[i] == 'n'				
				&& txt[i+1] == 'i' 
				&& txt[i+2] == 'n' 
				&& txt[i+3] == 'e') return 9;
			//zero
			if (txt[i] == 'z'
				&& txt[i+1] == 'e' 
				&& txt[i+2] == 'r' 
				&& txt[i+3] == 'o') return 0;
		}
	}
	else
	{
		for(int i = 0; i < len; i++)
		{	
			if (txt[i] == 'o' 
				&& txt[i+1] == 'n' 
				&& txt[i+2] == 'e' ) return 1;
		
			if (txt[i] == 't')
			{
				if (txt[i+1] == 'w' 
					&& txt[i+2] == 'o' ) return 2;
				if (txt[i+1] == 'h' 
					&& txt[i+2] == 'r' 
					&& txt[i+3] == 'e' 
					&& txt[i+4] == 'e') return 3;
			}
			if (txt[i] == 'f')
			{
				if (txt[i+1] == 'o' 
					&& txt[i+2] == 'u' 
					&& txt[i+3] == 'r') return 4;
				if (txt[i+1] == 'i' 
					&& txt[i+2] == 'v' 
					&& txt[i+3] == 'e') return 5;
			}
			if (txt[i] == 's')
			{
				if (txt[i+1] == 'i' 
					&& txt[i+2] == 'x' ) return 6;
				if (txt[i+1] == 'e' 
					&& txt[i+2] == 'v' 
					&& txt[i+3] == 'e' 
					&& txt[i+4] == 'n') return 7;
			}
			if (txt[i] == 'e'
				&& txt[i+1] == 'i' 
				&& txt[i+2] == 'g' 
				&& txt[i+3] == 'h' 
				&& txt[i+4] == 't') return 8;
			if (txt[i] == 'n'
				&& txt[i+1] == 'i' 
				&& txt[i+2] == 'n' 
				&& txt[i+3] == 'e') return 9;
			if (txt[i] == 'z'
				&& txt[i+1] == 'e' 
				&& txt[i+2] == 'r' 
				&& txt[i+3] == 'o') return 0;

		}
	}
	
	return 0;
}

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

int extract(char buff[100])
{
	int len = strlen(buff);
	char txt[MAX_LENGTH];
	int tens;
	int units;
	
	//tens place or linear search
	for (int i = 0; i < len; i++)
	{
		if (isnum(buff[i] ) )
		{
			if (isnumStr(txt, 1) )
			{
				tens = isnumStr(txt, 1);
			}
			else
			{
				tens = numWhat(buff[i] );
			}
			break;
		}
		txt[i] = buff[i];
	}

	//units place or stack search	
	for (int i = len - 1; i >= 0; i--)
	{
		if (isnum(buff[i] ) )
		{
			for(int j = i; j < len; j++)
				txt[j-i] = buff[j+1];
			if (isnumStr(txt, -1) )
			{
				units = isnumStr(txt, -1);
			}
			else
			{
				units = numWhat(buff[i] );
			}
			break;
		}
	}
	return tens * 10 + units;
}

int main(void)
{
	//logic
	//1. a = linear search for a digit 	
	//	&& 	str = all chars encountered so far
	//2. b = stack search for a digit 	
	//	&& 	str = all chars encountered so far
	//3. sum = 0 
	//4. sum += 10*a+b
	
	//conditions
	//1. if str is a num 	=> T,U = str 
	//2. else T,U = a,b  	
	
	//file i/o


	int sum = 0;
	
	FILE* f;
	f = fopen("values.txt","r");
	
	// react if smthing wrong with file
	if (f == NULL)
	{
		printf("Error while handling the file\n");
		return 1;
	}
	
	char buffer[MAX_LENGTH];
	
	while(fgets(buffer, sizeof(buffer), f) != NULL)
	{
		sum += extract(buffer);
	}

	printf("sum : %d\n",sum);
	
	fclose(f);
	
	return 0;
}
