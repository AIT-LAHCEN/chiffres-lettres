															//fct_login.c = 4 fonctions 
															//joueur * saisir_joueur();
															//liste_joueur*  Creer_compte(joueur * j);
															//liste_joueur* Inserer_joueur(joueur *j,liste_joueur* tete);
															//void Afficher_compte_joueurs(liste_joueur* tete);
#include "declar.h"



joueur * saisir_joueur(void){
	system("cls");
	//Ouverture du fichier en mode ecriture et lecture
	FILE *fichier = NULL;
	fichier=fopen("data.txt","a+");
	
	//Pointeur de type struct joueur qui parcours les infos
	joueur *j =Malloc(joueur);
	char entrer[20]="\n";
	char chaine_du_fichier[TAILLE_MAX];
	char copie_nom[TAILLE_MAX],copie_mot_de_passe[TAILLE_MAX];

	// Faire le choix entre creer ou se connecter a un compte
	label :
	printf("\nPossedez vous deja un compte ? \n\n");
	printf("\t1 . OUI \t\t 2 . NON \n\n");
	printf("\t>> ");
	int choix;
	scanf("%d",&choix);

	//Connexion au compte
	if(choix == 1)
	{
		fseek(fichier,0,SEEK_SET);
		system("cls");
		printf("\n\t\tCONNEXION AU COMPTE\n\n");
		printf("Saisir votre nom SVP : \n\n");
		getchar();
		gets(j->nom);
		strcpy(copie_nom,j->nom);
		strcat(copie_nom,entrer);
		printf("\nSaisir le mot de passe : \n\n");
		gets(j->mot_de_passe);
		strcpy(copie_mot_de_passe,j->mot_de_passe);
		strcat(copie_mot_de_passe,entrer);
		printf("\nVerification de l'existance du compte ...\n\n");
		int flag=0;
		while (fgets( chaine_du_fichier , TAILLE_MAX , fichier) != NULL )
		{
			if (strcmp(chaine_du_fichier,copie_mot_de_passe) == 0 && flag == 1 )
    	{
    		printf("Mot de passe valide\n\n");
    		flag++;
    	}
    	if (strcmp(chaine_du_fichier,copie_nom) == 0  && flag == 0)
    	{
    		printf("Nom valide\n\n");
    		flag++;
    	}
    }
    if (flag == 2)
    	{
    		printf("\nConnexion reussi\n\n");
    		printf("APPUYER SUR ENTRER POUR CONTINUER\n");
    		getchar();
    	}
    if(flag != 2 )
  	{
    printf("\nCe compte n'existe pas , veuillez creer un nouveau compte\n\n");
    printf("APPUYER SUR ENTRER POUR CONTINUER\n");
    getchar();
    fseek(fichier,0,SEEK_CUR);
		system("cls");
		printf("\t\tCREATION DU COMPTE\n\n");
		printf("Saisir votre nom SVP : \n\n");
		scanf("%[^'\n']s",j->nom);
		fprintf(fichier, "%s\n",j->nom);
		printf("\nSaisir le mot de passe : \n\n");
		getchar();
		gets(j->mot_de_passe);
		fprintf(fichier, "%s\n",j->mot_de_passe);
		printf("\nCreation du compte terminer\n\n");
  	}
	}
	//Creation du compte
	if (choix == 2)
	{
		fseek(fichier,0,SEEK_CUR);
		system("cls");
		printf("\n\t\tCREATION DU COMPTE\n\n");
		printf("Saisir votre nom SVP : \n\n");
		getchar();
		scanf("%[^'\n']s",j->nom);
		fprintf(fichier, "%s\n",j->nom);
		printf("\nSaisir le mot de passe : \n\n");
		getchar();
		gets(j->mot_de_passe);
		fprintf(fichier, "%s\n",j->mot_de_passe);
		printf("\nCreation du compte terminer .\n\n");
	}
	if (choix != 1 && choix != 2)
	{
		printf("\nReeasayer svp\n");
		printf("Tapez seulement 1 ou 2\n");
		ENTRER();
		getchar();
		system("cls");
		goto label;
	}
	fclose(fichier);
	return j;
}



liste_joueur * Creer_compte(joueur * j){

	liste_joueur *tete= Malloc(liste_joueur);
	tete->infos=j;
	tete->suivant= NULL;
	return tete;
}



liste_joueur *Inserer_joueur(joueur *j,liste_joueur *tete){
	//insere un nouveau ptr compte en queue de liste
	liste_joueur *nouveau =Creer_compte(j);
	if(tete==NULL)
	{
		tete=nouveau;
	}
	else
	{
		tete->suivant=nouveau;
	}
	return tete;
}



//Affichage des informations initiales des joueurs
void Afficher_compte_joueurs(liste_joueur *tete){
	liste_joueur *ptr=tete;
	int code=1;
	if(tete==NULL)
	{
		printf("il n'existe aucun compte !!\n\n"); 
		return ;
	}
	while(ptr!=NULL)
	{
		ptr->infos->code=code++;
		ptr->infos->point=0;
		printf("%s est le joueur Numero : %d\n\n",ptr->infos->nom,ptr->infos->code);
		printf("%s commence avec %d points\n\n",ptr->infos->nom,ptr->infos->point);
		ptr=ptr->suivant;
	}
	free(ptr);
}