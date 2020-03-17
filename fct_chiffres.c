													//			fct_chiffres.c = 7 fonctions
													//	void Affichage_des_chiffres(int T[6]);
													//	int Nombre_Occurrances_chiffres(int T[TAILLE_MAX],int a)
													//	int calculatrice(int T[6]);
													//	void Affichage_des_solutions_chiffre(int c);
													//	void compteur_points_chiffres(int diffJ1,int diffJ2,liste_joueur *tete);
													//	void jouer_chiffres(liste_joueur *tete);
													//	void winner(liste_joueur *tete);
#include "declar.h"



void Affichage_des_chiffres(int T[6]){
  printf("\nLe nombres a recherche est\n");
  printf("\t-->%d\n",T[0]);
  printf("\n\nRAPPEL : \tVous avez %d seconde pour repondre\n",NBR_SECONDE);
  printf("\n\nVoici la liste des chiffres : \n\n");
  for(int i = 1; i<=5 ; i++ )
  {
    printf("%d\t",T[i]);
  }
  printf("\n\nApprochez vous du resultat...\n");
}



int Nombre_Occurrances_chiffres(int T[TAILLE_MAX],int a){
	int Occur=0;
	for(int i=0;i<TAILLE_MAX;i++){
		if(a==T[i]){
			Occur++;
		}
	}
	return Occur;
}



int calculatrice(int T[6]){
	//DECLARATION DES VARIABLES
	double nbr_double=0;
	int nbr_division=0;
	int tab_Nbr[TAILLE_MAX];
	for(int i=0;i<5;i++){
		tab_Nbr[i]=T[i+1];	
	}	
	for(int i=5;i<TAILLE_MAX;i++){
		tab_Nbr[i]=-1;	
	}
	int indice_tab_Nbr=5;
	int *tab_res=(int*)malloc(20*sizeof(int));
	int *tab_a=(int*)malloc(20*sizeof(int));
	int *tab_b=(int*)malloc(20*sizeof(int));
	int *tab_r=(int*)malloc(20*sizeof(int));
	char *tab_operation=(char*)malloc(20*sizeof(char));
	int choix,quit=0;
	int compteur=0;
	int a,b,res;
	char operation;
	system("cls");
	//LISTE DES NOMBRES
	Affichage_des_chiffres(T);
	printf("\n\nOPERATION :\n");
	int e=0;
	int taille;
	do
	{
		int l=0;
		int m=0;
		e++;
		scanf("%d %c %d",&a,&operation,&b);
		if (e>0)
		{
			for (int t=0;t<=taille;t++)
			{
				if (tab_res[t]==a){l++;}
				if (tab_res[t]==a){m++;}
			}
			for (int i=0; i<=taille;i++)
			{
				if(tab_a[i]==a || tab_b[i]==b || tab_b[i]==a || tab_a[i]==b || (l>=2) || (m>=2)){
					printf("vous avez deja utilisez ce nombre\n");
					printf("reessayez svp\n");
					getchar();
					getchar();
					goto label;
				}
			}
		}
		//CHOIX DE L'OPERATION
		if (operation == '+')
		{
			res = a+b;
		}
		if (operation == '-')
		{
			if (a >= b)
			{
				res = a-b;
			}
			else 
			{
				printf("Operation impossible\n");
				res=0;
			}
		}
		if (operation == '*')
		{
			res = a*b;
		}
		if (operation == '/')
		{
			res=a/b;
		}
		int Oa=Nombre_Occurrances_chiffres(tab_Nbr,a);
		int Ob=Nombre_Occurrances_chiffres(tab_Nbr,b);
		if(Oa==0 || Ob==0){
			printf("Attention le principe est d'utiliser les chiffres donnees ou les resultats obtenus!!");
			getchar();
			getchar();
			system("cls");
			Affichage_des_chiffres(T);
			printf("\n\nOPERATION :\n");
			goto label;
		}
		tab_Nbr[indice_tab_Nbr]=res;
		indice_tab_Nbr++;
		//AFFICHAGE DU RESULTAT ACTUEL
		printf("> %d\n",res); 
		//QUITTER,EFFACER OU VALIDER
		printf("\n\n\nTAPEZ ENTRER POUR CONTINUER LE CALCUL");
		printf("\n      BACKSPACE(EFFACER) POUR EFFACER L'HISTORIQUE DE CALCUL");
		printf("\n      ESC POUR VALIDER VOTRE DERNIERE RESULTAT >> %d \n",res);
		quit=getch();
		if(quit ==8)
		{
			label:
			free(tab_res);
			free(tab_a);
			free(tab_b);
			free(tab_operation);
			int *tab_res=(int*)malloc(20*sizeof(int));
			int *tab_a=(int*)malloc(20*sizeof(int));
			int *tab_b=(int*)malloc(20*sizeof(int));
			char *tab_operation=(char*)malloc(20*sizeof(char));
			compteur=0;
			taille=0;
			system("cls");
			Affichage_des_chiffres(T);
			goto repere;
		}
		//STOCKE LES NOMBRES ENTRE DANS DES TABLEAU POUR LES AFFICHER
		tab_res[compteur]=res;
		tab_a[compteur]=a;
		tab_b[compteur]=b;
		tab_operation[compteur]=operation;
		system("cls");
		//REEAFICHAGE DE LA LISTE DES NOMBRES
		Affichage_des_chiffres(T);
		//AFFICHAGE DES OPERATIONS ENTREES
		for (int j=0; j<=compteur;j++)
		{
			printf("%d%c%d\n",tab_a[j],tab_operation[j],tab_b[j]);
			printf("> %d\n",tab_res[j]);
			printf("\n");
		}
		//COMPTEUR DU TABLEAU
		taille=compteur++;
		repere :
		printf("\n\nOPERATION :\n");
	}while(quit !=27);
	free(tab_res);
	free(tab_a);
	free(tab_b);
	free(tab_operation);
	return res;
}



void Affichage_des_solutions_chiffre(int m){
  FILE* fichier;
  char a;
  fichier=fopen("solutions.txt","r");
  fseek(fichier,m,SEEK_CUR);
  if(fichier!=NULL)
  {
    do
    {
      a=fgetc(fichier);
      printf("%c",a);
    }while(a!='\n');
  }
  fclose(fichier);
}



void compteur_points_chiffres(int diffJ1,int diffJ2,liste_joueur *tete){
	printf("\n\t\t BILAN DE LA MANCHE \n\n\n");
	if (diffJ1 == 0 && diffJ2== 0)
	{
		printf("%s et %s ont le compte exacte\n",tete->infos->nom,tete->suivant->infos->nom);
		printf("\nTous les deux gagnent %d points\n",_10_points);
		tete->infos->point+=_10_points;
		tete->suivant->infos->point+=_10_points;
		ENTRER();
	}
	if(diffJ1 == diffJ2 && (diffJ1 != 0 && diffJ1!= -1))
	{
		printf("%s et %s ont le meme ecart\n",tete->infos->nom,tete->suivant->infos->nom);
		printf("\nTous les deux gagnent %d points\n",_7_points);
		tete->infos->point+=_7_points;
		tete->suivant->infos->point+=_7_points;
		ENTRER();
	}
	if(diffJ1 < diffJ2 && (diffJ1 != 0 && diffJ1!= -1))
	{
		printf("%s a le plus petit ecart , il est pres de %d du resultat\n",tete->infos->nom,diffJ1 );
		printf("\nDonc %s gagne %d points\n",tete->infos->nom,_7_points );
		tete->infos->point+=_7_points;
		printf("\n%s ne gagne aucun points \n",tete->suivant->infos->nom);
		ENTRER();
	}
	if(diffJ1!=0 && diffJ1 !=-1 && diffJ2== -1)
	{
		printf("%s est le seul qui a respecte le temps\n",tete->infos->nom);
		printf("il est pres de %d du resultat\n",diffJ1 ) ;
		printf("\nDonc %s gagne %d points\n",tete->infos->nom,_7_points );
		tete->infos->point+=_7_points;
		printf("\n%s ne gagne aucun points \n",tete->suivant->infos->nom);
		ENTRER();
	}
	if(diffJ2 < diffJ1 && (diffJ2 != 0 && diffJ2!= -1))
	{
		printf("%s a le plus petit ecart , il est pres de %d du resultat\n",tete->suivant->infos->nom,diffJ2 );
		printf("\nDonc %s gagne %d points\n",tete->suivant->infos->nom,_7_points );
		tete->suivant->infos->point+=_7_points;
		printf("\n%s gagne aucun points \n",tete->infos->nom);
		ENTRER();
	}
	if(diffJ2!=0 && diffJ2 !=-1 && diffJ1== -1)
	{
		printf("%s est le seul qui a respecte le temps\n",tete->suivant->infos->nom);
		printf("il est pres de %d du resultat\n",diffJ2 ) ;
		printf("\nDonc %s gagne %d points\n",tete->suivant->infos->nom,_7_points );
		tete->suivant->infos->point+=_7_points;
		printf("\n%s ne gagne aucun points \n",tete->infos->nom);
		ENTRER();
	}
	if(diffJ1==0 && diffJ2!=0)
	{
		printf("%s est le seul qui a le compte exacte ! Bravo !\n",tete->infos->nom);
		printf("\nDonc %s gagne %d points\n",tete->infos->nom,_10_points );
		tete->infos->point+=_10_points;
		printf("\n%s ne gagne aucun points \n",tete->suivant->infos->nom);
		ENTRER();	
	}
	if(diffJ2==0 && diffJ1!=0)
	{
		printf("%s est le seul qui a le compte exacte ! Bravo !\n",tete->suivant->infos->nom);
		printf("\nDonc %s gagne %d points\n",tete->suivant->infos->nom,_10_points );
		tete->suivant->infos->point+=_10_points;
		printf("\n%s gagne aucun points \n",tete->infos->nom);
		ENTRER();	
	}
	if (diffJ1==-1 && diffJ2 ==-1)
	{
		printf("Les deux joueurs n'ont pas respecte le temps\n");
		printf("Tous les deux ne gagnent aucun point\n");
		tete->infos->point+=0;
		tete->suivant->infos->point+=0;
		ENTRER();
	}
}



void jouer_chiffres(liste_joueur *tete){
	int manche=1;//NUMERO DE LA MANCHE
	int duree;
	time_t start;
	liste_joueur *ptr;
	int resultat;
	int diffJ1,diffJ2;
	int nbr_144[6]={144,18,2,25,4,50};
  int nbr_409[6]={409,15,3,5,4,100};
  int nbr_608[6]={608,9,7,15,3,16};
  int nbr_553[6]={553,100,4,25,10,3};
	int Tableau_chiffre[6]={144,18,2,25,4,50};
	int indice_solution=0;
	system("cls");
	for (int i=2;i<=MANCHE_CHIFFRE+1;i++)
	{
		ptr=tete;
		//Joueur 1
		system("cls");
		printf("\n\t\t ----------------- ");
  	printf("\n\t\t LE COMPTE EST BON ");
  	printf("\n\t\t -----------------\n");
		printf("\nC'est le tour de %s\n",ptr->infos->nom);
		printf("\nVous avez %d seconde pour repondre\n",NBR_SECONDE);
		ENTRER();
		start=time(NULL);
		resultat=calculatrice(Tableau_chiffre); //Le joueur fait ses calculs avec la calculatrice
		duree=(int)(time(NULL)-start);
		system("cls");
		printf("\n\nVous avez mis >>> %d secondes <<< pour repondre \n",duree);
		printf("APPUYER SUR ENTRER POUR LES RESULTATS\n");
		getchar();
		getchar();
		system("cls");
		if(duree <= NBR_SECONDE)
		{
			printf("Vous avez respectez le temps :) !");
			printf("\n\nVotre resultat \t>>>> %d\n",resultat);
			printf("\nComparons le maintenant avec le chiffres demande\n");
			getchar();
			diffJ1= abs(resultat - Tableau_chiffre[0]); //difference entre resultat du joueur et le nombre voulue
			if(diffJ1==0)
			{
				printf("\n\nBRAVO %s !!\n",ptr->infos->nom);
				printf("\nLe compte est bon !\n");
				printf("\nPassez maintenant la main a l autre joueur\n");
				ENTRER();
			}
			else
			{
				printf("\n\n%s, vous etiez proche du resultat, il vous fallez encore \n",ptr->infos->nom);
				printf("\t\t>>>> %d\n",diffJ1);
				printf("\n\nPassez maintenant la main a l autre joueur\n");
				ENTRER();
			}
		}
		else {
			diffJ1=-1;
			system("cls");
			printf("\n\nVous avez depassez %ds\n",NBR_SECONDE);
			printf("Votre reponse n est pas acceptee\n");
			printf("Vous ne gagnez aucun point\n");
			printf("\n\nPassez maintenant la main a l autre joueur svp\n");
			ENTRER();
		}

		//Joueur 2
		system("cls");
		ptr=ptr->suivant;
		printf("\n\t\t ----------------- ");
  	printf("\n\t\t LE COMPTE EST BON ");
	  printf("\n\t\t -----------------\n");
		printf("\nC'est le tour de %s\n",ptr->infos->nom);
		printf("Vous avez %d seconde pour repondre\n",NBR_SECONDE);
		ENTRER();
		start = time(NULL);
		resultat=calculatrice(Tableau_chiffre); //Le joueur fait ses calculs avec la calculatrice
		duree = (int) (time (NULL) - start);
		system("cls");
		printf("\n\nVous avez mis >>> %d secondes <<< pour repondre \n",duree);
		printf("APPUYER SUR ENTRER POUR LES RESULTATS\n");
		getchar();
		getchar();
		system("cls");
		if (duree <= NBR_SECONDE)
		{
			printf("Vous avez respectez le temps :) !");
			printf("\n\nVotre resultat \t>>>> %d\n",resultat);
			printf("\nComparons le maintenant avec le chiffres demande\n");
			getchar();
			diffJ2= abs(resultat - Tableau_chiffre[0]); //difference entre resultat du joueur et le nombre voulue
			if(diffJ2==0)
			{
				printf("\n\nBRAVO %s !\n",ptr->infos->nom);
				printf("\nLe compte est bon !\n");
				ENTRER();
			}
			else
			{
				printf("\n\n%s, vous etiez proche du resultat, il vous fallez encore \n",ptr->infos->nom);
				printf("\t\t>>>> %d\n",diffJ2);
				ENTRER();
			}
		}else {
			diffJ2=-1;
			system("cls");
			printf("\n\nVous avez depassez %ds\n",NBR_SECONDE);
			printf("Votre reponse n est pas acceptee\n");
			printf("Vous ne gagnez aucun point\n");
			ENTRER();
		}
		system("cls");
		printf("\n\nCOMPARONS MAINTENANT LE RESULTAT DES DEUX JOUEURS\n");
		getchar();
		system("cls");
		compteur_points_chiffres(diffJ1,diffJ2,tete);
		printf("\nVoici une autre maniere de calcul \n\n");
		Affichage_des_solutions_chiffre(indice_solution);
		getchar();
		if (i == 2 )
  	{
  		for (int k = 0; k <=5; k++)
  		{
  			Tableau_chiffre[k]=nbr_409[k];
  		}
  		indice_solution=42;
  	}
  	if (i == 3 )
  	{
  		for (int k = 0; k <=5; k++)
  		{
  			Tableau_chiffre[k]=nbr_608[k];
  		}
  		indice_solution=90;
  	}
  	if (i == 4 )
  	{
  		for (int k = 0; k <=5; k++)
  		{
  			Tableau_chiffre[k]=nbr_553[k];
  		}
  		indice_solution=139;
  	}
  	if (i == 5){
  		getchar();	
  	}
  	affichage_des_points(tete);
  	printf("\n\nPoints apres la manche numero : %d\n",manche++);
  	ENTRER();
	}
	system("cls");
	printf("\n\t\tPPOINTS TOTAUX DU JEU : \n\n");
	affichage_des_points(tete);
  ENTRER();
}


void winner(liste_joueur *tete)
{
	liste_joueur *ptr;
	ptr=tete;
	if ( (ptr->infos->point) > (ptr->suivant->infos->point) )
	{
		printf("\nEt le gagnant de cette partie est : \n");
		printf("\t\t>>> %s <<< \n",ptr->suivant->infos->nom);
		printf("Avec un total de %d points\n",ptr->suivant->infos->point );
		printf("FELICITATION\n");
		printf("\nBonne chance et a la prochaine fois peut etre ^^\n");
		getchar();
	}
	if ( (ptr->suivant->infos->point) > (ptr->infos->point))
	{
		printf("\nEt le gagnant de cette partie est : \n");
		printf("\t\t>>> %s <<< \n",ptr->suivant->infos->nom);
		printf("Avec un total de %d points\n",ptr->suivant->infos->point );
		printf("FELICITATION\n");
		printf("\nBonne chance et a la prochaine fois peut etre ^^\n");
		getchar();
	}
	if ( (ptr->infos->point) == (ptr->suivant->infos->point) )
	{	
		printf("\nEt le gagnant de cette partie est : \n");
		printf("\t\t>>> %s <<< \n",ptr->infos->nom);
		printf("Mais aussi\n");
		printf("\t\t>>> %s <<< \n",ptr->suivant->infos->nom);
		printf("Car vous etes tous les deux a egalites\n");
		printf("Avec un total de %d points\n",ptr->suivant->infos->point );
	}
}
