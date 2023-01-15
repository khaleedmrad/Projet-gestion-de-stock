#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <wchar.h>
#include <ctype.h>
#include <stdbool.h>

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
        } else if (dot_count == 1  && isdigit(price_str[i])) {
            digits_after_dot++;
        } else if (!isdigit(price_str[i])) {
            return false;
        }
    }
    if (dot_count == 1 || dot_count == 0) {
        return true;
    }
    return false;
}


void ajoutprod() {
    char ch[180],cat[18],m[18],nom[18],qte[6],pr[8],dd1[2],mm1[2],aa1[4],id[180];
    int j,a,c,dd,mm,yy;
    char re,c1,c2,c3,c4;
    c1='|';
    c2=' ';
    c3='/';
    c4='0';

    system("cls");
    /*saisie du id*/
    c=1;
    while(c==1){
    c=0;
    printf("\033[0;33mDonner l'ID du produit(6 CHIFFRES): \n");
    printf("\033[0m");
    gets(ch);
    if (strlen(ch)==6){
        for (int i=0; i<6;i++){
            if ((ch[i]<48)||(ch[i]>57)){
               printf("\033[0;31mSaisie incorrecte\n");
                c=1;
                break;
            }
        }
        FILE *file = fopen("ref.txt", "r");
            if (file == NULL) {
                perror("\033[0;31mUnable to open  file");
                exit(1);}
        char line[100];
        while (fgets(line, sizeof(line), file) != NULL) {
            j=0;
            for(int i=0; i<6; i++){
            if(line[i] == ch[i]){
                j++;
            }
            }
            if (j == 6){
                printf("\033[0;31mCe ID est deja existant!!!\n");
                c=1;
                break;}
        }
    fclose(file);
    }
    else{
        printf("\033[0;31mSaisie incorrecte!\n");
        c=1;}}
    strcpy(id, ch);
    strncat(ch, &c1, 1);





    /*saisie du categorie*/
    c=1;
    while(c==1){
    c=0;
    printf("\033[0;33mDonner la categorie du produit(MAX 15 caracteres) : \n");
    printf("\033[0m");
    gets(cat);
    if (isAlphanumeric(cat)==false){
        printf("\033[0;31mSaisie incorrecte!\n");
        c=1;}
    if (strlen(cat)>15){
        printf("\033[0;31mDepassement de la longeur permise!!\n");
        c=1;}
    }
    for (int i=0; i<strlen(cat); i++){
        if (cat[i]==32){
            cat[i]=95;}}
    for (int i=strlen(cat); i<15; i++){
        strncat(cat, &c2, 1);}
    strncat(cat, &c1, 1);
    strcat(ch,cat);




    /*saisie de la marque*/
    c=1;
    while(c==1){
    c=0;
    printf("\033[0;33mDonner la marque du produit(MAX 15 caracteres) : \n");
    printf("\033[0m");
    gets(m);
    if (isAlphanumeric(m)==false){
        printf("\033[0;31mSaisie incorrecte!\n");
        c=1;}
    if (strlen(m)>15){
        printf("\033[0;31mDepassement de la longeur permise!!\n");
        c=1;}
    }
    for (int i=0; i<strlen(m); i++){
        if (m[i]==32){
            m[i]=95;
        }
    }
    for (int i=strlen(m); i<15; i++){
        strncat(m, &c2, 1);}
    strncat(m, &c1, 1);
    strcat(ch,m);



    /*saisie du nom*/
    c=1;
    while(c==1){
    c=0;
    printf("\033[0;33mDonner le nom du produit(MAX 15 caracteres) : \n");
    printf("\033[0m");
    gets(nom);
    if (isAlphanumeric(nom)==false){
        printf("\033[0;31mSaisie incorrecte!\n");
        c=1;}
    if (strlen(nom)>15){
        printf("\033[0;31mDepassement de la longeur permise!!\n");
        c=1;}
    }
    for (int i=0; i<strlen(nom); i++){
        if (nom[i]==32){
            nom[i]=95;
        }
    }
    for (int i=strlen(nom); i<15; i++){
        strncat(nom, &c2, 1);}
    strncat(nom, &c1, 1);
    strcat(ch,nom);





    /*saisie du prix*/
    c=1;
    while(c==1){
        c=0;
        printf("\033[0;33mDonner le prix unitaire du produit(9999.999DT MAXIMUM): \n");
        printf("\033[0m");
        gets(pr);
        if (is_valid_price(pr)==false){
            printf("\033[0;31mSaisie incorrecte!\n");
            c=1;
        }
        if (strlen(pr)>8){
            printf("\033[0;31mDepassement de la longeur permise!\n");
            c=1;
        }}
    for (int i=strlen(pr); i<8; i++){
        strncat(pr, &c2, 1);}
    strncat(pr, &c1, 1);
    strcat(ch,pr);




    /*saisie de la qte*/
    c=1;
    while(c==1){
        c=0;
        printf("\033[0;33mDonner la quantite du produit(6 CHIFFRES MAXIMUM): \n");
        printf("\033[0m");
        gets(qte);
        if (strlen(qte)<=6){
            for (int i=0; i<strlen(qte); i++){
                if (!((qte[i]>=48)&&(qte[i]<=57))){
                    printf("\033[0;31mSaisie incorrecte\n");
                    c=1;}}}
        else {
            printf("\033[0;31mSaisie incorrecte\n");
            c=1;}}
    for (int i=strlen(qte); i<6; i++){
        strncat(qte, &c2, 1);}
    strncat(qte, &c1, 1);
    strcat(ch,qte);


    /*saisie et verification de la date*/
    a=1;
    while(a==1){
        a=0;
        printf("\033[0;33mEst-ce que le produit a une date limite de consommation?(Y/N)");
        printf("\033[0m");
        scanf("%s", &re);
        if((re=='y')||(re=='Y')){
                            c=1;
                            while(c==1){
                                c=0;
                                printf("\033[0;33mEntrer la date limite de consommation (DD/MM/YYYY format): ");
                                scanf("%d/%d/%d",&dd,&mm,&yy);
                                //check year
                                if(yy>=2023 && yy<=9999){
                                    //check month
                                    if(mm>=1 && mm<=12){
                                        //check days
                                        if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)){
                                            printf("\033[0;32mDate valide.\n");}
                                        else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)){
                                            printf("\033[0;32mDate valide.\n");}
                                        else if((dd>=1 && dd<=28) && (mm==2)){
                                            printf("\033[0;32mDate valide.\n");}
                                        else if((dd==29 && mm==2) && (yy%400==0 ||(yy%4==0 && yy%100!=0))){
                                            printf("\033[0;32mDate valide.\n");}
                                        else{
                                            printf("\033[0;31mJour invalide.\n");
                                            c=1;
                                            }}
                                        else{
                                        printf("\033[0;31mMois invalide.\n");
                                        c=1;
                                        }}
                                else{
                                    printf("\033[0;31mAnnee invalide.\n");
                                    c=1;
                                    }
                                }
                            sprintf(dd1, "%d", dd);
                            if (strlen(dd1)==1){
                                strncat(ch,&c4,1);}
                            strcat(ch,dd1);
                            strncat(ch, &c3,1);
                            sprintf(mm1, "%d", mm);
                            if (strlen(mm1)==1){
                                strncat(ch,&c4,1);}
                            strcat(ch,mm1);
                            strncat(ch, &c3,1);
                            sprintf(aa1, "%d", yy);
                            strcat(ch,aa1);
                            strncat(ch, &c1,1);
                            strcat(ch,"\n");}
        else if (re=='N'||re=='n'){
            strcat(ch,"--/--/----|\n");
        }
        else{
            printf("\033[0;31mEntree invalide!\n");
            a=1;
        }
    }


printf("\033[0;32m&&Produit ajoute avec succes&&\n");
FILE*file;
file=fopen("ref.txt","a");
fputs(ch, file);
fclose(file);
FILE*hist;
hist=fopen("historique.txt","a");
time_t t;
time(&t);
fprintf(hist,"\nAjout   du   produit   avec   l'ID  %s a  la date :   %s", id, ctime(&t));
fputs("══════════════════════════════════════════════════════════════════════════════════", hist);
fclose(hist);
printf("\n\033[0;35mAttend 3 seconds");
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
