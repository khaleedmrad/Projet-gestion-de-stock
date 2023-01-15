#include <stdio.h>
#include <wchar.h>
#include <windows.h>
void affmenu(){
  system("cls");
FILE*file;
if((file=fopen("ref.txt","r"))==NULL){
  printf("Erreur");
  exit(1);
}else
{
  char line[82];
    while (fgets(line, sizeof(line), file) != NULL)
     {
        printf( "%s" , line );
      }
}
fclose(file);
printf("\n\033[0;35mAppuyer entree pour quitter...\033[0;0m");
getchar();
system("cls");
}
