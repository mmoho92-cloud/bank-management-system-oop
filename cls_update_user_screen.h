#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_user.h"
#include "cls_input_validation.h"
#include <iomanip>
class cls_update_user_screen :protected cls_screen
{
	static void _print_user(cls_user User)
	{
		cout << "======================================" << endl;
		cout << "First Name: " << User.first_name << endl;
		cout << "Last Name: " << User.last_name << endl;
		cout << "Email: " << User.email << endl;
		cout << "Phone: " << User.phone << endl;
		cout << "Password: " << User.password << endl;
		cout << "Permissions: " << User.permissions << endl;
		cout << "======================================" << endl;
	}

	static void _read_updated_user_info(cls_user& User)
	{
		cout << "\nEnter FirstName: ";
		User.first_name = cls_input_validation::read_string();
		cout << "\nEnter LastName: ";
		User.last_name = cls_input_validation::read_string();
		cout << "\nEnter Email: ";
		User.email = cls_input_validation::read_string();
		cout << "\nEnter Phone: ";
		User.phone = cls_input_validation::read_string();
		cout << "\nEnter Password: ";
		User.password = cls_input_validation::read_string();
		cout << "\nEnter Permissions: ";
		User.permissions = _read_permissions();
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
	static void update_user_screen()
	{
		_draw_screen_header("Update User Screen");
		string user_name = cls_input_validation::read_string("Enter User Name: ");
		cls_user user = cls_user::find(user_name);
		while (user.is_empty())
		{
			cout << "User Name not found, try another one.\n";
			user_name = cls_input_validation::read_string("Enter User Name: ");
		}
		
			_print_user(user);
			char answer = 'n';
			cout << "Are you sure you want to update this user? [y/n]: ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				_read_updated_user_info(user);
				if (user.save() == cls_user::en_save_results::sv_succeeded)
				{
					cout << "User updated successfully.\n";
					_print_user(user);
				}
				else
				{
					cout << "Error updating user.\n";
				}
			}
			else
			{
				cout << "Update cancelled.\n";
			}
		
	}
};

