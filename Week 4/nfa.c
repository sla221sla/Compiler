#include<stdio.h>
#include<string.h>
#define MAX 100
#define fl(i,a,b) for(i=a; i<b; i++)
#define nline printf("\n")
#define scan(a) scanf("%d", &a)
int states, symbols, symdir[20], final_states, mark[20], mat[20][20][20], initial;
char str1[MAX];


int curr[20], t[20];
		
int ind, ind1;
int l1,i, j, k;
		

int main()
{	
	char x[100], by[100];
	FILE *fptr;
	fptr = fopen("input.txt","r");
	fgets(x, MAX, fptr);
	states = (int)(x[0]%48);  //assuming number of states less than 10
	fgets(x, MAX, fptr);
	symbols = strlen(x)-1;
	fl(i, 0, symbols)
	{
		symdir[i] = (int)(x[i]%97);	
	}
	fgets(x, MAX, fptr);
	initial = (int)(x[0]%48);
	fgets(x, MAX, fptr);
	final_states = strlen(x)-1;
	fl(i, 0, final_states)
	{
		mark[i] = (int)(x[i]%48);	
	}
	while(!feof(fptr))
	{
		fgets(x, MAX, fptr);
		int cs = (int)(x[0]%48);
		printf("%d, ", cs);
		int csy = (int)(x[1]%97);
		printf("%d, ", csy);
		fl(k,2,strlen(x)-1)
		{ 
			mat[cs][csy][k]=(int)(x[k]%48);
			printf("%d\n", mat[cs][csy][k]);
		}
	}
	int cases;
	printf("Enter the number of strings to be tested : ");
	scanf("%d", &cases);
	fl(k,0,cases)
	{
		printf("Enter the string to be tested : ");
		
		scanf("%s", str1);

		curr[0]=0;
		ind=1;
		int limit=strlen(str1);

		fl(i,0,limit)
		{
			int ele=(int)(str1[i]-'0');

			ind1=0;
			
			fl(l1,0,ind)
			{
				j=0;
				while(mat[curr[l1]][ele][j]!=-1)
				{
					t[ind1++]=mat[curr[l1]][ele][j];
					j++;
				}
			}

			fl(l1,0,ind1)
			{
				curr[l1]=t[l1];
			}

			ind=ind1;
		}
		
		int flag=0;

		fl(i,0,ind)
		{
			if(mark[curr[i]]==1)
			{
				flag=1;
				break;
			}
		}
		printf("The entered string is ");

		if(flag==1)
			printf("Accepted");
		else
			printf("Rejected");
		nline;
	}
	fclose(fptr);
	return 0;
}
