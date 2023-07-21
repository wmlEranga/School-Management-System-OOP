#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include "user.h"
#include "analysMark.h"
#include "studentView.h"
#include "otherTask.h"
#include <regex>

#pragma warning(disable : 4996)

using namespace std;

int main() 
{
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Student Mode" << endl;
    cout << "\t\t\t 0. Regular Mode" << endl;
    char modeChar;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/0]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << " Enter Your Choose: ";
    cin >> modeChar;

    if (modeChar != '1' && modeChar != '0') {
        cout << "\n\n\t Invalid nput....! Press ENTER to back.";
        getch();
        main();

    }
    bool mode;
    if (modeChar == '1') {
        mode = 1;
    }
    else if (modeChar == '0') {
        mode = 0;
    }

    system("cls");
    cout << "\n--------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------ LOGIN FORM --------------------------------------------------" << endl;
    cout << "\t\t\t\t    1. Login as the teacher" << endl;
    cout << "\t\t\t\t    2. Login as the student" << endl;
    int userType;
    cout << ".........................................................................................................." << endl;
    cout << "\t\t\t\t    Choose Options:[1/2]" << endl;
    cout << "..........................................................................................................." << endl;
    cout << " Enter Your Choose: ";
    cin >> userType;


    bool choice3 = 0;
    fstream accFile;
    accFile.open("AccessMark.txt", ios::app | ios::out);
    accFile << " " << choice3 << "\n";
    accFile.close();
    if (userType == 1) {
    menu:
        system("cls");
        string username,password;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t|         LOGIN FORM         |" << endl;
        cout << "\t\t\t-----------------------------" << endl<<endl;
        cout << "\t\t\t User name: ";
        cin >> username;
        cout << "\t\t\t password : ";
        cin >> password;

        if ((username == "admin") && (password == "admin123")) {
        menuTeacher:
            int choice,choice2;
            char x;
            system("cls");
            user teacher(mode);
            cout << "\n\n\t\t\t 1. Enter New Student" << endl;
            cout << "\t\t\t 2. Display details of the students" << endl;
            cout << "\t\t\t 3. Modify a student" << endl;
            cout << "\t\t\t 4. Search a student" << endl;
            cout << "\t\t\t 5. Delete a student" << endl;
            cout << "\t\t\t 6. Go to exam Dashboard" << endl;
            cout << "\t\t\t 7. Set Timetable" << endl;
            cout << "\t\t\t 8. View Timetable" << endl;
            cout << "\t\t\t 9. Give Messages" << endl;
            cout << "\t\t\t 10. View messages that given" << endl;
            
            cout << "\t\t\t 0. Exit\n"<< endl;

            cout << "\t\t\t......................................." << endl;
            cout << "\t\t\tChoose Options:[1/2/3/4/5/6/7/8/9/10/0]" << endl;
            cout << "\t\t\t......................................." << endl;
            cout << " Enter Your Choicee: ";
            cin >> choice;
            
            analysMark teacherB(mode);
            otherTask teacherC(mode);
            switch (choice)
            {
            case 1:
                teacher.insert();
                cout << "\n\n\t\t\t Do you need a another task ? (Y, N) : ";
                cin >> x;
                if (x == 'Y' || x == 'y')
                    goto menuTeacher;
                else
                    cout << "\n\t\t\t Program Is Exit";
                    exit(0);
                break;
            case 2:
                teacher.display();
                break;
            case 3:
                teacher.modify();
                break;
            case 4:
                teacher.search();
                break;
            case 5:
                teacher.deleted();
                break;
            case 6:
            menuTeacher2:               
                system("cls");
                cout << "\t\t\t-----------------------------" << endl;
                cout << "\t\t\t|       EXAM DASHBOARD       |" << endl;
                cout << "\t\t\t-----------------------------" << endl << endl;
                cout << "\t\t\t 1. Enter all marks of the " << endl;
                cout << "\t\t\t 2. View the mark list" << endl;
                cout << "\t\t\t 3. Modify the marks" << endl;
                cout << "\t\t\t 4. Search the mark of a student" << endl;
                cout << "\t\t\t 5. View the Grade of the students" << endl; 
                cout << "\t\t\t 6. Giva access to children for Exam marks" << endl;
                cout << "\t\t\t 7. Back to Teacher Dashboard" << endl;
                cout << "\t\t\t 0. Exit\n" << endl;

                cout << "\t\t\t............................" << endl;
                cout << "\t\t\tChoose Options:[1/2/3/4/5/6/0]" << endl;
                cout << "\t\t\t............................" << endl;
                cout << " Enter Your Choose: ";
                cin >> choice2;
                
                switch (choice2)
                {
                case 1:
                    system("cls");
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------ Add Mark of the students -----------------------------------------" << endl;
                    cout << "\n\n\t\tHere all the data has to be entered again. Enter 1 if you like it. : ";
                    bool opinion;
                    cin >> opinion;
                    if (opinion != 1 && opinion != 0) {
                        cout << " \n\n\t\t Your Input is incorrect... please try again...";
                        goto menuTeacher2;
                    }
                    else if (opinion == 0) {
                        cout << " \n\n\t\t press Enter to go Teacher Dashboard...";
                        goto menuTeacher2;
                    }

                    teacherB.addMark(opinion);
                    break;
                case 2:
                    teacherB.displayMark();
                    break;
                case 3:
                    teacherB.modifyMark();
                    break;
                case 4:
                    teacherB.searchMark();
                    break;
                case 5:
                    teacherB.viewGrade();
                    break;
                case 6:
                    system("cls");
                    cout << "\n---------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------ Give Access for Exam Marks -----------------------------------------" << endl;
                    cout << "\n\n\t If exam Marks is Ready, Give the Access...  ( Enter 1 for access/ Enter 0 for No access)" << endl;
                    cout << "\n\t\t Your choice : ";
                    cin >> choice3;
                    if (choice3 == 1) {
                        teacherB.viewGrade();
                        ofstream ofs;
                        ofs.open("AccessMark.txt", std::ofstream::out | std::ofstream::trunc);
                        ofs.close();

                        fstream accFile;
                        accFile.open("AccessMark.txt", ios::app | ios::out);
                        accFile << " " << choice3 << "\n";
                        accFile.close();
                        cout << "\n\n\t That is the Final report... Accessed for students...";
                    }
                    else if (choice3 == 0) {
                        cout << "\n\n\t Did not Access Final Marks for students...";
                        ofstream ofs;
                        ofs.open("AccessMark.txt", std::ofstream::out | std::ofstream::trunc);
                        ofs.close();
                        fstream accFile;
                        accFile.open("AccessMark.txt", ios::app | ios::out);
                        accFile << " " << choice3 << "\n";
                        accFile.close();
                    }
                    else {
                        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
                    }
                    break;
                case 7:
                    goto menuTeacher;
                    break;
                case 0:
                    cout << "\n\t\t\t Program Is Exit\n\n\n";
                    exit(0);
                    break;
                default:
                    cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
                };

                cout << "\n\n\t\tpress Enter to go Exam Dashboard...";
                getch();
                goto menuTeacher2;
                break;
            case 7:
                teacherC.setTimetable();
                break;
            case 8:
                teacherC.viewShedule();
                break;
            case 9:
                teacherC.message();
                break;
            case 10:
                teacherC.viewMessageUser();
                break;
            case 0:
                cout << "\n\t\t\t Program Is Exit\n\n\n";
                exit(0);
                break;
            default:
                cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
            }
            cout << "\n\n\t\tpress Enter to go Teacher Dashboard...";
            getch();
            goto menuTeacher;
        }

        else {
            cout << "\n\t\t\t incorrect password or email..! try again... ";
            getch();
            goto menu;
        }
    }
    else if (userType == 2){
    menu2:
        system("cls");
        string indexNo, password;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t|         LOGIN FORM         |" << endl;
        cout << "\t\t\t-----------------------------" << endl << endl;
        cout << "\t\t\t Index No.: ";
        cin >> indexNo;
        cout << "\t\t\t password : ";
        cin >> password;
        system("cls");
        studentView student(mode);

        if (student.checkLoginData(indexNo,password)) {
        menuStudent:
            system("cls");
            int choice;
            if (mode)
                cout << "created a object regarding the studentView class " << endl << endl;
            cout << "\n\n\t\t\t 1. View my data" << endl;
            cout << "\t\t\t 2. View my Exam Result" << endl;
            cout << "\t\t\t 3. View Timetable" << endl;
            cout << "\t\t\t 4. View Messages" << endl;
            cout << "\t\t\t 0. Exit\n" << endl;

            cout << "\t\t\t.........................." << endl;
            cout << "\t\t\tChoose Options:[1/2/3/4/0]" << endl;
            cout << "\t\t\t.........................." << endl;
            cout << " Enter Your Choose: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                student.viewData(indexNo);
                break;
            case 2:
                accFile.open("AccessMark.txt", ios::in);
                accFile >> choice3;
                accFile.close();
                if (choice3) {
                    student.viewGrade(indexNo);
                }
                else {
                    cout << "\n\n\t\t\t Not accessed yet ... Please Try Again shortly...";
                }
                
                break;
            case 3:
                student.viewTimetable();
                break;
            case 4:
                student.viewMessage();
                break;
            case 0:
                cout << "\n\t\t\t Program Is Exit";
                exit(0);
            default:
                cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";

            }
            cout << "\n\n\t\tpress Enter to go Student Dashboard...";
            getch();
            goto menuStudent;
        }
        else {
            cout << "\t\t\tIncorrect Password or Email...Try again...!" << endl;
            getch();
            goto menu2;
        }

    }
    else {
        cout << "\n\t\t\t invalid input......! ";
        getch();
        system("cls");
        main();
    }
}