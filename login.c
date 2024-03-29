#include<stdio.h>
#include "structurJdida.h"
#include "fctAffichage.c"
#include "ajouter.c"
#include "supprimer.c"
#include "modifier.c"
#include "chercher.c"
#include <ctype.h>
#include<string.h>
#include <time.h>

int main(){
int choix,a1,a2,b1,b2,c1,c2;
int reponse;
title();
choixvalide:
        printf(" ______________________________________________\n");
		printf("│ -------- type d'utilisateurs-----------------│ \n");
		printf("│ 1  : employe                                 │ \n");
		printf("│ 2  : gerant                                  │ \n");
		printf("│ 3  : parmacier                               │ \n");
		printf("│ 0  : Quitter la base de donnes               │ \n");
		printf("│______________________________________________│ \n");
		printf("\n");
		printf(" Votre choix : ");
        scanf("%d",&choix);
switch(choix){
case 1:
    do{
    a1=login();
    a2=chercher_utilisateur(a1);
    if(a2 != 1){
        printf("login incorrect!!\n resaisir le code...\n");
        sleep(1);
        system("cls");
         }
    }while(a2 != 1);
    if(a2 == 1){
      int choixCommande;
      do{
            printf("________________________________________________\n");
            printf("│-------Veuillez choisir une commande :--------│\n");
            printf("│1. Chercher un medicament (par num)           │\n");                          //V
            printf("│2. Chercher un medicament (par nom)           │\n");
            printf("│3. Ajouter les ventes                         │\n");
            printf("│4. Consulter la quantite des medicaments      │\n");
            printf("│5. Afficher la liste des medicaments          │\n");                        //V
            printf("│6.  Affiche les ventes de lui meme            │\n");
            printf("│0.  Quitter                                   │\n");
            printf("│______________________________________________│\n");

            printf("Votre choix : ");
            scanf("%d", &choixCommande);
            switch(choixCommande){
    case 1:
        debuta1:
        system("cls");
        chercheParNum();
         printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
         scanf("%d",&reponse);
            system("cls");
         if(reponse==1)
         goto debuta1;
     break;
     case 2:
         debuta2:
        system("cls");
         chercheParNom();
          printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
         scanf("%d",&reponse);
            system("cls");
         if(reponse==1)
         goto debuta2;
     break;
     case 3:
         debuta3:
        system("cls");
        AjouterVent(a1);
         printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
         scanf("%d",&reponse);
            system("cls");
         if(reponse==1)
         goto debuta3;

       break;
     case 4:
         debuta4:
        system("cls");
        affichequantiteMed();
         printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
         scanf("%d",&reponse);
            system("cls");
         if(reponse==1)
         goto debuta4;
     break;
     case 5:
         debuta5:
        system("cls");
         afficheStokMed();
          printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
         scanf("%d",&reponse);
            system("cls");
         if(reponse==1)
         goto debuta5;
     break;
     case 6:
         debuta6:
        system("cls");
         afficherVentEmpl(a1);
          printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
         scanf("%d",&reponse);
            system("cls");
         if(reponse==1)
         goto debuta6;
     break;
     case 0:
         printf("deconexion...\n"); sleep(2);
                     exit(1);
     break;
     default:
         system("cls");
                    printf("Commande invalide\n");
                    printf("saisir un  choix entre 1 et 9\nEnter 1 pour retourner au menu principal: ");
                   scanf("%d", &reponse);
                   system("cls");
                    break;
     break;
   }
      }while(choixCommande!=0);

    }

     break;
case 2:
    do{
    b1=login();
    b2=chercher_gerant(b1);
    if(b2 != 1){
        printf("login incorrect!!\n resaisir le code...\n");
        sleep(1);
        system("cls");
    }
         }while(b2 != 1);

    if(b2 == 1){
      int choixCommande;
      do{
            printf(" ______________________________________________________\n");
            printf("│------------Veuillez choisir une commande :-----------│\n");
            printf("│1. Afficher la liste des medicaments                  │\n");     //V
            printf("│2. Afficher la liste des vents                        │\n");    //V
            printf("│3. Afficher la liste des fournisseurs                 │\n");   //V
            printf("│4. Ajouter un fournisseur                             │\n");
            printf("│5. Supprimer un fournisseur                           │\n");
            printf("│6. Ajouter nouveau medicament                         │\n");   //v
            printf("│7. Mise a jour la quantite d'un medicament            │\n");
            printf("│8. Consulter le fournisseur de medicament             │\n");   //V
            printf("│9. Afficher les medicaments en rupture de stock       │\n");
            printf("│10.Afficher les medicaments perimes (date expire)     │\n");
            printf("│0.quitter:                                            │\n");
            printf("│______________________________________________________│\n");
            printf("Votre choix : ");
            scanf("%d", &choixCommande);
        switch(choixCommande){
     case 1:
         debutb1:
             system("cls");
        afficheStokMed();
        printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
         scanf("%d",&reponse);
            system("cls");
         if(reponse==1)
         goto debutb1;
        break;
     case 2:
          debutb2:
         system("cls");
         affichevente();
         printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
         scanf("%d",&reponse);
         system("cls");
         if(reponse==1)
         goto debutb2;
        break;
     case 3:
         debutb3:
         system("cls");
       affichefourni();
       printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
        scanf("%d",&reponse);
        system("cls");
        if(reponse==1)
        goto debutb3;
       break;
     case 4:
         debutb4:
         system("cls");
         ajouterFornisseur();
          printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
        scanf("%d",&reponse);
        system("cls");
        if(reponse==1)
        goto debutb4;
        break;
     case 5:
         debutb5:
         system("cls");
         supprimerFornisseur();
         printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
        scanf("%d",&reponse);
        system("cls");
        if(reponse==1)
        goto debutb5;
        break;
     case 6:
         debutb6:
         system("cls");
          ajouterMedicament();
          printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
        scanf("%d",&reponse);
        system("cls");
        if(reponse==1)
        goto debutb6;
        break;
     case 7:
         debutb7:
         system("cls");
        Mise_jour_quantite();
        printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
        scanf("%d",&reponse);
        system("cls");
        if(reponse==1)
        goto debutb7;
        break;
     case 8:
         debutb8:
         system("cls");
         afficheFornisseurDeMedic();
         printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
        scanf("%d",&reponse);
        system("cls");
        if(reponse==1)
        goto debutb8;
        break;
     case 9:
         debutb9:
         system("cls");
         afficheRupture();
         printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
        scanf("%d",&reponse);
        system("cls");
        if(reponse==1)
        goto debutb9;
        break;
        case 10:
            debutb10:
         system("cls");
        afficheperime();
        printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
        scanf("%d",&reponse);
        system("cls");
        if(reponse==1)
        goto debutb10;
        break;
         case 0:
         printf("deconexion...\n");
         sleep(1);
          exit(1);
        break;
     default:
         system("cls");
                    printf("Commande invalide\n");
                    printf("saisir un  choix entre 1 et 9\nEnter 1 pour retourner au menu principal: ");
                   scanf("%d", &reponse);
                   system("cls");
                    break;
        break;
    }
    }while(choixCommande != 0);

    }

 break;
case 3:
    do{
    c1=login();
    c2=chercher_pharmacier(c1);
    if(c2 != 1){
        printf("login incorrect!!\n resaisir le code...\n");
        sleep(1);
        system("cls");
    }
    }while(c2 != 1);
    if(c2 == 1){

            int choixCommande;
            do{
            printf("Veuillez choisir une commande :\n");
            printf("_________________________________________________\n");
            printf("│1. Afficher le stock                            │\n");
            printf("│2. Afficher la liste des employes               │\n");
            printf("│3. Afficher les informations de gerant          │\n");
            printf("│4. Supprimer un employe                         │\n");
            printf("│5. Supprimer un gerant                          │\n");
            printf("│6. Modifier les informations d'un employe       │\n");
            printf("│7. Modifier les informations d'un gerant        │\n");
            printf("│8. Ajouter un employe                           │\n");
            printf("│9. Ajouter un gerant                            │\n");
            printf("│0. quitter                                      │\n");
            printf("│________________________________________________│\n");
            printf("Votre choix : ");
            scanf("%d", &choixCommande);

            // Traiter les commandes du pharmacien
            switch (choixCommande) {
                case 1:
                        debutc1:
                        system("cls");
                    printf("Commande : Afficher le stock\n");
                    afficheStokMed();
                    printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
                     scanf("%d",&reponse);
                    system("cls");
                  if(reponse==1)
                    goto debutc1;
                    break;
                case 2:
                    debutc2:
                        system("cls");
                    printf("Commande : Afficher la liste des employes\n");
                     afficheemploye();
                     printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
                     scanf("%d",&reponse);
                    system("cls");
                  if(reponse==1)
                    goto debutc2;
                    break;
                case 3:
                    debutc3:
                    system("cls");
                    printf("Commande :Afficher les informations de gerant\n");
                    affichegerant();
                    printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
                     scanf("%d",&reponse);
                    system("cls");
                  if(reponse==1)
                    goto debutc3;
                    break;
                case 4:
                    debutc4:
                        system("cls");
                    printf("Commande : Supprimer un employe\n");
                    supprimerEmploye();
                    printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
                     scanf("%d",&reponse);
                    system("cls");
                  if(reponse==1)
                    goto debutc4;
                    break;
                case 5:
                    debutc5:
                    system("cls");
                    printf("Commande : Supprimer un gerant\n");
                    supprimergerant();
                    printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
                     scanf("%d",&reponse);
                    system("cls");
                  if(reponse==1)
                    goto debutc5;

                    break;
                case 6:
                    debutc6:
                    system("cls");
                    printf("Commande : Modifier les informations d'un employe\n");
                    modifierEmployeParLogin();
                    printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
                     scanf("%d",&reponse);
                    system("cls");
                  if(reponse==1)
                    goto debutc6;
                    break;
                case 7:
                    debutc7:
                    system("cls");
                    printf("Commande : Modifier les informations d'un gerant \n");
                    modifierGerant();
                     printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
                     scanf("%d",&reponse);
                    system("cls");
                  if(reponse==1)
                    goto debutc7;
                    break;
                    case 8:
                        debutc8:
                    system("cls");
                    printf("Commande : Ajouter un employe :\n");
                    AjouterEmpl();
                    printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
                     scanf("%d",&reponse);
                    system("cls");
                  if(reponse==1)
                    goto debutc8;
                    break;
                    case 9:
                        debutc9:
                    system("cls");
                    printf("Commande : Ajouter un gerant\n");
                      AjouterGerant();
                      printf("\n1-Repeter l'action\n2-Retourner au Menu\nEntrer votre choix: ");
                     scanf("%d",&reponse);
                    system("cls");
                  if(reponse==1)
                    goto debutc9;
                    break;
                    case 0:
                    printf("deconexion...\n"); sleep(1);
                     exit(1);
                    break;

                default:
                    system("cls");
                    printf("Commande invalide\n");
                    printf("saisir un  choix entre 1 et 9\nEnter 1 pour retourner au menu principal: ");
                   scanf("%d", &reponse);
                   system("cls");
                    break;
            }
        }while(choixCommande!=0 );

    }

    break;
    case 0:
        printf("deconnecion..\n");sleep(1);
        exit(1);
        break;
default:
    printf("choix invalide...\n");sleep(1);
    system("cls");
    goto choixvalide;
break;

}
return 0;
}
