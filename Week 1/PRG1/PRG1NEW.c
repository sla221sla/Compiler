#include<stdio.h>
#include<string.h>
#include<stdlib.h>




void main()
{
	int pos=0,status,flag=0;
	FILE *file,*file2;
	file =fopen("1.c","r");
	file2=fopen("2.c","w");	
	char ch,word2[100];
	
	if (file==NULL || file2==NULL)
	 {
	 
	 printf("The file cannot be opened");
	 exit(0);
 	 }
	while ((ch=getc(file))!=EOF)
	{
		flag=0;	
		//	printf("%c",ch);
		if (ch=='/')
			{
			
			ch=getc(file);
			if (ch=='/' && ch!=EOF)
			{
			  fgets(word2,200,file);
			  flag=1;
			}		    	
			else
			if (ch=='*' && ch!=EOF)
			{
			  beg:
			  ch=getc(file);
			  if (ch=='*' && ch!=EOF)
			   {
                  	     ch=getc(file);
			     if (ch=='/' && ch!=EOF)
				{  
				ch=getc(file);
			 	goto beg2;
				}
			     else
				goto beg;
			  }				
			else
			  goto beg;
			}
			else
			goto beg2;
			 
		}	if (flag==0)		
			printf("%c",ch);
			
				
				beg2:
				if (flag==0)				
				fputc(ch,file2);
			}		
	
fclose(file);
fclose(file2);
//status=remove("1.c");
//if (status==0)
// printf("The file 1.c has been deleted");
//rename("2.c","1.c");
}
