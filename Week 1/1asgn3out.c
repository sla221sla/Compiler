#include<stdio.h>
void main()
{
	char punctuations[100] = {};
	int count = 0;
	int freq;
	FILE* in = fopen("punc.c","r");
	FILE* in1 = fopen("1asgn3.c","r");
	char c;
	while((c = fgetc(in)) != EOF)
	{
		if(c != ' ' && c != '\n')
		{
			punctuations[count] = c;
			count++;
		}
	}
	int frequency[100] = {};
	for(int i=0;i<count;i++)
		frequency[i]=0;
	int i;
	while((c = fgetc(in1)) != EOF)
		{
			for(i=0;i<count;i++)
				{
					if(c == punctuations[i])
						{
							freq = frequency[i];
							freq++;
							frequency[i]=freq;
						}
				}
		}
	printf("Punctuation\tFrequency\n");
	for(int i=0;i<count;i++)
		printf("\t%c\t%d\n",punctuations[i],frequency[i]);
fclose(in);
fclose(in1);
}
