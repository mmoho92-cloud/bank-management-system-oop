#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_bank_client.h"
#include "cls_input_validation.h"
#include <iomanip>

class cls_delete_client_screen: protected cls_screen
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

public:
	static void delete_client_screen()
	{
		if (!check_accsess_rights(cls_user::p_delete_client))
		{
			return;
		}
		_draw_screen_header("Delete Client Screen");
		string account_number = cls_input_validation::read_string("Enter Account Number: \n");
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
			cout << "Are you sure you want to delete this client? [y/n]: ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				client.dalate();
				cout << "Client deleted successfully.\n";
				_print_client_info(client);
			}
			else
			{
				cout << "Client deletion cancelled.\n";
			}
			
			
		}
		
		
		
	}
};

