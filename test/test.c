#include <function.h>
#include <ctest.h>
#include <stdlib.h>
	
CTEST(check_choice, choice)
{
	int choice1 = 0;
	int choice2 = 3;
	int choice3 = 18;
	
	int check1 = check_choice (choice1);
	int check2 = check_choice (choice2);
	int check3 = check_choice (choice3);
	
	const int expected1 = 0;
	const int expected2 = 1;
	const int expected3 = 0;
	
	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);

}
