#include "function.h"

int main()
{
	int choice, i;
	setlocale(0 , "");
	char *test_array;
	int ch = KEY_F1;
	int mistakes;
	int x, y;
	time_t start_t, end_t;
	WINDOW *typing_win;
	char string[80];
	
	string[0] = '\0';
						
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	intrflush(stdscr, FALSE);
	
	srandom(time(NULL));
	n_groups = sizeof(groups) / sizeof(char *);
	test_array = (char *)calloc(HSIZE + 1, sizeof(char));
	
	while(1)
	{		
		if(ch == KEY_F1)
		{	choice = print_menu();
			choice -= 1;
			if(choice == n_groups)
			{	print_byebye();
				free(test_array);
				endwin();
				exit(0);
			}
		}
		clear();
		strcpy(string, "Level");
		print_in_middle(STARTX, STARTY - 2, LENGTH, string, NULL);
		attron(A_REVERSE);
		mvprintw(STATUSY, STATUSX, "Press F1 to exit the main menu");
		refresh();
		attroff(A_REVERSE);

		create_test_string(test_array, choice);
		typing_win = newwin(WIDTH, LENGTH, STARTY, STARTX);
		keypad(typing_win, TRUE);
		intrflush(typing_win, FALSE);
		box(typing_win, 0, 0);
	
		x = 1;
		y = 1;
		mvwprintw(typing_win, y, x, "%s", test_array);
		wrefresh(typing_win);
		y += 1;
	
		mistakes = 0;
		i = 0;
		time(&start_t);
		wmove(typing_win, y, x);
		wrefresh(typing_win);
		ch = 0;
		while(ch != KEY_F1 && i != HSIZE + 1)
		{	ch = wgetch(typing_win);
			mvwprintw(typing_win, y, x, "%c", ch);
			wrefresh(typing_win);
			++x;
			if(ch == test_array[i])
			{	++i;
				continue;
			}
			else
			{	++mistakes;
				++i;
			}
		}
	
		time(&end_t);
		print_time(start_t, end_t, mistakes);
	}
	free(test_array);
	endwin();
	return 0;
}
		
