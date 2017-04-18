#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#ifndef TACTIC_H
#define TACTIC_H


struct jucator
{
int nr;
char Nume[20];
char post[20];
}jucatori[25];

extern int nrj;
extern int nr[4]; 
extern int cnt;
#endif;


int nrj=0;
int cnt=0;
int st[12];
int k=1;
int nr[4];
int x=0,j=0,l=0;
void init()
{
	st[k]=-1;
}
bool succesor()
{
	if(st[k]<nrj-1)
	{
		st[k]++;
		return 1;
	}
return 0;
}
bool valid()
{
	
	for(int i=1;i<k;i++)
	{
        if(st[i]==st[k])
		{
			return 0;
		}
	}
		if(k>3 && !(strcmp(jucatori[st[k]].post,"atacant")))
			return 0;
        else if((k<3 || k>6) && !(strcmp(jucatori[st[k]].post,"mijlocas")))
	         return 0;
	
		else if(k<6 && !(strcmp(jucatori[st[k]].post,"fundas")))
	         return 0;
		else if(k<11 && !(strcmp(jucatori[st[k]].post,"portar")))
	        return 0;
 



 return 1;
}
bool solutie()
{
	if(k==11)
		return 1;

return 0;
}


void back()
{
FILE *f;
f=fopen("Formations.txt","wt");


for(int i=0;i<nrj;i++)
 
	k=1;
	init();
	int gasit=0;
	while(k)
	{
		while((gasit=succesor())&& !(valid())) {}
	
		if(gasit)
		{
			if(solutie())
			{
				cnt++;
				for(int i=1;i<=11;i++)
				{
					x++;
					if(nr[j])
					l=40/nr[j];
					if(i==11)l=40;
					for(int v=1;v<=l;v++)
						fprintf(f," ");

					fprintf(f,"%s (%d)%c    ",jucatori[st[i]].Nume,jucatori[st[i]].nr,jucatori[st[i]].post[0]-32);
			        if(x==nr[j])
					{
						fprintf(f,"\n\n\n\n");
						x=0;j++;
					}
  			

				}
			 
			  j=x=0;

			  fprintf(f,"\n\n\n\n----------------------------------------------------------------\n\n\n\n");
			}
			else
			{
				k++;
				init();
			}
		}
		else
			k--;
	}

	printf("Total Posibilitati %d\n",cnt);
	nrj=0;
	cnt=0;
}