                              //fct_lettre.c = 8 fonctions
                              //char *Generateur_aleatoire_des_lettres(void);
                              //void Affichage_aleatoire_des_lettres(char *T);
                              //int Verification_du_mot(char *T,char chaine_utilisateur[TAILLE_MAX]);
                              //int Nombre_Occurrances_lettres(char T[10],char c);
                              //void Affichage_des_solutions(char *T);
                              //int search_dico(char chaine_utilisateur[TAILLE_MAX]);
                              //void jouer_lettre(liste_joueur *tete);
                              //void affichage_des_points(liste_joueur *tete);
#include "declar.h"



//L'affichage aleatoire des lettres pour construire une mot
char *Generateur_aleatoire_des_lettres(void){
	int indice_aleatoire_des_consonnes;
	int indice_aleatoire_des_voyelles;
	int nombre_de_voyelle_choisie;
	char Voyelle[]="aaeaeyeeieuuiioo";
	char Consonne[]="zrrtrtptqspsffgfghhjklhllmmwxcmccvbbnnbn";
  char *tableau_de_lettre=(char *)malloc(10*sizeof(char));
	srand(time(NULL));

  //Saisie du nombre de voyelles par l'utilisateur
  do
  {
  	printf("\n\tCombien de voyelle svp : ");
  	scanf("%d",&nombre_de_voyelle_choisie);
    if (nombre_de_voyelle_choisie<2 || nombre_de_voyelle_choisie>6)
    {
      printf("Attention le nbr de voyelle choisie doit etre entre 2 et 6 inclus !!\n\n");
      printf("APPUYER SUR ENTRER POUR REESAYER\n");
      getchar();
      getchar();
      system("cls");
    }
  }while(nombre_de_voyelle_choisie<2 || nombre_de_voyelle_choisie>6);

  //Generation de lettres aléatoires
	if(nombre_de_voyelle_choisie>=2 && nombre_de_voyelle_choisie<=6)
  {
		for(int i=0;i<nombre_de_voyelle_choisie;i++)
    {
			indice_aleatoire_des_voyelles = (rand()%16);
      tableau_de_lettre[i]=Voyelle[indice_aleatoire_des_voyelles];
		}
		for(int i=0;i<10-nombre_de_voyelle_choisie;i++)
    {
			indice_aleatoire_des_consonnes = (rand()%40);
      tableau_de_lettre[i+nombre_de_voyelle_choisie]=Consonne[indice_aleatoire_des_consonnes];
		}
	}
  return tableau_de_lettre;
}



//L'Affichage des lettres
void Affichage_aleatoire_des_lettres(char *T){
  printf("\n\nVoici la liste des lettres : \n\n");
  for(int i=0;i<10;i++)
  {
    printf("%c\t",toupper(T[i]));
  }
}



//Calcule du nombre d'occurrance d'un lettre donne dans une chaine donnee
int Nombre_Occurrances_lettres(char T[10],char c){
  int Nbr=0;
  for(int i=0;i<10;i++)
  {
    if(c==T[i])
    {
      Nbr++;
    }
  }
  return Nbr;
}



//La verification de la validité du mot entrée par le Joueur
int Verification_du_mot(char *T,char chaine_utilisateur[TAILLE_MAX])
{
  char nouveau_tab[10];
  for (int j=0;j<10;j++)
  {
    nouveau_tab[j]=T[j];
  }
  int N;
  N=strlen(chaine_utilisateur);
  for(int i=0;i<N;i++)
  {
    int b=Nombre_Occurrances_lettres(chaine_utilisateur,chaine_utilisateur[i]);
    int a=Nombre_Occurrances_lettres(nouveau_tab,chaine_utilisateur[i]);
    if (a==0 || b>a)
    {
      return 0;
    }
  }
  return 1; 
}



//L'affichage des meilleurs solutions résultants des lettres affichées 
void Affichage_des_solutions_lettre(char *T){
  char nouveau_tab[10];
  for (int j=0;j<=9;j++)
  {
    nouveau_tab[j]=T[j];
  }
  nouveau_tab[10]='\0';
  FILE *fichier;
  fichier = fopen("mots.txt","r");
  fseek(fichier,0,SEEK_SET);
  printf("\n\n\n\tLes meilleurs solutions de cette manche etait :\n");  
  char chaine_du_fichier[20];
    while (fgets(chaine_du_fichier,20,fichier) != NULL)
    {
      int N;
      N=strlen(chaine_du_fichier);
      int a,b;
      if(N>=TAILLE_DES_SOLUTIONS)
      {
        for(int i=0;i<N-1;i++)
        {
          a=Nombre_Occurrances_lettres(nouveau_tab,chaine_du_fichier[i]);
          b=Nombre_Occurrances_lettres(chaine_du_fichier,chaine_du_fichier[i]);
          if(a==0 || b>a)
          {
            goto label;
          }
        }
        printf("%s",chaine_du_fichier);
      }
      label:
      continue;
    }
  fclose(fichier);
}



//La recherche du mot entré par l'utilisateur dans le dictionnaire français
int search_dico(char chaine_utilisateur[TAILLE_MAX])
{
  char chaine_du_fichier[TAILLE_MAX];
  char entrer[20]="\n"; // car fgets() copie avec \n
  //mot entrer par l'utilisateur
  getchar();
  //ajouter \n au mot entrer par l'utilisateur
  strcat(chaine_utilisateur,entrer); 
  //ouverture du fichier en mode lecture/ecriture
  FILE *fichier;
  fichier = fopen("mots.txt","r");
  //positionner le curseur au debut
  fseek(fichier,0,SEEK_SET);
  //parcours du contenue du fichier ligne par ligne et le stock dans chaine_du_fichier
  int point=0;
  while (fgets( chaine_du_fichier , TAILLE_MAX , fichier) != NULL )
  {
    //comparaison des deux chaine si on la trouve on quitte la boucle
    if (strcmp(chaine_du_fichier,chaine_utilisateur) == 0)
    {
      point=strlen(chaine_utilisateur)-1;
      printf("Votre mot existe dans le dictionnaire\n");
      printf("Bien!! vous avez gagne %d points\n",point);
      break;
    }
  }
  //afficher un message comme quoi on n a pas trouve le mot dans le dictionnaire
  if(strcmp(chaine_du_fichier,chaine_utilisateur) != 0)
  {
    printf("Votre mot n'existe pas dans le dictionnaire!! malheureusement vous n'avez gagner aucun point :(");
  }
  //fermeture du fichier
  fclose(fichier);
  return point;
}



//L'affichage des points actuelles des deux joueurs
void affichage_des_points(liste_joueur *tete)
{
  liste_joueur *ptr=tete;
  system("cls");
  ptr=tete;
  printf("\n\t\t AFFICHAGE DES POINTS DES DEUX JOUEURS \n");
  printf("\n\t Actuellement %s a %d points",ptr->infos->nom,ptr->infos->point);
  ptr=ptr->suivant;
  printf("\n\t Actuellement %s a %d points",ptr->infos->nom,ptr->infos->point);
}



void jouer_lettre(liste_joueur *tete){
  liste_joueur *ptr;
  int score,manche=1,duree;
  time_t start;
  char chaine_utilisateur[TAILLE_MAX];
  char *tableau_de_lettre=(char*)malloc(10*sizeof(char));
  for (int i =1;i<=MANCHE_LETTRE;i++)
  {
    ptr=tete;
    //Joueur 1
    printf("\n\t\t ---------------- ");
    printf("\n\t\t LE PLUS LONG MOT ");
    printf("\n\t\t ----------------\n");
    printf("\nC'est le tour de %s\n",ptr->infos->nom);
    printf("\nRAPPEL : \tVous avez %d seconde pour repondre\n",NBR_SECONDE);
    ENTRER();
    tableau_de_lettre=Generateur_aleatoire_des_lettres();
    Affichage_aleatoire_des_lettres(tableau_de_lettre);
    start=time(NULL);        
    printf("\n\n\nEntrer votre mot en miniscule svp : \n\n\t\t>> "); 
    scanf("%s",chaine_utilisateur);
    duree=(int)(time(NULL)-start);
    printf("\n\nVous avez mis >>> %d secondes <<< pour repondre \n",duree);
    printf("APPUYER SUR ENTRER POUR LES RESULTATS\n");
    getchar();
    getchar();
    //Verification
    if(duree <= NBR_SECONDE)
    {
      printf("\n\nVous avez respectez le temps :) !");
      printf("\n\n");
      if (Verification_du_mot(tableau_de_lettre,chaine_utilisateur) == 1)
      {
        score=search_dico(chaine_utilisateur);
        (ptr->infos->point)+=score;
        printf("\n%s a maintenant %d points\n",ptr->infos->nom,ptr->infos->point);
        ENTRER();
      }
      else
      {
        printf("Ce mot ne respecte pas les lettres de la liste affichee ou bien il n'existe pas dans le dictionnaire francais!\n");
        printf("Vous n'avez gagne aucun point\n\n");
        ENTRER();
      }
    }
    else {
      printf("\n\nVous avez depassez %ds\n",NBR_SECONDE);
      printf("Votre reponse n est pas acceptee\n");
      printf("Vous ne gagnez aucun point\n");
      printf("\n\nPassez maintenant la main a l autre joueur svp\n");
      ENTRER();
    }
    //Joueur 2
    system("cls");
    ptr=ptr->suivant;
    printf("\n\t\t ---------------- ");
    printf("\n\t\t LE PLUS LONG MOT ");
    printf("\n\t\t ----------------\n");
    printf("\nC'est le tour de %s\n",ptr->infos->nom);
    printf("\nRAPPEL : \tVous avez %d seconde pour repondre\n",NBR_SECONDE);
    ENTRER();
    Affichage_aleatoire_des_lettres(tableau_de_lettre);
    start=time(NULL);  
    printf("\n\n\nEntrer votre mot en miniscule svp : \n\t\t>> "); 
    scanf("%s",chaine_utilisateur);
    duree=(int)(time(NULL)-start);
    printf("\n\nVous avez mis >>> %d secondes <<< pour repondre \n",duree);
    printf("APPUYER SUR ENTRER POUR LES RESULTATS\n");
    getchar();
    getchar();
    //Verification
    if(duree <= NBR_SECONDE)
    {
      printf("\n\nVous avez respectez le temps :) !");
      printf("\n\n");
      if (Verification_du_mot(tableau_de_lettre,chaine_utilisateur) == 1)
      {
        score=search_dico(chaine_utilisateur);
        (ptr->infos->point)+=score;
        printf("\n%s a maintenant %d points\n",ptr->infos->nom,ptr->infos->point);
        getchar();
      }
      else
      {
        printf("Ce mot ne respecte pas les lettres de la liste affichee ou bien il n'existe pas dans le dictionnaire francais!\n");
        printf("Vous n'avez gagne aucun point\n\n");
        ENTRER();
      }
    }
    else {
      printf("\n\nVous avez depassez %ds\n",NBR_SECONDE);
      printf("Votre reponse n est pas acceptee\n");
      printf("Vous ne gagnez aucun point\n");
      printf("\n\nPassez maintenant la main a l autre joueur svp\n");
      ENTRER();
    }
    system("cls");
    affichage_des_points(tete);
    printf("\n\nPoints apres la manche numero : %d\n\n",manche++);
    getchar();
    Affichage_aleatoire_des_lettres(tableau_de_lettre); 
    Affichage_des_solutions_lettre(tableau_de_lettre);
    getchar();
    system("cls");   
  }
}