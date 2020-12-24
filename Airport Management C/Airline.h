#ifndef Airline_H_
#define Airline_H_

#include "Flight.h"

typedef struct {
	char* company_name;
	int numOfFlights;
	Flight** flights;
	size_t currFlightIndex;
} Airline;

Airline* initAirline(Airline* airline); 

void addFlight(Airline* airline, Flight* flight); 

int checkFlightsOnLine(const Airline airline, char srcPort_IATA[], char destPort_IATA[]); 

void printFlightsNumberOnAirline(const Airline airline);

void freeAirline(Airline* airline); 

void printAirline(const Airline* airline); 

#endif

