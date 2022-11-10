
#include "LinkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TODO NULL;

// retourne vrai si l est vide et faux sinon



void afficheElement(Element e) {
    music* m= (music*)e;
	printf("%s ",(char*)m->name);
	printf("%s ",(char*)m->artist);
	printf("%s ",(char*)m->album);
	printf("%s ",(char*)m->genre);
	printf("%s ",(char*)m->Disc_number);
	printf("%s ",(char*)m->Track_number);
	printf("%s ",(char*)m->Year);
}
void detruireElement(Element e){
music* m= (music*)e;
free(m->name);
free(m->artist);
free(m->album);
free(m->genre);
free(m->Year);
free(m->Disc_number);
free(m->Track_number);
free(m);
}
bool equalsElement(Element e1, Element e2){
	music* m1= (music*)e1;
	music* m2= (music*)e2;
	return (strcmp((char *)m1->name,(char *)m2->name)==0 && strcmp((char *)m1->artist,(char *)m2->artist)==0 && strcmp((char *)m1->album,(char *)m2->album)==0 && strcmp((char *)m1->genre,(char *)m2->genre)==0 && strcmp((char *)m1->Disc_number,(char *)m2->Disc_number)==0 && strcmp((char *)m1->Track_number,(char *)m2->Track_number)==0 && strcmp((char *)m1->Year,(char *)m2->Year)==0);
}

music* newMusic(char* name,char* artist,char* album,char* genre,char* Disc_number,char* Track_number, char* Year){
 	music* newM = malloc(sizeof(music));
	newM->name=strdup(name);
	newM->artist=strdup(artist);
	newM->album=strdup(album);
	newM->genre=strdup(genre);
	newM->Disc_number=strdup(Disc_number);
	newM->Track_number=strdup(Track_number);
	newM->Year=strdup(Year);
    return newM;
}