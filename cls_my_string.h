#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class cls_my_string
{
private:
    string _value;

public:

    cls_my_string() { _value = ""; }
    cls_my_string(string s1) { _value = s1; }

    void set_string(string s1) { _value = s1; }
    string get_string() { return _value; }

    __declspec(property(get = get_string, put = set_string)) string Value;

    // ==============================
    static string lower_all_string(string s1)
    {
        for (int i = 0; i < s1.length(); i++)
            s1[i] = tolower(s1[i]);

        return s1;
    }
    void lower_all_string()
    {
        _value = lower_all_string(_value);
    }

    // ==============================
    static short how_many_words_in_string(string s1)
    {
        short counter = 0;
        string delim = " ";
        short pos = 0;
        string s_word;

        while ((pos = s1.find(delim)) != string::npos)
        {
            s_word = s1.substr(0, pos);

            if (s_word != "")
                counter++;

            s1.erase(0, pos + delim.length());
        }

        if (s1 != "")
            counter++;

        return counter;
    }
    short how_many_words_in_string()
    {
        return how_many_words_in_string(_value);
    }

    // ==============================
    static vector<string> split_string(string s1, string delim = " ")
    {
        vector<string> v_string;
        short pos = 0;
        string s_word;

        while ((pos = s1.find(delim)) != std::string::npos)
        {
            s_word = s1.substr(0, pos);

            if (s_word != "")
            {
                v_string.push_back(s_word);
            }

            s1.erase(0, pos + delim.length());
        }

        if (s1 != "")
            v_string.push_back(s1);

        return v_string;
    }
    vector<string> split(string delim = " ")
    {
        return split_string(_value, delim);
    }

    // ==============================
    static string trim_left(string s1)
    {
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != ' ')
                return s1.substr(i);
        }
        return "";
    }
    void trim_left()
    {
        _value = trim_left(_value);
    }

    // ==============================
    static string trim_right(string s1)
    {
        for (int i = s1.length() - 1; i >= 0; i--)
        {
            if (s1[i] != ' ')
                return s1.substr(0, i + 1);
        }
        return "";
    }
    void trim_right()
    {
        _value = trim_right(_value);
    }

    // ==============================
    static string join_string(vector<string> v_string, string delim = " ")
    {
        string s2;

        for (int i = 0; i < v_string.size(); i++)
        {
            s2 += v_string[i];
            if (i != v_string.size() - 1)
                s2 += delim;
        }

        return s2;
    }

    static string join_string(string arr_string[], string delim = " ")
    {
        string s2;

        for (int i = 0; i < arr_string->size(); i++)
        {
            s2 += arr_string[i];
            if (i != arr_string->size() - 1)
                s2 += delim;
        }

        return s2;
    }
    // ==============================
    static string revers_word(string s1)
    {
        vector<string> v = split_string(s1);
        string s2;

        for (int i = v.size() - 1; i >= 0; i--)
        {
            s2 += v[i];
            if (i != 0) s2 += " ";
        }

        return s2;
    }
    void revers_word()
    {
        _value = revers_word(_value);
    }

    // ==============================
    static string replace_word(string s1, string word1, string word2, bool ignore_case = true)
    {
        vector<string> v = split_string(s1);

        for (string& word : v)
        {
            if (ignore_case)
            {
                if (lower_all_string(word) == lower_all_string(word1))
                    word = word2;
            }
            else
            {
                if (word == word1)
                    word = word2;
            }
        }

        return join_string(v);
    }
    void replace_word(string word1, string word2, bool ignore_case = true)
    {
        _value = replace_word(_value, word1, word2, ignore_case);
    }

    // ==============================
    static string delete_punctautions(string s1)
    {
        string s2;

        for (char c : s1)
        {
            if (!ispunct(c))
                s2 += c;
        }

        return s2;
    }
    void delete_punctautions()
    {
        _value = delete_punctautions(_value);
    }

    // ==============================
    static string upper_all_string(string s1)
    {
        for (int i = 0; i < s1.length(); i++)
            s1[i] = toupper(s1[i]);

        return s1;
    }
    void upper_all_string()
    {
        _value = upper_all_string(_value);
    }

    // ==============================
    static string invert_char_in_all_string(string s1)
    {
        for (int i = 0; i < s1.length(); i++)
        {
            s1[i] = isupper(s1[i]) ? tolower(s1[i]) : toupper(s1[i]);
        }
        return s1;
    }
    void invert_char_in_all_string()
    {
        _value = invert_char_in_all_string(_value);
    }

    // ==============================
    enum en_what_to_count { small_letter = 0, capital_letter = 1, all = 2 };

    static int count_letters(string s1, en_what_to_count what = all)
    {
        if (what == all)
            return s1.length();

        int counter = 0;

        for (char c : s1)
        {
            if (what == capital_letter && isupper(c)) counter++;
            if (what == small_letter && islower(c)) counter++;
        }

        return counter;
    }
    int count_letters(en_what_to_count what = all)
    {
        return count_letters(_value, what);
    }

    // ==============================
    static bool is_char_vowel(char c)
    {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    static int count_vowel_latter(string s1)
    {
        int counter = 0;

        for (char c : s1)
        {
            if (is_char_vowel(c))
                counter++;
        }

        return counter;
    }
    int count_vowel_latter()
    {
        return count_vowel_latter(_value);
    }

};