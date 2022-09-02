#include "Test.h"

Test::Test(int i) { 
	Log("Constructor called");
	i = i; 
}
Test::Test(const Test& t) { 
	Log("Copy Constructor called");
	i = t.i; 
}

Test::~Test() {
	Log("Destructor called");
}