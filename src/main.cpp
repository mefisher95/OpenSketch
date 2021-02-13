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

	while(1)
	{
		if (event.quit()) break;
		window.draw_rand_pixel();
		window.delay(10);
	}
	return 0;
}