#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>
#include <time.h>
#define SECS_PER_DAY 86400
typedef struct date{
    int jj ;
    int mm ;
    int aa ;
}date;
typedef struct produit1{
    char id[100];
    char categorie[15];
    char marque[15];
    char nom[15];
    char prix[100];
    char quantite[100];
    char dlc[20];
}produit1;

void consultdate()
{ system("cls");
  date Date;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,11|FOREGROUND_INTENSITY);
    printf("Consultation des dates de consommation:\nLes produits:\n");
  //
  int day, mois, an;
  time_t now;
  time(&now);
  struct tm *local = localtime(&now);
  day = local->tm_mday;
  mois = local->tm_mon + 1;
  an = local->tm_year + 1900;
  //
    FILE* file = fopen("ref.txt", "r");
    char line[100];
    produit1 p;
    char str[100];

    if(file==NULL)
    {
      printf("Erreur lors de l'ouverture d'un fichier");
    }
    int valide=1;
    while (fgets(line, sizeof(line), file)!= NULL)
     {
        strcpy(str,line);
        char* token = strtok(line,"|");
        int i = 0;
        while (token != NULL)
        {
          switch (i)
           {
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
        token = strtok(NULL,"|");
        }
      if(strcmp(p.dlc,"--/--/----")!=0)
      {
      sscanf(p.dlc,"%d/%d/%d",&Date.jj,&Date.mm,&Date.aa);
      if (Date.jj>0&&Date.mm>0&&Date.aa>0)
      {
      struct tm date1 = { .tm_year = an - 1900, .tm_mon = mois - 1, .tm_mday = day };
      struct tm date2 = { .tm_year = Date.aa - 1900, .tm_mon = Date.mm - 1, .tm_mday = Date.jj };

      time_t t1 = mktime(&date1);
      time_t t2 = mktime(&date2);

      long diff = difftime(t2, t1);

      int days = diff / SECS_PER_DAY;
      if ((days<=30)&&(days>0))
      {
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
        printf("\n%s",str);
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        printf(" Il ne reste que moins de %d jours de consommation.\n ",days);
        valide=0;
      }

      }
      }
    }
    printf("\n");
    fclose(file);
    FILE* f = fopen("ref.txt", "r");
    if(f==NULL)
    {
      printf("Erreur lors de l'ouverture d'un fichier");
    }
     while (fgets(line, sizeof(line), f)!= NULL)
     {
        strcpy(str,line);
        char* token = strtok(line,"|");
        int i = 0;
        while (token != NULL)
        {
          switch (i)
           {
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
        token = strtok(NULL,"|");
        }
    if(strcmp(p.dlc,"--/--/----")!=0)
    {
      sscanf(p.dlc,"%d/%d/%d",&Date.jj,&Date.mm,&Date.aa);
      struct tm date1 = { .tm_year = an - 1900, .tm_mon = mois - 1, .tm_mday = day };
      struct tm date2 = { .tm_year = Date.aa - 1900, .tm_mon = Date.mm - 1, .tm_mday = Date.jj };

      time_t t1 = mktime(&date1);
      time_t t2 = mktime(&date2);

      long diff = difftime(t1, t2);

      int days = diff / SECS_PER_DAY;
      if (days>0)
      {
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
        printf("%s",str);
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
        printf(" Termine depuis %d jours\n ",days);
        valide=0;
      }
      }
    }
    if (valide)
    { HANDLE hConsole;
      hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(hConsole,10|FOREGROUND_INTENSITY);
      printf(" C'est bien, tous les produits possedent plus que 30 jours jusqu'a la date limite de consommation.\n");
    }else
    {
      SetConsoleTextAttribute(hConsole,10|FOREGROUND_INTENSITY);
      printf("\nTous les autres produits possedent plus que 30 jours jusqu'a la date limite de consommation.\n");
    }

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
