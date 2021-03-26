#include "stdafx.h" 
#include <iostream>

using namespace std;

class Shape {
private:
	int x, y;
public:
	Shape(int newx, int newy);
	int get_x();
	int get_y();
	void set_x(int newx);
	void set_y(int newy);
	void move_to(int newx, int newy);
	void rmove_to(int deltax, int deltay);
	void draw();
};

Shape::Shape(int newx, int newy) {
	move_to(newx, newy);
}

int Shape::get_x() { return x; }
int Shape::get_y() { return y; }
void Shape::set_x(int newx) { x = newx; }
void Shape::set_y(int newy) { y = newy; }

void Shape::move_to(int newx, int newy) {
	set_x(newx);
	set_y(newy);
}

void Shape::rmove_to(int deltax, int deltay) {
	move_to(get_x() + deltax, get_y() + deltay);
}

void Shape::draw() {
	cout << "drawing at: "
		<< "x: " << get_x()
		<< "y: " << get_y()
		<< endl;
}

class Rectangle : public Shape {
private:
	int width, height;
public:
	Rectangle(int, int, int, int);
	int get_width();
	int get_height();
	void set_width(int newwidth);
	void set_height(int newheight);
	void draw();
};

Rectangle::Rectangle(int newx, int newy, int newwidth, int newheight) : Shape(newx, newy) {
	set_width(newwidth);
	set_height(newheight);
}

int Rectangle::get_width() { return width; }
int Rectangle::get_height() { return height; }
void Rectangle::set_width(int newwidth) { width = newwidth; }
void Rectangle::set_height(int newheight) { height = newheight; }

void Rectangle::draw() {
	cout << "drawing a rectangle at (" << get_x() << ", "
		<< get_y() << ") width: " << get_width()
		<< " height: " << get_height() << endl;
}

class Square : public Rectangle {
private:
	int width, height;
public:
	Square(int, int, int, int);
	bool evaluate(int, int);
	void draw();
};

Square::Square(int newx, int newy, int newwidth, int newheight) : Rectangle(newx, newy, newwidth, newheight) {
	evaluate(newwidth, newheight);
}

bool Square::evaluate(int newwidth, int newheight) {
	if (newheight != newwidth) {
		cout << "all sides must be equal" << endl;
		return false;
	}
	else {
		return true;
	}
}

void Square::draw() {
	cout << "drawing a square at (" << get_x() << ", "
		<< get_y() << ") width: " << get_width()
		<< " height: " << get_height() << endl;
}

int main()
{
	Rectangle r1(1, 2, 3, 4);
	r1.draw();
	Square s1(0, 1, 4, 4);
	cout << "Squares (x,y) coordinates: (" << s1.get_x() << ", " << s1.get_y() << ")" << endl;
	s1.draw();
	Square s2(1, 1, 1, 1);
	s2.set_height(3);
	s2.set_width(3);
	s2.draw();

    return 0;
}