#if 01

#include "a.h"
int a;
//extern int x;
extern int count;
void print_a(void) {
	printf("A.C : a = %d\n", a);
	print_count();
	//printf("A.C : x = %d\n", x);
}

void print_count(void) {
	printf("A.C : count = %d\n", ++count);
}
#endif