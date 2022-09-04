#ifndef INT_CREATE_H
#define INT_CREATE_H
#include "int_string.h"
int_string create (char ptr[]) {

	int_string numstring;
	int i =0;
	while (ptr[i] != '\0') {
		numstring.value[i] = ptr[i];
		i++;
	}
	numstring.len = i;
	numstring.value[i] ='\0';

	return numstring;
}
#endif
