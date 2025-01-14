#ifndef MY_ARYLIB
#define MY_ARYLIB
void scanf_ary(int* ary);
int print_ary(int* ary, int size);
int findmax_ary(int* ary, int size);
int findmin_ary(int* ary, int size);
int sum_ary(int* ary, int size);
double avg_ary(int* ary, int size);
double var_ary(int* ary, int size, int is_ddof);
int sort_ary(int* ary, int size);
void print_menu(void);
#endif
