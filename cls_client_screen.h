#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_bank_client.h"
#include <iomanip>

class cls_client_screen : protected cls_screen
{

    static void _print_client_record_line(cls_bank_client Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.account_number;
        cout << "| " << setw(20) << left << Client.get_full_name();
        cout << "| " << setw(12) << left << Client.phone;
        cout << "| " << setw(20) << left << Client.email;
        cout << "| " << setw(10) << left << Client.pin_code;
        cout << "| " << setw(12) << left << Client.account_balance;
    }

public:
    static void show_client_list()
    {
		if (!check_accsess_rights(cls_user::p_list_clients))
        {
            return;
        }
        vector <cls_bank_client> vClients = cls_bank_client::get_clients_list();
        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _draw_screen_header(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (cls_bank_client Client : vClients)
            {

                _print_client_record_line(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};