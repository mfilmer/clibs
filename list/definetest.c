
#include <stdio.h>


#define DEF alphabet


typedef struct {
	int number;
} alphabet;




int main() {
	alphabet alpha;
	alpha.number = 5;
	printf("number: %d", alpha.number);
	return 0;
}