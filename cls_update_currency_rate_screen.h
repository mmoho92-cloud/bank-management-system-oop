#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_currency.h"
#include "cls_input_validation.h"
#include <iomanip>

class cls_update_currency_rate_screen :protected cls_screen
{
	static void _print_currency_info(cls_currency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________";
		cout << "\nCountry: " << Currency.contry();
		cout << "\nCurrency Name: " << Currency.currency_name();
		cout << "\nCurrency Code: " << Currency.currency_code();
		cout << "\nRate/(1$): " << Currency.rate();
		cout << "\n___________________\n";
	}

public:
	static void update_currency_rate_screen()
	{
		_draw_screen_header("Update Currency Rate Screen");
		string currency_code = cls_input_validation::read_string("Enter Currency Code: \n");
		cls_currency Currency = cls_currency::find_by_code(currency_code);
		while (Currency.is_empty())
		{
			cout << "Currency Code not found, try another one.\n";
			currency_code = cls_input_validation::read_string("Enter Currency Code: \n");
			Currency = cls_currency::find_by_code(currency_code);
		}
		_print_currency_info(Currency);
		char answer = 'n';
		cout << "\nAre you sure you want to update this currency rate? [y/n]: ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			float new_rate = cls_input_validation::read_float_number("Enter New Rate/(1$): ");
			Currency.update_rate(new_rate);
			cout << "\nCurrency Rate Updated Successfully!\n";
			_print_currency_info(Currency);
		}
		else
		{
			cout << "\nCurrency Rate Update Cancelled!\n";
		}

		
	}
};


