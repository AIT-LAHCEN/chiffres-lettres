#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h> 
#include <windows.h> 
#include <process.h>
#define TAILLE_MAX 100
#define _7_points 7
#define _10_points 10
#define TAILLE_DES_SOLUTIONS 6
#define MANCHE_LETTRE 4
#define MANCHE_CHIFFRE 4
#define NBR_SECONDE 40
#define Malloc(t) (t*)malloc(sizeof(t))
#define ENTRER()	printf("\nAPPUYER SUR ENTRER POUR CONTINUER\n"); \
									getchar(); \



//Structure joueur qui contient les infos
typedef struct{
	int code;
  char nom[TAILLE_MAX];
  char mot_de_passe[TAILLE_MAX];
  int point;
}joueur;



//Liste chainé de plusieurs joueurs
typedef struct compte{
	joueur * infos;
	struct compte *suivant;
}liste_joueur;



//										Declaration de toutes les fonctions

//		fct_login.c = 4 fonctions
joueur * saisir_joueur(void);
liste_joueur*  Creer_compte(joueur * j);
liste_joueur* Inserer_joueur(joueur *j,liste_joueur* tete);
void Afficher_compte_joueurs(liste_joueur* tete);

//		fct_lettre.c = 8 fonctions
char *Generateur_aleatoire_des_lettres(void);
void Affichage_aleatoire_des_lettres(char *T);
int Verification_du_mot(char *T,char chaine_utilisateur[TAILLE_MAX]);
int Nombre_Occurrances_lettres(char T[10],char c);
void Affichage_des_solutions_lettre(char *T);
int search_dico(char chaine_utilisateur[TAILLE_MAX]);
void jouer_lettre(liste_joueur *tete);
void affichage_des_points(liste_joueur *tete);

//		fct_chiffres.c = 7 fonctions
void Affichage_des_chiffres(int T[6]);
int Nombre_Occurrances_chiffres(int T[TAILLE_MAX],int a);
int calculatrice(int T[6]);
void Affichage_des_solutions_chiffre(int c);
void compteur_points_chiffres(int diffJ1,int diffJ2,liste_joueur *tete);
void jouer_chiffres(liste_joueur *tete);
void winner(liste_joueur *tete);