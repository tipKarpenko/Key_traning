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
