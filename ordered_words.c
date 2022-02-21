#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char words[200]={0}, ordered[200][200]={0};
	fgets(words, 200, stdin);
	int len=strlen(words);

	for (int i=0; i<len; i++)
	{
		if (!(words[i]>='a' && words[i]<='z') && !(words[i]>='A' && words[i]<='Z'))
			words[i]=' ';	
	}

	int letter=0, word_counter=0;

	for (int j=0; j<len; j++)
	{
		if (words[j]!=' ')
		{
			ordered[word_counter][letter]=words[j];
			letter++;
		}
		else
		{
			word_counter++;
			letter=0;
		}
	}
	
	for (int ascii_val=0x41; ascii_val<=0x7a; ascii_val++)
	{
		for (int first_letter=0; first_letter<word_counter; first_letter++)
		{
			if (ascii_val==ordered[first_letter][0])
			{
				printf("%s\n", ordered[first_letter]);
			}
		}
	}

	// print the ordered table
	/*
	for (int rows=0; rows<=word_counter; rows++)
	{
		for (int columns=0; columns<len; columns++)
		{
			printf("%c", ordered[rows][columns]);
		}
		printf("\n");
	}
	*/
	return 0;
}