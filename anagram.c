#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[100], b[100], anagram=1, found_let;
	fgets(a,100,stdin);
	fgets(b,100,stdin);
	if (a[strlen(a)-1]=='\n') // remove newline
			a[strlen(a)-1]='\0';

	if (b[strlen(b)-1]=='\n') // remove newline
			b[strlen(b)-1]='\0';

	for (int i=0; i<strlen(a); i++)
	{
		if (!(a[i]>= 'a' && a[i]<='z') || !(b[i]>= 'a' && b[i]<='z'))
		{
			printf("Wrong Input\n");
			return 0;
		}
	}

	for (int j=0; j<strlen(b); j++)
	{
		found_let=0;
		for (int k=0; k<strlen(a); k++)
		{
			//printf("Trying %c (b[j]) == %c (a[k])\n", b[j],a[k]);
			if(found_let==0 && b[j]==a[k])
			{
				//printf("letter b[%d]=%c found in a[%d]=%c\n", j,b[j],k,a[k]);
				found_let=1;
				a[k]=' ';
				break;
			}
		}
		if(found_let==0)
		{
			printf("No\n");
			return 0;
		}
	}
	if (anagram)
		printf("Yes\n");
	return 0;
}
