#ifndef Flight_t_
#define Flight_t_

#include "Airport.h"
#include "Date.h"

typedef struct {
	Airport* src_airport;
	Airport* dest_airport;
	int flight_hour;
	Date date;
} Flight;

Flight* initFlight(); // V

int checkFlight(Flight* flight, char srcPort_IATA[], char destPort_IATA[]); // V

void numOfFlightsOnLine(Flight** flights, char srcPort_IATA[], char destPort_IATA[]); //

void freeFlight(Flight* flight); //

void printFlight(const Flight* flight); // V

#endif

