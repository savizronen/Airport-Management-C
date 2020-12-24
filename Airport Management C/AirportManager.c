#include <stdio.h>
#include <stdlib.h>

#include "Airport.h"
#include "Airline.h"
#include "Utils.h"

// ====================================================================

Airport_manager* initAirportmanager() {
	Airport_manager* airport_manager = (Airport_manager*)malloc(sizeof(Airport_manager));
	if (!airport_manager)
	{
		printf("Allocation Failed");
		return NULL;
	}
	airport_manager->numOfAirports = 0;

	return airport_manager;
}

// ====================================================================

int addAirport(Airport_manager* airport_manager, Airport* airport) {
	int size = airport_manager->numOfAirports;
	for (int i = 0; i < size; i++) {
		if (isAirportEqual(&airport_manager->airports[i], airport)) {
			printf("IATA found - Airport Exists\n");
			return 0;
		}
	}
	airport_manager->airports[airport_manager->numOfAirports++] = *airport;
	return 1;
}

// ====================================================================

Airport* findAirport(Airport_manager* airport_manager, char IATA[]) {
	int size = airport_manager->numOfAirports;
	Airport* airportPtr = NULL;
	for (int i = 0; i < size; i++) {
		if (isAirport_IATA_Equal(&airport_manager->airports[i], IATA))
			return	airportPtr = &airport_manager->airports[i];
	}
	return airportPtr;
}

// ====================================================================

void freeAirportmanager(Airport_manager* airport_manager) {
	free(airport_manager);
}

// ====================================================================

void printAirportsList(const Airport_manager* airport_manager) {
	int size = airport_manager->numOfAirports;
	for (int i = 0; i < size; i++) {
		printf("=== %d ===\n", i + 1);
		printf("Name - %s\n", airport_manager->airports[i].name);
		printf("IATA - %s\n", airport_manager->airports[i].IATA);
	}
	printf("\n");
}

// ====================================================================

void printAirportmanager(const Airport_manager* airport_manager) {
	printf("==================================\n\n");
	printf("=== Airport Manager ===\n");
	printf("Number Of Airports - %d\n", airport_manager->numOfAirports);
	printf("\n");
	printAirportsList(airport_manager);
	printf("==================================\n");

}
