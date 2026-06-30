#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_bank_client.h"
#include "cls_input_validation.h"

class cls_diposit_screen : protected cls_screen
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
	static void deposit_screen()
	{
		_draw_screen_header("Deposit Screen");
		string account_number = _read_account_number();
		while (!cls_bank_client::is_client_exist(account_number))
		{
			cout << "Account Number is not exist, try another one.\n";
			account_number = _read_account_number();
		}
		cls_bank_client client = cls_bank_client::find_client(account_number);
		_print_client_info(client);

		double amount = 0;
		cout << "\nEnter amount to deposit: ";
		amount = cls_input_validation::read_double_number();

		cout << "\nAre you sure you want to deposit " << amount << " to account number " << client.account_number << "? (Y/N) ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			client.deposit(amount);
			cout << "\nAmount deposited successfully.\n";
			cout << "\nUpdated account balance Info:\n" << client.account_balance << endl;
		}
		else
		{
			cout << "\nDeposit operation cancelled.\n";
		}
	}
};

