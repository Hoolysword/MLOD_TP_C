#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CHUNK_SIZE_MAX 5

struct String_block {
	int CHUNK_SIZE;
	struct String* next;
    char* chunk;
};
typedef struct String_block String_b;
typedef String_b* String;

String Chunk_new(char* txt){
    int compteur;
    int longeur=strlen(txt);
    String news=malloc(sizeof(String_b));
        news->CHUNK_SIZE =CHUNK_SIZE_MAX;
        news->next =NULL;
        news->chunk = txt;
	return news;
}

String string_new(char* txt){
    String debut =Chunk_new("");
    String courant =debut;
    int compteur=0;
    int longeur=strlen(txt);
    while(longeur>0){     //la chaine de caractère ne continue pas après le 5eme caractère
        while(longeur>compteur+5){
            compteur=compteur+1
        }
        courant->next=(txt+compteur);
        courant=courant->next;
        longeur=longeur-5;
        compteur=0;
    }
    return debut;
}
void afficheChunk(char* txt) {
	printf("%s ",(char*)txt);
}

void afficheString(String s) {
    	while(s!=NULL){
			afficheChunk(s->chunk);
            s=s->next;
    		
    }
	
}










int main(void){
String s = Chunk_new("HELLO!!!");
afficheString(s);
}