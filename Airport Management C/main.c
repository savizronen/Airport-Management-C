#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AirportManager.h"
#include "Airline.h"
#include "Utils.h"

int main(void) {
	Airport_manager* airport_manager = NULL;
	Airline* airlinePtr = NULL;

	airport_manager = initAirportmanager(airport_manager);
	getNumOfAirportsFromTheUser(airport_manager);

	airlinePtr = initAirline(airlinePtr);

	int choice = 0;
	while (choice != 6) {
		printMenuOptions();
		scanf("%d", &choice);
		getchar();
		switch (choice) {
			case 1:
				getFlightInput(airport_manager, airlinePtr);
				break;
			case 2:
				getAirportInput(airport_manager);
				break;
			case 3:
				printAirline(airlinePtr);
				break;
			case 4:
				printAirportmanager(airport_manager);
				break;
			case 5:
				printFlightsNumberOnAirline(*airlinePtr);
				break;
			case 6:
				freeProgram(airport_manager, airlinePtr);
				break;
		}
	}
	printf("Bye Bye");
}

// ====================================================================

