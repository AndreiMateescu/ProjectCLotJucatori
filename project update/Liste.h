#include<stdio.h>
#include<stdlib.h>
#include"Fisiere.h"
#ifndef LISTE_H
#define LISTE_H



//function prototypes

void LoadToList();
void LoadToListTXT();
void View();
void Add();
void Modify();
void Insert();
void Delete();
void SaveList();




struct NOD
{
	player date;
	NOD* next;
	NOD* back;
};


#endif;
