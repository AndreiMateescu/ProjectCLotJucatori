#include<stdio.h>
#include"Fisiere.h"
#include"Liste.h"

#ifndef ARBORI_H
#define ARBORI_H




struct arb_nod
{
	 player date;
	 arb_nod *stg;
	 arb_nod *dr;
};





//function prototypes

arb_nod* AdaugareInArb(arb_nod *arb,player inf,int x);
arb_nod* creareArb(arb_nod *arb);
void AfisareArb(arb_nod* arb,int l);
void DetaliedView(arb_nod* arb,int x);
void Elimina();
void Stergere(int x);
void Save(arb_nod* arb);
void Modify(arb_nod* arb,int x);
void LoadToTactics(arb_nod* arb);
void see();

extern arb_nod *rad;
extern arb_nod pp;
extern arb_nod *p;
extern arb_nod *q;
extern arb_nod *r;
extern arb_nod *t;



#endif;

