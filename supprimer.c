
void supprimerFornisseur(){
fournisseur F;
FILE*fp=fopen("fournis.txt","rt");
FILE*cp=fopen("copieFornis.txt","wt");
char nome[max];
printf(" Veuillez indiquer le nom de fournisseur à supprimer :");
scanf("%s",nome);
while(fscanf(fp,"%d%s%s%s",&F.codeprd,F.nom,F.adresse,F.tele) == 4){
    if(strcmp(F.nom,nome) != 0){
        fprintf(cp,"\n%d\t%s\t\t%s\t\t\t%s",F.codeprd,F.nom,F.adresse,F.tele);
    }
}
fclose(fp);
fclose(cp);
remove("fournis.txt");
rename("copieFornis.txt","fournis.txt");
}
void supprimerEmploye(){
        int num;
        user T;
        FILE*fp=fopen("employe.txt","rt");
        FILE*temp=fopen("temp.txt","at");
        printf("\t Veuillez indiquer le numéro d'employe à supprimer : ");
        scanf("%d",&num);
        int i=chercher_utilisateur(num);
        if(i==0)
            printf("\tAucun employe avec le numero mentionne n'existe.");
        else{
            while(fscanf(fp,"%d%s",&T.login,T.nom)==2){
                if(T.login!=num){
                    fprintf(temp,"%d\t%s\n",T.login,T.nom);
                }
                else{
                    continue;
                }
            }


        }

          fclose(fp);
            fclose(temp);
            remove("employe.txt");
            rename("temp.txt","employe.txt");

}
// Supprimer un gérant
void supprimergerant() {
	char nom[max];
    user grt; // grt=gerant
    FILE *fp = fopen("gerant.txt", "rt");
    FILE *fic = fopen("copiegerant.txt", "wt");
    if (fp == NULL || fic == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
     char c[max];
    printf("Enterle nom du gerant voulez vous a supprimer : ");
    scanf("%s", nom);
         while (fgets(c, sizeof(c), fp) != NULL) {
        if (strstr(c, nom) == NULL) {
            fputs(c, fic);
        }
    }

    fclose(fp);
    fclose(fic);
    remove("gerant.txt");
    rename("copiegerant.txt", "gerant.txt");
}
