#include <iostream>
#include "Window.h"
#include "Event.h"
#include "Shape.h"

int main()
{
	Window window(640, 480, WHITE);
	Event event;

	Vertex start(100, 100);
	Vertex end(250, 250);

	std::vector< Shape* > shapes;

	Shape* shape = new Rect(rand() % window.width(), rand() % window.height(), rand() % 100, rand() % 100, rand_color());

	window.clear_window();
	window.set_shape(shape);
	window.render();
	window.delay(9000);

	Vertex* v = shape->get_verticies()[2];
	shape->translate(10, 20);
	window.set_shape(shape);
	window.render();
	window.delay(9000);

	delete shape;
	return 0;
}