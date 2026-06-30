#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_input_validation.h"
#include "cls_user.h"
#include <iomanip>

class cls_add_user_screen: protected cls_screen
{
	static void _read_user_info(cls_user &user)
	{
		user.first_name = cls_input_validation::read_string("Enter User First Name? ");
		user.last_name = cls_input_validation::read_string("Enter User Last Name? ");
		user.email = cls_input_validation::read_string("Enter User Email? ");
		user.phone = cls_input_validation::read_string("Enter User Phone? ");
		user.password = cls_input_validation::read_string("Enter User Password? ");
		user.permissions = _read_permissions();
	}
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

	static int _read_permissions()
	{
		int permissions = 0;
		char answer = 'Y';
		cout << "\nDo you want to give this user full permission ? [Y/N] ";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			return -1;
		}
		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permissions += cls_user::p_list_clients;
		}
		cout << "\nAllow to Add New Client? y/n? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permissions += cls_user::p_add_new_client;
		}
		cout << "\nAllow to Delete Client? y/n? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permissions += cls_user::p_delete_client;
		}
		cout << "\nAllow to Update Client? y/n? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permissions += cls_user::p_update_client;
		}
		cout << "\nAllow to Find Client? y/n? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permissions += cls_user::p_find_client;
		}
		cout << "\nAllow to Show Transactions? y/n? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permissions += cls_user::p_show_transactions;
		}
		cout << "\nAllow to Mange Users? y/n? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permissions += cls_user::p_mange_users;
		}
		cout << "\nAllow to Show Login Register List? y/n? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permissions += cls_user::p_login_register_list;
		}
		return permissions;
	}

public:
	static void add_new_user_screen()
	{
		_draw_screen_header("\t Add New User Screen");
		string user_name = "";

		user_name = cls_input_validation::read_string("\nPlease Enter UserName: ");
		while (cls_user::Is_user_exist(user_name))
		{
			cout << "\nUserName Is Already Used, Choose another one: ";
			user_name = cls_input_validation::read_string();
		}

		cls_user new_user = cls_user::get_add_new_user_object(user_name);

		_read_user_info(new_user);

		cls_user::en_save_results save_result;

		save_result = new_user.save();

		switch (save_result)
		{
			case  cls_user::en_save_results::sv_succeeded:
		{
			cout << "\nUser Addeded Successfully :-)\n";
			_print_user_info(new_user);
			break;
		}
		case cls_user::en_save_results::sv_faild_empty_object:
		{
			cout << "\nError User was not saved because it's Empty";
			break;

		}
		case cls_user::en_save_results::sv_faild_user_exists:
		{
			cout << "\nError User was not saved because UserName is used!\n";
			break;

		}
		}
	}
	};

