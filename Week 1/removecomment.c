#include<stdio.h>
void main()
{
	FILE* in = fopen("1asgn1.c","r");
	FILE* out = fopen("rmvdcmtpgm.c","w");
	char c;
	while((c = fgetc(in)) != EOF)	
		{
			if(c == '/')
				{
					c = fgetc(in);
					if(c == '/')
						{
							while((c = fgetc(in)) != '\n');
						}
					else if(c == '*')
						{
							while((c = fgetc(in)) != EOF)
							{
								if((c = fgetc(in)) == '*' && (c = fgetc(in)) == '/')
								{
									c = '\n';
									break;
								}	 																										
							}
						}
					else
						fputc('/',out);	
				}
			else
				fputc(c,out);
		}
	
	fclose(in);
	fclose(out);
}

