#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_bank_client.h"
#include "cls_input_validation.h"
#include <iomanip>

class cls_add_new_client_screen : protected cls_screen
{
private:
	static void _read_new_client(cls_bank_client& Client)
	{
	
		Client.first_name = cls_input_validation::read_string("\nEnter FirstName: ");

		Client.last_name = cls_input_validation::read_string("\nEnter LastName: ");

		Client.email = cls_input_validation::read_string("\nEnter Email: ");

		Client.phone = cls_input_validation::read_string("\nEnter Phone: ");

		Client.pin_code = cls_input_validation::read_string("\nEnter PinCode: ");

		cout << "\nEnter Account Balance: ";
		Client.account_balance = cls_input_validation::read_float_number();
	}
	static void _print_client_info(cls_bank_client Client)
	{
		cout << "==============================" << endl;
		cout << "Account Number: " << Client.account_number << endl;
		cout << "Pin Code: " << Client.pin_code << endl;
		cout << "First Name: " << Client.first_name << endl;
		cout << "Last Name: " << Client.last_name << endl;
		cout << "Email: " << Client.email << endl;
		cout << "Phone: " << Client.phone << endl;
		cout << "Account Balance: " << Client.account_balance << endl;
		cout << "==============================" << endl;
	}
public:
	static void add_new_client_screen()
	{
		_draw_screen_header("Add New Client Screen");
		if (!check_accsess_rights(cls_user::p_add_new_client))
		{
			return;
		}
		string account_number = cls_input_validation::read_string("Enter Account Number: ");
		if (cls_bank_client::is_client_exist(account_number))
		{
			cout << "Account Number already exists, try another one.\n";
			account_number = cls_input_validation::read_string("Enter Account Number: ");
		}
		_draw_screen_header("adding new client screen");
		cls_bank_client client = cls_bank_client::get_add_new_client_object(account_number);
		_read_new_client(client);



		if (client.save() == cls_bank_client::en_save_result::sv_faild_account_number_exists)
		{
			cout << "Account Number already exists, try another one.\n";

		}
		else
		{
			cout << "Client added successfully.\n";
			_print_client_info(client);
		}
	}
};