#include "function.h"

char groups[13][9] = {  "`123456" ,
					"7890-="  ,
					"~!@#$%^" ,
					"&*()_+"  ,
					"<>?" 	  , 	 
					",./\\"	  ,
					"asdfg",
					"jkl;'",
					"qwer",
					"uiop",
					"tyur",
					"zxcv",
					"bnm",
				  };

int print_menu()
{	int choice, i;
	choice = 0;
	while(1)
	{	clear();
		printw("\n\n");
		print_in_middle(1, 1, 0, "Клавиатурный тренажёр ", NULL);
		printw("\n\n\n");
		for(i = 0;i <= n_groups-2; ++i)
			printw("\t%3d: \nВыполнение %s\n", i + 1, groups[i]);
		printw("\t%3d: \tExit\n", i + 1);
	
		printw("\n\n\tВыберете: ");
		refresh();
		echo();
		scanw("%d", &choice);
		noecho();
	
		if(choice >= 1 && choice <= n_groups + 1)
			break;
		else
		{	attron(A_REVERSE);
			mvprintw(STATUSY, STATUSX, "Некорректный выбор");
			attroff(A_REVERSE);
			getch();
		}
	}
	return choice;
}

void create_test_string(char *test_array, int choice)
{	int i, index, length;
	
	length = strlen(groups[choice]);
	for(i = 0;i <= HSIZE - 1; ++i)
	{	if(i%5 == 0)
			test_array[i] = ' ';
		else
		{	index = (int)(random() % length);
			test_array[i] = groups[choice][index];
		}
	}
	test_array[i] = '\0';
}	

void print_time(time_t start_t, time_t end_t, int mistakes)
{	long int diff;
	int h,m,s;
	float wpm;

	diff = end_t - start_t;
	wpm = ((HSIZE / 5)/(double)diff)*60;

	h = (int)(diff / 3600);
    diff -= h * 3600;
	m = (int)(diff / 60);
	diff -= m * 60;
	s = (int)diff; 
	
	attron(A_REVERSE);
	mvprintw(STATUSY, STATUSX, "Ошибок : %d Времени затрачено: %d:%d:%d WPM : %.2f    Нажмите кнопку что бы продолжить", mistakes, h, m, s, wpm);
	attroff(A_REVERSE);

	refresh();
	getch();

}

void print_in_middle(int startx, int starty, int width, char *string, WINDOW *win)
{	int length, x, y;
	float temp;
	
	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;	
	mvwprintw(win, y, x, "%s", string);
	refresh();
}
