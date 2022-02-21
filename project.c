#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int word_counter, sentence_counter, paragraph_counter=0, total_words=0, total_sentences=0;
char **found_paragraphs;
char **sentences;
char **words;
char **input_text;
char *search_term;

int command_id(char *text)
{
	if (strncmp(text, "qt", 2)==0)
		exit(0);
	else if (strncmp(text, "ap:", 3)==0)
		return 1;
	else if (strncmp(text, "fw:", 3)==0)
		return 2;
	else if (strncmp(text, "fs:", 3)==0)
		return 3;
	else if (strncmp(text, "fp:", 3)==0)
		return 4;
	else if (strncmp(text, "owf", 3)==0)
		return 5;
	else if (strncmp(text, "owl", 3)==0)
		return 6;
	else
		printf("Unknown command\n");
	return -1;
}


void word_count_function(char *text)
{
	word_counter=1;
	// find how many words exist in the paragraph
	for (int i=0; i<strlen(text)-2; i++) 
		if ((text[i]==' ' || text[i]=='-' || text[i]=='\n') && i!=(strlen(text)-1))
			word_counter++;
	total_words += word_counter;
}

void split_in_words(char *text)
{
	if(words!=NULL)
		free(words);
	word_count_function(text);
	words = malloc(total_words*sizeof(char *));
	if (words==NULL)
			exit(0);

	int word=0, letter=0;
	
	for (int i = 0; i<total_words; i++)
	{
		words[i] = (char *) malloc(20*sizeof(char));
		if (words[i]==NULL)
			exit(0);
	}

	for (int j=0; j<=paragraph_counter; j++)
		for (int i=0; i<strlen(input_text[j]); i++)
			if (input_text[j][i]!='\n' && input_text[j][i]!=' ' && input_text[j][i]!='-')
			{
				if ((input_text[j][i]>='a' && input_text[j][i]<='z') || (input_text[j][i]>='A' && input_text[j][i]<='Z'))
				{
					words[word][letter]=input_text[j][i];
					letter++;
				}
			}
			else
			{
				words[word][letter]='\0';
				letter=0;
				word++;
			}
}

void sentence_count_function(char *text)
{
	sentence_counter=1;
	// find how many sentences exist in the paragraph
	for (int i=0; i<strlen(text)-3; i++) 
		if ((text[i]=='.' || text[i]=='!' || text[i]=='?' || text[i]==';'))
			sentence_counter++;
	total_sentences += sentence_counter;
}

void split_in_sentences(char *text)
{
	if(sentences!=NULL)
		free(sentences);
	sentence_count_function(text);
	sentences = (char **) malloc(total_sentences*sizeof(char *));
	if (sentences==NULL)
		exit(0);
	for (int i=0; i<total_sentences; ++i)
	{
		sentences[i] = (char *) malloc(200*sizeof(char));
		if (sentences[i]==NULL)
			exit(0);
	}
	int sentence=0, letter=0;
	for(int k=0; k<=paragraph_counter;k++)
	{
		for (int i=0; i<strlen(input_text[k])-1; i++)
		{
			if (input_text[k][i]!='.' && input_text[k][i]!='!' && input_text[k][i]!='?' && input_text[k][i]!=';')
			{
				sentences[sentence][letter]=input_text[k][i];
				letter++;
			}
			else
			{	
				sentences[sentence][letter]='\0';
				//sentences[sentence] = (char *) realloc(sentences[sentence], strlen(sentences[sentence]));
				letter=0;
				sentence++;
			}
		}
	}	
	// remove extra spaces at beginning
	for (int i=0; i<total_sentences; i++)
		if (sentences[i][0]==' ')
			for (int j=0; j<strlen(sentences[i]); j++)
				sentences[i][j]=sentences[i][j+1];
}

void fw_function(char * text)
{
	char * search_term = (char *) calloc(strlen(text),sizeof(char));
	for (int i=3; i<strlen(text); i++)
		if (text[i]!='\n')
			search_term[i-3]=text[i];

	char **found_words = (char **) malloc(200*sizeof(char *));
	if (found_words==NULL)
		exit(0);
	for (int i = 0; i<200; ++i)
	{
		found_words[i] = (char *) malloc(30*sizeof(char));
		if (found_words[i]==NULL)
			exit(0);
	}

	int found_words_counter=0;
	for (int i=0; i<total_words; i++)
	{
		char * search_result = strstr(words[i],search_term);
		if (search_result!=NULL)
		{
			found_words[found_words_counter] = words[i];
			found_words_counter++;
		}
	}

	// remove dublicates from found_words[]
	for (int i=0; i<found_words_counter; i++)
		for (int j=i+1; j<found_words_counter;)
			if(strcmp(found_words[j],found_words[i])==0)
			{
				for (int k=j; k<found_words_counter; k++)
					found_words[k]=found_words[k+1];
				found_words_counter--;
			}
			else
				j++;

	for (int i = 0; i < found_words_counter; i++)
		printf("%s\n", found_words[i]);
}

void fs_function(char * text)
{
	char * search_term = (char *) calloc(strlen(text),sizeof(char));
	if (search_term==NULL)
		exit(0);
	for (int i=3; i<strlen(text); i++)
		if (text[i]!='\n')
			search_term[i-3]=text[i];

	char **found_sentences= (char **) malloc(50*sizeof(char *));
	if (found_sentences==NULL)
		exit(0);
	for (int i = 0; i<50; ++i)
	{
		found_sentences[i] = (char *) malloc(300*sizeof(char));
		if (found_sentences[i]==NULL)
			exit(0);
	}

	int found_sentences_counter=0;
	for (int i=0; i<total_sentences; i++)
	{
		char * search_result = strstr(sentences[i],search_term);
		if (search_result!=NULL)
		{
			found_sentences[found_sentences_counter] = sentences[i];
			found_sentences_counter++;
		}
	}
	
	// remove dublicates from found_sentences[]
	for (int i=0; i<found_sentences_counter; i++)
		for (int j=i+1; j<found_sentences_counter;)
			if(strcmp(found_sentences[j],found_sentences[i])==0)
			{
				for (int k=j; k<found_sentences_counter; k++)
					found_sentences[k]=found_sentences[k+1];
				found_sentences_counter--;
			}
			else
				j++;
	
	for (int i = 0; i < found_sentences_counter; i++)
		printf("%s\n", found_sentences[i]);
}

void fp_function(char * text)
{	
	char * search_term = (char *) calloc(strlen(text),sizeof(char));
	for (int i=3; i<strlen(text); i++)	
		if (text[i]!='\n')	
			search_term[i-3]=text[i];
	for (int i = 0; i<paragraph_counter; i++)
		if (strstr(input_text[i],search_term))
		{
			for (int j=0; j<strlen(input_text[i])-2; j++)
			{
				if(input_text[i][j]=='-')
					printf(" ");
				if ((input_text[i][j]>='a' && input_text[i][j]<='z') || (input_text[i][j]>='A' && input_text[i][j]<='Z') || (input_text[i][j]==' ' && (input_text[i][j-1]!='.' && input_text[i][j-1]!='?' && input_text[i][j-1]!=';' && input_text[i][j-1]!='!' && input_text[i][j-1]!='1')))
				{
					if ((input_text[i][j-1]==' ' && input_text[i][j-2]=='.') || (input_text[i][j-1]==' ' && input_text[i][j-2]=='?') || (input_text[i][j-1]==' ' && input_text[i][j-2]=='!') || (input_text[i][j-1]==' ' && input_text[i][j-2]==';'))
						printf("\n");
					printf("%c", input_text[i][j]);
				}
			}
			printf("\n");
		}
	free(search_term);
}

void owf_function()
{
	struct owf_struct
	{
		char word[50];
		int frequency;		
	};
	struct owf_struct *owf_words = (struct owf_struct *) malloc(total_words*sizeof(struct owf_struct));
	int unique_word_counter=total_words;
	
	for (int i = 0; i<unique_word_counter; ++i)
	{
		strcpy(owf_words[i].word,words[i]);
		owf_words[i].frequency=1;
	}

	// remove dublicates from owf_words[]
	for (int i=0; i<unique_word_counter; i++)
	{
		for (int j=i+1; j<unique_word_counter;)
		{
			if(strcmp(owf_words[j].word,owf_words[i].word)==0)
			{
				owf_words[i].frequency++;
				for (int k=j; k<unique_word_counter; k++)
					strcpy(owf_words[k].word,owf_words[k+1].word);
				unique_word_counter--;
			}
			else
				j++;
		}
	}

    for (int i=0; i<unique_word_counter; i++)
    {
        for (int j=i+1; j<unique_word_counter; j++)
        {
            if (strcmp(owf_words[i].word,owf_words[j].word)>0) // if (owf_words[i].frequency < owf_words[j].frequency) 
            {
            	int temp_frequency=owf_words[i].frequency;
            	char temp_word[40]={'\0'};
            	strcpy(temp_word,owf_words[i].word);
            	owf_words[i].frequency=owf_words[j].frequency;
            	strcpy(owf_words[i].word,owf_words[j].word);
            	owf_words[j].frequency=temp_frequency;
            	strcpy(owf_words[j].word,temp_word);
            }
        }
    }

    for (int i = total_words-1; i>=0; i--)
    	for (int j = 0; j < unique_word_counter; j++)
    		if (owf_words[j].frequency==i && strcmp(owf_words[j].word,"")!=0)
    			printf("%s [%d]\n", owf_words[j].word, owf_words[j].frequency);
}

void owl_function()
{
	struct owl_struct
	{
		char word[50];
		int lenght;		
	};
	struct owl_struct *owl_words = (struct owl_struct *) malloc(total_words*sizeof(struct owl_struct));
	int unique_word_counter=total_words;
	
	for (int i = 0; i<unique_word_counter; ++i)
	{
		strcpy(owl_words[i].word,words[i]);
		
	}

	// remove dublicates from owl_words[]
	for (int i=0; i<unique_word_counter; i++)
	{
		for (int j=i+1; j<unique_word_counter;)
		{
			if(strcmp(owl_words[j].word,owl_words[i].word)==0)
			{
				for (int k=j; k<unique_word_counter; k++)
					strcpy(owl_words[k].word,owl_words[k+1].word);
				unique_word_counter--;
			}
			else
				j++;
		}
	}

	int max_len=0;
	for (int i = 0; i<unique_word_counter; ++i)
	{
		owl_words[i].lenght=strlen(owl_words[i].word);
		if(strlen(owl_words[i].word)>max_len)
			max_len=strlen(owl_words[i].word);
	}

	// sort owl_words alphabetically
    for (int i=0; i<unique_word_counter; i++)
        for (int j=i+1; j<unique_word_counter; j++)
            if (strcmp(owl_words[i].word,owl_words[j].word)>0) // if (owl_words[i].lenght < owl_words[j].lenght) 
            {
            	int temp_lenght=owl_words[i].lenght;
            	char temp_word[40]={'\0'};
            	strcpy(temp_word,owl_words[i].word);
            	owl_words[i].lenght=owl_words[j].lenght;
            	strcpy(owl_words[i].word,owl_words[j].word);
            	owl_words[j].lenght=temp_lenght;
            	strcpy(owl_words[j].word,temp_word);
            }

    for (int i=1; i<=max_len; i++)
    	for (int j=0; j<unique_word_counter; j++)
    		if (owl_words[j].lenght==i)
    			printf("%s [%d]\n", owl_words[j].word, owl_words[j].lenght);
}

int main()
{
	char *text = (char *) malloc(10000*sizeof(char));
	if (text==NULL)
		exit(0);
	input_text = malloc(15*sizeof(char *));
	if (input_text==NULL)
		exit(0);
	fgets(text,10000,stdin);
	if(text[strlen(text)-2]==' ')
		text[strlen(text)-1]='\0';
	int cmd = command_id(text);
	while(cmd!=0)
	{
		if (cmd==1) // ap:
		{
			input_text[paragraph_counter] = (char *) malloc(10000*sizeof(char));
			if (input_text[paragraph_counter]==NULL)
				exit(0);
			if (text[3]!=' ')
				strcpy(input_text[paragraph_counter],text+3);
			else
				strcpy(input_text[paragraph_counter],text+4);
			split_in_words(input_text[paragraph_counter]);
			split_in_sentences(input_text[paragraph_counter]);
			paragraph_counter++;
		}
		else if (cmd==2) // fw:
			fw_function(text);
		else if (cmd==3) // fs:
			fs_function(text);
		else if (cmd==4) // fp:
			fp_function(text);
		else if (cmd==5) // owf
			owf_function();
		else if (cmd==6) // owl
			owl_function();
		free(text);
		text = (char *) malloc(10000*sizeof(char));
		fgets(text,10000,stdin);
		if (text[strlen(text)-2]==' ')
			text[strlen(text)-1]='\0';
		cmd = command_id(text);
	}
	return 0;
}