
#define _CRT_SECURE_NO_WARNINGS

#pragma once

typedef struct music {
	unsigned int year;
	char album[51];
	char artist[51];
	char genre[51];
}MUSIC;


enum menu {


	addAlbum = 1,
	goToSubmenu = 2,
	delAlbum = 3,
	delFile = 4,
	close = 5,
};

enum sub {


	printArtist = 1,
	printGenre = 2,
	albumPrint = 3,
	searchAlbum = 4,
	searchFile = 5,
};

void add(void);
void deleteAlbum(void);
int exitProgram(void);
void deleteFile(void);
void alphabSort(static MUSIC* field, static int n);




