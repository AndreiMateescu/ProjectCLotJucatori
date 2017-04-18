#include<stdio.h>
#ifndef FISIERE_H
#define FISIERE_H



//function prototypes
void Create();
void ViewF();
void LoadTxt();
void SaveTxt(int x,int y);
void DeleteF();
void ModifyF();
void InsertF();
void AddF();
extern int global_cnt;

struct data
{
	float salariu;
	int   goluri;
   	int   key;
};


struct player
{
	char  nume[20];
	char  prenume[20];
    char  post[20];
	data  date;

};
extern player*	pl[25];

#endif;








