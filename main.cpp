#include <stdio.h>
#include <stdlib.h>
#define CMAX 10
#include <string.h>
#include <time.h>
typedef struct Date{
int mois;
int jour;
int annee;
}Date;

typedef struct Produit {
int id;
char nom[10];
int quantite;
int vendues ;
float  prixVente;
struct Date delai;
}Produit;
int choix ;
Produit produits[100];
//les templates

void menu();
void response(int n);

void response(int n){
    FILE* file;
//ajouter un produit
if (n==1){
struct Produit produit;

      file = fopen ("C:\\Users\\hazem\\Documents\\products.txt","r") ;

   int nb=0;
    while (fscanf(file, "%d %s %d %f %d %d %d", &produit.id, produit.nom, &produit.quantite,
                  &produit.prixVente, &produit.delai.annee, &produit.delai.mois, &produit.delai.jour) != EOF){
                 produits[nb]=produit;
                 nb++;}
                fclose(file);
file = fopen ("C:\\Users\\hazem\\Documents\\products.txt","a") ;
int g=0;
int test=0;

while(true){
while(true){
printf(" id: ");
scanf("%d", &produit.id);

for (int i=0; i<nb; i++){
    if (produits[i].id==produit.id){

        test++;
        break;
}

}
if (test==0){
 break;
}
else {
        test=0;
    printf("id deja existe \n");
}
}
printf("nom: ");
scanf("%s",& produit.nom);
printf("quantite: ");
scanf("%d", &produit.quantite);

printf("prix vente: ");
scanf("%f", &produit.prixVente);
while (true){
printf("delai anne: ");
scanf("%d", &produit.delai.annee);
if (produit.delai.annee<1990 ||produit.delai.annee >3000){
    printf ("format anne incorrecte \n");

}
else {
    break;
}
}
while (true ){
printf("delai mois: ");
scanf("%d", &produit.delai.mois);
if (produit.delai.mois<1 || produit.delai.mois>12){
    printf("format mois incorrecte \n");

}
else {
    break;
}
}
while (true){
printf("delai jour: ");
scanf("%d", &produit.delai.jour);
if (produit.delai.jour<1 || produit.delai.jour>31){
    printf("format jour incorrecte \n ");
}
else {
    break;
}
}
    fprintf(file, "%d %s %d %.2f %d %d %d\n", produit.id, produit.nom, produit.quantite, produit.prixVente, produit.delai.annee, produit.delai.mois, produit.delai.jour);
 printf("\033[2J\033[1;1H");
 printf("1-ajouter un autre client\n-clicker a quelque soit pour quitter");
printf("\nreponse ");
scanf("%d",&g);

 if (g==1){
     printf("\033[2J\033[1;1H");
    continue;
}
else {
    return;
}
}
 fclose(file);
}
//afficher les produits
else if (n==4){
    file = fopen ("C:\\Users\\hazem\\Documents\\products.txt","r") ;
   struct Produit produit;
printf("  ID   |  Nom         |  Quantite  | Prix de vente | Date de delai\n");
 while (fscanf(file, "%d %s %d %f %d %d %d", &produit.id, produit.nom, &produit.quantite,
                  &produit.prixVente, &produit.delai.annee, &produit.delai.mois, &produit.delai.jour) != EOF) {
    printf("%6d | %12s | %10d | %13.2f | %02d/%02d/%d\n",
               produit.id, produit.nom, produit.quantite, produit.prixVente,
               produit.delai.jour, produit.delai.mois, produit.delai.annee);
    }
    fclose(file);
}
else if (n==5){
 rename("C:\\Users\\hazem\\Documents\\new.txt","C:\\Users\\hazem\\Documents\\products.txt");
}
//supprimer un produit
else if (n==2){
    int s=0;
        int code;
        printf("donner le code de produit a supprimer: ");
       scanf("%d",&code);
      file = fopen ("C:\\Users\\hazem\\Documents\\products.txt","r") ;
   struct Produit produit;
   int nb=0;
    while (fscanf(file, "%d %s %d %f %d %d %d", &produit.id, produit.nom, &produit.quantite,
                  &produit.prixVente, &produit.delai.annee, &produit.delai.mois, &produit.delai.jour) != EOF){


           if (produit.id!=code){
                    produits[nb]=produit;
                 nb++;}
                 else {
                    s++;
                 }
                  }

if (s==0){
    printf("l'lement n'existe pas ");
    fclose(file);
}
else {
    FILE* fi;
    fi = fopen("C:\\Users\\hazem\\Documents\\new.txt","a");
    for (int i=0;i<nb;i++){

       fprintf(fi, "%d %s %d %.2f %d %d %d\n", produits[i].id, produits[i].nom, produits[i].quantite, produits[i].prixVente, produits[i].delai.annee, produits[i].delai.mois, produits[i].delai.jour);

    }
    fclose(file);
    printf("element supprimer avec succes");
    remove("C:\\Users\\hazem\\Documents\\products.txt");
 fclose(fi);
    rename("C:\\Users\\hazem\\Documents\\new.txt","C:\\Users\\hazem\\Documents\\products.txt");


   }

    return;

}
//modifier un produit
else if (n==3){
    int s=0;
        struct Produit produit;
    struct    Produit newProduct;
    printf ("donner l'id de enregistrement a modifier ");
    scanf("%d",&newProduct.id);
      int nb=0;
        file = fopen ("C:\\Users\\hazem\\Documents\\products.txt","r") ;
    while (fscanf(file, "%d %s %d %f %d %d %d", &produit.id, produit.nom, &produit.quantite,
                  &produit.prixVente, &produit.delai.annee, &produit.delai.mois, &produit.delai.jour) != EOF){

if (produit.id!=newProduct.id){
                    produits[nb]=produit;
                 nb++;
                 }
                 else {
    //debut code
printf("nom: ");
scanf("%s",& newProduct.nom);
printf("quantite: ");
scanf("%d", &newProduct.quantite);

printf("prix vente: ");
scanf("%f", &newProduct.prixVente);
while (true){
printf("delai anne: ");
scanf("%d", &newProduct.delai.annee);
if (newProduct.delai.annee<1990 ||newProduct.delai.annee >3000){
    printf ("format anne incorrecte \n");

}
else {
    break;
}
}
while (true ){
printf("delai mois: ");
scanf("%d", &newProduct.delai.mois);
if (newProduct.delai.mois<1 || newProduct.delai.mois>12){
    printf("format mois incorrecte \n");

}
else {
    break;
}
}
while (true){
printf("delai jour: ");
scanf("%d", &newProduct.delai.jour);
if (newProduct.delai.jour<1 || newProduct.delai.jour>31){
    printf("format jour incorrecte \n ");
}
else {
    break;
} }
       produits[nb]=newProduct;
                 nb++;
                    s++;
                 }
                  }

if (s==0){
    printf("l'lement n'existe pas ");
    fclose(file);
    return;
}
else {
     FILE* fi;
    fi = fopen("C:\\Users\\hazem\\Documents\\new.txt","a");
    for (int i=0;i<nb;i++){

       fprintf(fi, "%d %s %d %.2f %d %d %d\n", produits[i].id, produits[i].nom, produits[i].quantite, produits[i].prixVente, produits[i].delai.annee, produits[i].delai.mois, produits[i].delai.jour);

    }
    fclose(file);
    printf("element modifier avec succes");
    remove("C:\\Users\\hazem\\Documents\\products.txt");
 fclose(fi);
    rename("C:\\Users\\hazem\\Documents\\new.txt","C:\\Users\\hazem\\Documents\\products.txt");



}
}

//afficher les stocks termines
else if (n==7){
       file = fopen ("C:\\Users\\hazem\\Documents\\products.txt","r") ;
   struct Produit produit;
   int nb=0;
    while (fscanf(file, "%d %s %d %f %d %d %d", &produit.id, produit.nom, &produit.quantite,
                  &produit.prixVente, &produit.delai.annee, &produit.delai.mois, &produit.delai.jour) != EOF){


           if (produit.quantite==0){
                  printf("%d %s \n",produit.id, produit.nom);
                 nb++;
                  }

                  }
                    if (nb==0){
            printf("tout est correcte pas de probleme");
           }

}
else if(n==6){
   time_t t = time(NULL);
      struct tm *now = localtime(&t);
    file = fopen ("C:\\Users\\hazem\\Documents\\products.txt","r") ;
   struct Produit produit;
    int nb=0;
    while (fscanf(file, "%d %s %d %f %d %d %d", &produit.id, produit.nom, &produit.quantite,
                  &produit.prixVente, &produit.delai.annee, &produit.delai.mois, &produit.delai.jour) != EOF){


           if (produit.delai.annee< now->tm_year + 1900){
                 printf("%d %s \n",produit.id, produit.nom);
                  }
            else if (produit.delai.annee == now->tm_year + 1900 && produit.delai.mois==now->tm_mon +1){
                printf("%d %s \n",produit.id, produit.nom);
            }
            else if (produit.delai.annee == now->tm_year + 1900 && produit.delai.mois< now->tm_mon +1 && produit.delai.jour< now->tm_mday){
                    printf("%d %s \n",produit.id, produit.nom);}
                  }

}
//achats et prix
else if (n == 9) {
    int identity, quantity;
    int total = 0;
    struct Produit produit;
    int reponse;
while (true){
        printf("Donner le code du produit à vendre : ");
        scanf("%d", &identity);
        printf("Donner la quantité vendue : ");
        scanf("%d", &quantity);
        file = fopen("C:\\Users\\hazem\\Documents\\products.txt", "r");
        int s = 0;
        int nb = 0;
        while (fscanf(file, "%d %s %d %f %d %d %d", &produit.id, produit.nom, &produit.quantite,
                      &produit.prixVente, &produit.delai.annee, &produit.delai.mois, &produit.delai.jour) != EOF) {
            if (produit.id != identity) {
                produits[nb] = produit;
                nb++;
            } else {
                if (produit.quantite >= quantity) {
                    produit.quantite -= quantity;
                    total += quantity * produit.prixVente;
                    s++;
                       produits[nb] = produit;
                nb++;
                } else {
                    printf("Vous avez seulement %d pièces de %d\n", produit.quantite, produit.id);
                }
            }
        }
        fclose(file);
        if (s == 0) {
            printf("L'élément n'existe pas.\n");
        } else {
            FILE* fi;
            fi = fopen("C:\\Users\\hazem\\Documents\\new.txt", "a");
            for (int i = 0; i < nb; i++) {
                fprintf(fi, "%d %s %d %.2f %d %d %d\n", produits[i].id, produits[i].nom, produits[i].quantite,
                        produits[i].prixVente, produits[i].delai.annee, produits[i].delai.mois, produits[i].delai.jour);
            }
            fclose(fi);
            printf("Élément vendu avec succès.\n");
            remove("C:\\Users\\hazem\\Documents\\products.txt");
            rename("C:\\Users\\hazem\\Documents\\new.txt", "C:\\Users\\hazem\\Documents\\products.txt");
        }
        printf("voulez vous vendre un autre produit ");
        scanf("%d",&reponse);
      if(reponse!=1){
        break;
      }
}
printf("Le total des ventes est de : %d\n", total);


}

}
 void menu(){
printf("1-ajouter un produit \n");
printf("2-supprimer un produit \n");
printf("3-modifier un produit \n");
printf("4-afficher les produits et prix\n");
printf("5-ventes de produit et prix totale\n");
printf ("6-produit dont delai est depasse \n");
printf("7-les stocks finis \n");
printf ("que cherchez vous? ");
scanf("%d", &choix);
 printf("\033[2J\033[1;1H");
  response(choix);
 }



int main()
{

    menu();
    return 0;
}


