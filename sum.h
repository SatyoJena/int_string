#ifndef INT_SUM_H
#define INT_SUM_H
#include "int_string.h"
#include "create.h"
#include <string.h>
int_string sum(int_string a, int_string b) {
	int_string *higher ,*lower; 
	if (a.len != b.len) {
		higher = (a.len>b.len)?&a:&b;
		lower  = (a.len<b.len)?&a:&b;
	}
	else {
		higher = &a;
		lower  = &b;
	}
	char lower_copy[32*32], higher_copy[32*32], result_copy[32*32];
	strcpy(lower_copy,lower->value);
	strcpy(higher_copy,higher->value);
	
	//aligning lower with higher
	int i;
	int diff = higher->len - lower->len;
	for (i=0; i<diff; i++) {
		lower_copy[i] = '0';
	}
	for (; i<higher->len; i++) {
		lower_copy[i] = lower->value[i-diff];
	}
	//lets make the sum now
	char result[32*32] = {'\0'};
	int s=0,carry =0;
	for (i=higher->len - 1; i>=0; i--) {
		s = (int)(higher_copy[i] -'0' + lower_copy[i] -'0') + carry;
		result[i] =(char) (s%10 + '0');
		//printf("higher_copy[%d]=%c ,lower_copy[%d]=%c ,result[%d]=%c\n",i,higher_copy[i],i, lower_copy[i],i,result[i]); // a debug line
		carry = (s - s%10)/10;
		s=0;
	}
	strcpy(result_copy,result);
	if (carry == 1) {
		result[0] = '1';
		for (i=1; i<=higher->len; i++) {
			result[i] = result_copy[i-1];
		}
	}
	int_string final = create(result);
	return final;
	
}
#endif