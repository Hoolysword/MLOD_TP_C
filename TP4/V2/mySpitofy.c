#include "LinkedListOfMusic.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

music* readMusic(){
    char* ligne=scanLine();
    music* first;
    music* en_cours=first;
	char* name;
	char* artist;
	char* album;
	char* genre;
	int Disc_number;
	int Track_number;
	char* Year;
	Liste music=creer(first);
    while(paslafin){
        char* ligne=scanLine();
		name = strstep(ligne,",");
		artist = strstep(ligne,",");
		album = strstep(ligne,",");
		genre = strstep(ligne,",");
		Disc_number = (int)strstep(ligne,",");
		Track_number = (int)strstep(ligne,",");
		Year = strstep(ligne,",");
		en_cours=newMusic(name,artist,album,genre,Disc_number,Track_number,Year);
		ajoutFin_i(music,en_cours);
			
    }
	

int main(void){




}

