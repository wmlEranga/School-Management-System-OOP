#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <string_view>
#include <regex>

using namespace std;

class user
{
private:
    static int noOfStudents;
    string  name, DOB, indexNo, subject,email,password;
    long long int contact;
    bool modeB;
public:
    
    user(bool Mode);
    void insert();
    bool emailCheck(string email);
    void display();
    void modify();
    void search();
    void deleted();
};






