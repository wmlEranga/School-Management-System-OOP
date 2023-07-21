#pragma once
#include "studentView.h"

studentView::studentView(bool Mode)
{
    modeB = Mode;
    if(Mode)
		cout << "created a object regarding the studentView class "  << endl<< endl;
}

int studentView::noOfSub()
{
    fstream fileNoSub;
    int sub;
    fileNoSub.open("subRecord.txt", ios::in);
    fileNoSub >> sub;
    int sub3 = sub;
    fileNoSub >> sub;
    return sub3;

}

bool studentView::checkLoginData(string indexNo, string password) 
{
    fstream fileLogin;
    fileLogin.open("loginRecord.txt", ios::in);

    if (!fileLogin)
    {
        cout << "\n\t\t\tNo access to login now... ";
        fileLogin.close();
    }
    else
    {
        fileLogin >> indexID >> passwordID;
        while (!fileLogin.eof())
        {
            if (indexID == indexNo) {
                if (passwordID == password) {
                    return true;
                }
                else {
                    cout << "\t\t\tPassword is incorrect...! ";
                    return false;
                }
                
            }
 
            fileLogin >> indexID >>passwordID;
        }
    }
    return false;
    fileLogin.close();
}

void studentView::viewData(string indexNo)
{
    system("cls");
    if (modeB) {
        cout << "running viewData function(to view own personal data) in studentView class " << endl << endl;
    }
        

    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> DOB >> indexID >> email >> contact >> passwordID;
        while (!file.eof())
        {
            if (indexID == indexNo) {
                cout << "\t\t\tName: " << name << "\n";
                cout << "\t\t\tDOB: " << DOB << "\n";
                cout << "\t\t\tIndex No.: " << indexID << "\n";
                cout << "\t\t\tEmail Id: " << email << "\n";
                cout << "\t\t\tContact No.: " << contact << "\n";
                cout << "\t\t\tPassword: " << passwordID << "\n";
                
            }    
            file >> name >> DOB >> indexID >> email >> contact >> passwordID;
        }
        file.close();
    }

    
}

void studentView::viewGrade(string indexNo)
{
    system("cls");
    if (modeB)
        cout << "running viewGrade function(to view own exam results) in studentView class " << endl << endl;
    fstream file,fileMarks;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "----------------------------------------- Final REport ------------------------------------------------" << endl;
    file.open("Finalgrade.txt", ios::in);
    
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >>  indexID >> sum >> average >>  grade;
        int* subject5 = new int[noOfSub()];
        
        while (!file.eof())
        {
            if (indexID == indexNo) {
                cout << "\t\t\tIndex No.: " << indexID << "\n";

                fileMarks.open("MarksRecord.txt", ios::in);
                int l = 0;
                fileMarks >> indexNoB;
                while (l < noOfSub()) {
                    fileMarks >> subject5[l];
                    l++;
                }
                while (!fileMarks.eof())
                {
                    
                    if (indexNo == indexNoB) {
                        int i = 0;
                        while (i < noOfSub()) {
                            cout << "\t\t\tSubject " << i + 1 << ": " << subject5[i] << "\n";
                            i++;
                        }
                    }
                    int m = 0;
                    fileMarks >> indexNoB;
                    while (m < noOfSub()) {
                        fileMarks >> subject5[m];
                        m++;
                    }
                    
                }
                cout << "\t\t\tTotal sum: " << sum << "\n";
                cout << "\t\t\tAverage: " << average << "\n";
                cout << "\t\t\tGrade: " << grade << "\n";
                fileMarks.close();
            }

            file >> indexID >> sum >> average >> grade;
        }
    }
    file.close();
}

void studentView::viewTimetable()
{
    system("cls");
    if (modeB)
        cout << "running viewTimetable function(to view timetable) in studentView class " << endl << endl;
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------- Timetable --------------------------------------------------" << endl << endl<<endl;;
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
            cout << "\tDay     : " << day<<endl;
            cout << "\tMorning : " << subMorning<<endl;
            cout << "\tEvening : " << subEvening<<endl;
            cout << endl;
            file >> day >> subMorning >> subEvening;
        }
       
        file.close();
    }
    
}

void studentView::viewMessage()
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