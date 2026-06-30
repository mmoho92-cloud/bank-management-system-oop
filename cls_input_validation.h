#pragma once
#include "cls_date.h"
#include "cls_period.h"
#include "util.h"
#include "cls_my_string.h"
class cls_input_validation
{

public:
	static bool is_number_between(int number, int from, int to)
	{
		return number >= from && number <= to;
	}
	static bool is_number_between(double number, double from, double to)
	{
		return number >= from && number <= to;
	}
	static bool is_number_between(short number, short from, short to)
	{
		return number >= from && number <= to;
	}
	static bool is_number_between(long number, long from, long to)
	{
		return number >= from && number <= to;
	}
	static bool is_number_between(float number, float from, float to)
	{
		return number >= from && number <= to;
	}

	//===========================================
	////static bool is_date_between(cls_date date, cls_date from, cls_date to)
	//{
	//	return (cls_period::is_date_within_period(cls_period(from, to), date))
	//		|| (cls_period::is_date_within_period(cls_period(to, from), date));
	//}
	//===========================================
	static int read_int_number(string massege = "Invalid Number, Enter again\n")
	{
		int number;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << massege;
		}
		return number;
	}
	static int read_int_number_between(int from, int to, string massege = "Number is not within range, Enter again:\n")
	{
		int number;
		while (true)
		{
			number = read_int_number();
			if (is_number_between(number, from, to))
			{
				return number;
			}
			else
			{
				cout << massege;
			}
		}
	}
	static double read_double_number(string massege = "Invalid Number, Enter again\n")
	{
		double number;
		while (true)
		{

			cin >> number;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << massege;
			}
			else
			{
				return number;
			}
		}
	}
	static double read_double_number_between(double from, double to, string massege = "Number is not within range, Enter again:\n")
	{
		double number;
		while (true)
		{
			number = read_double_number();
			if (is_number_between(number, from, to))
			{
				return number;
			}
			else
			{
				cout << massege;
			}
		}
	}
	static float read_float_number(string massege = "Invalid Number, Enter again\n")
	{
		float number;
		while (true)
		{
			cout << massege << endl;
			cin >> number;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << massege;
			}
			else
			{
				return number;
			}
		}
	}
	//===========================================
	static bool is_valid_date(cls_date date)
	{
		return cls_date::validate_date(date);
	}
	//===========================================
	static string read_string(string massege = "")
	{
		string  S1 = "";
		cout << massege << endl;
		getline(cin >> ws, S1);
		return S1;
	}
	static char read_char(string massege = "Invalid Character, Enter again\n", string valid_characters = "")
	{
		char ch;
		while (true)
		{
			cin >> ch;
			if (cin.fail() || (!valid_characters.empty() && valid_characters.find(ch) == string::npos))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << massege;
			}
			else
			{
				return ch;
			}
		}
	}

};