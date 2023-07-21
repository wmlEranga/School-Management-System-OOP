#pragma once
#include <iostream>
#include <string>
#include "user.h"

using namespace std;

class otherTask : public user
{
private:
	string day, subMorning, subEvening;
	bool modeB;
	string msg;
public:
	otherTask(bool Mode) :user(Mode) {
		modeB = Mode;
		if (Mode)
			cout << "created a child object regarding the otherTask child class in user class " << endl<<endl;
	};
	void setTimetable();
	void viewShedule();
	void message();
	void viewMessageUser();
};