#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL2/SDL.h>


class Window
{
public:
    Window(int width = 640, int height = 480):
    WIDTH(width), HEIGHT(height)
    {
        window_ = SDL_CreateWindow("Project Usurper",
                                 SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 width, height,
                                 SDL_WINDOW_SHOWN);
    }
    ~Window() { SDL_DestroyWindow(window_); }

    int width() { return WIDTH; }
    int height() { return HEIGHT; }
    bool valid() const { return window_ != NULL; }
    SDL_Window * get_window() const { return window_; }
    void update() { SDL_UpdateWindowSurface(window_); }


private:
    const int WIDTH;
    const int HEIGHT;
    SDL_Window * window_;
};

// std::ostream &operator<<(std::ostream &cout, Window &window)
// {
//     cout << "{Window objecect: " << &window
//          << " Width: " << window.width()
//          << " Height: " << window.height()
//          << "}";
//     return cout;
// }

#endif
