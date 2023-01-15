#include <stdio.h>
#include "affiche_menu.c"
#include "ajout.c"
#include "resherche.c"
#include "consultatioon.c"
#include "aff his.c"
#include "logo.c"

void affiche()
{       system("cls");
        puts("\033[1;32m");
        puts("#############################################################");
        puts("#                     __                                    #");
        puts("#      /\\    /\\      |          /\\    /     |     |         #");
        puts("#     /  \\  /  \\     |--       /  \\  /      |     |         #");
        puts("#    /    \\/    \\    |__      /    \\/       |_____|         #");
        puts("#                                                           #");
        puts("#############################################################\n");
        puts("\033[0m");


}



int main()
{
    logofunc();
        int i = 0;
     char options[8][60] = { "1- Afficher le stock", "2- Rechercher un produit", "3- Ajouter un produit","4- Modifier les donnees d'un produit","5- Retirer un produit","6-Consulter les dates limites de consomation des produits","7- Afficher historique","8-Quitter" };
    int n = sizeof(options) / sizeof(options[0]);
    int ch;
    int here;
    while (1)
    {
        affiche();

        printf("Please select an option:\n\n");
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                 wprintf(L"\x1b[31m  >%s\r\n",options[j]);
            else
                printf("    \x1b[34m%s\r\n", options[j]);
                printf("    \x1b[37m\r");
        }
        ch = getch();

        if (ch == 72)
        {
            i--;
            if (i < 0)
                i = n - 1;
        }
        else if (ch == 80)
        {
            i++;
            if (i == n)
                i = 0;
        }
        else if (ch == 13)
        {

            switch(i){
            case 0:
                affmenu();
                break;
            case 1:
                cherchprod();
                break;
            case 2:
                system("cls");
                ajoutprod();
                break;
            case 3:
                system("cls");
                int status = system("cmd.exe /c gcc  modification.c ");
                status = system("cmd.exe /c modification ");
                printf("\n\033[0;35mAppuyer entree pour quitter...\033[0;0m");
                getchar();
                system("cls");
                break;
            case 4:
                system("cls");
                int test = system("cmd.exe /c gcc  retireprod.c ");
                test = system("cmd.exe /c retireprod ");
                printf("\n\033[0;35mAppuyer entree pour quitter...\033[0;0m");
                getchar();
                system("cls");
                break;
            case 5:
                consultdate();
                break;
            case 6:
                system("cls");
                aff();
                break;
            case 7:
                return 0;

            }
        }
    }
    return 0;
}
