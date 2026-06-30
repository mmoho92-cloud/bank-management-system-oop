#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_user.h"
#include <iomanip>

class cls_list_users_screen :protected cls_screen
{

private:
    static void _print_user_record_line(cls_user User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.user_name;
        cout << "| " << setw(25) << left << User.get_full_name();
        cout << "| " << setw(12) << left << User.phone;
        cout << "| " << setw(20) << left << User.email;
        cout << "| " << setw(10) << left << User.password;
        cout << "| " << setw(12) << left << User.permissions;

    }

public:

    static void show_users_list()
    {

        vector <cls_user> vUsers = cls_user::get_users_list();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _draw_screen_header(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (cls_user User : vUsers)
            {

                _print_user_record_line(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};
