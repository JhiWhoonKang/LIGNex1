#if 1
void scanf_ary(int* ary) {
	if (!ary) return;
	printf("배열 요소 5개를 입력해주세요: \n");
	for (int i = 0; i < 5; ++i)
		scanf("%d", ary + i);
}

int print_ary(int* ary, int size) {

	if (!ary) {
		printf("print_ary(): Error: array is NULL\n");
		return -1;
	}
	printf("array contents: ");
	for (int i = 0; i < size; ++i) {
		printf("%d ", ary[i]);
	}
	printf("\n");
	return 0;
}

int findmax_ary(int* ary, int size) {
	int mx;

	if (!ary) {
		printf("findmax_ary(): Error: array is NULL\n");
		return -1;
	}
	mx = ary[0];
	for (int i = 1; i < size; ++i) {
		if (ary[i] > mx)
			mx = ary[i];
	}
	return mx;
}

int findmin_ary(int* ary, int size) {
	int mx;

	if (!ary) {
		printf("findmin_ary(): Error: array is NULL\n");
		return -1;
	}
	mx = ary[0];
	for (int i = 1; i < size; ++i) {
		if (ary[i] < mx)
			mx = ary[i];
	}
	return mx;
}

int sum_ary(int* ary, int size) {
	int sum;

	if (!ary) {
		printf("sum_ary(): Error: array is NULL\n");
		return -1;
	}
	sum = ary[0];
	for (int i = 1; i < size; ++i) {
		sum += ary[i];
	}
	return sum;
}

double avg_ary(int* ary, int size) {
	double sum;

	if (!ary) {
		printf("avg_ary(): Error: array is NULL\n");
		return -1;
	}
	if (size == 0) {
		printf("avg_ary(): Error: array size is zero\n");
		return -1;
	}
	sum = ary[0];
	for (int i = 1; i < size; ++i) {
		sum += ary[i];
	}
	return sum / size;
}

double var_ary(int* ary, int size, int is_ddof) {
	double avg;
	double sum = 0;

	if (!ary) {
		printf("var_ary(): Error: array is NULL\n");
		return -1;
	}
	if (size == 0 || (is_ddof && size == 1)) {
		printf("var_ary(): Error: array size error\n");
		return -1;
	}
	avg = avg_ary(ary, size);
	for (int i = 0; i < size; ++i) {
		sum += (ary[i] - avg) * (ary[i] - avg);
	}
	return sum / (size - is_ddof);
}

static void my_swap(int* a, int* b) {
	int temp = *a;

	*a = *b;
	*b = temp;
	return;
}

int sort_ary(int* ary, int size) {

	if (!ary) {
		printf("sort_ary(): Error: array is NULL\n");
		return 1;
	}
	for (int i = 0; i < size - 1; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (ary[i] > ary[j]) {
				my_swap(ary + i, ary + j);
			}
		}
	}
	return 0;
}

void print_menu(void) {
	printf("+----------------------------+\n");
	printf("| 사용할 함수를 선택해주세요 |\n");
	printf("+----------------------------+\n");
	printf("| 1. 현재 배열값 출력        |\n");
	printf("| 2. 배열 정렬하기           |\n");
	printf("| 3. 최댓값 구하기           |\n");
	printf("| 4. 최솟값 구하기           |\n");
	printf("| 5. 배열의 합 구하기        |\n");
	printf("| 6. 배열의 평균 구하기      |\n");
	printf("| 7. 배열의 모분산 구하기    |\n");
	printf("| 8. 배열의 표본분산 구하기  |\n");
	printf("| 0. 종료                    |\n");
	printf("+----------------------------+\n");
	printf(": ");
}
#endif