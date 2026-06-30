#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_bank_client.h"
#include <iomanip>
#include "cls_user.h"

class cls_transfer_log_screen : protected cls_screen
{
    static void _print_Transfer_record_line(cls_bank_client::st_transfer_log Register)
    {
        cout << setw(8) << left << "" << "| " << Register.date<< "/"<< setw(23) << left << Register.time;
        cout << "| " << setw(8) << left << Register.from_account;
        cout << "| " << setw(8) << left << Register.to_account;
        cout << "| " << setw(8) << left << Register.amount;
        cout << "| " << setw(10) << left << Register.from_account_balance;
        cout << "| " << setw(10) << left << Register.to_account_balance;
        cout << "| " << setw(8) << left << Register.user_name;
    }
    
public:
    static void show_transfer_log_screen()
    {
		vector <cls_bank_client::st_transfer_log> vTransferLogRecord = cls_bank_client::get_transfer_log_list();

		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t\t(" + to_string(vTransferLogRecord.size()) + ") Record(s).";
		_draw_screen_header(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
        cout << "| " << left << setw(10) << "s.client";
        cout << "| " << left << setw(10) << "d.client";
        cout << "| " << left << setw(10) << "amount";
        cout << "| " << left << setw(10) << "s.balance";
        cout << "| " << left << setw(10) << "d.balance";
        cout << "| " << left << setw(10) << "user";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfer Record Available In the System!";
        for (cls_bank_client::st_transfer_log Record : vTransferLogRecord)
        {

            _print_Transfer_record_line(Record);
            cout << endl;
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


    }
};

