#include "telefork.h"
#include <stdio.h>

void f() {
	printf("child\n");
}

int main() {
	c_telefork("127.0.0.1:7335", f);	

	int i = 0;
	while(1){
		i++;
	}

	return i;
}
