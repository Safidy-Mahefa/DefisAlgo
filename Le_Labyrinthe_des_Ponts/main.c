#include <stdio.h>
#include <stdlib.h>

int nbLig,nbCol,nbIles,minPonts;

int main()
{
    printf("Entrez le nombre de ligne :");
    scanf("%d",&nbLig);
    printf("\n");
    printf("Entrez le nombre de colonne :");
    scanf("%d",&nbCol);

    int grille[nbLig][nbCol];
    for(int i = 0; i<nbLig; i++){
        for(int j = 0; j<nbCol;j++){
            printf("grille[%d][%d] :",i,j);
            scanf("%d",&grille[i][j]);
        }
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
    printf("Iles par ligne : %d", ilesParLig);

    // chercher le nombre exacte d'iles dans la grille

    //parcourir la grille jusq'àl'avant dernière ligne
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
    printf("Le nombre d'iles dans la grille est : %d",nbIles);

    //chercher le nb minimum de ponts : minPonts = nbIles - 1
    if(nbIles <= 1){
        minPonts = 0;
    }else{
         minPonts = nbIles - 1;
    }
    printf("Le nombre minimum de ponts pour relier %d iles est : %d",nbIles,minPonts);


    //affichage
    return 0;
}
