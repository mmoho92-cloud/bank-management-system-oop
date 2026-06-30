#pragma once
#include <iostream>
#include <string>
#include "cls_date.h"

using namespace std;

class util
{

public:
    enum en_char_type {
        samall_letter = 1, capital_letter = 2,
        digit = 3, mix_chars = 4, special_character = 5
    };

    static void  Srand()
    {
        srand((unsigned)time(NULL));
    }

    static  int random_number(int From, int To)
    {

        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char get_random_char(en_char_type char_type)
    {

        if (char_type == mix_chars)
        {
            char_type = (en_char_type)random_number(1, 3);

        }

        switch (char_type)
        {

        case en_char_type::samall_letter:
        {
            return char(random_number(97, 122));
            break;
        }
        case en_char_type::capital_letter:
        {
            return char(random_number(65, 90));
            break;
        }
        case en_char_type::special_character:
        {
            return char(random_number(33, 47));
            break;
        }
        case en_char_type::digit:
        {
            return char(random_number(48, 57));
            break;
        }
    defualt:
        {
            return char(random_number(65, 90));
            break;
        }
        }
    }

    static  string generate_word(en_char_type char_type, short length)

    {
        string Word;

        for (int i = 1; i <= length; i++)

        {

            Word = Word + get_random_char(char_type);

        }
        return Word;
    }

    static string  generate_key(en_char_type char_type = capital_letter)
    {

        string Key = "";


        Key = generate_word(char_type, 4) + "-";
        Key = Key + generate_word(char_type, 4) + "-";
        Key = Key + generate_word(char_type, 4) + "-";
        Key = Key + generate_word(char_type, 4);


        return Key;
    }

    static void generate_keys(short number_of_keys, en_char_type char_type)
    {

        for (int i = 1; i <= number_of_keys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << generate_key(char_type) << endl;
        }

    }

    static void fill_array_with_random_numbers(int arr[100], int arr_length, int from, int to)
    {
        for (int i = 0; i < arr_length; i++)
            arr[i] = random_number(from, to);
    }

    static void fill_array_with_random_words(string arr[100], int arr_length, en_char_type char_type, short word_length)
    {
        for (int i = 0; i < arr_length; i++)
            arr[i] = generate_word(char_type, word_length);

    }

    static void fill_array_with_random_keys(string arr[100], int arr_length, en_char_type char_type)
    {
        for (int i = 0; i < arr_length; i++)
            arr[i] = generate_key(char_type);
    }

    static  void swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void swap(cls_date& A, cls_date& B)
    {
        cls_date::swap_dates(A, B);

    }

    static  void shuffle_array(int arr[100], int arr_length)
    {

        for (int i = 0; i < arr_length; i++)
        {
            swap(arr[random_number(1, arr_length) - 1], arr[random_number(1, arr_length) - 1]);
        }

    }

    static  void shuffle_array(string arr[100], int arrL_length)
    {

        for (int i = 0; i < arrL_length; i++)
        {
            swap(arr[random_number(1, arrL_length) - 1], arr[random_number(1, arrL_length) - 1]);
        }

    }

    static string  tabs(short number_of_tabs)
    {
        string t = "";

        for (int i = 1; i < number_of_tabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string  encrypt_text(string text, short encryption_key)
    {

        for (int i = 0; i <= text.length(); i++)
        {

            text[i] = char((int)text[i] + encryption_key);

        }

        return text;

    }

    static string  decrypt_text(string text, short encryption_key)
    {

        for (int i = 0; i <= text.length(); i++)
        {

            text[i] = char((int)text[i] - encryption_key);

        }
        return text;

    }

    static string number_to_text(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + number_to_text(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + number_to_text(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   number_to_text(Number / 100) + "Hundreds " + number_to_text(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + number_to_text(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   number_to_text(Number / 1000) + "Thousands " + number_to_text(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + number_to_text(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   number_to_text(Number / 1000000) + "Millions " + number_to_text(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + number_to_text(Number % 1000000000);
        }
        else
        {
            return   number_to_text(Number / 1000000000) + "Billions " + number_to_text(Number % 1000000000);
        }


    }

};