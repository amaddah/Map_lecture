#include "define.h"

int main(int argc, char *argv[], char **arge)
{
	atexit(fin_programme);
	ANIMAL_RES* map_res = NULL;
	char* message = NULL;

	genererMap();
	map_res = dedoublerMap();
	printf("Voici la map après construction à partir de la map de base ... \n");
	afficherMapRes(map_res);
	message = construireMSG(map_res, message);
	//strcat(message,"-1,1,2,3;-1,1,2,3;-1,1,2,3;-1,1,2,3;0,1,2,3;-1,1,2,3;-1,1,2,3;-1,1,2,3;-1,1,2,3$");
	printf("Voici la map actuelle sous forme de chaine= %s\n",message);
	__ATTENTE__

	map_res = decomposerMSG(message);

	printf("Voici la map après découpage de la chaine ... (un peu de suspense mdrr)\n");
	__ATTENTE__
	afficherMapRes(map_res);

	return EXIT_SUCCESS;
}

void fin_programme()
	{

		printf("La prochaine fois, tu feras mieux ! <3\n");
		__ATTENTE__
	}

/* ISO-90 : ligne de fin */
