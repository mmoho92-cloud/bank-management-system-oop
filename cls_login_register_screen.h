#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_bank_client.h"
#include <iomanip>
#include "cls_user.h"
class cls_login_register_screen :protected cls_screen
{
    static void _print_Transfer_record_line(cls_user::st_login_register Register)
    {
            cout << setw(8) << left << "" << "| " << setw(12) << left << Register.date;
            cout << "| " << setw(25) << left << Register.time;
            cout << "| " << setw(12) << left << Register.user_name;
            cout << "| " << setw(20) << left << Register.password;
            cout << "| " << setw(10) << left << Register.permissions;
      
    }
    public:
    static void show_login_register_screen()
    {

        if (!check_accsess_rights(cls_user::en_permissions::p_login_register_list))
        {
            return;
        }
        vector <cls_user::st_login_register> vLoginRegisterRecord = cls_user::get_login_register_list();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

        _draw_screen_header(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (cls_user::st_login_register Record : vLoginRegisterRecord)
            {

                _print_Transfer_record_line(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

