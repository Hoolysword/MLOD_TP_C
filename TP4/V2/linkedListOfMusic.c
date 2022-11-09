#include "LinkedList.h"
#include "LinkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TODO NULL;

// retourne vrai si l est vide et faux sinon

typedef struct {
char* name;
char* artist;
char* album;
char* genre;
int Disc_number;
int Track_number;
char* Year;

}music;

void afficheElement(Element e) {
	printf("%s ",(char*)e.name);
	printf("%s ",(char*)e.artist);
	printf("%s ",(char*)e.album);
	printf("%s ",(char*)e.genre);
	printf("%d ",(int)e.Disc_number);
	printf("%d ",(int)e.Track_number);
	printf("%s ",(char*)e.Year);
}
void detruireElement(Element e){
music* m= (music*)e;
free(e->name);
free(e->artist);
free(e->album);
free(e->genre);
free(e->Year);
free(e);

}
bool equalsElement(Element e1, Element e2){
	music* m1= (music*)e1;
	music* m2= (music*)e2;
	return (strcmp((char *)m1->name,(char *)m2->name)==0 && strcmp((char *)m1->artist,(char *)m2->artist)==0 && strcmp((char *)m1->album,(char *)m2->album)==0 && strcmp((char *)m1->genre,(char *)m2->genre)==0 && (int)m1->Disc_number==(int)m2->Disc_number)==0 && (int)m1->Track_number==(int)m2->Track_number)==0 && strcmp((char *)m1->Year,(char *)m2->Year)==0)
}

music* newMusic(char* name,char* artist,char* album,char* genre,int Disc_number,int Track_number, char* Year){
 	music newM = malloc(sizeof(music));
	newM->name=calloc(strlen(name),sizeof(char));
	newM->artist=calloc(strlen(artist),sizeof(char));
	newM->album=calloc(strlen(album),sizeof(char));
	newM->genre=calloc(strlen(genre),sizeof(char));
	newM->Year=calloc(strlen(Year),sizeof(char));
	newM->name=name;
	newM->artist=artist;
	newM->album=album;
	newM->genre=genre;
	newM->Disc_number=Disc_number;
	newM->Track_number=Track_number;
	newM->Year=Year;
}
}
}