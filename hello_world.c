#include <stdio.h>

int main(void)
{
	char str[] = {'A', 'B', 'C', 'H', 'L', '\0'};	
	str[3] = 'D';
	str[4] = 'E';
	
	printf("Hello world! - %s\n", str);
	printf("Size of my string is : %llu \n", sizeof(str));
	printf("Set my last character to NULL. \n");
	str[0] = '\0';
	printf("Size of my string is : %llu \n", sizeof(str));
	printf("Hello world! - %s\n", str);

	return 0;
}

	

