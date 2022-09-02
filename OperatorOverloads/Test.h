#pragma once
#include "Log.h"

class Test {
	int i;
public:
	Test(int);
	Test(const Test&);

	~Test();
};
