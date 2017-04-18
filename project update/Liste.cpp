#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<time.h>
#include"Liste.h"





NOD* first=NULL;
NOD* last=NULL;




void LoadToList()
{
	FILE *f;
	f=fopen("f.txt","rb");

    
	first=new NOD;
	fread(&first->date,sizeof(struct player),1,f); 
     

	first->next=NULL;
	first->back=NULL;
    last=first;
    int cnt=2;
	while(cnt<=global_cnt)
	{
	
		last->next=new NOD;
	fread(&last->next->date,sizeof(struct player),1,f);
	 
		  last->next->back=last;
          last=last->next;
          last->next=NULL;

		  cnt++;
	}


	fclose(f);
	
	
	printf("Data has been loaded \n");
	
}

void LoadToListTXT()
{
	FILE *f1,*f2;
	f1=fopen("f1.txt","rt");
    f2=fopen("f2.txt","rt");

    
	first=new NOD;
	fscanf(f1,"%s %s %s",&first->date.nume,&first->date.prenume,&first->date.post); 
    fscanf(f2,"%d %d %f",&first->date.date.key,&first->date.date.goluri,&first->date.date.salariu );
 	
	first->next=NULL;
	first->back=NULL;
    last=first;
    int cnt=2;
	while(cnt<=global_cnt)
	{
	
		last->next=new NOD;
	fscanf(f1,"%s %s %s",&last->next->date.nume,&last->next->date.prenume,&last->next->date.post); 
    fscanf(f2,"%d %d %f",&last->next->date.date.key,&last->next->date.date.goluri,&last->next->date.date.salariu );
 	 
		  last->next->back=last;
          last=last->next;
          last->next=NULL;

		  cnt++;
	}


	fclose(f1);
	fclose(f2);
	
	
	printf("Data has been loaded \n");
	
}



void View()
{
	NOD* temp=first;
	int cnt=1;
	
	while(temp!=NULL)
	{
		printf("\n____________________( %d )\n",cnt);
        printf("Nume: %s\n",temp->date.nume);
    	printf("Prenume: %s\n",temp->date.prenume);
    	printf("Post: %s\n",temp->date.post);
		printf("Numar Tricou: %d\n",temp->date.date.key);
    	printf("Goluri Marcate: %d\n",temp->date.date.goluri);
		printf("Salariu: %.2f\n",temp->date.date.salariu);
    	
		cnt++;
		temp=temp->next;
	}
	delete temp;
}
 void Add()
{
	if(first!=NULL)
	{
	last->next=new NOD;
	
        printf("Nume: ");    scanf("%s",&last->next->date.nume);
    	printf("Prenume: "); scanf("%s",&last->next->date.prenume);
    	printf("Post: ");    scanf("%s",&last->next->date.post);
        //private data
          
         printf("Goluri Marcate:"); scanf("%d",&last->next->date.date.goluri);
	     printf("Salariu:"); scanf("%f",&last->next->date.date.salariu);

  
   last->next->back=last;
   last=last->next;
   last->next=NULL;
   
   global_cnt++;
	}
	else
	printf("\nTrebuie intai creata o lista!\n");
}



void Modify()
{
    int index;
	int cnt=0;
	int done=0;
	NOD* temp=first;
	printf("\nIndex: ");scanf("%d",&index);
	while(temp!=NULL)
	{
		cnt++;
		if(cnt==index)
		{
		printf("\n____________________( %d )\n",cnt);
        printf("Nume: ");    scanf("%s",&temp->date.nume);
    	printf("Prenume: "); scanf("%s",&temp->date.prenume);
    	printf("Post: ");    scanf("%s",&temp->date.post);
        //private data
          
         printf("Goluri Marcate:"); scanf("%d",&temp->date.date.goluri);
	     printf("Salariu:"); scanf("%f",&temp->date.date.salariu);
	
		}
		temp=temp->next;
	}
	delete temp;
	if(done==0)
		   printf("\nInregistrarea nu a fost gasita:\n");
}

void Insert()
{
    int index;
	int cnt=0;

	NOD* temp=first;
	NOD* newNOD=NULL;
	
	printf("\nIndex: ");scanf("%d",&index);
           

  
    while(temp!=NULL)
	{
		
		if(cnt==index )
		{
			newNOD=new NOD();
          	printf("Nume: ");scanf("%s",&newNOD->date.nume);
	        printf("Prenume: ");scanf("%s",&newNOD->date.prenume);
	        printf("Post: ");scanf("%s",&newNOD->date.post);
	
	        //private data
	     
	        printf("Goluri Marcate: ");scanf("%d",&newNOD->date.date.goluri);
	        printf("Salariu: ");scanf("%f",&newNOD->date.date.salariu);


         if(index==0)
		  {
			  temp->back=newNOD;
			  newNOD->next=first;
			  first=newNOD;
		  }
        
		  else if(temp->next!=NULL)
		  {
           
			temp->next->back=newNOD;
			newNOD->next=temp->next;
			temp->next=newNOD;
			newNOD->back=temp;
		  }
	
		}
		if(cnt>0)
		temp=temp->next;
		
		cnt++;
		
	}
	if(newNOD==NULL)
	{
    
 	printf("\n Inregistrarea nu a fost gasita:\n");
	}
	else
		global_cnt++;

}

void Delete()
{
	int index;
	int cnt=0;
	printf("\nIndex: ");scanf("%d",&index);
	NOD* temp=first;
	NOD* deleted=NULL;
	while(temp!=NULL)
	{
		cnt++;
		if(cnt==index)
		{
			
		
		  deleted=temp;

		  if(temp->back==NULL)
			  first=first->next;
		  else
		  {
         
           temp->back->next=temp->next;
           if(temp->next!=NULL)          
		   temp->next->back=temp->back;
		  }
		   
		}
	
		temp=temp->next;
	}
    delete temp;
    if(deleted!=NULL)
	{
		global_cnt--;
	   delete deleted;
       	printf("Nodul a fost sters\n");
  	 
	}
	else
		printf("Inregistrarea nu a fost gasita\n");
}

void SaveList()
{

	srand(time(0));
	int nr[100];
	//generare numar tricouri
	for(int i=0;i<global_cnt;i++)
	{
		nr[i]=1+ rand() % global_cnt;
		for(int j=0;j<i;j++)
				if(nr[i]==nr[j])
				{ 
					i--;
		          break;
		         }
	}

	NOD* temp=first;
	int cnt=1;
	int i=0;
    FILE *f1, *f2;	
	f1=fopen("f1.txt","wt");
    f2=fopen("f2.txt","wt");

	while(temp!=NULL)
	{
	 
    temp->date.date.key=nr[i++]; 
	 
	fprintf(f1,"%s %s %s \n",temp->date.nume,temp->date.prenume,temp->date.post);
	fprintf(f2,"%d %d %.2f \n",temp->date.date.key,temp->date.date.goluri,temp->date.date.salariu);
	 
	
		cnt++;
		temp=temp->next;
	}
	
	fclose(f1);
	fclose(f2);
	delete temp;
}








