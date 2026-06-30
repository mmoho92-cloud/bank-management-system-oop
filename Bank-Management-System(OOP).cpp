
#include <iostream>
#include <vector>
#include <string>
#include "cls_my_string.h";
#include "cls_date.h";
#include "cls_bank_client.h";
#include "cls_input_validation.h";
#include "util.h";
#include "cls_login_screen.h";
using namespace std;


int main()
{
	system("title Bank Management System");
	while (true)
	{
		if (!cls_login_screen::show_login_screen())
		{
			break;
		}
	}

	return 0;
}

