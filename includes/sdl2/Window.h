#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
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
    Window(int width = 640, int height = 480, const Color &fill = BLACK):
    WIDTH(width), HEIGHT(height), FILL(fill)
    {
        if (SDL_Init(SDL_INIT_EVERYTHING)) throw WindowError(0);

        SDL_CreateWindowAndRenderer(width, height, 0, &window_, &render_);
        SDL_SetWindowTitle(window_, "OpenSketch");
        // window_->title = "OpenSketch";
        if (window_ == NULL) throw WindowError(1);
        if (render_ == NULL) throw WindowError(2);

        clear_window();
        srand((unsigned int) time(NULL));
    }
    ~Window() 
    {
        SDL_DestroyTexture(texture_);
        SDL_DestroyRenderer(render_);
        SDL_DestroyWindow(window_); 
        SDL_Quit();
    }

    int width() const { return WIDTH; }
    int height() const { return HEIGHT; }
    void delay(int t) const { SDL_Delay(t); }

    void set_fullscreen() { SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN); }
    void set_fullscreen_desktop() { SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN_DESKTOP); }


    void render()
    {
        SDL_RenderPresent(render_);
    }

    void clear_window()
    {
        SDL_SetRenderDrawColor(render_, FILL.r, FILL.g, FILL.b,FILL.a);
        SDL_RenderClear(render_);
    }

    void draw_rand_pixel(const Color &c = RED, int ammount = 1000)
    {    
        SDL_SetRenderDrawColor(render_, RED.r, RED.g, RED.b, RED.a);    
        for (int i = 0; i < ammount; ++i)
        {
            int x = rand() % 100 + 50;
            int y = rand() % 100 + 50;
            SDL_RenderDrawPoint(render_, x, y);
        }
        render();
    }

    void set_pixel(int x, int y, const Color & c)
    {    
        SDL_SetRenderDrawColor(render_, c.r, c.g, c.b, c.a);    
        SDL_RenderDrawPoint(render_, x, y);
    }

    void set_line(const Vertex & v0, const Vertex & v1, const Color & c)
    {
        SDL_SetRenderDrawColor(render_, c.r, c.g, c.b, c.a);
        SDL_RenderDrawLine(render_, v0.x(), v0.y(), v1.x(), v1.y());
    }


    // OLD DONT KNOW IF I STILL WANT THEM
    // bool valid() const { return window_ != NULL; }
    // void update() { SDL_UpdateWindowSurface(window_); }
    // SDL_Window * get_window() const { return window_; }


    


private:
    const int WIDTH;
    const int HEIGHT;

    Color FILL;
    SDL_Window *window_ = NULL;
    SDL_Renderer *render_ = NULL;
    SDL_Texture *texture_ = NULL;
    
};

// std::ostream &operator<<(std::ostream &cout, Window &window)
// {
//     cout << "{Window objecect: " << &window
//          << " Width: " << window.width()
//          << " Height: " << winder_, ow.height()
//          << "}";
//     return cout;
// }

#endif