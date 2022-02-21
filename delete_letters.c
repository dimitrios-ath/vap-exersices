#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void deleteLetters(char text[], char letters[])
{
	for (int i=0; i<strlen(text); i++)
	{
		for (int j=0; j<strlen(letters); j++)
		{
			if (text[i]==letters[j])
			{
				text[i]=' ';
			}
		}
	}
	
	for (int k=0; k<strlen(text); k++)
	{
		if(text[k]==' ')
			for (int l=k; l<strlen(text); l++)
				text[l]=text[l+1];
	}
}

int main()
{
	char a[100],b[100];
	scanf("%s %s",a,b);
	deleteLetters(a,b);
	printf("%s\n", a);
	return 0;
}