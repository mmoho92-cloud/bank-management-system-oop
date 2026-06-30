#pragma warning(disable : 4996)
#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class cls_date
{
private:
    int _day = 1;
    int _month = 1;
    int _year = 1900;
    struct st_time {
		int _hour;
		int _minute;
		int _second;
    };
    static void print_header_of_calender(int month)
    {
        string months[12] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
        };
        string days[7] = {
          "Sun",
          "Mon",
          "Tue",
          "Wed",
          "Thu",
          "Fri",
          "Sat"
        };

        cout << "----------------" << months[month - 1] << "----------------" << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << setw(5) << days[i];
        }
        cout << endl;
    }
public:

    static bool is_year_leap(int year)
    {
        if (year % 400 == 0)
        {
            return true;
        }
        else
        {
            if (year % 4 == 0 && year % 100 != 0)
            {
                return true;
            }
            else {
                return false;
            }
        }

    }
    bool is_year_leap()
    {
        return is_year_leap(_year);
    }

    static int dayes_in_year(int year)
    {
        return is_year_leap(year) ? 366 : 365;
    }
    int dayes_in_year()
    {
        return dayes_in_year(_year);
    }

    static int how_many_days_in_month(int year, int month)
    {

        int number_of_dayes_in_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (month == 2) ? (is_year_leap(year) ? 29 : 28) : number_of_dayes_in_month[month - 1];

    }
    int how_many_days_in_month()
    {
        return how_many_days_in_month(_year, _month);
    }

    static int index_day_in_week(cls_date date)
    {

        int a = (14 - date._month) / 12;
        int y = date._year - a;
        int m = date._month + (12 * a) - 2;
        return (date._day + y + ((y / 4) - (y / 100)) + (y / 400) + ((31 * m) / 12)) % 7;

    }
    int index_day_in_week()
    {
        return index_day_in_week(*this);
    }

    static string name_of_day_in_week(cls_date date)
    {
        int index = index_day_in_week(date);
        string days[7] = {
           "Sunday",
           "Monday",
           "Tuesday",
           "Wednesday",
           "Thursday",
           "Friday",
           "Saturday"
        };
        return days[index];
    }
    string name_of_day_in_week()
    {
        return name_of_day_in_week(*this);
    }

    static int read_day(short year, short month)
    {
        int number_of_dayes_in_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (month == 2) ? (is_year_leap(year) ? 29 : 28) : number_of_dayes_in_month[month - 1];
    }

    static void print_calnder_of_month(int month, int year)
    {
        print_header_of_calender(month);
        int index = index_day_in_week(cls_date(1, month, year));
        int days_of_month = read_day(year, month);
        int i = 0;
        for (i = 0; i < index; i++)
        {
            cout << setw(5) << " ";
        }

        for (int j = 1; j <= days_of_month; j++)
        {
            cout << setw(5) << j;
            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }

        cout << "\n\n----------------------------------------\n\n";

    }
    void print_calnder_of_month()
    {
        print_calnder_of_month(_month, _year);
    }

    static void print_calnder_of_year(cls_date date)
    {
        cout << "-----------------------------------------" << endl;
        cout << "          CALNDER OF " << date._year << "      " << endl;
        cout << "-----------------------------------------" << endl;

        int j = 0;

        for (int i = 1; i <= 12; i++)
        {
            print_calnder_of_month(i, date._year);
            if (++j == 3)
            {
                j = 0;
                printf("\n");
            }
        }
    }
    void print_calnder_of_year()
    {
        print_calnder_of_year(*this);
    }

    static int days_counter_from_begining_of_year(cls_date date)
    {
        int counter = 0;
        int total = 0;
        for (int i = 1; i < date._month; i++)
        {
            counter += how_many_days_in_month(date._year, i);
        }
        total += counter + date._day;
        return total;
    }
    int days_counter_from_begining_of_year()
    {
        return days_counter_from_begining_of_year(*this);
    }

    static cls_date date_from_day(int year, int days)
    {
        cls_date date;
        int month = 1;

        while (days > how_many_days_in_month(year, month))
        {
            days -= how_many_days_in_month(year, month);
            month++;
        }

        date._day = days;
        date._month = month;
        date._year = year;

        return date;
    }
    cls_date date_from_day()
    {
        return date_from_day(_year, _day);
    }

    static cls_date date_after_adding_days(cls_date date, int days_you_want_to_add)
    {
        int month2 = date._month;
        int day2 = date._day;
        int year2 = date._year;

        days_you_want_to_add += days_counter_from_begining_of_year(date);
        month2 = 1;
        while (days_you_want_to_add > how_many_days_in_month(year2, month2))
        {
            days_you_want_to_add -= how_many_days_in_month(year2, month2);
            month2++;
            if (month2 > 12)
            {
                month2 = 1;
                year2++;
            }
        }

        date._day = days_you_want_to_add;
        date._month = month2;
        date._year = year2;

        return date;
    }
    cls_date date_after_adding_days(int days_you_want_to_add)
    {
        return date_after_adding_days(*this, days_you_want_to_add);
    }

    static bool is_date1_before_date2(cls_date date1, cls_date date2)
    {
        return (date1._year < date2._year) ? true : ((date1._year == date2._year) ? (date1._month < date2._month ? true : (date1._month == date2._month ? date1._day < date2._day : false)) : false);
    }
    bool is_current_date_before_this_date(cls_date date2)
    {
        return is_date1_before_date2(*this, date2);
    }

    static bool is_date1_after_date2(cls_date date1, cls_date date2)
    {
        return (!is_dates_equal(date1, date2) && !is_date1_before_date2(date1, date2));
    }
    bool is_current_date_after_this_date(cls_date date2)
    {
        return is_date1_after_date2(*this, date2);
    }

    static bool is_dates_equal(cls_date date1, cls_date date2)
    {
        return (date1._year == date2._year && date1._month == date2._month && date1._day == date2._day);
    }
    bool is_current_date_equal_with_this_date(cls_date date2)
    {
        return is_dates_equal(*this, date2);
    }

    static bool is_day_the_last_day_in_month(cls_date date)
    {
        return (date._day == how_many_days_in_month(date._year, date._month));
    }
    bool is_day_the_last_day_in_month()
    {
        return is_day_the_last_day_in_month(*this);
    }

    static bool is_month_is_last_month_in_the_year(int month)
    {
        return (month == 12);
    }
    bool is_month_is_last_month_in_the_year()
    {
        return is_month_is_last_month_in_the_year(_month);
    }

    static cls_date increase_date_by_one_day(cls_date date)
    {
        if (is_day_the_last_day_in_month(date) && is_month_is_last_month_in_the_year(date._month))
        {
            date._day = 1;
            date._month = 1;
            date._year++;
        }
        else if (is_day_the_last_day_in_month(date))
        {
            date._day = 1;
            date._month++;
        }
        else
        {
            date._day++;
        }
        return date;
    }
    cls_date increase_date_by_one_day()
    {
        return increase_date_by_one_day(*this);
    }

    static int defrence_betwen_two_date(cls_date date1, cls_date date2, bool w = false)
    {
        int counter = 0;
        while (date1._year != date2._year || date1._month != date2._month || date1._day != date2._day)
        {
            increase_date_by_one_day(date1);
            counter++;
        }
        if (w)
            return counter + 1;
        else
            return counter;
    }
    int defrence_betwen_current_date_and_this_date(cls_date date2)
    {
        return defrence_betwen_two_date(*this, date2);
    }

    static cls_date get_curent_date()
    {
        cls_date date;
        time_t t = time(0);
        tm* now = localtime(&t);
        date._day = now->tm_mday;
        date._month = now->tm_mon + 1;
        date._year = now->tm_year + 1900;
        return date;
    }

    static st_time get_curent_time()
    {
        st_time result;
        time_t t = time(0);
        tm* now = localtime(&t);
        result._hour = now->tm_hour;
        result._minute = now->tm_min;
        result._second = now->tm_sec;
        return result;
	}

    static string time_to_string(st_time time)
    {
        return to_string(time._hour) + ":" + to_string(time._minute) + ":" + to_string(time._second);
	}

    static int your_age_in_days(cls_date date_of_birth)
    {
        return defrence_betwen_two_date(date_of_birth, date_of_birth.get_curent_date(), true);
    }

    static void print_date_with_day_of_week(cls_date date, string massege)
    {
        cout << massege << name_of_day_in_week(date);
        printf(" %d/%d/%d \n", date._day, date._month, date._year);
    }
    void print_date_with_day_of_week(string massege)
    {
        print_date_with_day_of_week(*this, massege);
    }

    static string date_to_string(cls_date Date)
    {
        return to_string(Date._day) + "/" + to_string(Date._month) +
            "/" + to_string(Date._year);
    }
    string date_to_string()
    {
        return date_to_string(*this);
    }

    void print_date()
    {
        cout << date_to_string(*this);
    }

    static bool validate_date(cls_date date)
    {
        if (date._year < 1) return false;
        if (date._month > 12 || date._month < 1) return false;
        if (date._day < 1 || date._day > how_many_days_in_month(date._year, date._month)) return false;
        return true;
    }
    bool validate_date()
    {
        return validate_date(*this);
    }

    enum en_dates_compare { befor = -1, equel = 0, after = 1 };

    static void swap_dates(cls_date& date1, cls_date& date2)
    {
        cls_date temp = date1;
        date1 = date2;
        date2 = temp;
    }

    cls_date ()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        _day = now->tm_mday;
        _month = now->tm_mon + 1;
        _year = now->tm_year + 1900;
    }
    cls_date(int day, int month, int year)
    {
        _day = day;
        _month = month;
        _year = year;
    }
    cls_date(string date)
    {
        _day = stoi(date.substr(0, date.find('/')));
        date.erase(0, date.find('/') + 1);
        _month = stoi(date.substr(0, date.find('/')));
        date.erase(0, date.find('/') + 1);
        _year = stoi(date);
    }
    cls_date(int days_from_begining_of_year, int year)
    {
        *this = date_from_day(year, days_from_begining_of_year);
    }

};