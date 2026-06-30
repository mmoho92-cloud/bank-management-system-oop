#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_user.h"
#include <iomanip>
#include "cls_main_screen.h"
#include "global.h"


class cls_login_screen : protected cls_screen
{
	static bool _login()
	{

		bool login_field = false;

		int counter = 0;
		string user_name, password;
		do
		{
			
			if (login_field)
			{
				counter++; 
				cout << "\nInvalid User Name or Password, Please try again.\n";
				cout << "\nyou lift " <<3 - counter << " chances .\n";
			}
			if (counter == 3)
			{
				cout << "\nYou have exceeded the maximum number of login attempts.\n";
				return false;
			}
			cout << "\nEnter User Name: ";
			cin >> user_name;
			cout << "\nEnter Password: ";
			cin >> password;
			current_user = cls_user::find(user_name, password);
			 
			login_field = current_user.is_empty();

		} while (login_field);
		current_user.add_new_login_register();
		cls_main_screen::show_main_menue();
	}
public:
	static bool show_login_screen()
	{
		system("cls");
		_draw_screen_header("\tLogin Screen");
	
		return _login();
	}
};

