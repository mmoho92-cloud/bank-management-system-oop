#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "cls_my_string.h"

class cls_currency
{
	enum en_mode { empty_mode = 0, update_mode = 1};
	en_mode _mode;
	string _contry;
	string _currency_name;
	string _currency_code;
	float _rate;

	static cls_currency _convert_line_to_currency_object(string Line, string Seperator = "#//#")
	{
		vector<string> v_currency_data;
		v_currency_data = cls_my_string::split_string(Line, Seperator);
		return cls_currency(en_mode::update_mode, v_currency_data[0], v_currency_data[1], v_currency_data[2], stof(v_currency_data[3]));
	}

	static string _convert_currency_object_to_line(cls_currency Currency, string Seperator = "#//#")
	{
		string CurrencyRecord = "";
		CurrencyRecord += Currency._contry + Seperator;
		CurrencyRecord += Currency._currency_code + Seperator;
		CurrencyRecord += Currency._currency_name + Seperator;
		CurrencyRecord += to_string(Currency._rate);
		return CurrencyRecord;
	}

	static vector <cls_currency> _load_currencies_data_from_file()
	{
		vector<cls_currency> v_currencies;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				v_currencies.push_back(_convert_line_to_currency_object(Line));
			}
			MyFile.close();
		}
		return v_currencies;
	}

	static void _save_currencies_data_to_file(vector<cls_currency> v_currencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open())
		{
			for (cls_currency& Currency : v_currencies)
			{
				MyFile << _convert_currency_object_to_line(Currency) << endl;
			}
			MyFile.close();
		}
	}

	void _update()
	{
		vector<cls_currency> v_currencies = _load_currencies_data_from_file();
		for (cls_currency& Currency : v_currencies)
		{
			if (Currency.currency_code() == currency_code())
			{
				Currency = *this;
				break;
			}
		}
		_save_currencies_data_to_file(v_currencies);
	}

	static cls_currency _get_empty_currency_object()
	{
		return cls_currency(en_mode::empty_mode, "", "", "", 0);
	}

public:
	cls_currency(en_mode mode, string contry, string currency_code, string currency_name, float rate)
	{
		_mode = mode;
		_contry = contry;
		_currency_name = currency_name;
		_currency_code = currency_code;
		_rate = rate;
	}

	bool is_empty()
	{
		return (_mode == en_mode::empty_mode);
	}

	string contry() { return _contry; }

	string currency_name() { return _currency_name; }

	string currency_code() { return _currency_code; }

	void update_rate(float new_rate)
	{
		_rate = new_rate;
	    _update();
	}

	float rate() 
	{ return _rate; }

	static cls_currency find_by_code(string currency_code)
	{
		currency_code = cls_my_string::upper_all_string(currency_code);
		vector<cls_currency> v_currencies = _load_currencies_data_from_file();
		for (cls_currency& Currency : v_currencies)
		{
			if (Currency.currency_code() == currency_code)
			{
				return Currency;
			}
		}
		return _get_empty_currency_object();
	}

	static cls_currency find_by_contry(string contry)
	{
		contry = cls_my_string::upper_all_string(contry);
		vector<cls_currency> v_currencies = _load_currencies_data_from_file();
		for (cls_currency& Currency : v_currencies)
		{
			if (cls_my_string::upper_all_string(Currency.contry()) == contry)
			{
				return Currency;
			}
		}
		return _get_empty_currency_object();
	}

	static bool is_currency_exist(string currency_code)
	{
		return (!find_by_code(currency_code).is_empty());
	}

	static vector <cls_currency> get_currencies_list()
	{
		return _load_currencies_data_from_file();
	}

	static vector <cls_currency> get_all_USD_rates()
	{
		vector<cls_currency> v_currencies = _load_currencies_data_from_file();
		vector<cls_currency> v_USD_rates;
		for (cls_currency& Currency : v_currencies)
		{
			if (Currency.currency_code() != "USD")
			{
				v_USD_rates.push_back(Currency);
			}
		}
		return v_USD_rates;
	}


};

