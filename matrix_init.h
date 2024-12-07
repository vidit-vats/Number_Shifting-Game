#ifndef MAT_INIT
#define MAT_INIT

#define COLS 4
#define ROWS 4

int compareMatrix(int (*) [COLS]);
int (*convert_into_matrix(int a[]))[COLS];
void display_matrix(int (*) [COLS],int,int);
int (*createArray())[COLS];
void countDownExit();
void swap_value(int*,int*);

#endif


