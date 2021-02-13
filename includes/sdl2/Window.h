#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL2/SDL.h>

#include "Color.h"

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
        SDL_SetRenderDrawColor(render_, FILL.r, FILL.g, FILL.b,FILL.a);
        SDL_RenderClear(render_);
        SDL_RenderPresent(render_);
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
//          << " Height: " << window.height()
//          << "}";
//     return cout;
// }

#endif
