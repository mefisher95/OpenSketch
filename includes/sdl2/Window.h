#ifndef WINDOW_H
#define WINDOW_H

#include <ostream>
#include <SDL2/SDL.h>

#include "Color.h"
#include "Shape.h"

class WindowError
{
public:
    WindowError(int code) :code_(code) {}

    std::ostream& operator<<(std::ostream& cout)
    {
        cout << "<WindowError code: " << code_ << ">";
        return cout;
    }   
private:
    int code_;

};

class Window
{
public:
    Window(int width = 640, int height = 480, const Color &fill = BLACK);
    
    ~Window();

    int width() const;
    int height() const;
    void delay(int) const;

    void set_fullscreen();
    void set_fullscreen_desktop();
    void render();

    void clear_window();

    void draw_rand_pixel(const Color &c = RED, int ammount = 1000);

    void set_pixel(int x, int y, const Color &c);
    void set_line(const Vertex* v0, const Vertex* v1, const Color &c);
    void set_shape(const Shape* shape);

private:
    const int WIDTH;
    const int HEIGHT;

    Color FILL;
    SDL_Window *window_ = NULL;
    SDL_Renderer *render_ = NULL;
    SDL_Texture *texture_ = NULL;

    void set_color(const Color &c);
    
};

std::ostream &operator<<(std::ostream &cout, Window &window);

#endif