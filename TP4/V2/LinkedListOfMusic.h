#include "LinkedList.h"
#pragma once


typedef struct {
char* name;
char* artist;
char* album;
char* genre;
int Disc_number;
int Track_number;
char* Year;

}music;

music* newMusic(char* name,char* artist,char* album,char* genre,int Disc_number,int Track_number, char* Year)