#include <stdio.h>




int aff() {
    SetConsoleOutputCP(65001);
    FILE *file;
    char c;
    file = fopen("historique.txt", "r");

    if (file == NULL) {
        printf("File does not exist.\n");
        return 0;
    }
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }

    fclose(file);

    printf("\n\033[0;35mAppuyer entree pour quitter...\033[0;0m");
getchar();
system("cls");
}


