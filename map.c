#include "define.h"

void genererMap(void)
{
    int i;

    map = malloc(_TAILLE_TOTALE_*sizeof(Animal));

    if ( map == NULL ) { perror("Pas d'alloc de la map"); exit(EXIT_FAILURE); }

        /* si aucunes erreurs */

        for(i=0;i<_TAILLE_TOTALE_;i++)
        {
            if((i+1)%(_MAP_SIZE_)==0 || (i%_MAP_SIZE_)==0||i<_MAP_SIZE_ || i>(_TAILLE_TOTALE_-_MAP_SIZE_) )
            {
                ajouter_mur(i);
            }/* on met un mur*/
            else
            supprimer_animal(i); /* affectation d'un animal vide */
        }
}

void afficherMap(Animal* map)
	{
		int i;
		for(i=0; i<_TAILLE_TOTALE_; i++)
		{
			if( (i+1) % (_MAP_SIZE_) == 0)
				{
					printf("%d\n",map[i].espece);
				}
			else
				{
					printf("%d ",map[i].espece);
				}
		}
	}

void afficherMapRes(ANIMAL_RES* map)
		{
			int i;
			for(i=0; i<_TAILLE_TOTALE_; i++)
			{
				if( (i+1) % (_MAP_SIZE_) == 0)
					{
						printf("%d\n",map[i].espece);
					}
				else
					{
						printf("%d ",map[i].espece);
					}
			}
		}

void supprimer_animal(int position_map)
/* Bien mieux que get animal vide : on prend en compte la position de la map en plus !*/
{
    map[position_map].espece = t_vide;
}

void ajouter_mur(int position_map)
/* Bien mieux que get animal vide : on prend en compte la position de la map en plus !*/
{
    map[position_map].espece = t_mur;
}

ANIMAL_RES* dedoublerMap(void)
    {
        int j;
        Animal animal_courant;
        printf("nb_cases_possedees: %i\n", nb_cases_possedees);
        ANIMAL_RES* map_reseau = malloc(_TAILLE_TOTALE_*sizeof(ANIMAL_RES));
        int espece_courante = __VALEUR_NULLE__;


        if ( map_reseau == NULL )
            {
                perror("malloc map réseau");
                exit(EXIT_FAILURE);
            }

        nb_cases_possedees = 0;
        for(j=0; j<_TAILLE_TOTALE_; j++)
            {
                animal_courant = map[j];
								//animal_courant.id_proprietaire =  __PREMIER_PROPRIO__;

                /*if ( animal_courant.id_proprietaire != __PREMIER_PROPRIO__)
                    continue;*/
                /*else
                        {*/
                        espece_courante = (map+j)->espece;
                            map_reseau[nb_cases_possedees].position              = j;
                            map_reseau[nb_cases_possedees].espece                = espece_courante;
                            //printf("espece:%d\n",map_reseau[nb_cases_possedees].espece);
                            map_reseau[nb_cases_possedees].dernier_repas         = 1;//map[j].dernier_repas;
                            //printf("pos:%d\n",map_reseau[nb_cases_possedees].dernier_repas);
                            map_reseau[nb_cases_possedees].derniere_reproduction = 2;//map[j].derniere_reproduction;
                            //printf("pos:%d\n",map_reseau[nb_cases_possedees].derniere_reproduction);
                            map_reseau[nb_cases_possedees].satiete               = 3;//map[j].satiete;
                            //printf("pos:%d\n",map_reseau[nb_cases_possedees].satiete);
                            nb_cases_possedees++;
                        /*}*/
            }

            printf("nb cases:%d\n",nb_cases_possedees);

        return map_reseau;
    }

/* ISO-90 : ligne de fin */
