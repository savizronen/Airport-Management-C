#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Airline.h"
#include "Utils.h"

// ====================================================================

Airline* initAirline(Airline* airline) {
	airline = (Airline*)malloc(sizeof(Airline));
	if (!airline)
	{
		printf("Allocation Failed");
		return NULL;
	}
	airline->company_name = (char*)malloc(sizeof(char));
	airline->numOfFlights = 0;
	airline->currFlightIndex = 0;
	airline->company_name = createDynStr("Airline Name");
	airline->flights = (Flight**)malloc(sizeof(Flight*));

	return airline;
}

// ====================================================================

void addFlight(Airline* airline, Flight* flight) {
	if (airline->currFlightIndex == airline->numOfFlights) {
		airline->numOfFlights += 1;
		airline->flights = (Flight**)realloc(airline->flights, airline->numOfFlights * sizeof(Flight*));
	}
	if (!airline->flights) {
		printf("Allocation Failed");
		return NULL;
	}
	airline->flights[airline->currFlightIndex++] = flight;
}

// ====================================================================

int checkFlightsOnLine(const Airline airline, char srcAirport_IATA[], char destAirport_IATA[]) {
	int numOfFlights = 0;
	for (int i = 0; i < airline.numOfFlights; ++i) {
		if (checkFlight(airline.flights[i], srcAirport_IATA, destAirport_IATA))
			numOfFlights++;
	}
	return numOfFlights;
}

// ====================================================================

void  printFlightsNumberOnAirline(const Airline airline) {
	char* S;
	char* T;
	S = createDynStr("Enter IATA source");
	T = createDynStr("Enter IATA destination");
	printf("Flight number on this line is - %d", checkFlightsOnLine(airline, S, T));
}

// ====================================================================

void freeAirline(Airline* airline) {
	free(airline->company_name);
	for (int i = 0; i < airline->numOfFlights; ++i) {
		freeFlight(airline->flights[i]);
	}
}

// ====================================================================

void printAirline(const Airline* airline) {
	printf("========================\n");
	printf("\n");
	printf("=== AirLine ===\n");
	printf("Name - %s\n", airline->company_name);
	printf("Number Of Flights - %d\n", airline->numOfFlights);
	printf("============\n\n");
	for (int i = 0; i < airline->numOfFlights; i++) {
		printFlight(airline->flights[i]);
		printf("\n");
	}
	printf("========================\n");
}

