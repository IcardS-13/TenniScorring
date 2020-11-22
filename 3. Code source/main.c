#include <stdio.h>
#include <stdlib.h>
#include "Scoring.c"

void affichageScore(int score[3][2], int manche, int jeux, int *pointeur_score_player_1, int *pointeur_score_player_2);

int main() {

    char joueur_gagnant;

    int score[3][2] = {{0,0}, {0,0}};
    int count = 0;
    for(count = 0; count <= 2; ++count) {

        int jeux = 1;

        while (1) {

            // initialisation des variables de score
            int score_player_1 = 0;
            int score_player_2 = 0;


            // infinite loop
            while(1)
                {
                    int test=0;

                // affichage
                affichageScore(score, count, jeux, &score_player_1, &score_player_2);

                // on demande à l'arbitre de choisir le joueur qui a marqué le point: touche clavier
                printf("Quel joueur marque un point? (1 ou 2) : ");
                joueur_gagnant = fgetc(stdin);
                // variable servant à recueillir le choix de l'arbitre pour le joueur gagnant


                // on résoue le score et on récupere le résulat
                 resolution_du_score(joueur_gagnant, &score_player_1, &score_player_2, &test);

                 // si l'utilisateur à rentrer une autre valeur que 1 ou 2 on lui redemande de saisir
                if (test==1)
                {
                    printf("\n------------ !! Erreur veuillez choisir 1 ou 2 !! ------------  \n ");

                }


                //lit la valeur d'entrée demandé au dessus, qui s'insère après la saisie de caractères

                joueur_gagnant=getchar();


                if(score_player_1==99) {
                    score[count][0] += 1;
                    break;
                }


                if(score_player_2==99)
                    {
                        score[count][1] += 1;
                        break;
                    }
            }

            jeux++;

            if(score[count][0]==6||score[count][1]==6)
                {
                    break;
                    jeux = 0;
                }
        }
    }
    //calcul de fin des scores

    printf("\n------------------------------------------\n");
    int pt1=0;
    int pt2=0;
    pt1 =  score[0][0] + score[1][0] + score[2][0];
    pt2 =  score[0][1] + score[1][1] + score[2][1];

     if (pt1>pt2)
        {
          printf("joueur 1 gagnant");
        }
     else
        {
          printf("joueur 2 gagnant");
        }

    return 0;
}
 // tableau d'affichage
void affichageScore(int score[6][2], int set, int jeux, int *pointeur_score_player_1, int *pointeur_score_player_2) {
    printf("\n------------------------------------------\n");
    printf(" MATCH - set %d - Jeu %d \n", ++set, jeux );
    printf("------------------------------------------\n");
    printf(" joueur 1 | %d | %d | %d | %d |\n",*pointeur_score_player_1, score[0][0], score[1][0], score[2][0]);
    printf(" joueur 2 | %d | %d | %d | %d |\n",*pointeur_score_player_2, score[0][1], score[1][1], score[2][1]);
    printf("------------------------------------------\n");
}

