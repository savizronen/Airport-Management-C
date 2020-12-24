#ifndef AirportManager_H_
#define AirportManager_H_

# define AirportsListSIZE 100

#include "Airport.h"

typedef struct {
	int numOfAirports;
	Airport airports[AirportsListSIZE];
} Airport_manager;

Airport_manager* initAirportmanager();

int addAirport(Airport_manager* airport_manager, Airport* airport);

Airport* findAirport(Airport_manager* airport_manager, char IATA[]);

void freeAirportmanager(Airport_manager* airport_manager);

void printAirportsList(const Airport_manager* airport_manager);

void printAirportmanager(const Airport_manager* airport_manager);

#endif

