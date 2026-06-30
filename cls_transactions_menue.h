#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_input_validation.h"
#include <iomanip>
#include "cls_diposit_screen.h"
#include "cls_withdraw_screen.h"
#include "cls_total_balance_screen.h"
#include "cls_transfer_screen.h"
#include "cls_transfer_log_screen.h"

using namespace std;

class cls_transactions_menue : protected cls_screen
{
	enum en_transaction_choices {deposit = 1, withdraw = 2, total_balance = 3,
		transfer = 4 , tranfer_log =5  , back_to_main_menue = 6};

    static short _read_transaction_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = cls_input_validation::read_int_number_between(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _go_back_transaction_menue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to transaction Menue...\n";

        system("pause>0");
        show_transaction_menue();
    }

    static void _show_deposit_screen()
    {
        //cout << "\ndeposit Screen Will be here...\n";
		cls_diposit_screen::deposit_screen();
    }

    static void _show_withdraw_screen()
    {
        //cout << "\nwithdraw Screen Will be here...\n";
        cls_withdraw_screen::withdraw_screen();
    }

    static void _show_total_balance_screen()
    {
        //cout << "\ntotal balance screen Will be here...\n";
		cls_total_balance_screen::show_total_balances();
    }
    static void _show_transfer_screen()
    {
        //cout << "\ntransfer screen Will be here...\n";
		cls_transfer_screen::transfer_screen();
	}
    static void _show_transfer_log_screen()
    {
        //cout << "\ntransfer log screen Will be here...\n";
		cls_transfer_log_screen::show_transfer_log_screen();

	}
    


    static void _preform_transaction_menue_option(en_transaction_choices transaction_choice)
    {
        switch (transaction_choice)
        {
            case en_transaction_choices::deposit:
        {
            system("cls");
			_show_deposit_screen();
			_go_back_transaction_menue();   
            break;
        }
        case en_transaction_choices::withdraw:
        {
            system("cls");
            _show_withdraw_screen();
            _go_back_transaction_menue();
            break;
        }
        case en_transaction_choices::total_balance:
        {
            system("cls");
            _show_total_balance_screen();
            _go_back_transaction_menue();
            break;
        }
        case en_transaction_choices::transfer:
        {
            system("cls");
            _show_transfer_screen();
            _go_back_transaction_menue();
            break;
		}
        case en_transaction_choices::tranfer_log:
        {
            system("cls");
            _show_transfer_log_screen();
            _go_back_transaction_menue();
            break;
		}
        case en_transaction_choices::back_to_main_menue:
        {
          
        }
        
        }

    }

public:


    static void show_transaction_menue()
    {
		if (!check_accsess_rights(cls_user::p_show_transactions))
        {
            return;
        }

        system("cls");
        _draw_screen_header("\tTransaction Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t Transaction Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Toatal Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer .\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log .\n";
        cout << setw(37) << left << "" << "\t[6] Back To Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _preform_transaction_menue_option((en_transaction_choices)_read_transaction_option());
    }

};

