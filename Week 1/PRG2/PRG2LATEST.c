#include<stdio.h>
#include<string.h>
#include<ctype.h>




int main()
{
	int i,count=0,j,length,count2=0,k;
	FILE *file1,*file2;
	char word[100],word2[100],value[100],ch,ch2,word3[1000];
	file1=fopen("2.txt","r");
	file2=fopen("1.c","r");
	if (file1==NULL || file2==NULL)
		printf("the file cannot be opened");
	
	fseek(file1,0,SEEK_END);
	length=ftell(file1);
	fseek(file1,0,SEEK_SET);	
	fread(word3,1,length,file1);
	//printf("%s",word3);
	
/*	for(k=0;k<=strlen(word3);k++)
	if(word3[k]=='\0')
	printf("%d",k);*/
	

	j=0;	
	k=0;
	while(word3[k]!='!')
	{
		if(isalpha(word3[k]))
		{
			word2[j]=word3[k];
			j=j+1;
			k=k+1;
			
		}
		else
		{
		  if(j>0)
			{
	 			word2[j]='\0';
				j=0;
				k=k+1;
			}	
		
			
	
	i=0;
	printf("\n%s",word2);	
	while((ch=fgetc(file2))!=EOF)
	{
		if(isalpha(ch))
	    {
          //printf("%c\n",ch);
	     word[i]=ch;
         i=i+1;
	    }	  
	   else
	    {
            if (i>0)
		    {
			word[i]='\0';		  
			i=0;            		
			count2=0;
			
			if(strcmp(word,word2)==0)
			{
				count=count+1;
			}		   
			
		  // printf("%s\n",word);		
	       }
		}
}
     printf("\nThe no of times %s is present is %d",word2,count);
	count=0;
	strcpy(word2,"");
	fseek(file2,0,SEEK_SET);	
//token = strtok(NULL, " ");
     
}
}
fclose(file1);
fclose(file2);

return 0;
}	
