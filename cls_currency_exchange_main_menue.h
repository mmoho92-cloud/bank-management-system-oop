#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "cls_my_string.h"
#include <fstream>
#include "cls_currency.h"
#include "cls_user.h"
#include "cls_screen.h"
#include "cls_input_validation.h"
#include "cls_list_currencies_screen.h"
#include "cls_find_currency_screen.h"
#include "cls_update_currency_rate_screen.h"
#include "cls_currency_calculator_screen.h"

class cls_currency_exchange_main_menue:protected cls_screen
{
	enum en_currency_exchange_main_menue_options { e_list_currencies = 1, e_find_currency = 2,
		e_update_currency_rate = 3,en_currency_calculator =4 , e_main_menue = 5 };

	static short _read_currency_exchange_main_menue_option()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = cls_input_validation::read_double_number_between(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _go_back_to_currency_exchange_main_menue()
	{
		cout << "\n\nPress any key to go back to Currency Exchange Main Menue...";
		system("pause>0");
		show_currency_exchange_main_menue();
	}

	static void _show_list_currencies_screen()
	{
		cout << "\nList Currencies Screen Will Be Here.\n";
		cls_list_currencies_screen::show_currencies_list();
	}
	static void _show_find_currency_screen()
	{
		cout << "\nFind Currency Screen Will Be Here.\n";
		cls_find_currency_screen::find_currency_screen();
	}
	static void _show_update_currency_rate_screen()
	{
		cout << "\nUpdate Currency Rate Screen Will Be Here.\n";
		cls_update_currency_rate_screen::update_currency_rate_screen();
	}
	static void _show_currency_calculator_screen()
	{
		
		cls_currency_calculator_screen::currency_calculator_screen();
	}
	static void _perform_currency_exchange_main_menue_option(en_currency_exchange_main_menue_options option)
	{
		switch (option)
		{
		case en_currency_exchange_main_menue_options::e_list_currencies:
		{
			system("cls");
			_show_list_currencies_screen();
			_go_back_to_currency_exchange_main_menue();
			break;
		}
		case en_currency_exchange_main_menue_options::e_find_currency:
		{
			system("cls");
			_show_find_currency_screen();
			_go_back_to_currency_exchange_main_menue();
			break;
		}
		case en_currency_exchange_main_menue_options::e_update_currency_rate:
		{
			system("cls");
			_show_update_currency_rate_screen();
			_go_back_to_currency_exchange_main_menue();
			break;
		}
		case en_currency_exchange_main_menue_options::en_currency_calculator:
		{
			system("cls");
			_show_currency_calculator_screen();
			_go_back_to_currency_exchange_main_menue();
			break;
		}
		case en_currency_exchange_main_menue_options::e_main_menue:
		{
			//do nothing here the main screen will handle it :-) ;
		}
		}
	}

public:

	static void show_currency_exchange_main_menue()
	{
		if (!check_accsess_rights(cls_user::en_permissions::p_currency_exchange))
		{
			return;
		}
		system("cls");
		_draw_screen_header("\tCurrency Exchange Screen");

		cout << setw(37) << left << "" << "=====================================\n";
		cout << setw(37) << left << "" << "     Currency Exchange Main Menue    \n";
		cout << setw(37) << left << "" << "=====================================\n";
		cout << setw(37) << left << "" << "1. List Currencies.\n";
		cout << setw(37) << left << "" << "2. Find Currency.\n";
		cout << setw(37) << left << "" << "3. Update Currency Rate.\n";
		cout << setw(37) << left << "" << "4. Currency Calculator.\n";
		cout << setw(37) << left << "" << "5. Main Menue.\n";
		cout << setw(37) << left << "" << "=====================================\n";

		_perform_currency_exchange_main_menue_option((en_currency_exchange_main_menue_options)_read_currency_exchange_main_menue_option());
	}
};

