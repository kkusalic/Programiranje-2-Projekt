
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "search.h"

void artistPrint() {
	char artist[51];
	int n, i, flag = 0, index = 0;

	FILE* fp = fopen("musicfile.bin", "rb");
	if (fp == NULL) {
		printf("File empty");
		getchar();

		return;
	}

	fread(&n, sizeof(int), 1, fp);

	MUSIC* fieldSearch = (MUSIC*)malloc(n * sizeof(MUSIC));

	if (fieldSearch == NULL) {
		perror("field == NULL");
		exit(EXIT_FAILURE);
	}

	printf("Enter artist's name: ");
	scanf(" %50[^\n]", artist);
	printf("\n");
	fread(fieldSearch, sizeof(MUSIC), n, fp);
	for (int i = 0; i < n; i++) {
		if (strcmp((fieldSearch + i)->artist, artist) == 0) {
			index++;
			if (index == 1) {
				printf("%s albums:\n", artist);
			}
			printf("\nAlbum: %s", (fieldSearch + i)->album);
			printf("\nGenre: %s", (fieldSearch + i)->genre);
			printf("\nYear: %d\n", (fieldSearch + i)->year);
			flag = 1;

		}
	}
	if (flag == 0) {
		printf("No %s albums found", artist);
	}
	fclose(fp);
	free(fieldSearch);
	getchar();

}

void genrePrint() {
	char genre[51];
	int n, i, flag = 0, index = 0;

	FILE* fp = fopen("musicfile.bin", "rb");
	if (fp == NULL) {
		printf("File empty");
		getchar();

		return;
	}

	fread(&n, sizeof(int), 1, fp);

	MUSIC* fieldSearch = (MUSIC*)malloc(n * sizeof(MUSIC));
	if (fieldSearch == NULL) {
		perror("field == NULL");
		exit(EXIT_FAILURE);
	}
	printf("Enter genre name: ");
	scanf(" %50[^\n]", genre);
	printf("\n");
	fread(fieldSearch, sizeof(MUSIC), n, fp);
	alphabSort(fieldSearch, n);

	for (int i = 0; i < n; i++) {
		if (strcmp((fieldSearch + i)->genre, genre) == 0) {
			index++;
			if (index == 1) {
				printf("%s albums\n", genre);
			}
			printf("\nArtist: %s", (fieldSearch + i)->artist);
			printf("\nAlbum: %s", (fieldSearch + i)->album);
			printf("\nYear: %d\n", (fieldSearch + i)->year);
			flag = 1;

		}
	}
	if (flag == 0) {
		printf("No %s albums found", genre);
	}
	fclose(fp);
	free(fieldSearch);
	getchar();

}

void printAlbum() {
	int n, i;
	FILE* fp = NULL;
	MUSIC* fieldPrint = NULL;
	fp = fopen("musicfile.bin", "rb");
	if (fp == NULL) {
		printf("File empty");
		getchar();

		return;
	}
	fread(&n, sizeof(int), 1, fp);
	if (n == 0) {
		printf("File empty\n\n");
		getchar();

		return;
	}
	fieldPrint = (MUSIC*)malloc(n * sizeof(MUSIC));
	if (fieldPrint == NULL) {
		perror("field == NULL");
		exit(EXIT_FAILURE);
	}
	fread(fieldPrint, sizeof(MUSIC), n, fp);

	alphabSort(fieldPrint, n);


	printf("%d albums in file", n);

	for (i = 0; i < n; i++) {
		printf("\n\nArtist: %s", (fieldPrint + i)->artist);
		printf("\nAlbum: %s", (fieldPrint + i)->album);
		printf("\nGenre: %s", (fieldPrint + i)->genre);
		printf("\nYear: %d", (fieldPrint + i)->year);
	}
	fclose(fp);
	free(fieldPrint);
	getchar();


	return;
}

void albumSearch() {
	char searchedWord[51];
	int n, i, flag = 0;
	FILE* fp = fopen("musicfile.bin", "rb");
	if (fp == NULL) {
		printf("File empty");
		getchar();

		return;

	}

	fread(&n, sizeof(int), 1, fp);

	MUSIC* fieldSearch = (MUSIC*)malloc(n * sizeof(MUSIC));
	if (fieldSearch == NULL) {
		perror("field == NULL");
		exit(EXIT_FAILURE);
	}
	printf("Enter album: ");
	scanf(" %50[^\n]", searchedWord);
	fread(fieldSearch, sizeof(MUSIC), n, fp);

	for (int i = 0; i < n; i++) {
		if (strcmp((fieldSearch + i)->album, searchedWord) == 0) {
			printf("\nArtist %s", (fieldSearch + i)->artist);
			printf("\nAlbum: %s", (fieldSearch + i)->album);
			printf("\nGenre: %s", (fieldSearch + i)->genre);
			printf("\nYear: %d\n\n", (fieldSearch + i)->year);
			flag = 1;
			printf("Album found\n");
		}
	}


	if (flag == 0) {
		printf("Album not found");
	}
	fclose(fp);
	free(fieldSearch);
	getchar();


}

void searchWhole() {

	char search[51];
	int n, i, flag = 0;

	FILE* fp = fopen("musicfile.bin", "rb");
	if (fp == NULL) {
		printf("File empty");
		getchar();

		return;
	}

	fread(&n, sizeof(int), 1, fp);

	MUSIC* fieldSearch = (MUSIC*)malloc(n * sizeof(MUSIC));
	if (fieldSearch == NULL) {
		perror("field == NULL");
		exit(EXIT_FAILURE);
	}
	printf("Enter searched word: ");
	scanf(" %50[^\n]", search);
	fread(fieldSearch, sizeof(MUSIC), n, fp);
	alphabSort(fieldSearch, n);
	for (int i = 0; i < n; i++) {
		if (strcmp((fieldSearch + i)->artist, search) == 0) {
			printf("\nArtist %s", (fieldSearch + i)->artist);
			printf("\nAlbum: %s", (fieldSearch + i)->album);
			printf("\nGenre: %s", (fieldSearch + i)->genre);
			printf("\nYear: %d\n", (fieldSearch + i)->year);
			flag = 1;

		}
		else if (strcmp((fieldSearch + i)->album, search) == 0) {
			printf("\nArtist  %s", (fieldSearch + i)->artist);
			printf("\nAlbum: %s", (fieldSearch + i)->album);
			printf("\nGenre: %s", (fieldSearch + i)->genre);
			printf("\nYear: %d\n", (fieldSearch + i)->year);
			flag = 1;

		}
		else if (strcmp((fieldSearch + i)->genre, search) == 0) {
			printf("\nArtist %s", (fieldSearch + i)->artist);
			printf("\musicField: %s", (fieldSearch + i)->album);
			printf("\nGenre: %s", (fieldSearch + i)->genre);
			printf("\nYear: %d\n", (fieldSearch + i)->year);
			flag = 1;

		}

	}

	if (flag == 0) {
		printf("Nothing found");
	}

	fclose(fp);
	free(fieldSearch);
	getchar();

}
