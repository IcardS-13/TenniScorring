#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Scoring.c"


int main(void){

    int test=0;
    int joueur_gagnant=0;
    int i = 0;
    int score_player_2=0;
    int score_player_1=0;
    srand(time(NULL)); // initialisation de rand
    FILE* fichier = NULL;

    fichier = fopen("Classe de test.txt", "w+");

if (fichier != NULL){
for(i=0; i<1000; i++){

    joueur_gagnant=rand();
    resolution_du_score(joueur_gagnant, &score_player_1, &score_player_2, &test);
    if (joueur_gagnant=='1' || joueur_gagnant=='2' && test==0)
    {
        fputs("PASSED\n", fichier);
    }
    if (joueur_gagnant!='1' || joueur_gagnant!='2' && test==1)
    {
         fputs("PASSED\n", fichier);
    }
    else
    {
         fputs("FAILED\n", fichier);
    }

}
fclose(fichier);
printf("Classe de test termine");

}
return 0;
}
