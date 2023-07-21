#pragma once
#include "analysMark.h"



bool analysMark::is_empty(ifstream& pFile) {
    return pFile.peek() == ifstream::traits_type::eof();
}


int analysMark::noOfSub()
{
    fstream fileNoSub;

    ifstream file("subRecord.txt");

    if (is_empty(file))
    {
        fileNoSub.open("subRecord.txt", ios::app | ios::out);
        cout << " \n\n\t\t\tEnter the No. subjects: ";
        int sub;
        cin >> sub;

        fileNoSub << sub;
        fileNoSub.close();
        return sub;
    }
    else {
        int sub;
        fileNoSub.open("subRecord.txt", ios::in);
        fileNoSub >> sub;
        int sub3 = sub;
        fileNoSub >> sub;

        return sub3;
    }
}

void analysMark::addMark(bool op)
{
    
    
    system("cls");
    ofstream ofs;
    ofs.open("MarksRecord.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofstream ofs2;
    ofs2.open("subRecord.txt", std::ofstream::out | std::ofstream::trunc);
    ofs2.close();

    if (modeB)
        cout << "running addMark function(to add all exam data) in analysMark child class " << endl << endl;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------ Add Mark of the students -----------------------------------------" << endl;
    cout << "\n---------------------------------------Enter all data at once -----------------------------------------" << endl;
    fstream fileLogin;
    fstream fileMarks;
    bool total = true;
    fileLogin.open("loginRecord.txt", ios::in);

    ifstream file("MarksRecord.txt");

    if (op)
    {
        fileMarks.open("MarksRecord.txt", ios::app | ios::out);
        noOfSub();

        fileLogin >> indexNo >> password;
        while (!fileLogin.eof())
        {
            int* subject = new int(noOfSub());
            int k = 0;

            cout << "\n\n\t\t\tIndex No.: " << indexNo << endl << endl;
            int i = 0;
            while (i < noOfSub()) {
                int addMark;
                cout << "\t\t\tEnter the mark of Subject " << i + 1 << ": ";
                cin >> subject[i];
                i++;
            }
            int j = 0;
            fileMarks << " " << indexNo;
            while (j < noOfSub()) {
                fileMarks << " " << subject[j];
                j++;
            }
            fileMarks << "\n";

            fileLogin >> indexNo >> password;

        }
        fileMarks.close();
        fileLogin.close();
    }

}

void analysMark::displayMark()
{
    system("cls");
    if (modeB)
        cout << "running displayMark function(to display marks) in analysMark child class " << endl << endl;
    fstream fileMarks;
    //int* subject4 = new int(noOfSub());
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    fileMarks.open("MarksRecord.txt", ios::in);
    if (!fileMarks)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        fileMarks.close();
    }
    else
    {
       
        int l = 0;
        fileMarks >> indexNoB;
        while (l < noOfSub()) {
            fileMarks >> subject[l];
            l++;
        }

        while (!fileMarks.eof())
        {
            cout << "\n\n\t\t\tIndex No.: " << indexNoB << endl;

            int i = 0;
            while (i < noOfSub()) {
                cout << "\t\t\tSubject " << i + 1 << ": " << subject[i] << "\n";
                i++;
            }

            int m = 0;
            fileMarks >> indexNoB;
            while (m < noOfSub()) {
                fileMarks >> subject[m];
                m++;
            }
        }
 
    }
   // delete[] subject4;
    fileMarks.close();
    

}

void analysMark::modifyMark()
{
    system("cls");
    if (modeB)
        cout << "running modifyMark function(to modify marks of a student) in analysMark child class " << endl << endl;
    fstream fileMarks, fileMarksB;
    string indexID;
    int correct = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Marks Modify Details ------------------------------------------" << endl;
    fileMarks.open("MarksRecord.txt", ios::in);
    if (!fileMarks)
    {
        cout << "\n\t\t\tNo Data is Present..";
        fileMarks.close();
    }
    else
    {
        cout << "\nEnter the index of Student which you want to Modify: ";
        cin >> indexID;

        int* subject = new int[noOfSub()];
        int l = 0;
        

        fileMarks >> indexNoB;
        while (l < noOfSub()) {
            fileMarks >> subject[l];
            l++;
        }

        while (!fileMarks.eof())
        {

            if (indexID == indexNoB)
            {
                int i = 0;
                while (i < noOfSub()) {
                    cout << "\t\t\tEnter the mark of Subject " << i + 1 << ": ";
                    cin >> subject[i];
                    i++;
                }
                fileMarksB.open("MarksrecordB.txt", ios::app | ios::out);
                int j = 0;
                fileMarksB << " " << indexNoB;
                while (j < noOfSub()) {
                    fileMarksB << " " << subject[j];
                    j++;
                }
                fileMarksB << "\n";

            }
            else {
                int j = 0;
                fileMarksB << " " << indexNoB;
                while (j < noOfSub()) {
                    fileMarksB << " " << subject[j];
                    j++;
                }
                fileMarksB << "\n";
            }
            int k = 0;
            fileMarks >> indexNoB;
            while (k < noOfSub()) {
                fileMarks >> subject[k];
                k++;
            }

        }

        fileMarks.close();
        fileMarksB.close();

        remove("MarksRecord.txt");
        rename("MarksrecordB.txt", "MarksRecord.txt");
    }
}

void analysMark::searchMark()
{
    system("cls");
    if (modeB)
        cout << "running searchMark function(to search Marks of a student) in analysMark child class " << endl << endl;
    fstream fileMarks;
    int found = 0;
    fileMarks.open("MarksRecord.txt", ios::in);
    if (!fileMarks)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string indexID;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;
        cout << "\nEnter index of Student which you want to search: ";
        cin >> indexID;
        int* subject = new int(noOfSub());
        int l = 0;
        fileMarks >> indexNoB;
        while (l < noOfSub()) {
            fileMarks >> subject[l];
            l++;
        }

        while (!fileMarks.eof())
        {
            if (indexID == indexNoB)
            {
                cout << "\n\n\t\t\tIndex No.: " << indexNoB << endl;

                int i = 0;
                while (i < noOfSub()) {
                    cout << "\t\t\tSubject " << i + 1 << ": " << subject[i] << "\n";
                    i++;
                }
            }

            int m = 0;
            fileMarks >> indexNoB;
            while (m < noOfSub()) {
                fileMarks >> subject[m];
                m++;
            }

        }

        fileMarks.close();
    }
}

void analysMark::setGrade()
{
    ofstream ofs;
    ofs.open("gradeRecord.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    system("cls");
    fstream fileGrade,fileGradeB;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- See your Result ---------------------------------------------" << endl;

    fileGrade.open("MarksRecord.txt", ios::in);
    if (!fileGrade)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        fileGrade.close();
    }
    else
    {
        //int* subject = new int(noOfSub());
        int l = 0;
        fileGrade >> indexNoB;
        while (l < noOfSub()) {
            fileGrade >> subject[l];
            l++;
        }

        while (!fileGrade.eof())
        {
            fileGradeB.open("gradeRecord.txt", ios::app | ios::out);
            
            int j = 0;
            sum = 0;
            while (j < noOfSub()) { 
                float k = float(subject[j]);
                sum = sum + k;
                j++;
            }
            average = sum / noOfSub();

            int i = 0;
            fileGradeB << " " << indexNoB;
            while (i < noOfSub()) {
                fileGradeB << " " << subject[i];
                i++;
            }
            fileGradeB << " " << sum << " " << average << "\n";
            fileGradeB.close();

            int m = 0;
            fileGrade >> indexNoB;
            while (m < noOfSub()) {
                fileGrade >> subject[m];
                m++;
            }
        }       
    }
    fileGrade.close();
    setGradeB();
}

/*void analysMark::viewGrade()
{
    system("cls");
    fstream fileGrade;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    fileGrade.open("gradeRecord.txt", ios::in);
    if (!fileGrade)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        fileGrade.close();
    }
    else
    {
        int* subject = new int(noOfSub());
        int l = 0;
        fileGrade >> indexNoB;
        while (l < noOfSub()) {
            fileGrade >> subject[l];
            l++;
        }
        fileGrade >> sum >> average;

        while (!fileGrade.eof())
        {
            cout << "\n\n\t\t\tIndex No.: " << indexNoB << endl;

            int i = 0;
            while (i < noOfSub()) {
                cout << "\t\t\tSubject " << i + 1 << ": " << subject[i] << "\n";
                i++;
            }
            cout << "\t\t\tSum of the Marks: " << sum << "\n";
            cout << "\t\t\tAverage of the Marks: " << average << "\n";

            int m = 0;
            fileGrade >> indexNoB;
            while (m < noOfSub()) {
                fileGrade >> subject[m];
                m++;
            }
            fileGrade >> sum >> average;
        }
    }
    fileGrade.close();
}*/

void analysMark::setGradeB()
{
    system("cls");
    fstream fileGrade, fileGradeB;

    fileGradeB.open("gradeRecordB.txt", ios::app | ios::out);
    fileGradeB.close();

    ofstream ofs;
    ofs.open("gradeRecordB.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    
    
    int total = 1;
    vector<int> g1;
    vector<int> g2;
    vector<string> g3;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    fileGrade.open("gradeRecord.txt", ios::in);

    if (!fileGrade)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        fileGrade.close();
    }
    else
    {
        //int* subject3 = new int(noOfSub());
        int l = 0;
        fileGrade >> indexNoB;
        while (l < noOfSub()) {
            fileGrade >> subject[l];
            l++;
        }
        fileGrade >> sum >> average;

        while (!fileGrade.eof())
        {
            g1.push_back(sum);
            g2.push_back(sum);
            g3.push_back(indexNoB);

            int m = 0;
            fileGrade >> indexNoB;
            while (m < noOfSub()) {
                fileGrade >> subject[m];
                m++;
            }
            fileGrade >> sum >> average;
        }
    }

    fileGrade.close();

    fileGradeB.open("gradeRecordB.txt", ios::app | ios::out);
    sort(g1.begin(), g1.end(), greater<int>());

    for (int i = 0; i < g1.size(); i++) {
        for (int j = 0; j < g2.size(); j++)
        {
            if (g1[i] == g2[j]) {
                grade = i + 1;
                indexNoC = g3[j];
                fileGradeB << " " << grade << " " << indexNoC << "\n";
            }
        }
    }
    fileGradeB.close();
}

void analysMark::viewGrade()
{
    setGrade();

    system("cls");
    if (modeB)
        cout << "running setData and viewData functions(to set grade and display it) in analysMark child class " << endl << endl;
    fstream fileGrade,fileGradeB,fileFinal;

    fileFinal.open("Finalgrade.txt", ios::app | ios::out);
    fileFinal.close();

    ofstream ofs;
    ofs.open("Finalgrade.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    fileGradeB.open("gradeRecordB.txt", ios::in);

    if (!fileGrade)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        fileGrade.close();
    }
    else
    {
        //int* subject2 = new int(noOfSub());
        

        fileGradeB >> grade >> indexNoC;

        while (!fileGradeB.eof())
        {
            fileGrade.open("gradeRecord.txt", ios::in);
            int l = 0;
            fileGrade >> indexNoB;
            while (l < noOfSub()) {
                fileGrade >> subject[l];
                l++;
            }
            fileGrade >> sum >> average;
            while (!fileGrade.eof())
            {
                
                if (indexNoC == indexNoB)
                {
                    cout << "\n\n\t\t\tIndex No.: " << indexNoB << endl;

                    int i = 0;
                    while (i < noOfSub()) {
                        cout << "\t\t\tSubject " << i + 1 << ": " << subject[i] << "\n";
                        i++;
                    }
                    cout << "\t\t\tSum of the Marks: " << sum << "\n";
                    cout << "\t\t\tAverage of the Marks: " << average << "\n";
                    cout << "\t\t\tGrade of the student: " << grade << "\n";

                    fileFinal.open("Finalgrade.txt", ios::app | ios::out);
                    fileFinal << " " << indexNoB << " " << sum << " " << average << " " << grade << "\n";
                    fileFinal.close();
                }
                int m = 0;
                fileGrade >> indexNoB;
                while (m < noOfSub()) {
                    fileGrade >> subject[m];
                    m++;
                }
                fileGrade >> sum >> average;   
            }
            fileGrade.close();
                       
            fileGradeB >> grade >> indexNoC;
        }
        fileGradeB.close();
    }

}