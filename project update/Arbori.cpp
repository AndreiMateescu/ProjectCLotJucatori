#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Arbori.h"
#include"Tactic.h"


arb_nod *rad;
arb_nod pp;
arb_nod *p;
arb_nod *q;
arb_nod *r;
arb_nod *t;




arb_nod* AdaugareInArb(arb_nod *arb,player inf,int x)
{	
	

	if(arb==NULL)
	{
		arb=new(arb_nod);
		arb->stg=NULL;
		arb->dr=NULL;
		arb->date=inf;
		 
	}
	else if(arb->date.date.key<x)
	{
		  arb->dr= AdaugareInArb(arb->dr,inf,x);
		 
	}	
	else if(arb->date.date.key>x)
	{
			arb->stg=AdaugareInArb(arb->stg,inf,x);
	     
	}
	else
			 printf("Exista nodul cu informatia %d\n",x);
		 return arb;
}

arb_nod* creareArb(arb_nod *arb){
	int x;
	nrj=0;
	arb=NULL;
	player inf;
	FILE *f1,*f2;
	f1=fopen("f1.txt","rt");
	f2=fopen("f2.txt","rt");
	

   
	
do{

    fscanf(f1,"%s",&inf.nume);
	fscanf(f1,"%s",&inf.prenume);
	fscanf(f1,"%s",&inf.post);
	//private data
    fscanf(f2,"%d",&inf.date.key);
	fscanf(f2,"%d",&inf.date.goluri);
	fscanf(f2,"%f",&inf.date.salariu);
	x=inf.date.key;
	if(x>0) arb=AdaugareInArb(arb,inf,x);
}
	while(x>0 && !feof(f1));


	return arb;
}



void AfisareArb(arb_nod* arb,int l)
{

	int i;

	if(arb!=NULL)
	{
		AfisareArb(arb->dr,l+5);
		for(i=0;i<l;i++) 
			printf(" ");
		if(arb->date.date.key>0)
			printf("%d\n",arb->date.date.key);
		for(i=0;i<l;i++)
			printf(" ");
		printf("\n");
		AfisareArb(arb->stg,l+5);
	}
}

	FILE *f1, *f2;	

void Save(arb_nod* arb)
{
	if(arb!=NULL)
	{
     Save(arb->stg);

	 f1=fopen("f1.txt","at");
	 f2=fopen("f2.txt","at");
 
	fprintf(f1,"%s %s %s \n",arb->date.nume,arb->date.prenume,arb->date.post);
	fprintf(f2,"%d %d %.2f \n",arb->date.date.key,arb->date.date.goluri,arb->date.date.salariu);
	 
	
	fclose(f1);
	fclose(f2);

	Save(arb->dr);
	}

}



void Elimina()
{
	if(t->dr!=NULL){
		r=t;
		t=t->dr;
		Elimina();
	}
	else{
		   q->date.date.key=t->date.date.key;

		   if((r!=NULL)&&(r->dr==t))
			   r->dr=t->stg;
		   else q->stg=t->stg;
		   q=t;
	}
}

void Stergere(int x)
{
	if(p==NULL)
		printf("\n Acest nod nu exista \n");
	else if(x<p->date.date.key){
		r=p;
		p=p->stg;
		Stergere(x);
	}
	else if(x>p->date.date.key)
	     {
			 r=p;
			 p=p->dr;
			 Stergere(x);
	}
	else{
		   q=p;
		   if(q==rad){
			      if(rad->stg==NULL)
					  rad=rad->dr;
				  else if(rad->dr==NULL)
					     rad=rad->stg;
				  else{
					  t=q->stg;
					  Elimina();
				  }
		   }
		   else
			   if(q->dr==NULL){
				               if(r->stg==p)
								   r->stg=q->stg;
							   else
								   r->dr=q->stg;
			   }
			   else
				   if(q->stg==NULL){
					   if(r->stg==p)
						   r->stg=q->dr;
					   else
						   r->dr=q->dr;
				   }
				   else{
					      t=q->stg;
						  Elimina();
				   }
				   delete q;
	}
}


/*void LoadToTactics(arb_nod* arb)
{
	if(arb!=NULL)
	{
	 if(!strcmp("atacant",arb->date.post))
		{
			atacanti[a].nr=arb->date.date.key;
			strcpy(atacanti[a].Nume,arb->date.nume);
         a++;   
		}
		else if(!strcmp(arb->date.post,"mijlocas"))
		{
			mijlocasi[m].nr=arb->date.date.key;
			strcpy(mijlocasi[m].Nume,arb->date.nume);
            m++;
		}
		else if(!strcmp(arb->date.post,"fundas"))
		{
			fundasi[f].nr=arb->date.date.key;
			strcpy(fundasi[f].Nume,arb->date.nume);
            f++;
		}
		else if(!strcmp(arb->date.post,"portar"))
		{
			portari[pr].nr=arb->date.date.key;
			strcpy(portari[pr].Nume,arb->date.nume);
		    pr++;
		}
		
		
	
	LoadToTactics(arb->stg);
	LoadToTactics(arb->dr);
	}
}
*/

void LoadToTactics(arb_nod* arb)
{
	if(arb!=NULL)
	{
			jucatori[nrj].nr=arb->date.date.key;
			strcpy(jucatori[nrj].Nume,arb->date.nume);
			strcpy(jucatori[nrj].post,arb->date.post);
			
         nrj++;   
	
	LoadToTactics(arb->stg);
	LoadToTactics(arb->dr);
	}
	else
		global_cnt=nrj;
}

void Modify(arb_nod* arb,int x)
{
	if(arb!=NULL)
	{
		if(arb->date.date.key==x)
		{
         printf("Nume:");scanf("%s",&arb->date.nume);
         printf("Prenume:");scanf("%s",&arb->date.prenume);
         printf("Post:"); scanf("%s",&arb->date.post);
         printf("Goluri Marcate:"); scanf("%d",&arb->date.date.goluri);
         printf("Salariu"); scanf("%f",&arb->date.date.salariu);
		}
		else if(x>arb->date.date.key)
			Modify(arb->dr,x);
		else
			Modify(arb->stg,x);
	}
	else
		printf("Nodul nu exista\n");
}





void DetaliedView(arb_nod* arb,int x)
{
	if(arb!=NULL)
	{
		if(arb->date.date.key==x)
		{
			printf("Nume:%s \nPrenume:%s\nNumarTricou:%d\nGoluri:%d\nSalariu:%f\n\n",
				   arb->date.nume,arb->date.prenume,x,arb->date.date.goluri,arb->date.date.salariu);
		}
		else if(arb->date.date.key<x)
			DetaliedView(arb->dr,x);
		else
           DetaliedView(arb->stg,x);

	}
	else
		printf("Inregistrarea nu exista\n");
}


void see()
{
	printf("Formation type:");
	for(int i=0;i<4;i++)
		scanf("%d",&nr[i]);
	back();
};