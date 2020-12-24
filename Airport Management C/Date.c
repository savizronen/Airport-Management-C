#include <stdio.h>
#include <stdlib.h>
#include "Date.h"

static int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

// ====================================================================

int checkDate(int day, int month, int year) {
	if (1900 > year) { // year
		return 0;
	}
	if (daysInMonth[month - 1] > day || 1 < day) { //days
		return 0;
	}
	if (1 > month || month > 12) { //month
		return 0;
	}

	return 1;
}

