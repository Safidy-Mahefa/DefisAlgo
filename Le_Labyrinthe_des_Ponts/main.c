#include <stdio.h>
#include <stdlib.h>

int nbLig,nbCol,nbIles,minPonts;

int main()
{
    printf("Entrez n :");
    scanf("%d",&nbLig);
    printf("\n");
    printf("Entrez m :");
    scanf("%d",&nbCol);

    int grille[nbLig][nbCol];
    for(int i = 0; i<nbLig; i++){
        for(int j = 0; j<nbCol;j++){
            printf("grille[%d][%d] :",i,j);
            scanf("%d",&grille[i][j]);
        }
    }
    printf("\n\n");
    //affichage
    for(int i = 0; i<nbLig; i++){
        for(int j = 0; j<nbCol;j++){
            printf(" %d ",grille[i][j]);
        }
        printf("\n");
    }

    //chercher le nombre d'îles par ligne
    int ilesParLig = 0;

    for(int i =0; i<nbLig;i++){
        for(int j = 0; j<nbCol; j++){
            //si occurence = 1, vérifier si voisin gauche = 0 ou null,
            if(grille[i][j] == 1 ){
                //si voisin gauche = 0 ou dépasse la grille, ileParLig++
                if(grille[i][j+1] == 0 || j+1 == nbCol ){
                    //incrementer iles parligne
                    ilesParLig++;
                }
            }
        }
    }
    // chercher le nombre exacte d'iles dans la grille

    //parcourir la grille jusq'à l'avant dernière ligne
    for(int i =0; i<nbLig-1;i++){
         for(int j = 0; j<nbCol; j++){
            //si occurence = 1, vérifier si voisin bas = 1
                //si voisin bas = 1, ilesParLig--
            if(grille[i][j]== 1){
                if(grille[i+1][j] == 1){
                    ilesParLig --;
                }
            }
         }
    }
    nbIles = ilesParLig;

    //chercher le nb minimum de ponts : minPonts = nbIles - 1
    if(nbIles <= 1){
        printf("\nNombre d'ile inferieur ou egal a 1\nMin pont(s) :%d",minPonts);
    }else{
         minPonts = nbIles - 1;
         printf("\nNombre d'ile : %d\nMin pont(s) :%d",nbIles,minPonts);
    }
    printf("\n\n");
    return 0;
}
