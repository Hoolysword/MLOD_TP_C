#include "LinkedList.h"
#pragma once


typedef struct {
char* name;
char* artist;
char* album;
char* genre;
char* Disc_number;
char* Track_number;
char* Year;

}music;

music* newMusic(char* name,char* artist,char* album,char* genre,char* Disc_number,char* Track_number, char* Year);