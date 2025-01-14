#if 1
void scanf_ary(int* ary) {
	if (!ary) return;
	printf("�迭 ��� 5���� �Է����ּ���: \n");
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
	printf("| ����� �Լ��� �������ּ��� |\n");
	printf("+----------------------------+\n");
	printf("| 1. ���� �迭�� ���        |\n");
	printf("| 2. �迭 �����ϱ�           |\n");
	printf("| 3. �ִ� ���ϱ�           |\n");
	printf("| 4. �ּڰ� ���ϱ�           |\n");
	printf("| 5. �迭�� �� ���ϱ�        |\n");
	printf("| 6. �迭�� ��� ���ϱ�      |\n");
	printf("| 7. �迭�� ��л� ���ϱ�    |\n");
	printf("| 8. �迭�� ǥ���л� ���ϱ�  |\n");
	printf("| 0. ����                    |\n");
	printf("+----------------------------+\n");
	printf(": ");
}
#endif