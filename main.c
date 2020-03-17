#include "declar.h"



int main(){
	char chaine_utilisateur[TAILLE_MAX];
	system("cls");
	system("color 1B"); 
	//								INTRODUCTION DU JEU
	printf("\n\n\t\t\t\t OUVERTURE \n\n");
  for(int i=1;i<=80;i++){
  	Sleep(20);
  	printf("*");
  }
  system("cls");
	printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*DES CHIFFRES ET DES LETTRES*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n\nLe jeu se joue en deux parties :\n\n");
	printf("---->LE PLUS LONG MOT\n\n");
	printf("---->LE COMPTE EST BON\n\n");
	printf("\t\tBonne chance :)");
	getchar();
	//								CREATION OU CONNEXION AUX COMPTES 
	liste_joueur *tete;
	joueur *j;
	system("cls");
	system("color b");
	printf("\n\tPremier joueur:\n");
	printf("\nAppuyez sur ENTRER pour commencer le jeu\n");
	getchar();
	j= saisir_joueur();
	tete= Creer_compte(j);
	system("cls");
	printf("\n\tDeuxieme joueur:\n");
	printf("\nAppuyez sur ENTRER pour commencer le jeu\n");
	getchar();
	j= saisir_joueur();
	tete= Inserer_joueur(j,tete);
	system("cls");
	//AFFICHAGE DES INFOS
	printf("\n\t\t AFFICHAGE DES INFORMATIONS DES DEUX JOUEURS \n\n");
	Afficher_compte_joueurs(tete);
	getchar();
	printf("\n\nAPPUYER SUR UNE ENTRER POUR COMMENCER LE JEU\n");
	getchar();
	system("cls");
	system("color a");
	//										COMMENCEMENT DU JEU
	//COUPS DE LETTRES !!
	jouer_lettre(tete);
	affichage_des_points(tete);
  getchar();
  //COUPS DE CHIFFRES !!
  //AFFICHAGE DU MODE D EMPLOIE DE LA CALCULATRICE
  system("color b");
  system("cls");
  printf("\n\t\t ----------------- ");
 	printf("\n\t\t LE COMPTE EST BON ");
  printf("\n\t\t -----------------\n");
  printf("\t\t\n\nLA CALCULATRICE FAIT SEULEMENT LES OPERATIONS MATHEMATIQUES ELEMENTAIRES (ENTIRES POSITIFS)\n\n" );
	printf("\nExemple d'emploie :\n2+5 \n");
	printf("> 7\n");
	getchar();
  jouer_chiffres(tete);
  getchar();
  system("cls");
  system("color a");
  winner(tete);
  getchar();
  system("cls");
  for(int i=1;i<=80;i++){
  	Sleep(20);
  	printf("*");
  }
  printf("\n\n\t\tCe jeu est developpe par: ");
  printf("\n\n\t CHICHI HAMZA\t&\tAHMED AIT LAHCEN ");
  getchar();
  system("cls");
  system("color 1B");
  printf("\n\n\t\t\t\t FERMETURE \n\n");
  for(int i=1;i<=80;i++){
  	Sleep(20);
  	printf("*");
  }
	return 0;
}