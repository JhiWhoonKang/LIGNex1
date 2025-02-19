#if 01

int b;
extern int count;
void print_b(void) {
	printf("B.C : count = %d\n", ++count);
}

#endif