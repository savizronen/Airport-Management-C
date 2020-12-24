#include <stdio.h>
#include <stdlib.h>

#include "Airport.h"
#include "Utils.h"
#include "AirportManager.h"

# define LEN 4

// ====================================================================

Airport* initAirport() {
	Airport* airport = (Airport*)malloc(sizeof(Airport));
	if (!airport) {
		printf("Allocation Failed");
		return NULL;
	}

	return airport;
}

// ====================================================================

int isAirportEqual(Airport* one, Airport* two) {
	if (isAirport_IATA_Equal(one, two->IATA))
		return 1;
	return 0;
}

int isAirport_IATA_Equal(Airport* airport, char IATA[]) {
	for (int i = 0; i < LEN - 1; ++i) {
		if (airport->IATA[i] != IATA[i]) {
			return 0;
		}
	}
	return 1;
}

// ====================================================================

void freeAirport(Airport* airport) {
	free(airport->name);
	free(airport->country_name);
	for (int i = 0; i < LEN; ++i) {
		free(&airport->IATA[i]);
	}
}

// ====================================================================

void printAirport(const Airport* airport) {
	printf("=== Airport ===\n");
	printf("Name - %s\n", airport->name);
	printf("Country - %s\n", airport->country_name);
	printf("IATA - %s\n", airport->IATA);

}

// ====================================================================

