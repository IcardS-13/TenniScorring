#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Scoring.c"


const int max_size = 5;
const int taille =103;
const char set[] = "azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN1234567890&""'(-_)=$*!:;,?./��%��+�<>}]@^\\`|[{#~�"; // 103 caract�res
int test=0;


int main()
{
    int b=0;
    int i = 0;
    int score_player_2=0;
    int score_player_1=0;
    srand(time(NULL)); // initialisation de rand
    FILE* fichier = NULL;
    char joueur_gagnant[max_size];
    time(NULL);


    FILE *fp = fopen("classe_de_test_char.txt", "w+");

    if ( fp == NULL )
        {
            fputs("Le fichier texte.txt n'a pas pu �tre ouvert\n", stderr);
            return -1;
        }
for(b=0; b<10000; b++)
{
       for (int j = 0; j < 5; j++ )
        {
            i = rand()%taille;
            joueur_gagnant[j] = set[i];
            resolution_du_score(joueur_gagnant, &score_player_1, &score_player_2, &test);
        }

        if (joueur_gagnant=='1' || joueur_gagnant=='2' && test==0)
        {
            fprintf(fp,"PASSED\n");
        }

        if (joueur_gagnant!='1' || joueur_gagnant!='2' && test==1)
        {
            fprintf(fp,"PASSED\n");
        }

        else
        {
            fprintf(fp,"FAILED\n");
        }

}
    printf("fin de la classe de test");
    fclose(fp);
    return 0;
}

