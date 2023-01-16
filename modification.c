#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <wchar.h>

bool isAlphanumeric(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if ((!isalnum(str[i]))&&(str[i] != ' ')) {
            return false;
        }
    }
    return true;
}


bool is_valid_price(const char *price_str) {
    int dot_count = 0;
    int digits_after_dot = 0;

    for (int i = 0; i < strlen(price_str); i++) {
        if (price_str[i] == '.') {
            dot_count++;
        } else if (dot_count == 1 && isdigit(price_str[i])) {
            digits_after_dot++;
        } else if (!isdigit(price_str[i])) {
            return false;
        }
    }
    if (dot_count == 1 && digits_after_dot == 3) {
        return true;
    }
    return false;
}



typedef struct product {
    char id[10];
    char categorie[20];
    char marque[20];
    char nom[20];
    char prix[10];
    char quantite[10];
    char dlc[10];
}product;

void add_spaces(char* str,int n) {
    int len = strlen(str);
    while (len < n) {
        str[len++] = ' ';
    }
    str[len] = '\0';
}

int rech(char* idrech)
{

    product p;

    FILE* file = fopen("ref.txt", "r");
    char line[256];
    char id[20];
    int j=1;
    char test[20];
    if(file==NULL){
             printf("Erreur lors de l'ouverture d'un fichier");

            }
    while (fgets(line, sizeof(line), file)) {
        strncpy(test,line,6);
        if(strcmp(idrech,test)==0){
            fclose(file);
            return 1;
        }

    }

    fclose(file);
      return 0;

}

void modifier(){
    product p;
system("cls");
   char tab[7][20];
    FILE* file = fopen("ref.txt", "r");
    FILE* his = fopen("historique.txt", "a");
    FILE* aux = fopen("temp.txt", "a");
    int ctr=1,c;
    char line[256];
    char num[20];
        puts("\033[1;32m");

    c=1;
    while(c==1){
    c=0;
    printf("\033[0;33mDonner l'ID du produit a modifier(6 CHIFFRES): \n");
    printf("\033[0m");
    gets(num);
    if (strlen(num)==6){
        for (int i=0; i<6;i++){
            if ((num[i]<48)||(num[i]>57)){
               printf("\033[0;31mSaisie incorrecte\n");
                c=1;
                break;
            }
        }}
    else{
        printf("\033[0;31mSaisie incorrecte!\n");
        c=1;}}
 if(rech(num)==1){
    while (fgets(line, sizeof(line), file)) {
        if ((ctr==1)||(ctr==2)){
                fprintf(aux, "%s",line);
            ctr++;
            continue;
        }
        char auxline[100];
        strcpy(auxline,line);

/////////////////////////////////////////////////////////////////////
        char* token = strtok(line, "|");
    int i = 0;
    while (token != NULL) {
        switch (i) {
            case 0:
                strcpy(p.id, token);
                break;
            case 1:
                strcpy(p.categorie, token);
                break;
            case 2:
                strcpy(p.marque, token);
                break;
            case 3:
                strcpy(p.nom, token);
                break;
            case 4:
                strcpy(p.prix, token);
                break;
            case 5:
                strcpy(p.quantite, token);
            case 6:
                strcpy(p.dlc, token);
                break;
        }
        i++;
        token = strtok(NULL, "|");
    }
/////////////////////////////////////////////////////////////////


        if (strcmp(num,p.id)==0){
                int chang=0;
                char res[100];
            product ref;
            printf("\n");
            printf("\033[0;33m");
            printf("\033[0;32mLe produit est :\n");
            printf("ID    |CATEGORIE      |MARQUE         |NOM            |PRIX    |QTE.  |DATE LIM. |\n");
                puts(auxline);
                puts("\033[0m");
            int quit=0;
            do{
            int choice;
            puts("\033[1;32m");
                printf("\n1. Modifier l'Id du produit?\n");
                printf("\n2. Modifier le nom du produit?\n");
                printf("\n3. Modifier la quantite du produit?\n");
                printf("\n4. Modifier le prix unitaire du produit?\n");
                printf("\n5. Quitter?\n");
                printf("\nEntrez votre choix: ");
              puts("\033[0m");
                fflush(stdin);
                scanf("%d", &choice);

                time_t t;
time(&t);






            switch (choice)
    {
    case 1:
    printf("\033[0;36m");
     printf("Entrez la nouvelle Id: (6 CHIFFRES):\n");

 		fflush(stdin);
 		chang=1;
        gets(ref.id);
        add_spaces(ref.id,6);
        strcpy(p.id,ref.id);
         sprintf(res, "%s|%s|%s|%s|%s|%s|%s|\n", ref.id,p.categorie,p.marque,p.nom,p.prix,p.quantite,p.dlc);
         printf(".\033[0;0m");
          fprintf(his, "\nModification de l'ID de produit %s  %s", ref.id,ctime(&t));
          puts("\033[0m");
        fprintf(his,"══════════════════════════════════════════════════════════════════════════════════");
     break;
    case 2:
        printf("\033[0;36m");
     printf("Entrez nouveau nom: (MAX 15 characters):\n");
    	fflush(stdin);
    	chang=1;
        gets(ref.nom);
        add_spaces(ref.nom,15);
        strcpy(p.nom,ref.nom);
        sprintf(res, "%s|%s|%s|%s|%s|%s|%s|\n", p.id,p.categorie,p.marque,ref.nom,p.prix,p.quantite,p.dlc);
        printf(".\033[0;0m");
        fprintf(his, "\nModification de nom de produit %s : %s  %s", p.id,ref.nom,ctime(&t));
        puts("\033[0m");
        fprintf(his,"══════════════════════════════════════════════════════════════════════════════════");
     break;
    case 3:
        printf("\033[0;36m");
     printf("Entrez Quantite: (MAX 999999):\n");
     fflush(stdin);
     chang=1;
    gets(ref.quantite);
    add_spaces(ref.quantite,6);
    strcpy(p.quantite,ref.quantite);
    sprintf(res, "%s|%s|%s|%s|%s|%s|%s|\n", p.id,p.categorie,p.marque,p.nom,p.prix,ref.quantite,p.dlc);
    printf(".\033[0;0m");
    fprintf(his, "\nModification de la quantite de produit %s : %s  %s", p.id,ref.quantite,ctime(&t));
    puts("\033[0m");
        fprintf(his,"══════════════════════════════════════════════════════════════════════════════════");
    break;
    case 4:
        printf("\033[0;36m");
     printf("Entrez le nouveau Prix unitaire de produit: (Max 9999.000)\n");
    scanf("%s",ref.prix);
    chang=1;
    add_spaces(ref.prix,8);
    strcpy(p.prix,ref.prix);
    sprintf(res, "%s|%s|%s|%s|%s|%s|%s|\n", p.id,p.categorie,p.marque,p.nom,ref.prix,p.quantite,p.dlc);
    printf(".\033[0;0m");
    fprintf(his, "\nModification du Prix unitaire de produit %s : %s  %s", p.id,ref.prix,ctime(&t));
    puts("\033[0m");
        fprintf(his,"══════════════════════════════════════════════════════════════════════════════════");
     break;

    case 5:
        quit=1;
        break;

    default:
        printf(".\033[0;0m");
     printf("choix invalide");
     puts("\033[0m");
     break;
    }


            }while (quit!=1);
            if (chang){fprintf(aux,"%s",res);}
            else{fprintf(aux,"%s",auxline);}

    }

        else
        {fprintf(aux, "%s",auxline);}
        ctr++;
    }


 }
else {
        printf("\033[0;31m");
puts("Le produit n existe pas");

return;
}



    fclose(file);
    fclose(his);
    fclose(aux);

    FILE *fp;
    fp = freopen("ref.txt", "w", stdout);
    fclose(fp);
    FILE *src,*dest;
    char buffer[1024];
    size_t bytes;

    src = fopen("temp.txt", "r");
    dest=fopen("ref.txt","w");

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }
    fclose(src);
    fclose(dest);


    FILE *sup;
    sup = freopen("temp.txt", "w", stdout);
    fclose(sup);




///////////////////////////////////////////////////////////////////////////////////////////////////////




}

int main(){
    modifier();
    return 0;
}


