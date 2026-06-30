#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_bank_client.h"
#include "cls_input_validation.h"

class cls_transfer_screen : protected cls_screen
{
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

	static string _read_account_number()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}

public:
	static void transfer_screen()
	{
		_draw_screen_header("Transfer Screen");
		cout << "\nEnter the account number you want to transfer from:\n";
		string account_number1 = _read_account_number();
		while (!cls_bank_client::is_client_exist(account_number1))
		{
			cout << "Account Number is not exist, try another one.\n";
			account_number1 = _read_account_number();
		}
		cls_bank_client client1 = cls_bank_client::find_client(account_number1);
		_print_client_info(client1);

		cout << "\nEnter the account number you want to transfer to:\n";
		string account_number2 = _read_account_number();
		while (!cls_bank_client::is_client_exist(account_number2))
		{
			cout << "Account Number is not exist, try another one.\n";
			account_number2 = _read_account_number();
		}
		cls_bank_client client2 = cls_bank_client::find_client(account_number2);
		_print_client_info(client2);

		double amount = 0;
		cout << "\nEnter You Want To Transfer: ";
		amount = cls_input_validation::read_double_number();

		cout << "\nAre you sure you want to transfer " << amount << " from account with account number : " << client1.account_number 
			<<" to account with account number : "<<client2.account_number << "? (Y/N) ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			client1.transfer(client2,amount);
			cout << "\nAmount transfered successfully.\n";
			cout << "\nUpdated account balance Info:\n" << client1.account_balance << endl;
			cout << "\nUpdated account balance Info:\n" << client2.account_balance << endl;
			client1.add_transfer_log(client2, amount);
		}
		else
		{
			cout << "\nTransfer operation cancelled.\n";
		}

	}
};

