#ifndef _HEADER_MAIN_
#define _HEADER_MAIN_

#define _GNU_SOURCE

/* Include locaux */

/* Include globaux  */

// Basique

#include <features.h>

#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <ctype.h>

// Systeme

#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <fcntl.h>

// Reseau

#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netdb.h>

#define __SEPARATEUR_AVANT_DEBUT_NOUVEAU_CHAMP__  '#'
#define __SEPARATEUR_APRES_DEBUT_NOUVEAU_CHAMP__  ':'
#define __SEPARATEUR_SOUS_CHAMP__                 ','
#define __CARACTERE_FIN_CHAMP__                   ';'
#define __SEPARATEUR_FIN_CHAMP_NB_CHAMP__         '$'

#define __CHAR_NUL__ '0'

/* Exemple : pr nb champs = 2 et nb sous champs = 2 [a_1,a_2,b_1,b_2]

  #2:a_1,a_2;b_1,b_2$

  */

/* Defines */

#define CONTINUER 1
#define BUFFERSIZE 1024
#define BUFFERMIN 128
#define __SUCCESS_ERRNO__ 0
#define __ERROR_CREAT__ -1
#define __ERROR_FORK__ -1
#define __ATTENTE__ sleep(2);
#define __VALEUR_NULLE__ 0

#define POSITION_LECTURE 3
#define _MAP_SIZE_          3
#define _TAILLE_TOTALE_     _MAP_SIZE_*_MAP_SIZE_
#define NB_SOUS_CHAMP 7

/* Enum */

typedef enum
  {
    t_mur=-1,
    t_vide,
  }Type;

/* Structures */
typedef struct Animal
    {
        int dernier_repas;
        unsigned int derniere_reproduction;
        int satiete;
        Type espece;
    }Animal;

typedef struct
    {
        int position;
        Type espece;
        int dernier_repas;
        unsigned int derniere_reproduction;
        int satiete;
    }ANIMAL_RES;

/* Prototypes */
void genererMap(void);
void afficherMap(Animal*);
void afficherMapRes(ANIMAL_RES*);
void supprimer_animal(int position_map);
void ajouter_mur(int position_map);
ANIMAL_RES* dedoublerMap(void);
char* initierMSG(char*);
char* construireMSG(ANIMAL_RES*, char*);
ANIMAL_RES* decomposerMSG(char*);
void fin_programme(void);

/* Extern */

int nb_cases_possedees;
Animal* map;
extern int errno;
extern char **environ;


#endif
