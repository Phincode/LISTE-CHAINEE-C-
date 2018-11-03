#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 10000




float moy,tt,my;


typedef struct Maillon Maillon;
	typedef struct Note Note;
	typedef struct pointeurpremier pointeurpremier;
	
	struct Note{
		float n;
		int coeff;
		Note *suivant;
	};
	
	struct Maillon{
		char no[10];
		char nom[30];
		char prenom[30];
		float moy;
		Note *eval;
		Maillon *suivant;
	};
	
	struct pointeurpremier{
		Maillon  *premier;
	};
	//
  
   //
pointeurpremier *ajouteEtudiant(pointeurpremier *tete,char no[10],char nom[30],char prenom[30],int nombre){
	
	float n1;
	int n2;
	
	Maillon *nouveau=malloc(sizeof(*nouveau));
	Note *note=malloc(sizeof(*note));
	
	if (note == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    strcpy(nouveau->no,no);
    strcpy(nouveau->nom,nom);
    strcpy(nouveau->prenom,prenom);
    nouveau->moy=0;
    nouveau->eval=note;
    nouveau->suivant=tete;
    tete->premier=nouveau;
    printf("CONFIGURATION DES NOTE DE: ");
    printf("%s",&nouveau->prenom);
    printf("\n");
    printf("Note 1:\n");
    printf("Veillez entrer la note:\n");
    scanf("%f",&n1);
    note->n=n1;
    printf("ok, Entrer le coefficient:\n");
    scanf("%d",&n2);
    note->coeff=n2;
    note->suivant=NULL;
     int cmp=0;
     while(cmp < nombre-1){
     	
     	 printf("Note suivante:\n");
         scanf("%f",&n1);
         
         printf("ok, Entrer le coefficient:\n");
         scanf("%d",&n2);
         Note *notes=malloc(sizeof(*notes));
	     notes->n=n1;
	     notes->coeff=n2;
	     notes->suivant=nouveau->eval;
	     nouveau->eval=notes;
	
     	 cmp+=1;
     	
	 }
    
    system("color c");
    printf("CONFIGURATION TERMINEE POUR CET ETUDIANT\n");

    return tete->premier;
    	
}
 



void afficheliste(Maillon *maillon){
	
}

 Maillon* calculemoy(Maillon *maillon){
	    pointeurpremier *tete;
		tete->premier=maillon; 
	     
		while (tete->premier != NULL)
    {
    	 printf("\n"); 
        printf("%s -> ", tete->premier->nom);
        printf("%s -> ", tete->premier->prenom);
        Note *pres=tete->premier->eval;
        
        if(pres==NULL){
        	printf("aucune note pour cette eleve");
		}else{
			moy=0;
			tt=0;
			my=0;
			while(pres!=NULL){
				printf("Note:");
				printf("%f",pres->n);
				printf("   ");
				printf("coefficient:");
				printf("%d ->",pres->coeff);
				 tt+=(pres->n)*(pres->coeff);
				 my+=(pres->coeff);
				 
				pres=pres->suivant;
				
			}
			
			
			tete->premier->moy=tt/my;
			printf("moyenne:");
			printf("%f",tete->premier->moy);
		}
		 
       
        
         //printf("%f",&maillon->moy);
        tete->premier = tete->premier->suivant;
    }
    
    	
  
        
        
    
   
   
   return maillon;
 // classement(maillon,2);
	printf("\n");
	
}

pointeurpremier *ajoutedebut(char no[10],char nom[30],char prenom[30],float moyenne,pointeurpremier *tete2){
	   
		Maillon *nouveau=malloc(sizeof(*nouveau));
		
		strcpy(nouveau->no,no);
		strcpy(nouveau->nom,nom);
		nouveau->moy=moyenne;
		strcpy(nouveau->prenom,prenom);
		nouveau->suivant=tete2;
		tete2=nouveau;	
		
	    return tete2;
}

Maillon *supprimerElement(Maillon *liste, char no[10])
{
    /* Liste vide, il n'y a plus rien à supprimer */
    if(liste == NULL)
        return NULL;
 
    /* Si l'élément en cours de traitement doit être supprimé */
    if(liste->no == no)
    {
        /* On le supprime en prenant soin de mémoriser 
        l'adresse de l'élément suivant */
        Maillon* tmp = liste->suivant;
        free(liste);
        /* L'élément ayant été supprimé, la liste commencera à l'élément suivant
        pointant sur une liste qui ne contient plus aucun élément ayant la valeur recherchée */
        tmp = supprimerElement(tmp, no);
        return tmp;
    }
    else
    {
        /* Si l'élement en cours de traitement ne doit pas être supprimé,
        alors la liste finale commencera par cet élément et suivra une liste ne contenant
        plus d'élément ayant la valeur recherchée */
        liste->suivant = supprimerElement(liste->suivant, no);
        return liste;
    }
}


classement(Maillon *tete,int nbr){
  FILE* fichier = NULL;// pointeur sur le fichier ou sera stocker le classement
  fichier = fopen("classement.txt", "w+");//le fichier ou sera stocker le classement
  Maillon *liste=tete;	
  Maillon *tmp;
  pointeurpremier *tete2=malloc(sizeof(*tete2));// cree une fois
  
  Maillon *listeclassement=malloc(sizeof(*listeclassement));// création d'une nouvelle liste pour stocker le classement
  listeclassement->suivant=NULL;
  listeclassement->eval=NULL;
  strcpy(listeclassement->no,"0");
  strcpy(listeclassement->nom,"0");
  strcpy(listeclassement->prenom,"0");
  listeclassement->moy=0;
  tete2->premier=listeclassement;
 int i=0;
  tmp=liste;
	  for(i=1;i<=nbr;i++){
 	    
	     while(liste != NULL){
	     	
	     	if( (tmp->moy) >= (liste->moy)){
	     		// on ne change rien
	    	 }else{
			tmp=liste; // on prend le plus grand
		    }
        	liste=liste->suivant;
    	}
    	//on affiche le classement
    	printf("\n");
    	printf("Rang:");
    	printf("==>");
    	printf("%d",i);
    	printf("   ");
		printf("%s==>",tmp->nom);
		printf("%s==>",tmp->prenom);
    	printf("%f",tmp->moy);
    	//stockage
    	fprintf(fichier,"Rang: %d",i);
		fprintf(fichier,"nom: %s",tmp->nom);
		fprintf(fichier,"prenom: %s",tmp->prenom);
		fprintf(fichier,"moyenne= %f ",tmp->moy);
		fprintf(fichier,"\n");
        tete2->premier=ajoutedebut(tmp->no,tmp->nom,tmp->prenom,tmp->moy,tete2->premier);//on ajoute a notre nouvelle liste
	    liste=supprimerElement(tete,tmp->no);// déjà trié donc on le suprime de la liste courante
	    tmp=liste;// tmp prend la liste retourné par supprimerElement()
	    
	
	}
	
	  printf("\n");      
	  printf("Votre classement est sauvegarder dans votre repertoire courant sous le nom de classement.txt");      
	
	return tete2;// on retourne la tete de la nouvelle liste créer
}


int main(int argc, char *argv[]) {
	
////////////////////////////////////////////////////////////////////	

	
///////////////////////////////////////////////////////////////	

	int choix,nombreetu;
	int nombre;
	system("color 2");
	Maillon *actuel;
	
	printf("====================================> BIENVENU DANS SUPER MOYENNE <======================================\n");
	
	printf("\n");
	
	printf("                            ********************* MENU PRINCIPALE *******************\n");
	
	printf("|1| Nouveau calcule\n");
	printf("|2| charger un jeu de donnees\n");
	printf("|3| quiter\n");
	printf("Entrer le numero correspondant a loperation souhaite:\n");
	scanf("%d",&choix);
	switch(choix){
		case 1:
			   system("color 5");
			  printf("_________________________________CONFIGURATION DU PROGRAMME ________________________________________\n");
			  printf("\n");
			  printf("                           | ETAPE 1: Entrer le nombre d\'etudiant|                                          \n");
			  printf("                           |_____________________________________|                                          \n");
			  scanf("%d",&nombreetu);
			  
			  printf("                           |      ETAPE 2: ENTREE DES VALEURS    |                                           \n");
			  
			  
	pointeurpremier *pointe=malloc(sizeof(*pointe));// on cre une fois
	// maillon1 de la liste
        	Maillon *maillon=malloc(sizeof(*maillon)); 
         	Note *note=malloc(sizeof(*note));
	
	if(maillon==NULL || pointe==NULL || note==NULL){
		exit(EXIT_FAILURE);
	}
	
	//variable 
	    char no1[10];
		char nom1[30];
		char prenom1[30];
		int coeff1,nombres;
		float n1;
		
	
	/////////////////////////////
	// assignation1	
		system("color 5");
		printf("ETUDIANT");
		printf("==>");
		printf("1");
		printf("\n");
		printf("NUMERO:\n");
		
		scanf("%s",&no1);
		printf("NOM:\n");
		scanf("%s",&nom1);
		printf("PRENOM:\n");
		scanf("%s",&prenom1);
		printf("NOMBRE DE NOTE :\n");
		scanf("%d",&nombres); 
		printf("Entrer la premiere note :\n");
		scanf("%f",&n1);
		printf("Entrer son coefficient:");
		scanf("%d",&coeff1);
		strcpy(maillon->no,no1);
	strcpy(maillon->nom,nom1);
	strcpy(maillon->prenom,prenom1);
	maillon->moy=0;
	maillon->eval=note;
	maillon->suivant=NULL;
	pointe->premier=maillon;//pointe sur le premier element
	note->n=n1;
	note->coeff=coeff1;
	note->suivant=NULL;
	int cmpteur=0;
     while(cmpteur < nombres-1){
     	
     	 printf("Note suivante:\n");
         scanf("%f",&n1);
         
         printf("ok, Entrer le coefficient:\n");
         scanf("%d",&coeff1);
         Note *notes=malloc(sizeof(*notes));
	     notes->n=n1;
	     notes->coeff=coeff1;
	     notes->suivant=maillon->eval;
	     maillon->eval=notes;
	
     	 cmpteur+=1;
     	
	 }
	
	//
	actuel=pointe->premier;
	

	
	    char no[10];
		char nom[30];
		char prenom[30];
	int cmpt=0;	
	while(cmpt<nombreetu-1){
	
		if(cmpt!=0){
		pointe->premier=actuel;	
			system("color 5");
		printf("ETUDIANT");
		printf("==>");
		printf("%d",cmpt+2);
		printf("\n");
		printf("NUMERO:\n");
		
		scanf("%s",&no);
		printf("NOM:\n");
		scanf("%s",&nom);
		printf("PRENOM:\n");
		scanf("%s",&prenom);
		printf("NOMBRE DE NOTE :\n");
		scanf("%d",&nombre); 
		actuel=ajouteEtudiant(pointe->premier,no,nom,prenom,nombre);
    
		
			
		}else{
		
		
		system("color 5");
		printf("ETUDIANT");
		printf("==>");
		printf("%d",cmpt+2);
		printf("\n");
		printf("NUMERO:\n");
		
		scanf("%s",&no);
		printf("NOM:\n");
		scanf("%s",&nom);
		printf("PRENOM:\n");
		scanf("%s",&prenom);
		printf("NOMBRE DE NOTE :\n");
		scanf("%d",&nombre); 
		actuel=ajouteEtudiant(pointe->premier,no,nom,prenom,nombre);
		
			
		}
    
	cmpt+=1;
	}
	//calcule moyenne
	    printf("________________________________________________________________________________________________\n");
	    printf("                                      CALCULE DES MOYENNES                                       \n");
	    printf("_____________________________________| ");
	    printf("                  |_____________________________________\n");
	    
	    
	   actuel=calculemoy(actuel);
	//fin calcule moyenne
	   printf("_____________________________________________________________________________________________________\n");
	   printf("                                      CLASSEMENT DES ETUDIANTS                                       \n");
	   printf("_____________________________________| ");
	   printf("                      |_____________________________________\n");
	   
	  
	actuel=classement(actuel,nombreetu);
	
	

		 	break;
		case 2:
			system("color 8");
			char chaine[TAILLE_MAX];
			char reponse;
			FILE *fichier=NULL;
			char chemin[100];
			  printf("_________________________________CHARGEMENT DES  DONNEES __________________________________\n");
			  
			  printf("NB: le fichier classement.txt doit etre dans le repertoire courant du programme.\n");
			  printf("Etes vous sur que le fichier y est ?(Reponse: O/N)\n");
			  scanf("%s",&reponse);
			  if(reponse=='O' || reponse=='o'){
			  	         printf("\n");  	
			  	         fichier=fopen("classement.txt","r");
			  	        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
                           {
                               printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
                           }
				        fclose(fichier);
			  	        printf("\n");
			            printf("lecture termine");
			  }else{
			  	
			  	printf("Revenez apres la verification\n");
			  	
			  }
			  
			            
			  	
			  
			
			
			
			
			
		    break;
		case 3:
				printf("Aurevoir (:");
		    break;
		default:
			system("color 4");
		    printf("!! choix non valide !!");
              
           
    }
   
	
	
			  
		return 0;		 
			 
					
	}
	
	
	

	
	
	
	
	
	

           
    
	
	
	
	
	
	
	

