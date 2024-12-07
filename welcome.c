#include <ncurses.h>
#include <locale.h>
#include "welcome.h"

int max_moves = 10;

int wm[][4] = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,' '}
};

void displayUI(int x,int y)
{
		setlocale(LC_ALL,"");
		int ch;
		initscr();
		cbreak();
		noecho();
		curs_set(1);
		refresh();
		keypad(stdscr,TRUE);

		attron(A_BOLD | A_UNDERLINE);
		printw("****************RULES OF THE GAME****************\n\n");
		attroff(A_BOLD | A_UNDERLINE);

		attron(A_BOLD);
		printw("1)You can move only 1 step at a time by using following arrow keys: -\n");
		printw("Move Up    : by using \u2191\n");
		printw("Move Down  : by using \u2193\n");
		printw("Move Left  : by using \u2190\n");
		printw("Move Right : by using \u2192\n\n");

		printw("2)You can move number at empty position only\n\n");

		printw("3)For each valid move : your total moves will decrease by 1\n\n");
		printw("4)Winning Situation: Numbers in 4x4 matrix should be in order from 1 to 15\n\n");
		printw("5)You can exit the game at any time by pressing 'e' OR 'E':-\n\n");
		attroff(A_BOLD);

		getyx(stdscr,y,x);

		attron(A_BOLD | A_UNDERLINE);
		mvprintw(y+1,x+10,"********Winning Situation********\n");
		attroff(A_BOLD | A_UNDERLINE);

		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++)
				printw("  %2d",wm[i][j]);
			printw("\n");
		}
		attron(A_BOLD);
		printw("\n==>Try Winning the game in the minimum moves possible\n");
		attroff(A_BOLD);

		printw("==>Total Moves Allowed: %d\n",max_moves);

		start_color();
		init_pair(1,COLOR_YELLOW,COLOR_BLACK);
		attron(COLOR_PAIR(1) | A_BOLD);
		mvprintw(getcury(stdscr)+2,getcurx(stdscr),"Happy Gaming,Good Luck\n");
		attroff(COLOR_PAIR(1) | A_BOLD);
}
