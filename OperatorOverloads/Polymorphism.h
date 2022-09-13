#pragma once
#include "Log.h"

class Shape {
public:
	virtual void Draw() = 0;
};

class Circle : public Shape {
public :
	void Draw();
};

class Line : public Shape {
public:
	void Draw();
};

class Rectangle : public Line {
public:
	void Draw();
};
