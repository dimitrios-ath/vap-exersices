#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chars(char *s, char *most_seen, char *less_seen);
char *reverse(char *s);

void chars(char *s, char *most_seen, char *less_seen)
{
	struct dict
	{
		char letter;
		int freq;
	};
	struct dict *letters = malloc(strlen(s)*sizeof(struct dict));
	int len=strlen(s);
	for (int i=0; i<len; i++)
	{
		letters[i].letter=s[i];
		letters[i].freq++;
	}

	for (int i=0; i<len; i++)
		for (int j=i+1; j<len;)
			if (letters[i].letter==letters[j].letter)
			{
				for (int k=j; k<len; k++)
				{
					letters[k].letter=letters[k+1].letter;
					letters[k].freq=letters[k+1].freq;
				}
				letters[i].freq++;
				len--;
			}
			else
				j++;

	int min=letters[0].freq, max=letters[0].freq;

	for (int i=1; i<len; i++)
	{
		if (letters[i].freq<min)
			min=letters[i].freq;
		if (letters[i].freq>max)
			max=letters[i].freq;
	}
	
	for (int i=0; i<len; i++)
		if(letters[i].freq==max)
		{
			*most_seen=letters[i].letter;
			break;
		}

	for (int i=0; i<len; i++)
		if(letters[i].freq==min)
		{
			*less_seen=letters[i].letter;
			break;
		}
}

char *reverse(char *s)
{
	char *reversed = malloc((strlen(s)+1)*sizeof(char));
	for (int i=0; i<strlen(s); i++)
		reversed[i]=s[strlen(s)-i-1];
	return reversed;
}

int main()
{
	char *s = malloc (1000*sizeof(char));
	char *s2;
	char mostSeen, lessSeen;

	fgets(s,1000,stdin);
	s[strcspn(s,"\n")] = '\0';

	chars(s,&mostSeen, &lessSeen);
	s2 = reverse(s);

	printf("%s\n",s);
	printf("%s\n",s2);
	printf("%c\n%c\n",mostSeen,lessSeen);
	return 0;
}
