#pragma once
#pragma once
#include <iostream>
#include "cls_user.h"
#include "global.h"
#include "cls_date.h"


using namespace std;
class cls_screen
{
protected:
    static void _draw_screen_header(string Title, string SubTitle = "")
    {
		system("cls");
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

		cls_date date = cls_date::get_curent_date();
		string current_user_name = current_user.user_name;
		cout << "\t\t\t\t\t user:" << current_user_name <<endl;
        cout << "\t\t\t\t\t date:"; date.print_date();
        cout << "\n\t\t\t\t\t______________________________________\n";

    }

	static bool check_accsess_rights(cls_user::en_permissions permission)
    {
		if (!current_user.check_acsses_permissions(permission))
       {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        
       }
    }

    



};

