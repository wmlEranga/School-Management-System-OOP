#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <string_view>

using namespace std;

class studentView
{
private:
    string indexID, passwordID,indexNoB;
    string name, DOB, email, contact;
    float sum, average;
    int grade;
    string subMorning, subEvening, day;
    bool modeB;
    string msg;
public:
    studentView(bool Mode);
    bool checkLoginData(string indexNo, string password);
    void viewData(string indexNo);
    void viewGrade(string indexNo);
    int noOfSub();
    void viewTimetable();
    void viewMessage();
};

