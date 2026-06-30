#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_bank_client.h"
#include "cls_input_validation.h"
#include <iomanip>

class cls_update_client_screen:protected cls_screen
{
private:
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

	static void _read_updated_client_info(cls_bank_client& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.first_name = cls_input_validation::read_string();
		cout << "\nEnter LastName: ";
		Client.last_name = cls_input_validation::read_string();
		cout << "\nEnter Email: ";
		Client.email = cls_input_validation::read_string();
		cout << "\nEnter Phone: ";
		Client.phone = cls_input_validation::read_string();
		cout << "\nEnter PinCode: ";
		Client.pin_code = cls_input_validation::read_string();
		cout << "\nEnter Account Balance: ";
		Client.account_balance = cls_input_validation::read_float_number();
	}


public:
	static void update_client_screen()
	{
		if (!check_accsess_rights(cls_user::p_update_client))
		{
			return;
		}
		_draw_screen_header("Update Client Screen");
		cout << "Enter Account Number: "<<endl;
		string account_number = cls_input_validation::read_string();
		cls_bank_client client = cls_bank_client::find_client(account_number);
		if (client.is_empty())
		{
			cout << "Account Number not found, try another one.\n";
			account_number = cls_input_validation::read_string("Enter Account Number: ");
		}
		else
		{
			_print_client_info(client);
			char answer = 'n';
			cout << "Are you sure you want to update this client? [y/n]: ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				_read_updated_client_info(client);
				if (client.save() == cls_bank_client::en_save_result::sv_succeeded)
				{
					cout << "Client updated successfully.\n";
					_print_client_info(client);
				}
				else
				{
					cout << "Failed to update client.\n";

				}

			}
			else
			{
				cout << "Client update cancelled.\n";
			}
		}
	}
};

