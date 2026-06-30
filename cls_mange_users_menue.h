#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_input_validation.h"
#include <iomanip>
#include "cls_user_list_screen.h"
#include "cls_add_user_screen.h"
#include "cls_delete_user_screen.h"
#include "cls_update_user_screen.h"
#include "cls_find_user_screen.h"

class cls_mange_users_menue : protected cls_screen
{

private:
    enum en_manage_users_menue_options {
        e_list_users = 1, e_add_new_user = 2, e_delete_user = 3,
        e_update_user = 4, e_find_user = 5, e_main_menue = 6
    };

    static short read_manage_users_menue_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = cls_input_validation::read_double_number_between(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _go_back_to_manage_users_menue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        show_manage_users_menue();
    }

    static void _show_list_users_screen()
    {
        //cout << "\nList Users Screen Will Be Here.\n";
		cls_list_users_screen::show_users_list();
    }

    static void _show_add_new_user_screen()
    {
        //cout << "\nAdd New User Screen Will Be Here.\n";
		cls_add_user_screen::add_new_user_screen();
    }

    static void _show_delete_user_screen()
    {
        //cout << "\nDelete User Screen Will Be Here.\n";
		cls_delete_user_screen::delete_user_screen();
    }

    static void _show_update_user_screen()
    {
        //cout << "\nUpdate User Screen Will Be Here.\n";
        cls_update_user_screen::update_user_screen();
    }

    static void _show_find_user_screen()
    {
        //cout << "\nFind User Screen Will Be Here.\n";
		cls_find_user_screen::find_user_screen();   
    }


    static void _perform_manage_users_menue_option(en_manage_users_menue_options manage_users_menue_option)
    {

        switch (manage_users_menue_option)
        {
        case en_manage_users_menue_options::e_list_users:
        {
            system("cls");
            _show_list_users_screen();
            _go_back_to_manage_users_menue();
            break;
        }

        case en_manage_users_menue_options::e_add_new_user:
        {
            system("cls");
            _show_add_new_user_screen();
            _go_back_to_manage_users_menue();
            break;
        }

        case en_manage_users_menue_options::e_delete_user:
        {
            system("cls");
            _show_delete_user_screen();
            _go_back_to_manage_users_menue();
            break;
        }

        case en_manage_users_menue_options::e_update_user:
        {
            system("cls");
            _show_update_user_screen();
            _go_back_to_manage_users_menue();
            break;
        }

        case en_manage_users_menue_options::e_find_user:
        {
            system("cls");

            _show_find_user_screen();
            _go_back_to_manage_users_menue();
            break;
        }

        case en_manage_users_menue_options::e_main_menue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }



public:


    static void show_manage_users_menue()
    {
		if (!check_accsess_rights(cls_user::p_mange_users))
        {
            return;
        }

        system("cls");
        _draw_screen_header("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _perform_manage_users_menue_option((en_manage_users_menue_options)read_manage_users_menue_option());
    }

};

