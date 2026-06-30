#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_input_validation.h"
#include <iomanip>
#include "cls_client_screen.h"
#include "cls_add_new_client_screen.h"
#include "cls_delete_client_screen.h"
#include "cls_update_client_screen.h"
#include "cls_find_screen.h"
#include "cls_transactions_menue.h"
#include "cls_mange_users_menue.h"  
#include "global.h"
#include "cls_login_register_screen.h"
#include "cls_currency_exchange_main_menue.h"

using namespace std;

class cls_main_screen : protected cls_screen
{
private:
	enum en_main_choices { list_clients = 1, add_new_client = 2, delete_client = 3,
		update_client = 4, find_client = 5, transactions = 6, mange_users = 7, login_register = 8 , currency_exchange= 9, logout
    =10};

    static short _read_main_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10 ]? ";
        short Choice = cls_input_validation::read_int_number_between(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static void _go_back_main_menue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        show_main_menue();
    }

    static void _show_client_screen()
    {
        //cout << "\nClient List Screen Will be here...\n";
        cls_client_screen::show_client_list();
    }

    static void _show_add_new_clients_screen()
    {
        //cout << "\nAdd New Client Screen Will be here...\n";
		cls_add_new_client_screen::add_new_client_screen();
    }

    static void _show_delete_client_screen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
		cls_delete_client_screen::delete_client_screen();   
    }

    static void _show_update_client_screen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
		cls_update_client_screen::update_client_screen();
    }

    static void _show_find_client_screen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
		cls_find_screen::find_client_screen();
    }

    static void _show_transactions_menue()
    {
		cls_transactions_menue::show_transaction_menue();
    }

    static void _show_manage_users_menue()
    {
        //cout << "\nUsers Menue Will be here...\n";
		cls_mange_users_menue::show_manage_users_menue();   
    }

    /*static void _show_end_screen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }*/
    static void _show_login_register_screen()
    {
        //cout << "\nLogin Register Screen Will be here...\n";
		cls_login_register_screen::show_login_register_screen();
    }

    static void _show_currency_exchange_menue()
    {
        //cout << "\nCurrency Exchange Menue Will be here...\n";
		cls_currency_exchange_main_menue::show_currency_exchange_main_menue();
    }

    static void _logout()
    {
        current_user = cls_user::find("", "");

    }

    static void _preform_main_menue_option(en_main_choices main_menue_option)
    {
        switch (main_menue_option)
        {
        case en_main_choices::list_clients:
        {
            system("cls");
           _show_client_screen();
            _go_back_main_menue();
            break;
        }
        case en_main_choices::add_new_client:
        {
            system("cls");
            _show_add_new_clients_screen();
            _go_back_main_menue();
            break;
        }
        case en_main_choices::delete_client:
        {
            system("cls");
            _show_delete_client_screen();
            _go_back_main_menue();
            break;
        }
        case en_main_choices::update_client:
        {
            system("cls");
            _show_update_client_screen();
            _go_back_main_menue();
            break;
        }
        case en_main_choices::find_client:
        {
            system("cls");
            _show_find_client_screen();
            _go_back_main_menue();
            break;
        }
        case en_main_choices::transactions:
        {
            system("cls");
            _show_transactions_menue();
            _go_back_main_menue();
            break;
        }
        case en_main_choices::mange_users:
        {
            system("cls");
            _show_manage_users_menue();
            _go_back_main_menue();
            break;
		}
        case en_main_choices::login_register:
        {
            system("cls");
            _show_login_register_screen();
            _go_back_main_menue();
            break;
		}
       case en_main_choices::currency_exchange:
        {
            system("cls");
            _show_currency_exchange_menue();
            _go_back_main_menue();
            break;
	   }
        case en_main_choices::logout:
        {
            system("cls");
            _logout();
            break;
        }
        }

    }
    
    public:


        static void show_main_menue()
        {

            system("cls");
            _draw_screen_header("\t\tMain Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Login Register list.\n";
			cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
            cout << setw(37) << left << "" << "\t[10] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _preform_main_menue_option((en_main_choices)_read_main_option());
        }

};



