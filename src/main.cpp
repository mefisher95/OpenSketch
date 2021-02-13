#include <iostream>
#include "Window.h"
#include "Event.h"
#include "Rect.h"
#include "math.h"
int main()
{
	Window window(640, 480, WHITE);
	Event event;

	Shape *shape = new Rect(RED, 0, 0, 10, 20);
	Verticies v = shape->get_verticies();
	Color c = shape->get_color();

	std::cout << v << std::endl;

	for (int i = 0; i < 20; ++i)
	{
		if (event.quit()) break;
		window.render();
		std::cout << i << std::endl;
		window.delay(100);
	}


	window.set_fullscreen_desktop();

	for (int i = 0; i < 20; ++i)
	{
		if (event.quit()) break;
		window.render();
		std::cout << i << std::endl;
		window.delay(100);
	}
	
	return 0;
}