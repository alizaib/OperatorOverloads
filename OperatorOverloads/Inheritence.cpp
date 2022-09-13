#include "Log.h"

class GrandParent {
public:
	void DoSomething() {
		Log("Do something of grand parent called");
	}
};
class Parent : private GrandParent {
public:
	void SomeFunction() {
		DoSomething();
	}
};
class Child : private Parent
{
public:
	Child() {
		SomeFunction(); //Error
	}
};