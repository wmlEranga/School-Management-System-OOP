#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <string_view>
#include "user.h"
#include <vector>

using namespace std;

class analysMark : public user
{
private:
    string  indexNo, password, indexNoB, sub, indexNoC;
    int grade;
    float sum = 0;
    float average = 0;
    bool modeB;
    
public:
    analysMark(bool Mode) :user(Mode) {
        modeB = Mode;
        if (Mode)
            cout << "created a child object regarding the analys child class in user class " << endl<<endl;
    };
    bool is_empty(ifstream& pFile);
    int noOfSub();
    void addMark(bool op);
    void displayMark();
    void modifyMark();
    void searchMark();
    void setGrade();
    void viewGrade();
    void setGradeB();
    int* subject = new int[noOfSub()];
};

