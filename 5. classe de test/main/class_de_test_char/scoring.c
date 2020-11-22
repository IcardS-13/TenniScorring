#include <stdio.h>
#include <stdlib.h>

//Déclaration des fonctions
int resolution_du_score(int joueur_gagnant, int *pointeur_score_player_1, int *pointeur_score_player_2,int *pointeur_test);
int get_next_score(int point);
int get_egal_score(int point);

//fonction traitant du scoring
int resolution_du_score(int joueur_gagnant, int *pointeur_score_player_1, int *pointeur_score_player_2,int *pointeur_test)

{
if (joueur_gagnant=='1'|| joueur_gagnant=='2')
{


     // si on appuie sur la touche 1 ajouter un point au joueur 1
   if (joueur_gagnant=='1')
	{   // on test si il y a egalité (40-40)
		if(*pointeur_score_player_1==*pointeur_score_player_2 && *pointeur_score_player_1==40)
		{
			*pointeur_score_player_1 = get_egal_score(*pointeur_score_player_1);
		}
		//on test si il y a avantage
		else if(*pointeur_score_player_1==40 && *pointeur_score_player_2==50 )
        {
            *pointeur_score_player_2 = get_egal_score(*pointeur_score_player_2);
        }
		//sinon on ajoute un point classique au joueur 1
		else
		{
			*pointeur_score_player_1 = get_next_score(*pointeur_score_player_1);
		}

	}

     // si on appuie sur la touche 2 ajouter un point au joueur 2
	if (joueur_gagnant=='2')
	{    // on test si il y a egalité (40-40)
		if(*pointeur_score_player_1==*pointeur_score_player_2 && *pointeur_score_player_1==40)
		{
			*pointeur_score_player_2 = get_egal_score(*pointeur_score_player_2);
		}
		//on test si il y a avantage
		else if(*pointeur_score_player_2==40 && *pointeur_score_player_1==50 )
        {
            *pointeur_score_player_1 = get_egal_score(*pointeur_score_player_1);
        }
		//sinon on ajoute un point classique au joueur 2
		else
		{
			*pointeur_score_player_2 = get_next_score(*pointeur_score_player_2);
		}
	}
	return 0;
	*pointeur_test=0;
}
	else
    {
        *pointeur_test=1;

    }
return 0;
}





//cette fonction permet de gerer l'ajout de point "classique"
//Si la fonction retour 99 alors on a "JEU"
int get_next_score(int point)
{
	switch(point)
	{
		case 0:
			return 15;
			break;

		case 15:
			return 30;
			break;

		case 30:
			return 40;
			break;

		default:
			return 99;
			break;
	}
}

//cette fonction permet de gerer le cas de l'egalité
int get_egal_score(int point)
{
	if (point==40)
	{
		return 50;
	}
	else
	{
		return 40;
	}
}
