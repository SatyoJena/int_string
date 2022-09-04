#ifndef INT_PRODUCT_H
#define INT_PRODUCT_H
#include <string.h>
#include "int_string.h"
#include "create.h"
#include "sum.h"

int_string product(int_string x, int_string y) {
	int coefficients[32*32][3];
	int n = x.len;
	int m = y.len;
	int i=0,j=0,k=0;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			coefficients[k][0] = (x.value[i] - '0')*(y.value[j] - '0');
			coefficients[k][1] = (n-1) - i; 
			coefficients[k][2] = (m-1) - j; 
			k++;
		}
	}
	char list_of_coeffs_with_0s[32*32][32*32];
	char individual_coeffs_with_0s[32*32];
	
	for (i=0; i<n*m; i++) {
		//adding first two digits 00 - 81
		individual_coeffs_with_0s[0] = (char)(coefficients[i][0]/10 + '0');
		individual_coeffs_with_0s[1] = (char)(coefficients[i][0]%10 + '0');
		//adding zeros
		for (j=2; j< (coefficients[i][1]+coefficients[i][2]+ 2); j++) {
			individual_coeffs_with_0s[j] ='0';
		}
		individual_coeffs_with_0s[j] ='\0';
		//adding this individual string to the list of strings
		strcpy(list_of_coeffs_with_0s[i], individual_coeffs_with_0s);
	}
	// make the list even termed if it is odd termed
	if ((m*n)%2 != 0) {
		strcpy(list_of_coeffs_with_0s[i],"0");
	}
	// summing every terms
	int_string temp = create("0");
	int_string temp_sum = sum(temp, temp);
	for (i=0; i< (n*m); i++) {
		
		temp = create(list_of_coeffs_with_0s[i]);;
		temp_sum = sum(temp,temp_sum);	
	}
	return temp_sum;
}
#endif











