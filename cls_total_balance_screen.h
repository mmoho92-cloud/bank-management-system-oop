#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_bank_client.h"
#include <iomanip>
#include "util.h"

class cls_total_balance_screen:protected cls_screen
{
private:

    static void print_client_record_balance_line(cls_bank_client Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.account_number;
        cout << "| " << setw(40) << left << Client.get_full_name();
        cout << "| " << setw(12) << left << Client.account_balance;
    }

public:

    static void show_total_balances()
    {

        vector <cls_bank_client> vClients = cls_bank_client::get_clients_list();

        string title = "\t  Balances List Screen";
        string subtitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _draw_screen_header(title, subtitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double total_balances = cls_bank_client::get_total_balance();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (cls_bank_client Client : vClients)
            {
                print_client_record_balance_line(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << total_balances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t  ( " << util::number_to_text(total_balances) << ")";
    }

};

