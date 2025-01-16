
#if 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int map[25 + 2][25 + 2] = { 0 };
int N;
int cnt;
int danji[(25 * 25) / 2];
int danji_cnt;

void input_data(void)
{
	int i, j;
	scanf("%d", &N);
	for (i = 1;i <= N;++i)
	{
		for (j = 1;j <= N;++j)
		{
			scanf("%1d", &map[i][j]);
		}
	}
}

void print_map(void)
{
	int i, j;
	for (i = 1;i <= N;++i)
	{
		for (j = 1;j <= N;++j)
		{
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
}

void solve(void)
{
	int i, j;
	danji_cnt = 0;
	for (i = 1;i <= N;++i)
	{
		for (j = 1;j <= N;++j)
		{
			if (map[i][j] == 1)
			{
				
			}
		}
	}
}

int main(void)
{
	(void)freopen("data_2667.txt", "r", stdin);
	input_data();
	print_map();
	return 0;
}
#endif