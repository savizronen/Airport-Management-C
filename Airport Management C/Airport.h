#ifndef Airport_H_
#define Airport_H_

# define LEN 4

typedef struct {
	char* name;
	char* country_name;
	char IATA[LEN];
} Airport;

Airport* initAirport();

int isAirportEqual(Airport* one, Airport* two); 

int isAirport_IATA_Equal(Airport* airport, char IATA[]); 

void freeAirport(Airport* airport);

void printAirport(const Airport* airport); 

#endif

