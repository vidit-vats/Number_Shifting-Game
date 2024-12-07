#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include "matrix_init.h"
#include "welcome.h"

extern int max_moves;

int win_matrix[][4] = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,' '}
};

int countdown = 3;
int moves = 0;

static int y,x;

int main(int argc,char *argv[]) {
	int win_status;
	int bx = 3;
	int by = 3;

	int nbx = bx;
	int nby = by;

	int ch;
	int (*gameMatrix)[COLS];

	displayUI(y,x);
	curs_set(0);
	printw("Press 'g' to start: ");
	ch = getch();
	refresh();

	/* ----------------Logic Starts From Here---------------- */

	if(ch == 'g'){
		clear();
		gameMatrix = createArray();
		display_matrix(gameMatrix,nbx,nby);

		while(moves < max_moves){
			ch = getch();
			switch (ch) {
				case(KEY_DOWN):
					nbx = bx - 1;
					nby = by;
					break;

				case(KEY_UP):
					nbx = bx + 1;
					nby = by;
					break;

				case(KEY_RIGHT):
					nby = by - 1;
					nbx = bx;
					break;

				case(KEY_LEFT):
					nby = by + 1;
					nbx = bx;
					break;

				case('e'):
				case('E'):
					countDownExit();
					free(gameMatrix);
					endwin();
					return 0;
			}

			if((nbx >= 0 && nbx < 4) && (nby >= 0 && nby < 4)){
				gameMatrix[bx][by] = gameMatrix[nbx][nby];
				gameMatrix[nbx][nby] = ' ';
				bx = nbx;
				by = nby;
				moves++;
			}

			else if(nbx > bx)
				nbx = bx;
			
			else if(nby > by)
				nby = by;

			else if(nbx <= 0 && nby <= 0){
				nbx = 0;
				nby = 0;
			}

			else if(nbx >=0 && nby <= 0 || nbx <= 0 && nby >= 0){
				nbx = bx;
				nby = by;
			}

			display_matrix(gameMatrix,nbx,nby);
			refresh();

			win_status = compareMatrix(gameMatrix);

			if(win_status == 1){
				printw("You Won in: %d moves :--) ",moves);
				break;
			}
		}
		refresh();
	}

	if (win_status == 0){
		printw("You Lose :( \n");
		refresh();
	}
}

int (*createArray())[COLS]{
	int no;
	int low = 1, high = 15;
	int i,k;
	int a[16];
	int flag = 0;
	int (*mat)[4];

	srand(time(NULL));

	for(i = 0; i < 15; i++){
		no = low + rand() % (high-low+1);

		for(k = i - 1; k >= 0; k--){
			if(no == a[k]){
				i--;
				flag = 1;
				break;
			}

			else
				flag = 0;
		}

		if(flag == 0)
			a[i] = no;
	}

	a[15] = ' ';

	/* Below function call helps in converting the 1D matrix into 2D */
	mat = convert_into_matrix(a);
	return mat;
}

void display_matrix(int (*p) [COLS],int nx,int ny)
{
	clear();
	int row,col;
	attron(A_BOLD);
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(p[i][j] == ' ')
				printw("    ");
			
			else
				printw("  %2d",p[i][j]);

			refresh();
		}
		printw("\n");
		refresh();
	}
		printw("Blank X: (%d,%d)\n",nx,ny);
		printw("Moves: %d\n",moves);
		refresh();
	attroff(A_BOLD);
}

int (*convert_into_matrix(int a[]))[COLS]
{
	int (*p)[4] = (int (*)[4])malloc(ROWS*COLS*sizeof(int));

	for(int i = 0; i < ROWS; i++)
		for(int j = 0; j < COLS; j++)
			p[i] [j] = a[4*i+j];

	return p;
}

void countDownExit()
{
	clear();
	init_pair(2,COLOR_MAGENTA,COLOR_BLACK);
	attron(COLOR_PAIR(2) | A_BOLD);

	while(countdown > 0){
		getyx(stdscr, y, x);
		printw("===>Program will exit in ");
		attron(A_BLINK);
		printw("%d",countdown);
		attroff(A_BLINK);
		printw(" seconds ");
		move(y, x);
		refresh();
		sleep(1);
		countdown--;
	}

	attroff(COLOR_PAIR(2) | A_BOLD);
}

int compareMatrix(int (*gm) [COLS]){
	int i,j;
	int flag = 0;

	for(i = 0; i <= 3; i++){
		for(j = 0; j <= 3; j++){
			if(gm[i][j] == win_matrix[i][j]){
				flag = 1;
				break;
			}

			else{
				flag = 0;
				break;
			}
		}
	}
	refresh();

	return flag;
}
