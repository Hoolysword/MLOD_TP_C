/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c
 Exécution
 ./prixTuring < turingWinners.txt > out.txt
 Tests
 diff out.txt turingWinners.txt
 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
};

typedef struct{
    int annee;
    char *Nom;
    char *RaisonVictoire;

}winner;
int nb; //variable nb de gagnant;
winner *tab;
winner *readWinners(){
    winner *result=calloc(nb,sizeof(winner));
    for(int i=0;i<nb;i++){
        (result+i)->annee=scanLineAsInt();
		(result+i)->Nom=scanLine();
		(result+i)->RaisonVictoire=scanLine();
    }
	return result;
}
 void printWinners(winner *tab){
	 for(int i=0;i<nb;i++){
		 printf("%i \n",tab[i].annee);
		 printf("%s \n",tab[i].Nom);
		 printf("%s \n",tab[i].RaisonVictoire);
	 }
 }
void infosAnnee(int annee){
    int i=0;
    while(tab[i].annee!=annee){
        i++;
    }
    printf("L'annee %d,le(s) gagnant(s) ont été : %s \n Nature des travaux : %s",annee,tab[i].Nom,tab[i].RaisonVictoire );

}
void tri_annee(winner *tab){
	int i=1;
	while(i!=0){
		i=0;
		for(int j=0;j<nb-1;j++){
			if(tab[j].annee>tab[j+1].annee){
			    winner k=tab[j];
				tab[j]=tab[j+1];
				tab[j+1]=k;
				i++;
			}
		}
	}
}
void addNewWinner(winner* tab){
	nb++;
	tab=(winner*)realloc(tab,nb*sizeof(winner));
	tab[nb-1].annee=2013;
	tab[nb-1].Nom="Robin";
	tab[nb-1].RaisonVictoire="trop fort";

}

int main(void){
    nb=scanLineAsInt();
    tab=readWinners();
	//int nbGagnants = scanLineAsInt();
	//printf("nbGagnants = %i\n",nbGagnants);
    //winner *resultat= readWinners();
	tri_annee(tab);
	addNewWinner(tab);
	printWinners(tab);
    infosAnnee(2003);
	/*for(int i=0;i<nb;i++){
		free((tab+i)->Nom);
		free((tab+i)->Nom);
	}*/
    free(tab);
	return EXIT_SUCCESS;
}
