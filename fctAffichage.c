#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <time.h>
void title(){
printf("\n");
	printf("\t  _____                _     _                         _            _____    _                                                 _        \n");
  	printf("\t / ____|              | |   (_)                       | |          |  __ \\  | |                                               (_)       \n");
 	printf("\t| |  __    ___   ___  | |_   _    ___    _ __       __| |   ___    | |__) | | |__     __ _   _ __   _ __ ___     __ _    ___   _    ___ \n");
 	printf("\t| | |_ |  / _ \\ / __| | __| | |  /  _\\  |    _\\    / _  |  / _ \\   |  ___/  |  _ \\   / _  | |  __| |  _   _ \\   / _  |  / __| | |  / _ \\\n");
 	printf("\t| |__| | |  __/ \\__ \\ | |_  | | | (_) | | | | |   | (_| | |  __/   | |      | | | | | (_| | | |    | | | | | | | (_| | | (__  | | |  __/\n");
  	printf("\t \\_____|  \\___| |___/  \\__| |_|  \\___/  |_| |_|    \\__ _|  \\___|   |_|      |_| |_|  \\__ _| |_|    |_| |_| |_|  \\__ _|  \\___| |_|  \\___|\n");
 printf("\n\n");
}
int teste_date_med(Medicament T){
    time_t temps_actuel;
    struct tm *temps_info;
    time(&temps_actuel);
    temps_info = localtime(&temps_actuel);
    int sysjour = temps_info->tm_mday;
    int sysmois=temps_info->tm_mon + 1;
    int sysanne=temps_info->tm_year + 1900;

    if (sysanne < T.date.a){
       	return -1;

      }else if (sysanne > T.date.a){
    		return 1;
		}

    	else if (sysanne == T.date.a)
    	{
	        if (sysmois < T.date.m)
	            return -1;
	        else if (sysmois > T.date.m){
	        	return 1;

			}
	        else if (sysjour < T.date.j)
	            return -1;
	        else if(sysjour >= T.date.j){
	        	return 1;

			}

    	}
  }
void affichequantiteMed(){
      FILE*fp=fopen("medica.txt","rt");
      Medicament T;
      printf("__________________________________________________________________\n");
      printf("│Code\t\t Nom \t\t\t\t\tQuantite │\n");
      printf("│________________________________________________________________│\n");
  while(fscanf(fp,"%d%s%d/%d/%d%f%d",&T.code,T.nom,&T.date.j,&T.date.m,&T.date.a,&T.prix,&T.q)==7){
       printf("│%-5d\t\t%-20s\t\t\t%-9d│\n", T.code, T.nom,T.q);

        }

     printf("│________________________________________________________________│\n");
     fclose(fp);
}

void afficheStokMed(){
      FILE*fp=fopen("medica.txt","rt");
      Medicament T;
      printf("__________________________________________________________________________\n");
      printf("│Code \tNom \t\t\tDate Fin\t Prix(DHs)\tQuantite │\n");
      printf("│________________________________________________________________________│\n");
  while(fscanf(fp,"%d%s%d/%d/%d%f%d",&T.code,T.nom,&T.date.j,&T.date.m,&T.date.a,&T.prix,&T.q)==7){
       printf("│%-5d\t%-20s\t%-2d/%-2d/%-4d \t %-8.2f \t %-5d\t │\n", T.code, T.nom, T.date.j, T.date.m, T.date.a, T.prix, T.q);

        }

     printf("│________________________________________________________________________│\n");
     fclose(fp);
}

void affichefourni(){
    FILE*fp=fopen("fournis.txt","rt");
    fournisseur T;
    printf("_______________________________________________________________________\n");
    printf("│Nom \t\t\t ville \t\t Telephone \t   Numproduit  │ \n");
    printf("│______________________________________________________________________│\n");
    while(fscanf(fp,"%d%s%s%s",&T.codeprd,T.nom,T.adresse,T.tele)==4){
        printf("│%-16s\t%-12s\t%-18s\t%-7d│\n",T.nom,T.adresse,T.tele,T.codeprd);
    }
    printf("│______________________________________________________________________│\n");
    fclose(fp);
}
void afficheRupture(){

   FILE*fp=fopen("Rupture.txt","wt");
    Medicament T;
    FILE*fm=fopen("medica.txt","rt");

 while(fscanf(fm,"%d%s%d/%d/%d%f%d",&T.code,T.nom,&T.date.j,&T.date.m,&T.date.a,&T.prix,&T.q)==7){
       if(T.q==0){
    fprintf(fp,"\n%d\t%s\t\t\t\t%d/%d/%d\t\t\t%.2f\t%d",T.code,T.nom,T.date.j,T.date.m,T.date.a,T.prix,T.q);

       }
        }
        fclose(fp);
        fclose(fm);
    fp=fopen("Rupture.txt","rt");

      printf("__________________________________________________________________________\n");
      printf("│Code \tNom \t\t\tDate Fin\t Prix(DHs)\tQuantite │\n");
      printf("│________________________________________________________________________│\n");
  while(fscanf(fp,"%d%s%d/%d/%d%f%d",&T.code,T.nom,&T.date.j,&T.date.m,&T.date.a,&T.prix,&T.q)==7){
       printf("|%-5d\t%-20s\t%-2d/%-2d/%-4d \t %-8.2f \t %-5d\t |\n", T.code, T.nom, T.date.j, T.date.m, T.date.a, T.prix, T.q);

        }

     printf("│________________________________________________________________________│\n");

    fclose(fp);

}
void afficheperime(){
      FILE*fp=fopen("perimes.txt","wt");
      Medicament T;
      FILE*fm=fopen("medica.txt","rt");
      while(fscanf(fm,"%d%s%d/%d/%d%f%d",&T.code,T.nom,&T.date.j,&T.date.m,&T.date.a,&T.prix,&T.q)==7){
          int p=teste_date_med(T);
        if(p == 1){
    fprintf(fp,"\n%d\t%s\t\t\t\t%d/%d/%d\t\t\t%.2f\t%d",T.code,T.nom,T.date.j,T.date.m,T.date.a,T.prix,T.q);

       }
        }
        fclose(fp);
        fclose(fm);

        fp=fopen("perimes.txt","rt");
      printf("__________________________________________________________________________\n");
      printf("│Code \tNom \t\t\tDate Fin\t Prix(DHs)\tQuantite │\n");
      printf("│________________________________________________________________________│\n");
  while(fscanf(fp,"%d%s%d/%d/%d%f%d",&T.code,T.nom,&T.date.j,&T.date.m,&T.date.a,&T.prix,&T.q)==7){
       printf("│%-5d\t%-20s\t%-2d/%-2d/%-4d \t %-8.2f \t %-5d\t │\n", T.code, T.nom, T.date.j, T.date.m, T.date.a, T.prix, T.q);

        }

     printf("│________________________________________________________________________│\n");

    fclose(fp);
}
void afficheemploye(){
       FILE*fp=fopen("employe.txt","rt");
           user T;
        printf(" _________________\n");
        printf("│Code  \t Nom     │\n");
        printf("│_________________│\n");
        while(fscanf(fp,"%d%s",&T.login,T.nom)==2){
              printf("|%-4d\t%-10s|\n",T.login,T.nom);
    }
        printf("│_________________│\n");
    fclose(fp);
}
void affichegerant(){
       FILE*fp=fopen("gerant.txt","rt");
        user T;
        printf(" _________________\n");
        printf("│Code  \t Nom     │\n");
        printf("│_________________│\n");
        while(fscanf(fp,"%d%s",&T.login,T.nom)==2){
             printf("│%-4d\t%-10s│\n",T.login,T.nom);
    }
        printf("│_________________│\n");
    fclose(fp);
}
void affichevente(){
         FILE*fp=fopen("Ventes.txt","rt");
         Ventes T;
          printf("________________________________________________________________\n");
          printf("│ Nom \t\tCode\t\tQuantite\t Date de vente  │\n");
          printf("│_______________________________________________________________│\n");
         while(fscanf(fp,"%s%d%d%d/%d/%d",T.nom,&T.codeprdu,&T.quantite,&T.dateVente.j,&T.dateVente.m,&T.dateVente.a)==6){
      printf("│%-10s\t%-8d\t%-10d\t %d/%d/%d\t│\n",T.nom,T.codeprdu,T.quantite,T.dateVente.j,T.dateVente.m,T.dateVente.a);

}
          printf("│_______________________________________________________________│\n");

    fclose(fp);
}
void afficheFornisseurDeMedic(){
    int num;
    printf("afficher le fournisseur d'un medicament:\n");
    printf("saisir le code de medicament:\n");
    scanf("%d",&num);
    FILE*fp=fopen("fournis.txt","rt");
    fournisseur T;
    int i=0;
    printf("_______________________________________________________________________\n");
    printf("│Nom \t\t\t ville \t\t Telephone \t   Numproduit  │ \n");
    printf("│______________________________________________________________________│\n");
    while(fscanf(fp,"%d%s%s%s",&T.codeprd,T.nom,T.adresse,T.tele)==4){
          if(T.codeprd==num){
            printf("│%-16s\t%-12s\t%-18s\t%-7d│\n",T.nom,T.adresse,T.tele,T.codeprd);
            i=1;
            break;
          }

    }
     printf("│______________________________________________________________________│\n");
    fclose(fp);

    if(i==0){
        printf("%d n'existe pas",num);
    }

}

void afficherVentEmpl(int code){
    char nome[max];
    user E;
    printf("afficher la liste des ventes..\n");
    sleep(2);
    FILE*fe=fopen("employe.txt","rt");
    while(fscanf(fe,"%d%s",&E.login,E.nom)==2){
        if(code==E.login){
            strcpy(nome,E.nom);
             break;
        }
    }
    fclose(fe);
    Ventes T;
    FILE*fp=fopen("Ventes.txt","rt");
        printf("________________________________________________\n");
     printf("│Code\t\tQuantite\t Date de vente  │\n");
     printf("│_______________________________________________│\n");
           while(fscanf(fp,"%s%d%d%d/%d/%d",T.nom,&T.codeprdu,&T.quantite,&T.dateVente.j,&T.dateVente.m,&T.dateVente.a)==6){
                   if(strcmp(T.nom,nome)==0){
                        printf("│%-8d\t%-10d\t %d/%d/%d\t│\n",T.codeprdu,T.quantite,T.dateVente.j,T.dateVente.m,T.dateVente.a);
      }

}
    printf("│_______________________________________________│\n");




fclose(fp);
}



