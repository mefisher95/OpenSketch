#include <iostream>
#include "Surface.h"
#include "Event.h"
#include "Rect.h"
int main()
{
	Window window(640, 480);
	Surface surface(window);
	Event event;

	Shape *shape = new Rect(RED, 0, 0, 10, 20);
	Verticies v = shape->get_verticies();
	Color c = shape->get_color();

	std::cout << c << std::endl;
	std::cout << v << std::endl;

	// while (1)
	// {
	// 	if (event.quit()) break;
	// 	SDL_Delay(1);
	// }
	
	return 0;
}