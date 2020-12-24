#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AirportManager.h"
#include "Airport.h"
#include "Airline.h"
#include "Flight.h"

// ====================================================================

int validFlightHour(const int flightHour) {
	if (flightHour < 0 || flightHour > 23) {
		return 0;
	}
	return 1;
}

// ====================================================================

int validIATA(const char ch[]) {
	int i;
	for (i = 0; ch[i] != '\0'; i++) {
		if (ch[i] < 65 || ch[i] > 90) {
			printf("Not all the Letters is Uppercase try again \n");
			return 0;
		}
	}
	if (i != 3) {
		printf("IATA is 3 Letters try again \n");
		return 0;
	}
	return 1;
}

// ===============================================

char* createDynStr(const char* msg) {
	char* str;
	char temp[255];
	printf("%s \n", msg);
	scanf("%[^'\n']s", temp);
	getchar();
	str = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	if (str != NULL)
		strcpy(str, temp);

	return str;
}

// ===============================================

char* concat(const char* s1, const char* s2) {
	char* result = malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(result, s1);
	strcat(result, s2);

	return result;
}

// ===============================================

char* changeAirportNameToValidName(char* string) {
	int numberOfWords = 0;
	int len = 0;
	int sumlen = 0;
	char* p = strtok(string, " ");
	char* array[5];
	while (p != NULL) {
		array[numberOfWords++] = p;
		p = strtok(NULL, " ");
	}
	sumlen = sumlen + (numberOfWords * 2);
	//if the len of  the word is even
	for (int z = 0; z < numberOfWords; z++) {
		len = strlen(array[z]);
		sumlen = +len;
		if (len % 2 == 0) {
			for (int r = 0; r < len; r += 2) {
				array[z][r] = toupper(array[z][r]);
			}
		}
	}
	if (numberOfWords == 1) { //only one word
		array[numberOfWords - 1][0] = toupper(array[numberOfWords - 1][0]);
	}
	else {
		//uppercase to all with out the last
		for (int j = 0; j < numberOfWords - 1; j++) {
			array[j][0] = toupper(array[j][0]);
		}
	}
	char* str;
	str = concat(array[0], "  ");
	for (int w = 1; w < numberOfWords; w++) {
		str = concat(str, array[w]);
		str = concat(str, " ");
	}
	return str;
}

// ====================================================================

void freeProgram(Airport_manager* airport_manager, Airline* airline) {
	freeAirline(airline);
	freeAirportmanager(airport_manager);
}

// ====================================================================

void printMenuOptions() {
	printf("\n\n");
	printf("Please choose one of the following options \n");
	printf("1 - Add Flight \n");
	printf("2 - Add Airport \n");
	printf("3 - Print Airline \n");
	printf("4 - Print Airport Manager \n");
	printf("5 - Print flights number on Airline \n");
	printf("6 - Quit \n");
	printf("\n");
}

// ===============================================

void getDateInput(Flight* flight) {
	char* ch;
	char* array[3];
	int day, month, year;
	do {
		ch = createDynStr("Enter Flight Date: yyyy/mm/dd");
		int i = 0;
		char* p = strtok(ch, "/");
		while (p != NULL) {
			array[i++] = p;
			p = strtok(NULL, "/");
		}
		year = atoi(array[0]);
		month = atoi(array[1]);
		day = atoi(array[2]);
	} while (checkDate(day, month, year));

	flight->date.year = year;
	flight->date.month = month;
	flight->date.day = day;
}

// ====================================================================

void getFlightInput( Airport_manager* airport_manager,Airline* airline) {
	Flight *flight= initFlight();

	char* ch;
	int sameAirport = 0;

	do {
		ch = createDynStr("Enter Source IATA :");
		flight->src_airport = findAirport(airport_manager, ch);
	} while (flight->src_airport == NULL || !validIATA(ch));

	do {
		ch = createDynStr("Enter Destination IATA :");
		flight->dest_airport = findAirport(airport_manager, ch);

		sameAirport = flight->dest_airport == flight->src_airport;
		if (sameAirport)
			printf("Destination and Source cannot be the same \n");

	} while (flight->dest_airport == NULL || sameAirport || !validIATA(ch));

	getDateInput(flight);

	do {
		puts("Enter Flight Hour");
		fgets(ch, 3, stdin);
		flight->flight_hour = atoi(ch);
	} while (!validFlightHour(flight->flight_hour));

	addFlight(airline, flight);
}

// ===============================================

void getAirportInput(Airport_manager* airportmanagerPtr) {

	Airport* airport = initAirport();
	char* validStringName = changeAirportNameToValidName(createDynStr("Enter Name:"));
	airport->name = validStringName;
	airport->country_name = createDynStr("Enter Country:");

	char* ch;
	do {
		do {
			ch = createDynStr("Enter IATA Code :");
		} while (!validIATA(ch));

		for (int i = 0; i < 3; i++) { airport->IATA[i] = ch[i]; }
		airport->IATA[3] = '\0';

	} while (!addAirport(airportmanagerPtr, airport));

	printf("Airport Added! \n");
	printf("----------------------------------------- \n");
}

// ====================================================================

void getNumOfAirportsFromTheUser(Airport_manager* airportmanager) {
	int num;
	printf("How many Airports to Create? \n");
	scanf("%d", &num); // fix input not int
	getchar();
	for (int i = 0; i < num; i++) {
		getAirportInput(airportmanager);
	}
}

