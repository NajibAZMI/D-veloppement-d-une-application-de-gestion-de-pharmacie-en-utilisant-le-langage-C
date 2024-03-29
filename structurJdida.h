
#define max 50
typedef struct {
      char nom[max];
      char adresse[max];
      char tele[max];
      int  codeprd;
}fournisseur;
typedef struct {
   int j;
   int m;
   int a;
}Date;
typedef struct {
    char nom[max];
    int  code;
    int q;
    float prix;
    Date date;
} Medicament;
typedef struct{
    char nom[max];
    int login;
}user;
typedef struct{
     char nom[max];
     int codeprdu;
     int quantite;
     Date dateVente;
}Ventes;



