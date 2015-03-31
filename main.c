#include "define.h"

int main(int argc, char *argv[], char **arge)
{
	atexit(fin_programme);

	ANIMAL_RES* map_res = NULL;
	char* message = NULL;

	viderEcran;

	genererMap();
	map_res = dedoublerMap();
	printf("Voici la map après construction à partir de la map de base ... \n");
	afficherMapRes(map_res);
	entrerPourContinuer
	message = construireMSG(map_res, message);
	printf("Voici le msg à envoyer par le réseau ...\n%s",message);
	entrerPourContinuer
	map_res = decomposerMSG(message);
	printf("\nVoici la map après découpage de la chaine ... (un peu de suspense mdrr)\n");
	afficherMapRes(map_res);
	free(map_res);
	free(message);
	return EXIT_SUCCESS;
}

void fin_programme()
	{

		printf("La prochaine fois, tu feras mieux ! <3\n");
		__ATTENTE__
	}

/* ISO-90 : ligne de fin */
