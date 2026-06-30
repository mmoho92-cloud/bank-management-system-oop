#pragma once
#include <string>
#include "cls_person.h"
#include "cls_my_string.h"
#include "util.h"
#include "cls_input_validation.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "cls_date.h"
#include "cls_user.h"
#include "global.h"

class cls_login_register 
{
	string date;
	string time;
	string user_name;
	string password;
	int permissions;
	bool _marked_for_delete = false;

	static cls_login_register _convert_line_to_register_object(string Line, string Seperator = "#//#")
	{
		vector<string> v_register_data;
		v_register_data = cls_my_string::split_string(Line, Seperator);

		return cls_login_register(v_register_data[0], v_register_data[1], v_register_data[2], v_register_data[3], stoi(v_register_data[4]));

	}

	static string _convert_register_object_to_line(cls_login_register Register, string Seperator = "#//#")
	{

		string login_register = "";
		login_register += Register.date + Seperator;
		login_register += Register.time + Seperator;
		login_register += Register.user_name + Seperator;
		login_register += Register.password + Seperator;
		login_register += Register.permissions;

		return login_register;

	}

	static  vector <cls_login_register> _load_registers_data_from_file()
	{

		vector <cls_login_register> v_registers;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				cls_login_register User = _convert_line_to_register_object(Line);

				v_registers.push_back(User);
			}

			MyFile.close();

		}

		return v_registers;

	}

	static void _save_registers_data_to_file(vector <cls_login_register> v_registers)
	{

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{

			for (cls_login_register U : v_registers)
			{
				if (U.marked_for_deleted() == false)
				{
					 
					DataLine = _convert_register_object_to_line(U);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}

	void _add_data_line_to_file(string  st_data_line)
	{
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << st_data_line << endl;

			MyFile.close();
		}

	}





public:
	cls_login_register(string date, string time, string user_name, string password, int permissions) 
	{
		date = date;
		time = time;
		user_name = user_name;
		password = password;
		permissions = permissions;
	}

	bool marked_for_deleted()
	{
		return _marked_for_delete;
	}

	void set_date() 
	{
		date = cls_date::date_to_string(cls_date::get_curent_date());
	}

	string get_date() { return date; }
	__declspec(property(get = get_date, put = set_date)) string date;

	void set_time()
	{
		time = cls_date::time_to_string(cls_date::get_curent_time());
	}
	string get_time() { return time; }
	__declspec(property(get = get_time, put = set_time)) string time;

	void set_user_name() 
	{ user_name = current_user.user_name; }
	string get_user_name() { return user_name; }
	__declspec(property(get = get_user_name, put = set_user_name)) string user_name;

	void set_password() 
	{
		password = current_user.password;
	}
	string get_password() { return password; }
	__declspec(property(get = get_password, put = set_password)) string password;

	void set_permissions() 
	{
		permissions = current_user.permissions;
	}
	string get_permissions() { return to_string(permissions); }
	__declspec(property(get = get_permissions, put = set_permissions)) string permissions;

	static void add_new_login_register() 
	{
		cls_login_register login_register("", "", "", "", 0);
		login_register.set_date();
		login_register.set_time();
		login_register.set_user_name();
		login_register.set_password();
		login_register.set_permissions();
		login_register._add_data_line_to_file(_convert_register_object_to_line(login_register));
	}

};

