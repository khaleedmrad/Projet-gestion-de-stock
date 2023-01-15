#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>
typedef struct produit{
    char id[100];
    char catg[15];
    char mark[15];
    char nom[15];
    char prix[100];
    char qte[100];
    char Date[100];
}produit;
void  cherchprod() {
  system("cls");
    FILE* file = fopen("ref.txt", "r");
    char line[100];
    char id_rech[15];
    produit p;
    if(file==NULL)
    {
      printf("Erreur lors de l'ouverture d'un fichier");
      exit(1);
    }
int c;
   char ch[10];
    c=1;
    while(c==1){
        c=0;
        printf("\033[1;33m");
        printf("Donner l'ID du produit(6 CHIFFRES): \n");
        printf("\033[1;0m");
        gets(ch);
        if (strlen(ch)==6){
            for (int i=0; i<6;i++){
            if ((ch[i]<48)||(ch[i]>57)){
                printf("\033[1;31m");
                printf("Saisie incorrecte\n");
                printf("\033[1;0m");
                c=1;
                break;
            }
            }}
        else{
            printf("\033[1;31m");
            printf("Saisie incorrecte\n");
            printf("\033[1;0m");
            c=1;}}

      while (fgets(line, sizeof(line), file)!= NULL)
    {
      char str2[100];
      strcpy(str2,line);
      int i=0;
         while(i<82)
         {
          i++;
          if (line[i]==124)
           {
              line[i]=32;
            }
          }
      sscanf(line, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n",&p.id,p.catg,p.mark,p.nom,&p.prix,&p.qte,&p.Date);
      if (strcmp(p.id,ch) == 0)
      { printf("\033[0;36mle produit recherche est:\nID    |CATEGORIE      |MARQUE         |NOM            |PRIX    |QTE.  |DATE LIM. |\033[0;0m");
        printf("\n%s\n",str2);
        fclose(file);
        printf("\033[0;0m");
        printf("\033[0;35mAppuyer entree pour quitter");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".\033[0;0m");
        getchar();
        system("cls");
        return 0;
      }
    }
    printf("\033[1;31m");
    printf("Le produit n'existe pas dans le stock");
    printf("\033[1;0m");
    printf("\n\033[0;35mAppuyer sur entree pour quitter");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".\033[0;0m");
    getchar();
    system("cls");
  }
