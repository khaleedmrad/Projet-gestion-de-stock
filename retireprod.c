#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <wchar.h>
#include <ctype.h>

int main(){
    int a,c,j;
    char ch[10];
    a=0;
    c=1;
    system("cls");
    while(c==1){
        c=0;
        printf("\033[0;33mDonner l'ID du produit(6 CHIFFRES): \n");
        printf("\033[0m");
        gets(ch);
        if (strlen(ch)==6){
            for (int i=0; i<6;i++){
            if ((ch[i]<48)||(ch[i]>57)){
                printf("\033[0;31mSaisie incorrecte\n");
                printf("\033[0m");
                c=1;
                break;
            }
            }}
        else{
            printf("\033[0;31mSaisie incorrecte\n");
            printf("\033[0m");
            c=1;}}
    FILE *file = fopen("ref.txt", "r"),*temp = fopen("temp.txt", "a");
    if (file == NULL) {
        perror("\033[0;31mUnable to open  file");
        printf("\033[0m");
        exit(1);
    }
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        j=0;
        for(int i=0; i<6; i++){
            if(line[i] == ch[i]){
                j++;
            }}
        if (j != 6){
            fputs(line, temp);}
        if (j == 6){
            a=1;  }
    }

    if(a==1){
        printf("\033[0;32mProduit retire avec succes!");
        printf("\033[0m");}
    else{
        printf("\033[0;31mCet ID n'existe pas!!");
        printf("\033[0m");
    }

    fclose(file);
    fclose(temp);

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

    FILE*hist;
    hist=fopen("historique.txt","a");
    time_t t;
    time(&t);
    fprintf(hist,"\nSupression  du  produit  avec  l'ID  %s a la date :   %s", ch, ctime(&t));
    fputs("══════════════════════════════════════════════════════════════════════════════════", hist);
    fclose(hist);
    printf("\n\033[0;35mAppuyer sur entree pour quitter");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".\033[0;0m");
    getchar();
    system("cls");
    return 0;
}
