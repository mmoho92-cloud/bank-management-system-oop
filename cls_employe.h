#pragma once
#include <iostream>
#include "cls_person.h"
using namespace std;


class cls_employe : public cls_person
{
private:
	string _title;
	double _salary;
	string _department;

public:

	cls_employe(short id, string first_name, string last_name, string email, string phone, string title, double salary, string department)
		: cls_person(id, first_name, last_name, email, phone)
	{
		_title = title;
		_salary = salary;
		_department = department;
	}


	void set_title(string title)
	{
		_title = title;
	}
	string get_title()
	{
		return _title;
	}

	void set_salary(double salary)
	{
		_salary = salary;
	}
	double get_salary()
	{
		return _salary;
	}

	void set_department(string department)
	{
		_department = department;
	}
	string get_department()
	{
		return _department;
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
		cout << "department : " << _department << endl;
		cout << "titel      : " << _title << endl;
		cout << "salary     : " << _salary << endl;
		cout << "---------------------------\n";
	}

};

