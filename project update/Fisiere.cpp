#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include"Fisiere.h"


int global_cnt=11;
player* pl[25];

void Create()
{
  player a;

	
     printf("Nume: ");scanf("%s",&a.nume);
	 printf("Prenume: ");scanf("%s",&a.prenume);
	 printf("Post: ");scanf("%s",&a.post);
	
	//private data
	 a.date.key=0;
	 printf("Goluri Marcate: ");scanf("%d",&a.date.goluri);
	 printf("Salariu: ");scanf("%f",&a.date.salariu);

      
	FILE *f;
	f=fopen("f.txt","ab");
	
	 fwrite(&a,sizeof(struct player),1,f);


	
	fclose(f);
	global_cnt++;

}

void LoadTxt()
{
	
       FILE *f1,*f2;
	   f1=fopen("d:\\f1.txt","rt");
	   f2=fopen("d:\\f2.txt","rt");
		int cnt=0;
		
		//clrear memory
	for(int i=0;i<25;i++)
		pl[i]=NULL;
		
		while(cnt<global_cnt)
		{

			pl[cnt]=new player();


			fscanf(f1,"%s %s %s",&pl[cnt]->nume,&pl[cnt]->prenume,&pl[cnt]->post); 
            fscanf(f2,"%d %d %f",&pl[cnt]->date.key,&pl[cnt]->date.goluri,&pl[cnt]->date.salariu );
           
		cnt++;
		}

		fclose(f1);
		fclose(f2);
}


void ViewF()
{
	int cnt=1;
	
	while(pl[cnt-1]!=NULL)
	{
		printf("\n____________________( %d )\n",cnt);
        printf("Nume: %s\n",pl[cnt-1]->nume);
    	printf("Prenume: %s\n",pl[cnt-1]->prenume);
    	printf("Post: %s\n",pl[cnt-1]->post);
		printf("Numar Tricou: %d\n",pl[cnt-1]->date.key);
    	printf("Goluri Marcate: %d\n",pl[cnt-1]->date.goluri);
		printf("Salariu: %.2f\n",pl[cnt-1]->date.salariu);
    	
		cnt++;
	}
}


void SaveTxt(int x,int y)
{
	//x index to delete ,y index to insert
	
		FILE *f1,*f2;
    	f1=fopen("f1.txt","wt");
		f2=fopen("f2.txt","wt");
		player* insert;

	
	int cnt=0;
	while(pl[cnt]!=NULL)
	{
		if(x-1!=cnt)
		{
			fprintf(f1,"%s %s %s \n",pl[cnt]->nume,pl[cnt]->prenume,pl[cnt]->post); 
            fprintf(f2,"%d %d %.2f \n",pl[cnt]->date.key,pl[cnt]->date.goluri,pl[cnt]->date.salariu );
           
		}

		if(y-1==cnt)
		{
		insert=new player();

      	printf("\n____________________( %d )\n",cnt);
        printf("Nume: ");    scanf("%s",&insert->nume);
    	printf("Prenume: "); scanf("%s",&insert->prenume);
    	printf("Post: ");    scanf("%s",&insert->post);
        //private data
          
         printf("Goluri Marcate:"); scanf("%d",&insert->date.goluri);
	     printf("Salariu:"); scanf("%f",&insert->date.salariu);

			fprintf(f1,"%s %s %s \n",insert->nume,insert->prenume,insert->post); 
            fprintf(f2,"%d %d %.2f \n",insert->date.key,insert->date.goluri,insert->date.salariu );
           
		
		}

     cnt++;
	}

fclose(f1);
fclose(f2);
}


void DeleteF()
{
	int x;
	printf("Index:");scanf("%d",&x);
    if(x>0 && x<=global_cnt)
	{
		SaveTxt(x,0);
		global_cnt--;
		LoadTxt();
		pl[global_cnt]=NULL;
		printf("Inregistrarea a fost eliminata...\n");
	}
	else
		
		printf("Inregistrarea nu exista...\n");
}


void InsertF()
{
	int y;
	printf("Index:");scanf("%d",&y);
    if(y>0 && y<=global_cnt)
	{
		pl[global_cnt++]=new player();
		SaveTxt(0,y);
		LoadTxt();
		
	}
	else
		
		printf("Inregistrarea nu exista...\n");
}


void ModifyF()
{
    int index;
		
	printf("Index: ");scanf("%d",&index);
if(index>0 && index<=global_cnt)
{
	index--;
      	printf("\n____________________( %d )\n",index+1);
        printf("Nume: ");    scanf("%s",&pl[index]->nume);
    	printf("Prenume: "); scanf("%s",&pl[index]->prenume);
    	printf("Post: ");    scanf("%s",&pl[index]->post);
        //private data
          
         printf("Goluri Marcate:"); scanf("%d",&pl[index]->date.goluri);
	     printf("Salariu:"); scanf("%f",&pl[index]->date.salariu);
}
else
   printf("Inregistrarea nu a fost gasita\n");
}


void AddF()
{
	pl[global_cnt]=new player();
	

     	printf("\n____________________( %d )\n",global_cnt);
        printf("Nume: ");    scanf("%s",&pl[global_cnt]->nume);
    	printf("Prenume: "); scanf("%s",&pl[global_cnt]->prenume);
    	printf("Post: ");    scanf("%s",&pl[global_cnt]->post);
        //private data
          
         printf("Goluri Marcate:"); scanf("%d",&pl[global_cnt]->date.goluri);
	     printf("Salariu:"); scanf("%f",&pl[global_cnt]->date.salariu);

global_cnt++;
}