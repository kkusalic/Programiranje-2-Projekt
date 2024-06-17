
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "search.h"


void add() {
	FILE* fp = NULL;
	int n;
	MUSIC* musicField = (MUSIC*)malloc(sizeof(MUSIC));
	if (musicField == NULL) {
		perror("field == NULL");
		exit(EXIT_FAILURE);
	}

	printf("Enter name of artist: ");
	scanf(" %50[^\n]", musicField->artist);
	printf("Enter name of album: ");
	scanf(" %50[^\n]", musicField->album);
	printf("Enter name of genre: ");
	scanf(" %50[^\n]", musicField->genre);
	printf("Enter year: ");
	do {

		scanf("%d", &musicField->year);
		getchar();

	} while (musicField->year > 2024);

	printf("\n");

	fp = fopen("musicfile.bin", "rb");
	if (fp == NULL) {
		fp = fopen("musicfile.bin", "wb");
		n = 1;
		fwrite(&n, sizeof(int), 1, fp);
		fwrite(musicField, sizeof(MUSIC), 1, fp);
		fclose(fp);
	}
	else {
		fclose(fp);
		fp = fopen("musicfile.bin", "rb+");
		if (fp == NULL) {
			printf("Error");
		}
		else {
			fseek(fp, 0, SEEK_SET);
			fread(&n, sizeof(int), 1, fp);
			n++;
			fseek(fp, 0, SEEK_SET);
			fwrite(&n, sizeof(int), 1, fp);
			fseek(fp, 0, SEEK_END);
			fwrite(musicField, sizeof(MUSIC), 1, fp);
			fclose(fp);
		}
	}


	fclose(fp);
	free(musicField);


	return;
}





void alphabSort(static MUSIC* musicField, static int n) {
	int j, i;
	MUSIC* temp = (MUSIC*)malloc(n * sizeof(MUSIC));


	for (i = 0; i < n; ++i) {
		for (j = i + 1; j < n; j++) {
			if (strcmp(musicField[i].artist, musicField[j].artist) > 0) {
				strcpy(temp, musicField[i].artist);
				strcpy(musicField[i].artist, musicField[j].artist);
				strcpy(musicField[j].artist, temp);

				strcpy(temp, musicField[i].album);
				strcpy(musicField[i].album, musicField[j].album);
				strcpy(musicField[j].album, temp);

				strcpy(temp, musicField[i].genre);
				strcpy(musicField[i].genre, musicField[j].genre);
				strcpy(musicField[j].genre, temp);

				temp->year = musicField[i].year;
				musicField[i].year = musicField[j].year;
				musicField[j].year = temp->year;
			}
		}
	}
	free(temp);

}



void deleteAlbum() {
	MUSIC* delField = NULL;
	int n, index, flag = 0;
	char s[51];
	FILE* fp = fopen("musicfile.bin", "rb");
	if (fp == NULL) {
		printf("File empty");
		getchar();

		return;
	}
	else {
		fread(&n, sizeof(int), 1, fp);
		delField = (MUSIC*)malloc(n * sizeof(MUSIC));
		if (delField == NULL) {
			perror("field == NULL");
			exit(EXIT_FAILURE);
		}
		else {
			fread(delField, sizeof(MUSIC), n, fp);
			fclose(fp);

			printf("Enter the name of the album you want deleted: \n");
			scanf(" %50[^\n]", s);
			for (int i = 0; i < n; i++) {
				if (strcmp((delField + i)->album, s) == 0) {
					index = i;
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				printf("\nAlbum is not available ");
			}
			else {
				fclose(fp);
				fp = fopen("musicfile.bin", "wb");
				if (fp == NULL) {
					perror("Error");
					exit(EXIT_FAILURE);
				}
				else {
					n--;
					fwrite(&n, sizeof(int), 1, fp);
					for (int i = 0; i < n + 1; i++) {
						if (i == index) {
							continue;
						}
						else {
							fwrite((delField + i), sizeof(MUSIC), 1, fp);
						}
					}
					printf("\nAlbum is deleted\n");
					fclose(fp);
					free(delField);
				}
			}
		}
	}
}


int exitProgram() {
	printf("Do you want to exit?\n");
	printf("\"Y\" for yes,\"n\" for no\n");

	char confirm[2] = { '\0' };


	scanf("%c", confirm);
	getchar();

	if (!strcmp("Y", confirm)) {
		return 0;

	}

	if (confirm == 1) {

		return 0;
	}

	else { return 1; }

}

void deleteFile() {

	printf("Do you want to delete the file?\n");
	printf("\"Y\" for yes,\"n\" for no\n");


	char filename[] = "musicfile.bin";

	char confirm[2] = { '\0' };

	scanf("%c", confirm);
	getchar();

	if (!strcmp("Y", confirm)) {

		remove(filename);
		printf("File deleted.");
		return;
	}


	else {

		printf("File not deleted");
		return;
	}
}







