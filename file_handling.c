#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line_counter()
{
	FILE *file = fopen("./a.txt","r");
	int lines = 0;
	char c;
	while((c = fgetc(file)) != EOF)
    	if(c=='\n')
        	lines++;
    return lines;
}

int main()
{
	int lines=line_counter(), k;
	char *temp=calloc(1000,sizeof(char));
	size_t len = 0;
    ssize_t data;
	FILE *input_file = fopen("./a.txt","r");
    lines++;
    scanf("%d",&k);
    // Copying file contents to memory
    char **strings = malloc(lines*sizeof(char *));
    for (int i=0; i<lines; i++)
    {
    	strings[i] = malloc(1000*sizeof(char));
    	data = getline(&temp, &len, input_file);
    	if (data != -1)
    		strcpy(strings[i],temp);
    	strings[i] = realloc(strings[i],strlen(strings[i])*sizeof(char));
    }
    free(temp);
    fclose(input_file);
    
    // Replacing chars
    for (int i=0; i<lines; i++)
    {
    	for (int j=0; j <strlen(strings[i]); j++)
    		if (strings[i][j]!='\n')
				strings[i][j]=strings[i][j]+k;
    }

    // Printing replaced text
	for (int i=0; i<lines; i++)
		printf("%s", strings[i]);
	printf("\n");

	// Writing to file
	FILE *output_file = fopen("./o.txt", "a");
	for (int i=0; i<lines; i++)
	{
		fprintf(output_file, "%s", strings[i]);
	}
	fclose(output_file);

	return 0;
}