#include "define.h"

char* initierMSG(char* __msg)
	{
		__msg = malloc(BUFFERSIZE*sizeof(char));
		if ( __msg == NULL )
					exit(EXIT_FAILURE);

					__msg[0] = __SEPARATEUR_AVANT_DEBUT_NOUVEAU_CHAMP__;
					__msg[1] = __CHAR_NUL__ + nb_cases_possedees;
					__msg[2] = __SEPARATEUR_APRES_DEBUT_NOUVEAU_CHAMP__;

			return __msg;
	}

char* construireMSG(ANIMAL_RES* map_res__, char* __msg)
	{
		int i = __VALEUR_NULLE__;
		int __position_read = POSITION_LECTURE;
		Type espece_courante = t_mur;
		int dernier_repas_courant = __VALEUR_NULLE__;
		unsigned int derniere_reproduction_courante = __VALEUR_NULLE__;
		int satiete_courante = __VALEUR_NULLE__;

		__msg = initierMSG(__msg);

		for(i=0; i<nb_cases_possedees ;i++)
			{
				espece_courante									= map_res__[i].espece;
				//printf("espec %i\n",espece_courante);
				dernier_repas_courant						= map_res__[i].dernier_repas;
				//printf("repas %i\n",dernier_repas_courant);
				derniere_reproduction_courante	= map_res__[i].derniere_reproduction;
				//printf("repro %i\n",derniere_reproduction_courante);
				satiete_courante								= map_res__[i].satiete;
				//printf("sat %i\n",satiete_courante);

				if ( espece_courante == t_mur )
					{
						__msg[__position_read++] = '-';
						__msg[__position_read++] = '1';
						__msg[__position_read++] = __SEPARATEUR_SOUS_CHAMP__;
						__msg[__position_read++] = __CHAR_NUL__ + dernier_repas_courant;
						__msg[__position_read++] = __SEPARATEUR_SOUS_CHAMP__;
						__msg[__position_read++] = __CHAR_NUL__ + derniere_reproduction_courante;
						__msg[__position_read++] = __SEPARATEUR_SOUS_CHAMP__;
						__msg[__position_read++] = __CHAR_NUL__ + satiete_courante;
					}
				else
					{
						__msg[__position_read++] = __CHAR_NUL__ + espece_courante;
						__msg[__position_read++] = __SEPARATEUR_SOUS_CHAMP__;
						__msg[__position_read++] = __CHAR_NUL__ + dernier_repas_courant;
						__msg[__position_read++] = __SEPARATEUR_SOUS_CHAMP__;
						__msg[__position_read++] = __CHAR_NUL__ + derniere_reproduction_courante;
						__msg[__position_read++] = __SEPARATEUR_SOUS_CHAMP__;
						__msg[__position_read++] = __CHAR_NUL__ + satiete_courante;
					}

				if ( i == nb_cases_possedees-1 )
						__msg[__position_read++] = __SEPARATEUR_FIN_CHAMP_NB_CHAMP__;
				else
						__msg[__position_read++] = __CARACTERE_FIN_CHAMP__;
			}
		//printf("Msg apres construc %s\n",__msg);
		return __msg;
	}

ANIMAL_RES* decomposerMSG(char* __msg)
	{
		int nb_cases = __VALEUR_NULLE__;
		int i, j = __VALEUR_NULLE__;
		ANIMAL_RES* __map = NULL;

		char
					*str1 = NULL,
					*str2 = NULL,
					*token = NULL,
					*subtoken = NULL,
					*saveptr1 = NULL,
					*saveptr2 = NULL,
					*sous_donnees = NULL,
					**donnees_map = NULL,
					*chaine_temp = NULL;

		//printf("Msg avant for %s\n",__msg);
		//exit(EXIT_FAILURE);

		sous_donnees = malloc(NB_SOUS_CHAMP*sizeof(char));
		// Ne sert qu'au donnees map qui va nous servir à stocker toutes les sous chaines
		// contenant les sous champs (=cases avec infos) du tableau
		if ( sous_donnees == NULL )
			{
				perror("donnes map");
				exit(EXIT_FAILURE);
			}

			chaine_temp = malloc(BUFFERSIZE*sizeof(char));
			if ( chaine_temp == NULL )
			{
				perror("donnes map");
				exit(EXIT_FAILURE);
			}
			//printf("Msg avant strtok %s\n",__msg);
			//exit(EXIT_FAILURE);
			strcpy(chaine_temp,__msg);
			nb_cases = strtok(chaine_temp,"#:")[0] - '0';
			if ( nb_cases <= 0 )
							nb_cases = 100;
			//printf("Après découpage, nb nb_cases vaut %i\n",nb_cases);
			__ATTENTE__

			// On a maintenant le nb_cases, on peut malloquer le gros tableau

			donnees_map = malloc(nb_cases*sizeof(sous_donnees));
			if ( donnees_map == NULL )
			{
				perror("donnees map 2");
				exit(EXIT_FAILURE);
			}

		// On commence naturellement par découper notre message en plusieurs sous champs
		// stockées dans les donnes_map + j (j variant de 0 à nb_cases)

		//printf("Msg avant for %s\n",__msg);
		//exit(EXIT_FAILURE);

   for (i = 1, str1 = __msg; ; i++, str1 = NULL) {
        token = strtok_r(str1, "#:", &saveptr1);
        if (token == NULL)
            break;

       for (j=0,str2 = token; j < nb_cases; j++,str2 = NULL)
				{
            subtoken = strtok_r(str2, ";", &saveptr2);
            if (subtoken == NULL)
                break;
						if ( i == 2 )
							donnees_map[j] = subtoken;
        }
    }

		//printf("On affiche les éléments de la map :\n");
		//__ATTENTE__
		//for(i=0;i<nb_cases;i++)
			//printf("Case %i %s\n",i, *(donnees_map+i));


		// On découpe le reste pour avoir les bonnees données

		__map = malloc(nb_cases*sizeof(ANIMAL_RES));
	for(j=0;j<nb_cases;j++)
	{
		for (i = 1, str1 = *(donnees_map+j); ; i++, str1 = NULL)
			{
	        token = strtok_r(str1, ",", &saveptr1);
	        if (token == NULL)
	            break;
	        //printf("%d: %s\n", i, token);
					if( i == 1)
						{
							if ( token[0] == '-')
									__map[j].espece 							= t_mur;
							else
								__map[j].espece 								= token[0] - '0';
						}
					if( i == 2)
								__map[j].dernier_repas					= token[0] - '0';
					if( i == 3)
								__map[j].derniere_reproduction	= token[0] - '0';
					if( i == 4)
								__map[i].satiete								= token[0] - '0';
	    }
	}
	free(donnees_map);
	free(sous_donnees);
		return __map;
	}
