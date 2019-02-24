#include<stdio.h>
#include<string.h>

FILE *r, *w; 

void multi()
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

void single()
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

void check(char c1)
{

	char c2;
	if(c1 == '/')
	{
		c2 = fgetc(r);
		if(c2 == '*')
		{
			multi();
		}
		else if(c2 == '/')
		{
			single();
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

void main()
{

	char filename[50];
	char c1;
	printf("Enter filename : ");
	scanf("%s", filename);	
	r = fopen(filename, "r");
	w = fopen("newfile.c", "w");
	c1 = fgetc(r);
	while(c1 != EOF)
	{
		check(c1);
		c1 = fgetc(r);				
	}
	fclose(r);
	fclose(w);
	remove(filename);
	rename("newfile.c", filename);
}
