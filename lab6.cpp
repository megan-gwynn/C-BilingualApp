// Name: Megan Gagliardi
// Date: 4/18/2022
// App: Bilingual App
// Desc: App where the user can choose between displaying the text in English or French

#include "iostream"
#include "fstream"

using namespace std;

const string BANNER1 = R"(
=================================
    Please choose a language
---------------------------------
  Veuillez choisir votre langue
=================================

)";

const string BANNER2 = R"(
=============================
= Welcome to Durham College =
=============================

)";

const string BANNER3 = R"(
===============================
= Bienvenue au College Durham =
===============================

)";

// enumeration with main menu options
enum Options {ENGLISH=1, FRENCH};

int main()
{
    // Display French accents
    system("chcp 65001");

    // set the title
    system("title Bilingual App - Megan Gagliardi");

    // variables
    int option;
    ifstream input_file; // read file
    ofstream output_file; // write file
    string name;
    string program;
    string file_name;
    string welcome_text;
    string student_name;
    string student_program;
    string student_file;
    string exit_prompt;

    while(true)
    {
        // print the banner
        // main menu
        cout << BANNER1
             << "1. English\n"
             << "2. Français\n"
             << "-> ";

        // get user input
        cin >> option;
        cin.clear();
        cin.sync();

        // invalid option
        if(option < ENGLISH || option > FRENCH)
        {
            cout << "Error - Invalid option";
        }

        // english option
        else if(option == ENGLISH)
        {
            system("cls");
            cout << BANNER2;

            input_file.open("english.lang");

            getline(input_file, welcome_text);
            cout << welcome_text;

            getline(input_file, student_name);
            cout << "\n" << student_name;
            cin >> name;

            getline(input_file, student_program);
            cout << student_program;
            cin >> program;
            cin.sync();

            getline(input_file, student_file);
            // format the file name
            file_name = name + ".data";
            output_file.open(file_name, ios::out);
            output_file << file_name;
            cout << student_file << file_name;

            // exit prompt
            getline(input_file, exit_prompt);
            cout << "\n" << exit_prompt;
            cin.get();

            input_file.close();
        }

        else if(option == FRENCH)
        {
            system("cls");
            cout << BANNER2;

            input_file.open("french.lang");

            getline(input_file, welcome_text);
            cout << welcome_text;

            getline(input_file, student_name);
            cout << "\n" << student_name;
            cin >> name;

            getline(input_file, student_program);
            cout << student_program;
            cin >> program;
            cin.sync();

            getline(input_file, student_file);
            // format the file name
            file_name = name + ".data";
            output_file.open(file_name, ios::out);
            output_file << file_name;
            cout << student_file << file_name;

            // exit prompt
            getline(input_file, exit_prompt);
            cout << "\n" << exit_prompt;
            cin.get();

            input_file.close();
        }

        // invalid option
        else
            cout << "error - invalid option";

    }
}