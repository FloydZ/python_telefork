#include "telefork.h"
#include <stdio.h>
#include <math.h>

void f() {
	const float x = sqrtf(2.);
	printf("child: %f\n", x);
}

int main() {
	c_telefork("127.0.0.1:7335", f);	

	int i = 0;
	while(1){
		i++;
	}

	return i;
}
