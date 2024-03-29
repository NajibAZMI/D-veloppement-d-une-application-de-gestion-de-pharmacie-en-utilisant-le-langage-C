int login(){
    int code;
    printf("login :");
    scanf("%d",&code);
    return code;
}
int chercher_utilisateur(int code){
    user employee;
    int i=0;
    FILE *fp = fopen("employe.txt","rt");
    if (fp == NULL){
        printf("imposible d'ouvrir la liste des utilisateurs:\n");
        exit(0);
    }
    while (fscanf(fp,"%d%s",&employee.login,employee.nom) == 2){
            if(employee.login == code){
                i=1;
                break;}

    }
    fclose(fp);
    return i;


}
int chercher_gerant(int code){
    user employee;
    int i=0;
    FILE *fp = fopen("gerant.txt","rt");
    if (fp == NULL){
        printf("imposible d'ouvrir la liste :\n");
        exit(0);
    }
    while (fscanf(fp,"%d%s",&employee.login,employee.nom) == 2){
            if(employee.login == code){
                i=1;
                break;}

    }
    fclose(fp);
    return i;


};
int chercher_pharmacier(int code){
    user employee;
    int i=0;
  FILE *fp = fopen("pharmacien.txt","rt");
    while(fscanf(fp,"%d%s",&employee.login,employee.nom)==2){
            if(employee.login == code){
              i=1;

            break; }


    }
  fclose(fp);
return i;
}
void chercheParNum(){
    FILE*fp=fopen("medica.txt","rt");
    Medicament T;
    int num;
    printf("\tveuillez saisir le numero de medicament a recherche : ");
    scanf("%d",&num);
    int i=0;
    while(fscanf(fp,"%d%s%d/%d/%d%f%d",&T.code,T.nom,&T.date.j,&T.date.m,&T.date.a,&T.prix,&T.q)==7){
        if(T.code == num){
            i=1;
            printf("\tNom:%s\t NumProduit:%d\t Quantite:%d\t Prix:%.2f DHs",T.nom,T.code,T.q,T.prix);

            break;
        }
        else{
            i=0;
        }
    }
    fclose(fp);

    if(i==0){
        printf("\tProduits de Code %d n'existe pas ",num);
    }
    }
 void chercheParNom(){
    FILE*fp=fopen("medica.txt","rt");
    Medicament T;
    char nome[max];
    printf("\tveuillez saisir le nom de medicament a recherche : ");
    scanf("%s",nome);
    int i=0;
    while(fscanf(fp,"%d%s%d/%d/%d%f%d",&T.code,T.nom,&T.date.j,&T.date.m,&T.date.a,&T.prix,&T.q)==7){
        if(strcmp(T.nom,nome) == 0){
            i=1;
            printf("\tNom:%s\t NumProduit:%d\t Quantite:%d\t Prix:%.2f DHs",T.nom,T.code,T.q,T.prix);

            break;
        }
        else{
            i=0;
        }
    }
    fclose(fp);

    if(i==0){
        printf("\tProduits de Code %s n'existe pas ",nome);
}
 }
