#pragma once
#pragma once
#include <iostream>
#include "cls_person.h"
#include "cls_employe.h"
using namespace std;


class cls_programer : public cls_employe
{
	string _main_programing_language;
public:

	cls_programer(short id, string first_name, string last_name, string email, string phone, string title, double salary, string department, string programing_language)
		:cls_employe(id, first_name, last_name, email, phone, title, salary, department)
	{
		_main_programing_language = programing_language;
	}
	void set_programing_language(string programing_language)
	{
		_main_programing_language = programing_language;
	}
	string get_programing_language()
	{
		return _main_programing_language;
	}
	void print()
	{
		cout << "---------------------------\n";
		cout << "ID         : " << get_id() << endl;
		cout << "First Name : " << get_first_name() << endl;
		cout << "Last Name  : " << get_last_name() << endl;
		cout << "Full Name  : " << get_full_name() << endl;
		cout << "Email      : " << get_email() << endl;
		cout << "Phone      : " << get_phone() << endl;
		cout << "department : " << get_department() << endl;
		cout << "titel      : " << get_title() << endl;
		cout << "salary     : " << get_salary() << endl;
		cout << "main programing language: " << _main_programing_language << endl;
		cout << "---------------------------\n";
	}
};
