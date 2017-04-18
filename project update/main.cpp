#include"Liste.h"
#include"Arbori.h"


#include<time.h>
#include<conio.h>

void Begin();

void main()
{

  FILE *f1, *f2;	
  int x=0;
  char chooseL=1,chooseA=0,chooseF=0;
  player pl;
  
  srand(time(0));
  arb_nod* S;
  //Begin(); 
  
  LoadToList();
  SaveList(); 
  LoadToListTXT();
  S=creareArb(S);

while(1)
{
 
 while(chooseL)
 {
	 system("cls");

                                                                                                                           
                                                                                                                            
printf("                          LLLLLLLLLLL             IIIIIIIIII   SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTTEEEEEEEEEEEEEEEEEEEEEE\n");
printf("                          L:::::::::L             I::::::::I SS:::::::::::::::ST:::::::::::::::::::::TE::::::::::::::::::::E\n");
printf("                          L:::::::::L             I::::::::IS:::::SSSSSS::::::ST:::::::::::::::::::::TE::::::::::::::::::::E\n");
printf("                          LL:::::::LL             II::::::IIS:::::S     SSSSSSST:::::TT:::::::TT:::::TEE::::::EEEEEEEEE::::E\n");
printf("                            L:::::L                 I::::I  S:::::S            TTTTTT  T:::::T  TTTTTT  E:::::E       EEEEEE\n");
printf("                            L:::::L                 I::::I  S:::::S                    T:::::T          E:::::E             \n");
printf("                            L:::::L                 I::::I   S::::SSSS                 T:::::T          E::::::EEEEEEEEEE   \n");
printf("                            L:::::L                 I::::I    SS::::::SSSSS            T:::::T          E:::::::::::::::E   \n");
printf("                            L:::::L                 I::::I      SSS::::::::SS          T:::::T          E:::::::::::::::E   \n");
printf("                            L:::::L                 I::::I         SSSSSS::::S         T:::::T          E::::::EEEEEEEEEE   \n");
printf("                            L:::::L                 I::::I              S:::::S        T:::::T          E:::::E             \n");
printf("                            L:::::L         LLLLLL  I::::I              S:::::S        T:::::T          E:::::E       EEEEEE\n");
printf("                          LL:::::::LLLLLLLLL:::::LII::::::IISSSSSSS     S:::::S      TT:::::::TT      EE::::::EEEEEEEE:::::E\n");
printf("                          L::::::::::::::::::::::LI::::::::IS::::::SSSSSS:::::S      T:::::::::T      E::::::::::::::::::::E\n");
printf("                          L::::::::::::::::::::::LI::::::::IS:::::::::::::::SS       T:::::::::T      E::::::::::::::::::::E\n");
printf("                          LLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIII SSSSSSSSSSSSSSS         TTTTTTTTTTT      EEEEEEEEEEEEEEEEEEEEEE\n");
                                                                                                                            


	 printf("                                            \------------------------------------------------------\n");
	 printf("\n                                              1-ADD 2-VIEW 3-INSERT 4-DELETE 5-SAVE 0-NEXT \n");
	 printf("                                            \------------------------------------------------------   ");
  
	 switch(chooseL=getch())
  {
  case '1':
	  Add();
	  break;
  case '2':
	  View();
	  break;
  case '3':
    Insert();
	break;
  case '4':
	  Delete();
	  break;
  case '5' :
	  SaveList();
	  break;
  default:
	  printf("1-FISIERE 2-ARBORE :");chooseL=getch();
	  if(chooseL=='1')
	  {
		  chooseF=1;
          LoadTxt();
	  }
	  else
	  {
		  chooseA=1;
          S=creareArb(S);
	  }
	  chooseL=0;

	  break;
  }
	 getch();
 }


 
while(chooseA)
{
    system("cls");

                                                                                                                                              
                                                                                                                                              
printf("                       AAA               RRRRRRRRRRRRRRRRR   BBBBBBBBBBBBBBBBB        OOOOOOOOO     RRRRRRRRRRRRRRRRR   EEEEEEEEEEEEEEEEEEEEEE\n");
printf("                      A:::A              R::::::::::::::::R  B::::::::::::::::B     OO:::::::::OO   R::::::::::::::::R  E::::::::::::::::::::E\n");
printf("                     A:::::A             R::::::RRRRRR:::::R B::::::BBBBBB:::::B  OO:::::::::::::OO R::::::RRRRRR:::::R E::::::::::::::::::::E\n");
printf("                    A:::::::A            RR:::::R     R:::::RBB:::::B     B:::::BO:::::::OOO:::::::ORR:::::R     R:::::REE::::::EEEEEEEEE::::E\n");
printf("                   A:::::::::A             R::::R     R:::::R  B::::B     B:::::BO::::::O   O::::::O  R::::R     R:::::R  E:::::E       EEEEEE\n");
printf("                  A:::::A:::::A            R::::R     R:::::R  B::::B     B:::::BO:::::O     O:::::O  R::::R     R:::::R  E:::::E             \n");
printf("                 A:::::A A:::::A           R::::RRRRRR:::::R   B::::BBBBBB:::::B O:::::O     O:::::O  R::::RRRRRR:::::R   E::::::EEEEEEEEEE   \n");
printf("                A:::::A   A:::::A          R:::::::::::::RR    B:::::::::::::BB  O:::::O     O:::::O  R:::::::::::::RR    E:::::::::::::::E   \n");
printf("               A:::::A     A:::::A         R::::RRRRRR:::::R   B::::BBBBBB:::::B O:::::O     O:::::O  R::::RRRRRR:::::R   E:::::::::::::::E   \n");
printf("              A:::::AAAAAAAAA:::::A        R::::R     R:::::R  B::::B     B:::::BO:::::O     O:::::O  R::::R     R:::::R  E::::::EEEEEEEEEE   \n");
printf("             A:::::::::::::::::::::A       R::::R     R:::::R  B::::B     B:::::BO:::::O     O:::::O  R::::R     R:::::R  E:::::E             \n");
printf("            A:::::AAAAAAAAAAAAA:::::A      R::::R     R:::::R  B::::B     B:::::BO::::::O   O::::::O  R::::R     R:::::R  E:::::E       EEEEEE\n");
printf("           A:::::A             A:::::A   RR:::::R     R:::::RBB:::::BBBBBB::::::BO:::::::OOO:::::::ORR:::::R     R:::::REE::::::EEEEEEEE:::::E\n");
printf("          A:::::A               A:::::A  R::::::R     R:::::RB:::::::::::::::::B  OO:::::::::::::OO R::::::R     R:::::RE::::::::::::::::::::E\n");
printf("         A:::::A                 A:::::A R::::::R     R:::::RB::::::::::::::::B     OO:::::::::OO   R::::::R     R:::::RE::::::::::::::::::::E\n");
printf("        AAAAAAA                   AAAAAAARRRRRRRR     RRRRRRRBBBBBBBBBBBBBBBBB        OOOOOOOOO     RRRRRRRR     RRRRRRREEEEEEEEEEEEEEEEEEEEEE\n");




	printf("                                        \---------------------------------------------------------\n");
	printf("\n                                           1-ADD 2-VIEW  3-DELETE 4-MODIFY 5-SAVE 0-NEXT \n");
    printf("                                        \---------------------------------------------------------      ");
     

	 switch(chooseA=getch())
  {
  case '1':
	  if(global_cnt<25)
	  {
	  printf("Nume:");scanf("%s",&pl.nume);
      printf("Prenume:");scanf("%s",&pl.prenume);
      printf("Post:"); scanf("%s",&pl.post);
      printf("Numar:"); scanf("%d",&pl.date.key);
      while(pl.date.key<1)
	  {   printf("Introduceti un nr mai mare ca 0\n");
		  printf("Numar:"); scanf("%d",&pl.date.key);
	  }
	  printf("Goluri Marcate:"); scanf("%d",&pl.date.goluri);
      printf("Salariu"); scanf("%f",&pl.date.salariu);
      

	  S=AdaugareInArb(S,pl,pl.date.key);
	  global_cnt++;
	  }
	  else
		  printf("Lotul este plin, pentru a inregsitra un jucator sunteti nevoit sa stergeti\n");
	  break;
  case '2':
	AfisareArb(S,0);

	printf("Doriti vizualizare detaliata? 0-Nu 1-Da\n");
	chooseA=getch();
	while(chooseA=='1')
	{
	
	printf("index:");scanf("%d",&x);
	DetaliedView(S,x);   
	printf("Doriti vizualizare detaliata? 0-Nu 1-Da\n");
	chooseA=getch();
	}
	chooseA='2';
	break;
  case '3':
    p=S;
	printf("index:");scanf("%d",&x);
    Stergere(x);
 	break;
case '4':
	printf("index:");scanf("%d",&x);
    Modify(S,x);
	break;

case '5':
	 f1=fopen("f1.txt","wt");
	 f2=fopen("f2.txt","wt");
     
	Save(S);  

   break;
  default:
	 global_cnt=0; 
	
	  LoadToTactics(S);
	  if(global_cnt<11)
		  printf("lot insuficient pentru a genera formatii \n");
	  else
	  {
	  see();
	  }


  printf("1-FISIERE 2-LISTE :");chooseA=getch();
	  if(chooseA=='1')
	  {
		  chooseF=1;
          LoadTxt();
	  }
	  else
	  {
		  chooseL=1;
          LoadToListTXT();
	  }
	  chooseA=0;
  

	  break;
  }
	 getch();
}

 while(chooseF)
 {
	 system("cls");
	
	 printf("        FFFFFFFFFFFFFFFFFFFFFFIIIIIIIIII   SSSSSSSSSSSSSSS IIIIIIIIIIEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRRR   EEEEEEEEEEEEEEEEEEEEEE\n");
     printf("       F::::::::::::::::::::FI::::::::I SS:::::::::::::::SI::::::::IE::::::::::::::::::::ER::::::::::::::::R  E::::::::::::::::::::E\n");
     printf("       F::::::::::::::::::::FI::::::::IS:::::SSSSSS::::::SI::::::::IE::::::::::::::::::::ER::::::RRRRRR:::::R E::::::::::::::::::::E\n");
     printf("       FF::::::FFFFFFFFF::::FII::::::IIS:::::S     SSSSSSSII::::::IIEE::::::EEEEEEEEE::::ERR:::::R     R:::::REE::::::EEEEEEEEE::::E\n");
     printf("         F:::::F       FFFFFF  I::::I  S:::::S              I::::I    E:::::E       EEEEEE  R::::R     R:::::R  E:::::E       EEEEEE\n");
     printf("         F:::::F               I::::I  S:::::S              I::::I    E:::::E               R::::R     R:::::R  E:::::E             \n");
     printf("         F::::::FFFFFFFFFF     I::::I   S::::SSSS           I::::I    E::::::EEEEEEEEEE     R::::RRRRRR:::::R   E::::::EEEEEEEEEE   \n");
     printf("         F:::::::::::::::F     I::::I    SS::::::SSSSS      I::::I    E:::::::::::::::E     R:::::::::::::RR    E:::::::::::::::E   \n");
     printf("         F:::::::::::::::F     I::::I      SSS::::::::SS    I::::I    E:::::::::::::::E     R::::RRRRRR:::::R   E:::::::::::::::E   \n");
     printf("         F::::::FFFFFFFFFF     I::::I         SSSSSS::::S   I::::I    E::::::EEEEEEEEEE     R::::R     R:::::R  E::::::EEEEEEEEEE   \n");
     printf("         F:::::F               I::::I              S:::::S  I::::I    E:::::E               R::::R     R:::::R  E:::::E             \n");
     printf("         F:::::F               I::::I              S:::::S  I::::I    E:::::E       EEEEEE  R::::R     R:::::R  E:::::E       EEEEEE\n");
     printf("       FF:::::::FF           II::::::IISSSSSSS     S:::::SII::::::IIEE::::::EEEEEEEE:::::ERR:::::R     R:::::REE::::::EEEEEEEE:::::E\n");
     printf("       F::::::::FF           I::::::::IS::::::SSSSSS:::::SI::::::::IE::::::::::::::::::::ER::::::R     R:::::RE::::::::::::::::::::E\n");
     printf("       F::::::::FF           I::::::::IS:::::::::::::::SS I::::::::IE::::::::::::::::::::ER::::::R     R:::::RE::::::::::::::::::::E\n");
     printf("       FFFFFFFFFFF           IIIIIIIIII SSSSSSSSSSSSSSS   IIIIIIIIIIEEEEEEEEEEEEEEEEEEEEEERRRRRRRR     RRRRRRREEEEEEEEEEEEEEEEEEEEEE\n");


                                                               
	 
	 printf("                                          \-----------------------------------------------------------------\n");
	 printf("\n                                           1-ADD 2-VIEW 3-MODIFY 4-DELETE 5-INSERT 6-SAVE 0-NEXT \n");
	 printf("                                           \-----------------------------------------------------------------         ");
      
	 switch(chooseF=getch())
  {
  case '1':
	  AddF();
	  break;
  case '2':
	  ViewF();
	  break;
  case '3':
    ModifyF();
	break;
  case '4':
	  DeleteF();
	  break;
  case '5':
	  InsertF();
	  S=creareArb(S);
	  LoadToListTXT();
	  break;
  case '6' :
	  SaveTxt(0,0);
	  break;
  default:
 printf("1-ARBORE 2-LISTE :");chooseF=getch();
	  if(chooseF=='1')
	  {
		  chooseA=1;
          S=creareArb(S);
		   

	  }
	  else
	  {
		  chooseL=1;
          LoadToListTXT();
	  }
	  chooseF=0;
	  break;
  }
	 getch();
}



}
}




void Begin()
{
	  //clear the file
 FILE *f=fopen("f.txt","wb");
 fclose(f);
  
 int done=1;
 while(done)
 {
   Create();
   printf("0-exit");scanf("%d",&done);


 }
}





