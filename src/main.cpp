#include <iostream>
#include "Window.h"
#include "Event.h"
#include "math.h"
#include <SDL2/SDL.h>

int main()
{
	Window window(640, 480, WHITE);
	Event event;

	Vertex start(100, 100);
	Vertex end(250, 250);

	while(1)
	{
		Color c = { Uint8(rand() % 256), Uint8(rand() % 256), Uint8(rand() % 256), Uint8(255)};
		Vertex start(rand() % window.width() - 1, rand() % window.height() - 1);
		Vertex end(250, 250);
		if (event.quit()) break;
		/* window.set_pixel(, , BLUE); */
		window.set_line(start, end, c);
		if (event.mouse_click_down())
		{
			std::cout <<  "success\n";
		}
		window.render();
		window.delay(10);
	}
	return 0;
}