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

	

	while(1)
	{
		Shape* shape = new Rect(rand() % window.width(), rand() % window.height(), rand() % 100, rand() % 100, rand_color());
		shapes.push_back(shape);
		if (event.quit()) break;
		window.clear_window();
		for (int i = 0; i < shapes.size(); ++i)
		{
			window.set_shape(shapes[i]);
		}
		window.render();
		std::cout << shapes.size() << std::endl;
		// window.delay(10);
	}

	for (int i = 0; i < shapes.size(); ++i)
	{
		delete shapes[i];
	}
	return 0;
}