#include<stdio.h>
#include<stdlib.h>
int count=1;
void check(char ch2)
{
	if(ch2=='\n')
	 {
	 count=count+1;
      printf("count values");
	 }
}


int main()
{
	FILE *file1,*file2;
	char ch,word[100],word2[100],ch2,ch3,final;
	int i=0,j=0,flag=0,k=0,num2=0,flag2=0;
	file2=fopen("1.c","r");
	if(file2==NULL)
		printf("THE FILE CANNOT BE OPENED");
	while((ch=getc(file2))!=EOF)
	{
		check(ch2);
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
	  	ch2='a';
		  
		  if(strcmp(word,"int")==0)
	  	{
			beg100:
			ch2=getc(file2);
			check(ch2);
			while(ch2!='=')
			{ 
			   
			    word2[j]=ch2;
			   j=j+1;
			   ch2=getc(file2);	  
				check(ch2);
			}	  
			word2[j]='\0';
		//	x=check2(word);
			j=0;
			flag=1;
			printf("%s ",word2);
		 
		    
			if(ch2=='=')
			{
			   beg200:
			   ch2=getc(file2);
			   check(ch2);
			   if(ch2==',')
			   {
			   	   goto beg100; 
			   }
				else
				if(ch2==';')
				 goto beg300;	   
		          
		          goto beg200;
           }
		  
       beg300:
	   if(flag==1)
       printf("ARE THE INTEGER TOKENS. THEY ARE PRESENT IN LINE NUMBER IN %d",count);
}
  else
	    
		if(strcmp(word,"float")==0)
	  	{
			printf("\n");
			beg1:
			ch2=getc(file2);
			check(ch2);
			while(ch2!='=')
			{ 
			   
			    word2[j]=ch2;
			   j=j+1;
			   ch2=getc(file2);	  
			   check(ch2);
			}	  
			word2[j]='\0';
			//x=check2(word2);
			j=0;
			flag=1;
			printf("%s ",word2);
		 
		    
			if(ch2=='=')
			{
			   beg2:
			   ch2=getc(file2);
			   check(ch2);
			   if(ch2==',')
			   {
			   	   goto beg1; 
			   }
				else
				if(ch2==';')
				 goto beg3;	   
		          
		          goto beg2;
           }
		  
       beg3:
	   if(flag==1)
       printf("ARE THE FLOAT TOKENS.THEY ARE PRESENT IN LINE NUMBER %d",count);
}   
if(strcmp(word,"char")==0)

   {
			printf("\n\n");
			beg11:
			ch2=getc(file2);
			check(ch2);
			while(ch2!='=')
			{ 
			   
			   word2[j]=ch2;
			   j=j+1;
			   ch2=getc(file2);	  
			   check(ch2);
			}	  
			word2[j]='\0';
		//	x=check(word2);
			j=0;
			flag=1;
			flag2=1;
			//printf("%s ",word2);
		 
		    
			if(ch2=='=')
			{
			   beg12:
			   ch2=getc(file2);
			   
			   if(ch2=='"' && flag2==1)
			   {
			       printf("%s-ARRAY OF CHARACTER\n",word2);
			    	flag2=0;
				}
			    else
			     if(flag2==1)
				 {
			    
				 	printf("%s-SINGLE CHARACTER\n",word2);
				    flag2=0;
				 }
			   
			   check(ch2);
			   if(ch2==',')
			   {
			   	   goto beg11; 
			   }
				else
				if(ch2==';')
				 goto beg13;	   
		          
		          goto beg12;
           }
		  
       beg13:
	   final=1;
	   
}   	

}
}
return 0;
}
