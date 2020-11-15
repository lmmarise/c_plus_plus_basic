#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "21 Worker.h"

class Manager : public Worker {
public:
	Manager(int id, string name, int dept_id);

	virtual void show_info();

	virtual string get_dept_name();
};