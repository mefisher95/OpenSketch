#include <iostream>
#include "Window.h"
#include "Event.h"
#include "Shape.h"

int main()
{
	int DELAY = 6000;
	Window window(640, 480, WHITE);
	Event event;

	Vertex start(100, 100);
	Vertex end(250, 250);

	std::vector< Shape* > shapes;

	Shape* rect = new Rect(rand() % window.width(), rand() % window.height(), rand() % 100, rand() % 100, rand_color());
	Shape* line = new Line(rand() % window.width(), rand() % window.height(), rand() % 100, rand() % 100, rand_color());
	Shape* triangle = new Triangle(rand() % window.width(), rand() % window.height(), rand() % 100, rand() % 100, rand_color());

	shapes.push_back(rect);
	shapes.push_back(line);
	shapes.push_back(triangle);

	window.clear_window();

	for (int i = 0; i < shapes.size(); ++i)
	{
		std::cout << i << std::endl;
		window.set_shape(shapes[i]);
	}

	window.render();
	window.delay(DELAY);

	for (int i = 0; i < shapes.size(); ++i)
	{
		shapes[i]->translate(10, 20);
		window.set_shape(shapes[i]);
	}

	window.render();
	window.delay(DELAY);

	for (int i = 0; i < shapes.size(); ++i)
	{
		Vertex* v = shapes[i]->get_verticies()[1];
		shapes[i]->move_vertex(v, v->x() + 10, v->y() - 10);
		window.set_shape(shapes[i]);
	}

	window.render();
	window.delay(DELAY);

	for (int i = 0; i < shapes.size(); ++i)
	{
		shapes[i]->resize(30, 30);
		window.set_shape(shapes[i]);
	}

	window.render();
	window.delay(DELAY);

	for (int i = 0; i < shapes.size(); ++i)
	{
		delete shapes[i];
	}

	return 0;
}