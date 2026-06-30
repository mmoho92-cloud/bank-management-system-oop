#pragma once
#include "cls_person.h"
#include "cls_my_string.h"
#include "util.h"
#include "cls_input_validation.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "global.h"

using namespace std;

class cls_bank_client : public cls_person
{
private:
	enum en_mode { empty_mode = 0, update_mode = 1, add_new_mode = 2 };
	en_mode _mode;

	string _account_number;
	string _pin_code;
	double _account_balance;
	bool _mark_for_delete = false;

	static cls_bank_client _convert_line_to_client(string line, string seperator = "#//#")
	{
		vector <string> v_client_data;
		v_client_data = cls_my_string::split_string(line, seperator);

		if (v_client_data.size() < 7)
		{
			return _get_empty_client();
		}

		cls_bank_client client(en_mode::update_mode, v_client_data[0], v_client_data[1], v_client_data[2], v_client_data[3],
			v_client_data[4], v_client_data[5], stof(v_client_data[6]));
		return client;
	}

	static string _convert_client_to_line(cls_bank_client client, string seperator = "#//#")
	{
		string line = client.first_name + seperator + client.last_name + seperator + client.email + seperator + client.phone + seperator + client.account_number + seperator +
			client.pin_code + seperator + to_string(client._account_balance);
		return line;
	}

	static cls_bank_client _get_empty_client()
	{
		cls_bank_client client(en_mode::empty_mode, "", "", "", "", "", "", 0);
		return client;
	}

	static vector <cls_bank_client> _load_clients_data_from_file()
	{
		fstream my_file;
		vector <cls_bank_client> v_file_content;
		my_file.open("clients.txt", ios::in);

		if (my_file.is_open())
		{
			string line;
			while (getline(my_file, line))
			{
				cls_bank_client client_info = _convert_line_to_client(line);
				v_file_content.push_back(client_info);
			}
			my_file.close();
		}
		return v_file_content;
	}

	static void _save_client_data_to_file(vector <cls_bank_client>v_clients_data)
	{
		fstream my_file;
		my_file.open("clients.txt", ios::out);
		string data_line;
		if (my_file.is_open())
		{

			for (cls_bank_client& c : v_clients_data)
			{
				if (!c._mark_for_delete)
				{
					data_line = _convert_client_to_line(c);
					my_file << data_line << endl;

				}

			}
			my_file.close();


		}

	}

	void _update()
	{
		vector <cls_bank_client> _v_clints_data;
		_v_clints_data = _load_clients_data_from_file();

		for (cls_bank_client& c : _v_clints_data)
		{
			if (c.account_number == account_number)
			{
				c = *this;
				break;
			}
		}
		_save_client_data_to_file(_v_clints_data);
	}

	void _add_data_line_to_file(string data_line)
	{
		fstream my_file;
		my_file.open("clients.txt", ios::out | ios::app);
		{
			if (my_file.is_open())
			{
				my_file << data_line << endl;
				my_file.close();
			}

		}

	}

	void _add_new_client()
	{
		_add_data_line_to_file(_convert_client_to_line(*this));
	}

	struct st_transfer_log;

	static st_transfer_log _convert_transfer_log_registers_to_record(string Line, string Seperator = "#//#")
	{
		vector<string> v_transfer_log_data;
		v_transfer_log_data = cls_my_string::split_string(Line, Seperator);
		return st_transfer_log{ v_transfer_log_data[0], v_transfer_log_data[1], v_transfer_log_data[2],
			v_transfer_log_data[3], stod(v_transfer_log_data[4]), stod(v_transfer_log_data[5]), stod(v_transfer_log_data[6]), v_transfer_log_data[7] };
	}

	string _prepare_transfer_log_record(cls_bank_client& to_client, double amount, string seperator = "#//#")
	{
		string transfer_log_record = "";
		transfer_log_record += cls_date::date_to_string(cls_date::get_curent_date()) + seperator;
		transfer_log_record += cls_date::time_to_string(cls_date::get_curent_time()) + seperator;
		transfer_log_record += _account_number + seperator;
		transfer_log_record += to_client.account_number + seperator;
		transfer_log_record += to_string(amount) + seperator;
		transfer_log_record += to_string(_account_balance) + seperator;
		transfer_log_record += to_string(to_client.account_balance) + seperator;
		transfer_log_record += current_user.user_name;
		return transfer_log_record;
	}

public:
	cls_bank_client(en_mode mode, string first_name, string last_name, string email, string phone, string account_number, string pin_code, float account_balance) :
		cls_person(first_name, last_name, email, phone)
	{
		_mode = mode;
		_account_number = account_number;
		_pin_code = pin_code;
		_account_balance = account_balance;
	}

	struct st_transfer_log
	{
		string date;
		string time;
		string from_account;
		string to_account;
		double amount;
		double from_account_balance;
		double to_account_balance;
		string user_name;
	};

	bool is_empty()
	{
		return _mode == en_mode::empty_mode;
	}

	void set_account_number(string account_number)
	{
		_account_number = account_number;
	}
	string get_account_number()
	{
		return _account_number;
	}
	__declspec(property(get = get_account_number, put = set_account_number)) string account_number;

	string get_pin_code()
	{
		return _pin_code;
	}
	void set_pin_code(string pin_code)
	{
		_pin_code = pin_code;
	}
	__declspec(property(get = get_pin_code, put = set_pin_code)) string pin_code;

	void set_account_balance(float account_balance)
	{
		_account_balance = account_balance;
	}
	float get_account_balance()
	{
		return _account_balance;
	}
	__declspec(property(get = get_account_balance, put = set_account_balance)) float account_balance;

	static cls_bank_client find_client(string account_number)
	{
		fstream my_file;
		my_file.open("clients.txt", ios::in);

		if (my_file.is_open())
		{
			string line;
			while (getline(my_file, line))
			{
				cls_bank_client client = _convert_line_to_client(line);
				if (client.account_number == account_number)
				{
					my_file.close();
					return client;
				}

			}
			my_file.close();
			return _get_empty_client();
		}
	}

	static cls_bank_client find_client(string account_number, string pin_code)
	{
		ifstream my_file;
		my_file.open("clients", ios::in);
		if (my_file.is_open())
		{
			string line;
			while (getline(my_file, line))
			{
				cls_bank_client client = _convert_line_to_client(line);
				if (client.account_number == account_number, client.pin_code == pin_code)
				{
					return client;
					my_file.close();
				}
				my_file.close();
			}
			return _get_empty_client();
		}

	}

	static bool is_client_exist(string account_number)
	{
		cls_bank_client client = find_client(account_number);
		return (!client.is_empty());
	}

	enum en_save_result { sv_faild_empty_opject = 0, sv_succeeded = 1, sv_faild_account_number_exists = 2 };

	en_save_result save()
	{
		switch (_mode)
		{
		case en_mode::empty_mode:
		{
			return en_save_result::sv_faild_empty_opject;
		}
		case en_mode::update_mode:
		{
			_update();
			return en_save_result::sv_succeeded;
			break;
		}
		case en_mode::add_new_mode:
		{
			if (cls_bank_client::is_client_exist(account_number))
			{
				return en_save_result::sv_faild_account_number_exists;
			}
			else
			{
				_add_new_client();
				_mode = en_mode::update_mode;
				return en_save_result::sv_succeeded;
			}
		}
		}
	}

	static cls_bank_client get_add_new_client_object(string account_number)
	{
		cls_bank_client client(en_mode::add_new_mode, "", "", "", "", account_number, "", 0.0f);

		return client;
	}

	bool dalate()
	{
		vector <cls_bank_client> v_clients;
		v_clients = _load_clients_data_from_file();

		for (cls_bank_client& c : v_clients)
		{
			if (c.account_number == _account_number)
			{
				c._mark_for_delete = true;
				break;
			}
		}
		_save_client_data_to_file(v_clients);
		*this = _get_empty_client();
		return true;
	}

	static vector <cls_bank_client> get_clients_list()
	{
		return _load_clients_data_from_file();
	}

	static float get_total_balance()
	{
		vector <cls_bank_client> v_clients = _load_clients_data_from_file();

		double total_balance = 0;
		for (cls_bank_client& C : v_clients)
		{
			total_balance += C.account_balance;
		}
		return total_balance;
	}

	void deposit(double amount)
	{
		_account_balance += amount;
		save();
	}

	void withdraw(double amount)
	{
		while (amount > _account_balance)
		{
			cout << "Insufficient balance enter another amount.\n";
			cin >> amount;
		}
		_account_balance -= amount;
		save();
	}

	void transfer(cls_bank_client& to_client, double amount)
	{
		while (amount > _account_balance)
		{
			cout << "Insufficient balance enter another amount.\n";
			cin >> amount;
		}
		_account_balance -= amount;
		to_client._account_balance += amount;
		save();
		to_client.save();
	}

	void add_transfer_log(cls_bank_client& to_client, double amount)
	{
		string transfer_log_record = _prepare_transfer_log_record(to_client, amount);
		fstream my_file;
		my_file.open("TransferLog.txt", ios::out | ios::app);
		if (my_file.is_open())
		{
			my_file << transfer_log_record << endl;
		}
		my_file.close();

	}

	static vector <st_transfer_log> get_transfer_log_list()
	{
		vector <st_transfer_log> v_registers;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				st_transfer_log User = _convert_transfer_log_registers_to_record(Line);

				v_registers.push_back(User);
			}

			MyFile.close();

		}

		return v_registers;

	}


};