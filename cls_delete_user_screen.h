#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_user.h"
#include "cls_input_validation.h"
#include <iomanip>

class cls_delete_user_screen : protected cls_screen
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
	static void delete_user_screen()
	{
		_draw_screen_header("Delete User Screen");
		string user_name = cls_input_validation::read_string("Enter User Name: \n");
		cls_user user = cls_user::find(user_name);
		if (user.is_empty())
		{
			cout << "User Name not found, try another one.\n";
			user_name = cls_input_validation::read_string("Enter User Name: ");
		}
		else
		{
			_print_user_info(user);
			char answer = 'n';
			cout << "Are you sure you want to delete this user? [y/n]: ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				user.Delete();
				cout << "User deleted successfully.\n";
				_print_user_info(user);
			}
			else
			{
				cout << "User deletion cancelled.\n";
			}
		}
	}
	};
