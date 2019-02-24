#include<stdio.h>
#include<string.h>
void main()
{
	FILE* in = fopen("1asgn2.txt","r");
	FILE* in1 = fopen("1exmple2.c","r");
	int count = 0,flag = 0;
	char keyword[20],codeword[100],c,c1,strng[2] = {'c','\0'};
	for(int i=0;i<20;i++)
		keyword[i] = '\0';
	for(int i=0;i<100;i++)
		codeword[i] = '\0';
	while((c = fgetc(in)) != EOF)
	{
		if(c != ' ' && c != '\n')
		{
			strng[0] = c;
			strcat(keyword,strng);
		}
		else
		{
			while((c1 = fgetc(in1)) != EOF && keyword[0] != '\0')
			{
				if(c1 != ' ' && c1 != '\n')
				{
					strng[0] = c1;
					strcat(codeword,strng);
				}
				else
				{
					if (strcmp(keyword,codeword) == 0)
					{
						count++;
						flag = 1;
					}
					for(int i=0;i<100;i++)
						codeword[i] = '\0';
					if( c1 == ' ' || c1 == '\n')
						continue;					

				}
			}
			if (flag == 1)
			{
				printf("%s\n",keyword);
				flag = 0;
			}
			for(int i=0;i<20;i++)
				keyword[i] = '\0';
			if(count !=0)
				printf("Frequency is %d\n",count);
			count = 0;
			fseek(in1, 0, SEEK_SET);
			if( c == ' ' || c == '\n')
				continue;	
		}
	}
	
}
