#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AirportManager.h"
#include "Flight.h"
#include "Airport.h"
#include "Utils.h"

// ===============================================

Flight* initFlight() {
	Flight *flight = (Flight*)malloc(sizeof(Flight));
	if (!flight) {
		printf("Allocation Failed");
		return NULL;
	}
	flight->src_airport = (Airport*)malloc(sizeof(Airport));
	flight->dest_airport = (Airport*)malloc(sizeof(Airport));
	flight->flight_hour = 0;
	flight->date.day = 0;
	flight->date.month = 0;
	flight->date.year = 0;

	return flight;
}

// ===============================================

int checkFlight(Flight* flight, char srcAirport_IATA[], char destAirport_IATA[]) {
	if (isAirport_IATA_Equal(flight->src_airport, srcAirport_IATA)
		&& isAirport_IATA_Equal(flight->dest_airport, destAirport_IATA))
		return 1;
	return 0;
}

// ===============================================

void numOfFlightsOnLine(Flight** flights, char srcPort_IATA[], char destPort_IATA[]) {
	int numOfFlights = 0;
	int size = sizeof(flights) / sizeof(flights[0][0]);
	for (int i = 0; i < size; ++i) {
		if (checkFlight(*(flights + i), srcPort_IATA, destPort_IATA)) {
			numOfFlights++;
		}
	}
}

// ===============================================

void freeFlight(Flight* flight) {
	free(flight->src_airport);
	free(flight->dest_airport);
	free(flight);
}

// ===============================================

void printFlight(const Flight* flight) {
	printf("=== Flight ===\n");
	printf("Date - %d / %d / %d\n", flight->date.day, flight->date.month, flight->date.year);
	printf("Hour - %d\n", flight->flight_hour);
	printf("Source Airport - %s\n", flight->src_airport->name);
	printf("Destination Airport - %s\n", flight->dest_airport->name);
	printf("=== ==== ===\n");
}

