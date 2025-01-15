#if 0
#include <stdio.h>

int main(void)
{
	char input;
	(void)scanf("%c", &input);

	printf("%zu", sizeof(input));

	return 0;
}
#endif

#if 01
#include <stdio.h>

int main(void)
{
	int arr[5];
	printf("sizeof(arr): %d, sizeof(&arr): %d)", sizeof(arr), sizeof(&arr));

	return 0;
}

#endif