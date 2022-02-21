#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char normal[])
{
	int len=strlen(normal);
	char original[100];
	for (int i=0; i<len; i++)
		original[i]=normal[i];
	for (int j=0; j<len; j++)
		normal[j]=original[len-j-1];
}

int main()
{
	char text[100];
	scanf("%s",text);
	reverseString(text);
	printf("%s\n", text);
	return 0;
}