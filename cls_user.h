#pragma once
#include <iostream>
#include <string>
#include "cls_person.h"
#include "cls_my_string.h"
#include <vector>
#include <fstream>
#include "util.h"

class cls_user : public cls_person
{
private:

    enum en_mode { empty_mode = 0, update_mode = 1, add_new_mode = 2 };
    en_mode _mode;
    string _user_name;
    string _password;
    int _permissions;
    bool _marked_for_delete = false;

    static cls_user _convert_line_to_user_object(string Line, string Seperator = "#//#")
    {
        vector<string> v_user_data;
        v_user_data = cls_my_string::split_string (Line, Seperator);

        return cls_user(en_mode::update_mode, v_user_data[0], v_user_data[1], v_user_data[2],
            v_user_data[3], v_user_data[4], v_user_data[5], stoi(v_user_data[6]));

    }

    static cls_user _convert_line_to_user_object(string Line,short key , string Seperator = "#//#")
    {
        vector<string> v_user_data;
        v_user_data = cls_my_string::split_string(Line, Seperator);

        return cls_user(en_mode::update_mode, v_user_data[0], v_user_data[1], v_user_data[2],
            v_user_data[3], v_user_data[4], util::decrypt_text(v_user_data[5],3), stoi(v_user_data[6]));

    }

    static string _convert_user_object_to_line(cls_user User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.get_first_name() + Seperator;
        UserRecord += User.get_last_name() + Seperator;
        UserRecord += User.get_email() + Seperator;
        UserRecord += User.get_phone() + Seperator;
        UserRecord += User.user_name + Seperator;
        UserRecord += User.password + Seperator;
        UserRecord += to_string(User.permissions);

        return UserRecord;

    }

    static string _convert_user_object_to_line(cls_user User,  short key,string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.get_first_name() + Seperator;
        UserRecord += User.get_last_name() + Seperator;
        UserRecord += User.get_email() + Seperator;
        UserRecord += User.get_phone() + Seperator;
        UserRecord += User.user_name + Seperator;
        UserRecord += util::encrypt_text(User.password , key) + Seperator;
        UserRecord += to_string(User.permissions);

        return UserRecord;

    }

    static  vector <cls_user> _load_users_data_from_file()
    {

        vector <cls_user> v_users;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                cls_user User = _convert_line_to_user_object(Line,3);

                v_users.push_back(User);
            }

            MyFile.close();

        }

        return v_users;

    }

    static void _save_users_data_to_file(vector <cls_user> v_users)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (cls_user U : v_users)
            {
                if (U.marked_for_deleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _convert_user_object_to_line(U,3);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _update()
    {
        vector <cls_user> _v_users;
        _v_users = _load_users_data_from_file();

        for (cls_user& U : _v_users)
        {
            if (U.user_name == user_name)
            {
                U = *this;
                break;
            }

        }

        _save_users_data_to_file(_v_users);

    }

    void _add_new()
    {

        _add_data_line_to_file(_convert_user_object_to_line(*this,3));
    }

    void _add_data_line_to_file(string  st_data_line)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << st_data_line << endl;

            MyFile.close();
        }

    }

    static cls_user _get_empty_user_object()
    {
        return cls_user(en_mode::empty_mode, "", "", "", "", "", "", 0);
    }

    string _prepare_login_record(string seperator = "#//#")
    {
        string login_record = "";
        login_record +=cls_date::date_to_string( cls_date::get_curent_date() )+ seperator;
        login_record += cls_date::time_to_string(cls_date::get_curent_time()) + seperator;
        login_record += user_name + seperator;
        login_record += password + seperator;
        login_record += to_string(permissions);
        return login_record;
    }

    struct st_login_register;

    static st_login_register _convert_login_registers_to_record(string Line, string Seperator = "#//#")
    {
        vector<string> v_login_register_data;
        v_login_register_data = cls_my_string::split_string(Line, Seperator);
        return st_login_register{ v_login_register_data[0], v_login_register_data[1], v_login_register_data[2],
            v_login_register_data[3], stoi(v_login_register_data[4]) };
	}


public:

    enum en_permissions {
        p_all = -1, p_list_clients = 1, p_add_new_client = 2, p_delete_client = 4,
        p_update_client = 8, p_find_client = 16, p_show_transactions = 32,
		p_mange_users = 64, p_login_register_list = 128, p_currency_exchange = 256
	};
    cls_user(en_mode mode, string first_name, string last_name,
        string email, string phone, string user_name, string password,
        int permissions) :
        cls_person(first_name, last_name, email, phone)

    {
        _mode = mode;
        _user_name = user_name;
        _password = password;
        _permissions = permissions;
    }
    struct st_login_register {
        string date;
        string time;
        string user_name;
        string password;
        int permissions;
	};

    bool is_empty()
    {
        return (_mode == en_mode::empty_mode);
    }

    bool marked_for_deleted()
    {
        return _marked_for_delete;
    }

    string get_user_name()
    {
        return _user_name;
    }

    void set_user_name(string user_name)
    {
        user_name = user_name;
    }

    __declspec(property(get = get_user_name, put = set_user_name)) string user_name;

    void set_password (string password)
    {
        _password = password;
    }

    string get_password()
    {
        return _password;
    }
    __declspec(property(get = get_password, put = set_password)) string password;

    void set_permissions(int permissions)
    {
        _permissions = permissions;
    }

    int get_permissions()
    {
        return _permissions;
    }
    __declspec(property(get = get_permissions, put = set_permissions)) int permissions;

    static cls_user find(string user_name)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                cls_user User = _convert_line_to_user_object(Line);
                if (User.user_name == user_name)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _get_empty_user_object();
    }

    static cls_user find(string user_name, string password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                cls_user user = _convert_line_to_user_object(Line);
                if (user.user_name == user_name && util::decrypt_text(user.password,3) == password)
                {
                    MyFile.close();
                    return user;
                }

            }

            MyFile.close();

        }
        return _get_empty_user_object();
    }

    enum en_save_results { sv_faild_empty_object = 0, sv_succeeded = 1, sv_faild_user_exists = 2 };

    en_save_results save()
    {

        switch (_mode)
        {
        case en_mode::empty_mode:
        {
            if (is_empty())
            {
                return en_save_results::sv_faild_empty_object;
            }
        }

        case en_mode::update_mode:
        {
            _update();
            return en_save_results::sv_succeeded;

            break;
        }

        case en_mode::add_new_mode:
        {
            //This will add new record to file or database
            if (cls_user::Is_user_exist(user_name))
            {
                return en_save_results::sv_faild_user_exists;
            }
            else
            {
                _add_new();
                //We need to set the mode to update after add new
                _mode = en_mode::update_mode;
                return en_save_results::sv_succeeded;
            }

            break;
        }
        }

    }

    static bool Is_user_exist(string user_name)
    {

        cls_user User = cls_user::find(user_name);
        return (!User.is_empty());
    }

    bool Delete()
    {
        vector <cls_user> _vUsers;
        _vUsers = _load_users_data_from_file();

        for (cls_user& U : _vUsers)
        {
            if (U.user_name == user_name)
            {
                U._marked_for_delete = true;
                break;
            }

        }

        _save_users_data_to_file(_vUsers);

        *this = _get_empty_user_object();

        return true;

    }

    static cls_user get_add_new_user_object(string user_name)
    {
        return cls_user(en_mode::add_new_mode, "", "", "", "", user_name, "", 0);
    }

    static vector <cls_user> get_users_list()
    {
        return _load_users_data_from_file();
    }

    bool check_acsses_permissions(en_permissions permission)
    {
		if (this->permissions == en_permissions::p_all)
        {
            return true;
        }
        else
        {
            return ((this->permissions & permission) == permission);
        }

    }

    void add_new_login_register()
    {
        string st_data_line = _prepare_login_record();

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << st_data_line << endl;
        
        }
        MyFile.close();
    }

    static vector <st_login_register> get_login_register_list()
    {
        vector <st_login_register> v_registers;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                st_login_register User = _convert_login_registers_to_record(Line);

                v_registers.push_back(User);
            }

            MyFile.close();

        }

        return v_registers;

    }

    


    
};

