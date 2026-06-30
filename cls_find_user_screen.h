#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_user.h"
#include "cls_input_validation.h"
#include <iomanip>

class cls_find_user_screen : protected cls_screen
{
	static void _print_user_info(cls_user user)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nUser Name: " << user.user_name;
		cout << "\nFirst Name: " << user.first_name;
		cout << "\nLast Name: " << user.last_name;
		cout << "\nFull Name: " << user.get_full_name();
		cout << "\nEmail: " << user.email;
		cout << "\nPhone: " << user.phone;
		cout << "\nPassword: " << user.password;
		cout << "\nPermissions: " << user.permissions;
		cout << "\n___________________\n";

	}

public:
	static void find_user_screen()
	{
		_draw_screen_header("Find User Screen");
		string user_name = cls_input_validation::read_string("Enter User Name: \n");
		cls_user user = cls_user::find(user_name);
		while (user.is_empty())
		{
			cout << "User Name not found, try another one.\n";
			user_name = cls_input_validation::read_string("Enter User Name: \n");
		}


		_print_user_info(user);

	}
};

