#pragma once
#include "otherTask.h"

using namespace std;

void otherTask::setTimetable()
{
    ofstream ofs;
    ofs.open("Timetable.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    
    fstream file;
    system("cls");
    if (modeB)
        cout << "running setTimetable function(to set Timetable) in otherTask child class " << endl << endl;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "----------------------------------------- Set Time Table ----------------------------------------------" << endl;
    cout << "\nEnter the subject codes" <<  endl;
    file.open("Timetable.txt", ios::app | ios::out);
    cout << "\n\n\t\t---------Monday---------- "  << "\n";
    day = "Monday";
    cout << "\t\tMorning: ";
    //getline(cin, subMorning);
    cin >> subMorning;
    cout << "\t\tEvening: ";
    //getline(cin, subEvening);
    cin >> subEvening;

    file << " " << day << " " << subMorning << " "<< subEvening << "\n";

    cout << "\n\n\t\t---------Tuesday---------- " << "\n";
    day = "Tuesday";
    cout << "\t\tMorning: ";
    cin >> subMorning;
    //getline(cin, subMorning);
    cout << "\t\tEvening: ";
    cin >> subEvening;
    //getline(cin, subEvening);

    file << " " << day << " " << subMorning << " " << subEvening << "\n";

    cout << "\n\n\t\t---------Wednesday---------- " << "\n";
    day = "Wednesday";
    cout << "\t\tMorning: ";
    cin >> subMorning;
    //getline(cin, subMorning);
    cout << "\t\tEvening: ";
    cin >> subEvening;
    //getline(cin, subEvening);

    file << " " << day << " " << subMorning << " " << subEvening << "\n";

    cout << "\n\n\t\t---------Thursday---------- " << "\n";
    day = "Thursday";
    cout << "\t\tMorning: ";
    cin >> subMorning;
    //getline(cin, subMorning);
    cout << "\t\tEvening: ";
    cin >> subEvening;
    //getline(cin, subEvening);

    file << " " << day << " " << subMorning << " " << subEvening << "\n";

    cout << "\n\n\t\t---------Friday---------- " << "\n";
    day = "Friday";
    cout << "\t\tMorning: ";
    cin >> subMorning;
    //getline(cin, subMorning);
    cout << "\t\tEvening: ";
    cin >> subEvening;
    //getline(cin, subEvening);

    file << " " << day << " " << subMorning << " " << subEvening << "\n";
    file.close();

}

void otherTask::viewShedule()
{
    system("cls");
    if (modeB)
        cout << "running viewShedule function(to view Timetable) in otherTask child class " << endl << endl;
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------- Timetable --------------------------------------------------" << endl << endl << endl;;
    file.open("Timetable.txt", ios::in);

    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> day >> subMorning >> subEvening;

        while (!file.eof())
        {
            cout << "\tDay     : " << day << endl;
            cout << "\tMorning : " << subMorning << endl;
            cout << "\tEvening : " << subEvening << endl;
            cout << endl;
            file >> day >> subMorning >> subEvening;
        }

        file.close();
    }

    cout << "\n\n----------------If you need the change timetable, goto set timetable and retype-----------------" << endl;
}

void otherTask::message()
{
    fstream file;
    system("cls");
    if (modeB)
        cout << "running message function(to give messages ) in otherTask child class " << endl << endl;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "----------------------------------------- Set Messages ----------------------------------------------" << endl;
    cout << "\n\n\tDo you want to clear before messages, \n\t\t Enter 1 for clear \n\t\t Enter 0 for not clear \n\n\t Enter the choice : ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        ofstream ofs;
        ofs.open("messages.txt", std::ofstream::out | std::ofstream::trunc);
        ofs.close();
        system("cls");
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------------- Set Messages ----------------------------------------------" << endl;
        cout << "\n\n\tEnter the messages : " << endl<<endl;
        cin.ignore();
        getline(cin,msg);
 
        file.open("messages.txt", ios::app | ios::out);
        file << msg << "\n";
        file.close();
    }
    else if (choice == 0) {
        system("cls");
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------------- Set Messages ----------------------------------------------" << endl;
        cout << "\n\n\tEnter the messages : " << endl << endl;
        cin.ignore();
        getline(cin,msg);
        file.open("messages.txt", ios::app | ios::out);
        file << msg << "\n";
        file.close();
    }
}

void otherTask::viewMessageUser()
{

    system("cls");
    if (modeB)
        cout << "running viewmessage function(to view message) in studentView class " << endl << endl;
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------- Messages --------------------------------------------------" << endl << endl << endl;;
    file.open("messages.txt", ios::in);

    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> msg;
        string line;
        int i = 0;
        while (getline(file, line)) {
            cout << "Message [" << ++i << "]: " << line << endl;
        }

        file.close();
    }
}