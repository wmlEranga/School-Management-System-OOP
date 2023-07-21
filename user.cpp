#pragma once
#include "user.h"

int user::noOfStudents = 0;

user::user(bool Mode)
{
    modeB = Mode;
    noOfStudents++;
	if(Mode)
		cout << "created a object regarding the user class "  << endl<<endl;
}

bool user::emailCheck(string email) {
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

void user::insert()
{
    system("cls");
    if (modeB)
        cout << "running insert function(to insert a student data) in user class " << endl << endl;
    fstream file;
    fstream fileLogin;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
    cout << "Your ID Number is " << noOfStudents << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter the birtday: ";
    cin >> DOB;
    cout << "\t\t\tEnter Index No.: ";
    cin >> indexNo;

email:
    cout << "\t\t\tEnter Email (name@gmail.com): ";
    cin >> email;
    if (emailCheck(email))
    {
        cout << "\t\t\t\t Your Email is Valid" << endl;
    }
    else
    {
        cout << "\t\t\t\t Your Email-Id is InValid" << endl;
        goto email;
    }

contact:
    cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
    cin >> contact;
    if (contact< 0000000000 || contact > 9999999999)
    {
        cout << "\t\t\t\t Please Enter Only 10 Digits..." << endl;
        goto contact;
    }

    cout << "\t\t\tEnter his login password: ";
    cin >> password;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << DOB << " " << indexNo << " " << email << " " << contact << " " << password << "\n";
    file.close();
    fileLogin.open("loginRecord.txt", ios::app | ios::out);
    fileLogin << " " << indexNo << " " << password << "\n";
    fileLogin.close();

}

void user::display()
{
    system("cls");
    if (modeB)
        cout << "running display function(to view all of student data) in user class " << endl << endl;
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
        file >> name >> DOB >> indexNo >> email >> contact >> password;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tStudent No.: " << total++ << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tDOB: " << DOB << "\n";
            cout << "\t\t\tIndex No.: " << indexNo << "\n";
            cout << "\t\t\tEmail Id: " << email << "\n";
            cout << "\t\t\tContact No.: " << contact << "\n";
            cout << "\t\t\tPassword: " << password << "\n";
            file >> name >> DOB >> indexNo >> email >> contact >> password;
        }
        if (total == 0)
        {

            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}

void user::modify()
{
    system("cls");
    if (modeB)
        cout << "running modify function(to modify a student data) in user class " << endl << endl;
    fstream file, file1;
    string indexID;
    int correct = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter the Index No. of Student which you want to Modify: ";
        cin >> indexID;
           
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> DOB >> indexNo >> email >> contact >> password;
        while (!file.eof())
        {
               
            if(indexID == indexNo)
            {
                cout << "\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter the birtday: ";
                cin >> DOB;
                cout << "\t\t\tEnter Index No.: ";
                cin >> indexNo;

            email:
                cout << "\t\t\tEnter Email (name@gmail.com): ";
                cin >> email;
                if (emailCheck(email))
                {
                    cout << "\t\t\t\t Your Email is Valid" << endl;
                }
                else
                {
                    cout << "\t\t\t\t Your Email-Id is InValid" << endl;
                    goto email;
                }

            contact:
                cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
                cin >> contact;
                if (contact < 0000000000 || contact > 9999999999)
                {
                    cout << "\t\t\t\t Please Enter Only 10 Digits..." << endl;
                    goto contact;
                }

                cout << "\t\t\tEnter Password: ";
                cin >> password;
                file1 << " " << name << " " << DOB << " " << indexNo << " " << email << " " << contact << " " << password << "\n";
            }
            else {
                file1 << " " << name << " " << DOB << " " << indexNo << " " << email << " " << contact << " " << password << "\n";
            }

            file >> name >> DOB >> indexNo >> email >> contact >> password;
   
        }

        file.close();
        file1.close();
        
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

void user::search()
{
    system("cls");
    if (modeB)
        cout << "running search function(to search a student data) in user class " << endl << endl;
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
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
        cout << "\nEnter email of Student which you want to search: ";
        cin >> indexID;
        file >> name >> DOB >> indexNo >> email >> contact >> password;
        while (!file.eof())
        {
            if (indexID == indexNo)
            {
                cout << "\n\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tDate of Birthday: " << DOB << "\n";
                cout << "\t\t\tIndex No.: " << indexNo << "\n";
                cout << "\t\t\tEmail Id: " << email << "\n";
                cout << "\t\t\tContact No.: " << contact << "\n";
                cout << "\t\t\tAddress: " << password << "\n";
                found++;
            }
            file >> name >> DOB >> indexNo >> email >> contact >> password;   
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student index Not Found....";
        }
        file.close();
    }
}

void user::deleted()
{
    system("cls");
    if (modeB)
        cout << "running delete function (to delete a student data) in user class " << endl << endl;
    fstream file, file1;
    int found = 0;
    string emailID;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter the email of Student which you want Delete Data: ";
        cin >> emailID;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> DOB >> indexNo >> email >> contact >> password;
        while (!file.eof())
        {
            if (emailID != email)
            {
                file1 << " " << name << " " << DOB << " " << indexNo << " " << email << " " << contact << " " << password << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> DOB >> indexNo >> email >> contact >> password;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student email Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
