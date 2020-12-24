#ifndef UTILS_H_
#define UTILS_H_

#include "AirportManager.h"
#include "Flight.h"
#include "Airline.h"
#include "Airport.h"

int validFlightHour(const int flightHour);

int validIATA(const char ch[]);

char* createDynStr(const char* msg); 

void getNumOfAirportsFromTheUser(Airport_manager* airportmanager);

void printMenuOptions();

char* changeAirportNameToValidName(char* string);

char* concat(const char* s1, const char* s2);

void freeProgram(Airport_manager* airport_manager, Airline* airline);

void getDateInput(Flight* flight);

void getFlightInput(Airport_manager* airport_manager, Airline* airline);

void getAirportInput(Airport_manager* airportmanagerPtr);

#endif
