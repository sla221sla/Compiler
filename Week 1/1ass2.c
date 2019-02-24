#include<stdio.h>
#include<string.h>

FILE *r, *w, *k; 
char filename[50];

void multi_line_comments()
{
	
	char c3, c4;
	while((c3 = fgetc(r)) != EOF)
	{
		if(c3 == '*')
		{
			c4 = fgetc(r);
			if(c4 == '/')
			{
				return;
			}
		}
	}

}

void single_line_comments()
{
	char c3;
	while((c3 = fgetc(r)) != EOF)
	{
		if(c3 == '\n')
		{
			return;
		}
	}

}

void check_for_comments(char c1)
{

	char c2;
	if(c1 == '/')
	{
		c2 = fgetc(r);
		if(c2 == '*')
		{
			multi_line_comments();
		}
		else if(c2 == '/')
		{
			single_line_comments();
		}
		else
		{
			fputc(c1, w);
			fputc(c2, w);
		}
	}
	else
	{
		fputc(c1, w);
	}
	return;
	
}

void remove_comments()
{
	
	char c1;	
	r = fopen(filename, "r");
	w = fopen("newfile.c", "w");
	c1 = fgetc(r);
	while(c1 != EOF)
	{
		check_for_comments(c1);
		c1 = fgetc(r);				
	}
	fclose(r);
	fclose(w);
	remove(filename);
	rename("newfile.c", filename);
	printf("Comments removed\n");
}

void check_literals()
{
	char c;
	while((c = fgetc(r)) != EOF)
	{
		if(c == '"')
		{
			return;
		}
	}
}

void remove_literals()
{

	char c;
	r = fopen(filename, "r");
	w = fopen("inter.txt", "w");
	while((c = fgetc(r)) != EOF)
	{
		if(c == '"')
		{
			check_literals();
		}
		else
		{
			fputc(c, w);
		}
	}
	printf("Literals removed\n");
	fclose(r);
	fclose(w);

}

void main()
{
	
	printf("Enter filename : ");
	scanf("%s", filename);		
	remove_comments();
	int count[32], i;
	for(i = 0; i<32; i++)
	{
		count[i] = 0;
	}
	remove_literals();
	k = fopen("keywords.txt", "r");
	r = fopen("inter.txt", "r");
	char keyword[50], word[50];
	i=0;
	fscanf(k, "%s", keyword);
	while(!feof(k))
	{
		fscanf(r,"%s", word);
		printf("%s", word);
		while(!feof(r))
		{
			if(strcmp(keyword, word) == 0)
			{
				count[i]++;
			}
			fscanf(r,"%s" ,word);			
			
		}
		i++;
		if(count[i] > 0)
		{
			printf("The frequency of %s is %d", keyword, count[i]);
		}
		fscanf(k, "%s", keyword);
	}
	

}
