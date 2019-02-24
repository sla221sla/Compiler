#include<stdio.h>
#include<string.h>


int main()
{
	int i,count=0;
	FILE *file1,*file2;
	char word,word2[100],value[100],ch;
	file2=fopen("1.c","r");
	while((ch=fgetc(file2))!=EOF)
	{
	  printf("%c",ch);
	}
	
	file1=fopen("2.txt","r");
	file2=fopen("1.c","r");
	if (file1==NULL || file2==NULL)
		printf("the file cannot be opened");
	
//	printf("%s",word);
	i=0;
	count=0;
	while (!feof(file1))
		{
		
		word= fgetc(file1);
		if (word=='!')
			break;
		printf("\n%c",word);
		while ((ch=fgetc(file2))!=EOF)
			{
	//		printf("%c",ch);
			if (ch==word)
				count=count+1; 
				
		   	}
		printf("\nThe character %c is present %d times",word,count);
		fseek(file2,0,SEEK_SET);
		count=0;
		}
		
//printf("%d",count);
//printf("%s",value);
return 0;		
}
