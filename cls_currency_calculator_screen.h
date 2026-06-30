#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_currency.h"
#include "cls_input_validation.h"
#include "cls_my_string.h"
#include <iomanip>

class cls_currency_calculator_screen : protected cls_screen
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

	static double _currency_calculator_USD(string currency1,string currency2 , double amount)
	{
		double result = 0;
		cls_currency Currency1 = cls_currency::find_by_code(currency1);
		cls_currency Currency2 = cls_currency::find_by_code(currency2);
		
	    if (cls_my_string::upper_all_string(currency1) == "USD")
			{
				if (Currency2.rate() > 0)
				{
					 result = amount * Currency2.rate();
				}
				else
				{
					 result = amount / Currency2.rate();
				}
			}
	    else if (cls_my_string::upper_all_string(currency2) == "USD")
			{
				if (Currency1.rate() > 0)
				{
					 result = amount / Currency1.rate();
				}
				else
				{
					 result = amount * Currency1.rate();
				}
			}
		
		return result;
	}

	static double _currency_calculator(string currency1, string currency2, double amount)
	{
		double result = 0;
		cls_currency Currency1 = cls_currency::find_by_code(currency1);
		cls_currency Currency2 = cls_currency::find_by_code(currency2);
		
		double amount_in_usd = _currency_calculator_USD(currency1, "USD", amount);
	
		return result = _currency_calculator_USD("USD", currency2, amount_in_usd);
	}

public:
	static void currency_calculator_screen()
	{
		char answer = 'y';
		do
		{
			_draw_screen_header("Currency Calculator Screen");
			string currency1 = cls_input_validation::read_string("Enter Currency Code 1: \n");
			cls_currency Currency1 = cls_currency::find_by_code(currency1);
			while (Currency1.is_empty())
			{
				cout << "Currency Code not found, try another one.\n";
				currency1 = cls_input_validation::read_string("Enter Currency Code 1: \n");
				Currency1 = cls_currency::find_by_code(currency1);
			}
			string currency2 = cls_input_validation::read_string("Enter Currency Code 2: \n");
			cls_currency Currency2 = cls_currency::find_by_code(currency2);
			while (Currency2.is_empty())
			{
				cout << "Currency Code not found, try another one.\n";
				currency2 = cls_input_validation::read_string("Enter Currency Code 2: \n");
				Currency2 = cls_currency::find_by_code(currency2);
			}

			cout << "\nEnter Amount in " << Currency1.currency_code() << ": ";
			double amount = cls_input_validation::read_double_number();

			double result = _currency_calculator(currency1, currency2, amount);

			cout << "\n" << amount << " " << currency1 << " = " << result << " " << currency2 << "\n";

			cout << "\nDo you want to perform another calculation? (y/n): ";
			cin >> answer;
		} while (answer == 'y' || answer == 'Y');
		
	
	}

};

