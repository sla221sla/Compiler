#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main()
{
	FILE *file1,*file2;
	char ch,word[100],word2[100],ch2,ch3,final;
	int i=0,j=0,flag=0,k=0,num2=0,count=0,count2=0,count3=0,count4=0;
	file2=fopen("1.c","r");
	if(file2==NULL)
		printf("THE FILE CANNOT BE OPENED");
	while((ch=getc(file2))!=EOF)
	{
		//printf("%c",ch);
		if(isalpha(ch))	
			{
			
			word[i]=ch;
			i=i+1;
		}
	  else
	  {
	  	word[i]='\0';
	  	i=0;
	  	j=0;
	  	if(strcmp(word,"int")==0)
	  	{
			ch3='a';
			while(ch3!=';' && ch2!=';')
		     {
			 ch2=getc(file2);
	  		 //printf("%c",ch2);
			   if(ch2=='=' && ch2!=EOF)
	  			{
	  				beg:
					ch3=getc(file2);
	  			//	printf("%c\t",ch3);
					  if(isdigit(ch3) && ch3!=EOF)
	  				{
	  				
						
						word2[j]=ch3;
					    j=j+1;
					    goto beg;
					  }
				    else
				    if((ch3==','||ch3==';') && ch3!=EOF)
					{
				    //	printf("%c",ch3);
						word2[j]='\0';
					    j=0;
					   flag=1;
					    count=count+1;
						//printf("%d\t",num2);
					for(k=0;k<strlen(word2);k++)
					   printf("%c",word2[k]);
					    printf(" ");
					}
				  
				  }
	         }
		   if (flag==1)
		   printf(" are integer constants\n");
		  }
		  
	    
	
		
		else
	  	if(strcmp(word,"float")==0)
	  	{
			
			ch3='a';
			while(ch3!=';' && ch2!=';')
		     {
			 ch2=getc(file2);
	  		 //printf("%c",ch2);
			   if(ch2=='=' && ch2!=EOF)
	  			{
	  				beg4:
					ch3=getc(file2);
	  			//	printf("%c\t",ch3);
					  if((isdigit(ch3)||ch3=='.') && ch3!=EOF)
	  				{
	  				
						
						word2[j]=ch3;
					    j=j+1;
					    goto beg4;
					  }
				    else
				    if((ch3==','||ch3==';') && ch3!=EOF)
					{
				    //	printf("%c",ch3);
						word2[j]='\0';
					    j=0;
					   flag=1;
					   count2=count2+1;
						//printf("%d\t",num2);
					for(k=0;k<strlen(word2);k++)
					   printf("%c",word2[k]);
					    printf(" ");
					}
				  
				  }
	         }
		   if (flag==1)
		   printf(" are Floating Point constants");
		  }
	
   else
	   printf("\n");
	   if(strcmp(word,"char")==0)
	   {
			//printf("%s\n",word);
			//fseek(file2,0,SEEK_SET);
			ch3='a';
			ch2='a';
			while(ch3!=';' && ch2!=';')
		     {
			 beg10:
			 ch2=getc(file2);
	  		 //printf("%c",ch2);
			   if(ch2=='=' && ch2!=EOF)
	  			{
	  				beg20:
					ch3=getc(file2);
					if(ch3!='"')
					{
					ch3=getc(file2);
	  			    //printf("%c\t",ch3);
	  				 final=ch3;
	  				 printf("%c-SINGLE CHARACTER\n",final);
	  			     ch3=getc(file2); 
					   count3=count3+1;
					   goto beg10;
				  }
	  			 else
	  			    {
					count4=count4+1;
					 ch3=getc(file2);
					 while(ch3!='"')
	  			   {
	  			   	printf("%c",ch3);
					 ch3=getc(file2);
					}
				    printf("-STRING CONSTANTS\n");
				  }
  }
   }
	//printf(" are the single characters constants present");

}
}
}
printf("\nNo of times int values are there is %d",count);
printf("\nNo of times float values are there is %d",count2);
printf("\nNo of times single char values are there is %d",count3);
printf("\nNo of times string values are there is %d",count4);
return 0;	
}
