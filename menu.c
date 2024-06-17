#include "header.h"

int menu(void) {


	printf("\n====================");
	printf("Choose one of the options:");
	printf("====================\n");
	printf("\t\t\tOption 1: Add a listened album\n");
	printf("\t\t\tOption 2: Go to submenu\n");
	printf("\t\t\tOption 3: Delete an album\n");
	printf("\t\t\tOption 4: Delete whole file\n");
	printf("\t\t\tOption 5: Exit program\n");
	printf("============================================================================\n");



	unsigned int condition = 0;
	printf("Enter a number: \n");
	do {

		scanf("%d", &condition);
		getchar();

	} while (condition < 1 || condition > 5);


	switch (condition) {

	case addAlbum:

		add();
		break;

	case goToSubmenu:

		submenu();
		break;

	case delAlbum:

		deleteAlbum();
		break;

	case delFile:

		deleteFile();
		break;


	case close:

		condition = exitProgram();
		break;



	default:
		condition = 0;
	}

	return condition;
}

int submenu(void) {

	printf("====================");
	printf("Choose one of the options:");
	printf("====================\n");
	printf("\t\t\tOption 1: Search for artist\n");
	printf("\t\t\tOption 2: Search for genre\n");
	printf("\t\t\tOption 3: Print all albums\n");
	printf("\t\t\tOption 4: Search for album\n");
	printf("\t\t\tOption 5: Search a word\n");
	printf("============================================================================\n");


	int condition = 0;

	do {
		scanf("%d", &condition);
	} while (condition < 1 || condition > 5);

	switch (condition) {

	case printArtist:
		artistPrint();
		break;


	case printGenre:
		genrePrint();
		break;


	case albumPrint:
		printAlbum();
		break;

	case searchAlbum:
		albumSearch();
		break;

	case searchFile:
		searchWhole();
		break;

	default:

		condition = 0;
	}

	return;
}