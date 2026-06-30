#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_currency.h"
#include "cls_input_validation.h"
#include <iomanip>

class cls_find_currency_screen :protected cls_screen
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
	static void find_currency_screen()
	{
		_draw_screen_header("Find Currency Screen");
		short answer;
		cout << "Enter 1 to Find Currency by Code or 2 to Find Currency by contry:  ";
		cin >> answer;
		if (answer == 1)
		{ 
			string currency_code = cls_input_validation::read_string("Enter Currency Code: \n");
			cls_currency Currency = cls_currency::find_by_code(currency_code);
			while (Currency.is_empty())
			{
				cout << "Currency Code not found, try another one.\n";
				currency_code = cls_input_validation::read_string("Enter Currency Code: \n");
				Currency = cls_currency::find_by_code(currency_code);
			}
			_print_currency_info(Currency);
		}
		else if (answer == 2)
		{
			string currency_name = cls_input_validation::read_string("Enter Currency Name: \n");
			cls_currency Currency = cls_currency::find_by_contry(currency_name);
			while (Currency.is_empty())
			{
				cout << "Currency Name not found, try another one.\n";
				currency_name = cls_input_validation::read_string("Enter Currency Name: \n");
				Currency = cls_currency::find_by_contry(currency_name);
			}
			_print_currency_info(Currency);
		}
		
		

		
	}
};

