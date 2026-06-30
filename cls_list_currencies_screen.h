#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_currency.h"
#include <iomanip>

class cls_list_currencies_screen :protected cls_screen
{
	static void _print_currency_record(cls_currency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.contry();
		cout << "| " << setw(8) << left << Currency.currency_code();
		cout << "| " << setw(45) << left << Currency.currency_name();
		cout << "| " << setw(10) << left << Currency.rate() << endl;
	}
public:
	static void show_currencies_list()
	{
		vector <cls_currency> vCurrencies = cls_currency::get_currencies_list();
		string Title = "\t  Currencies List Screen";
		string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency(s).";

		_draw_screen_header(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Currency Name";
		cout << "| " << left << setw(45) << "Code";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
		if (vCurrencies.size() == 0)
			cout << "\t\t\t\tNo Currencies Available In the System!";
		else
			for (cls_currency Currency : vCurrencies)
			{
				_print_currency_record(Currency);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}
};

