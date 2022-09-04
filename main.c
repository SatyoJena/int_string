#include <stdio.h>
#include <string.h>
#include "int_string.h"
#include "create.h"
#include "sum.h"
#include "product.h"


int main() {
	int_string longnum1 = create("349823496234896");
	int_string longnum2 = create("2389657487433");
	
	int_string sum_of2 = sum(longnum1, longnum2);
	printf("sum of these = %s\n",sum_of2.value);
	
	int_string product_of2 = product(longnum2,longnum1);
	printf("product of these = %s\n",product_of2.value);
	
}








