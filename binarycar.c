//******************************************************************
//** Written by..: Antonio Urdaneta
//** Date Written: 10/9/2022
//** Purpose.....: Car struct
//******************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define PAUSE system("pause")
#define CLS system("cls")
#define SIZE 100
#define FLUSH myFlush()

typedef struct
{
	char brand[100];
	char model[100];
	int year;
	int price;
	char color[10];

}CAR;

//Prototype
void displayMenu();
void getChoice(char*);
void myFlush();
void addACar(CAR cars[], int* eSize);
void deleteACar(CAR cars[], int* eSize);
void displayCars(CAR cars[], int eSize);
void saveCars(CAR cars[], int eSize);
void loadCars(CAR cars[], int* eSize);


int main(){
	CAR cars[SIZE];
	int eSize = 0;
	char choice;
	loadCars(cars, &eSize);
	do
	{
		getChoice(&choice);
		switch (toupper(choice))
		{
		case 'A': // add a car
			addACar(cars, &eSize);
			break;
		case 'D': // display all cars
			displayCars(cars, eSize);
			break;

		case 'E': // Delete a car
			deleteACar(cars, &eSize);
			break;
		case'Q':// bye bye and save call
			printf("Have a good day\n");
			saveCars(cars, eSize);
			PAUSE;
			exit(0);
			break;
		default:
			printf("Invalid selection\n");
			PAUSE;
			break;
		}

	} while (choice != 'Q');

} // end of main
void addACar(CAR cars[], int* eSize)
{
	if (*eSize == SIZE)
	{
		printf("It is full\n");
		PAUSE;
		return;
	}

	printf("What is the car brand: ");
	scanf("%s", cars[*eSize].brand); FLUSH;
	printf("What is the car model: ");
	scanf("%s", cars[*eSize].model); FLUSH;
	printf("What is the car year.: ");
	scanf("%i", &cars[*eSize].year); FLUSH;
	printf("What is the car price: ");
	scanf("%i", &cars[*eSize].price); FLUSH;
	printf("What is the car color: ");
	scanf("%s", cars[*eSize].color); FLUSH;

	(*eSize)++;
	return;

} // end of addACar

void displayMenu()
{
	CLS;
	printf("Main Menu\n");
	printf("[A]dd a car\n");
	printf("[D]isplay all cars\n");
	printf("[E]rase a car\n");
	printf("[Q]uit\n");
	printf("Enter your choice: ");

} // end of displayMenu

void getChoice(char* choice)
{
	displayMenu();
	scanf("%c", choice); FLUSH;



} // end of getChoice


void displayCars(CAR cars[], int eSize)
{
	CLS;
	printf("----------------------------------------\n");
	for (int i = 0; i < eSize; i++)
	{
		printf("(CAR ID #%i)\n", i);
		printf("Brand of car: %s\n", cars[i].brand);
		printf("Model of car: %s\n", cars[i].model);
		printf("Year of car.: %i\n", cars[i].year);
		printf("Price of car: $%i\n", cars[i].price);
		printf("Color of car: %s\n", cars[i].color);
		printf("----------------------------------------\n");


	} // end of for
	PAUSE;
} // end of displayCars


void saveCars(CAR cars[], int eSize)
{
	FILE* ptr = fopen("cars.b", "wb");
	if (ptr == NULL) {
		printf("File not found");
	}
	fwrite(&eSize, sizeof(int), 1, ptr);
	fwrite(cars, sizeof(CAR), eSize, ptr);
	printf("Data saved\n");
	PAUSE;
	fclose(ptr);

} // end of saveCars

void loadCars(CAR cars[], int* eSize)
{
	FILE* ptr = fopen("cars.b", "rb");
	if (ptr == NULL) {
		printf("File not readable");
	}
	else {
		fread(eSize, sizeof(int), 1, ptr);
		fread(cars, sizeof(CAR), *eSize, ptr);
		printf("Data loaded\n");
		PAUSE;
		fclose(ptr);
	}
}// end of load car

void deleteACar(CAR cars[], int* eSize) {
    int removeCar = 0;

    printf("Enter the ID of which car you'd like to remove: ");
    scanf("%i", &removeCar);

    if (removeCar >= *eSize || removeCar < 0) {
        printf("Invalid Selection\n");
        return;
    } else {
        for (int i = removeCar; i < *eSize - 1; i++) {
            // Shift elements to fill the gap of the removed car
            cars[i] = cars[i + 1];
        }

        printf("Vehicle deleted\n");
        (*eSize)--;
    }

    PAUSE;
}// end of remove car





void myFlush()
{

	while (getchar() != '\n');
}// keyboard flush 0;

