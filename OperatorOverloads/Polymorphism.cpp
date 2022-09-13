#include "Polymorphism.h"

// following method is pure virtual but c++ allows to have body
void Shape::Draw() {
	Log("Shape Drawn");
}

void Circle::Draw() {	
	Log("Circle Drawn");
}

void Line::Draw() {
	Log("Line Drawn");
}

void Rectangle::Draw() {
	Log("Rectangle Drawn");
}