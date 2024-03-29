

void ajouterMedicament(){
int nbre;
Medicament Med;
FILE*fp=fopen("medica.txt","at");
if(fp == NULL){
    printf("fichier introuvable");
    exit(0);
}
printf("nombre des medicament a ajouter: ");scanf("%d",&nbre);
for(int i=1;i<= nbre;i++){
printf("code%d : ",i);scanf("%d",&Med.code);
printf("nom%d : ",i);scanf("%s",Med.nom);
printf("jour%d : ",i);scanf("%d",&Med.date.j);
printf("mois%d : ",i);scanf("%d",&Med.date.m);
printf("annee%d : ",i);scanf("%d",&Med.date.a);
printf("prix%d : ",i);scanf("%f",&Med.prix);
printf("quantite%d : ",i);scanf("%d",&Med.q);
fprintf(fp,"\n%d\t%s\t\t\t\t%d/%d/%d\t\t\t%.2f\t%d",Med.code,Med.nom,Med.date.j,Med.date.m,Med.date.a,Med.prix,Med.q);
}
fclose(fp);
}
void ajouterFornisseur(){
      fournisseur T;
      FILE*fp=fopen("fournis.txt","at");
      int n;
      printf("entrer le nombre des fournisseurs  qui tu veux ajouter:");
      scanf("%d",&n);

      for(int i=1;i<=n;i++){
         printf("Entrer les information de fournisseur %d :\n",i);
         printf("Nom:");
         scanf("%s",T.nom);
         printf("Adresse: ");
         scanf("%s",T.adresse);
         printf("Fax: ");
         scanf("%s",T.tele);
         printf("Numero de produit :");
         scanf("%d",&T.codeprd);
         fprintf(fp,"\n%d\t%s\t\t%s\t\t\t%s",T.codeprd,T.nom,T.adresse,T.tele);

    }
    fclose(fp);
}
void AjouterEmpl(){
  user T;
  int n;
  int i;
  printf("\t Veuillez indiquer le nombre d'employés à ajouter:");
  scanf("%d",&n);
  FILE*fp=fopen("employe.txt","at");
  for(i=1;i<=n;i++){
      printf("\t Saisir les informations de l'employe %d :\n",i);
      printf("\t Numero de l'employe(Code): ");
      scanf("%d",&T.login);
      printf("\t Nom de l'employe(Code): ");
      scanf("%s",T.nom);
      fprintf(fp,"%d\t%s\n",T.login,T.nom);
  }

fclose(fp);
}
void AjouterGerant(){
  user T;
  int n;
  int i;
  printf("\tVeuillez indiquer le nombre des gerants à ajouter:");
  scanf("%d",&n);
  FILE*fp=fopen("gerant.txt","at");
  for(i=1;i<=n;i++){
      printf("\t Saisir les informations de gerant %d :\n",i);
      printf("\t Numero de gerant(Code): ");
      scanf("%d",&T.login);
      printf("\t Nom de gerant(Code): ");
      scanf("%s",T.nom);
      fprintf(fp,"\n%d\t%s",T.login,T.nom);
  }

fclose(fp);

}
void AjouterVent(int lgn){
    FILE*medic=fopen("medica.txt","rt");
    FILE*empl=fopen("employe.txt","rt");
    FILE*Vente=fopen("Ventes.txt","at");
    int Codemed,Qua,jour,mois,annee,cmp=0 ;
    user T;
    Medicament M;
    printf("Veuillez indiquer le code du médicament que vous souhaitez vendre: ");
    scanf("%d",&Codemed);

    printf("Saisir la quantite: ");
    scanf("%d",&Qua);
    printf("Entre la date : ");
    scanf("%d%d%d",&jour,&mois,&annee);
    while(fscanf(medic,"%d%s%d/%d/%d%f%d",&M.code,M.nom,&M.date.j,&M.date.m,&M.date.a,&M.prix,&M.q)==7){
        if(M.code==Codemed){
                 cmp=1;
             break;
            }
        }
        if(cmp==1){
                if(M.q < Qua){
                printf("quantite insuffisant:\n");
                return 0;
                }
           else{
                printf("Voici la commande:\n");
                printf("Code de medicament:%d\t Nom de medicament:%s\t quantite:%d \t Prix:%d x %.2f=%.2f \n",M.code,M.nom,Qua,Qua,M.prix,Qua*M.prix);

                while(fscanf(empl,"%d%s",&T.login,T.nom)==2){
                    if(T.login==lgn){
                        fprintf(Vente,"%s\t%d\t%d\t%d/%d/%d\n",T.nom,M.code,Qua,jour,mois,annee);
                    }
                }
            }


        }

        else
            printf("le medicament n'existe pas !!");


    fclose(medic);
    fclose(empl);
    fclose(Vente);
    Mise_jour_quantite_reduit(Codemed,Qua);
}
