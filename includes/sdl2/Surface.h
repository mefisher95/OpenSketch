#ifndef SURFACE_H
#define SURFACE_H

#include "Window.h"
#include "iostream"
// #include "Image.h"
// #include "Rect.h"

class InvalidWindowObj
{
public:
    InvalidWindowObj()
    {
        std::cout << "InvalidWindowObj: There was a problem initializing this "
                  << "Surface object with the provided Window object."
                  << std::endl;
    }
};

class Surface
{
public:
    Surface(const Window &window)
    {
        // if (window.valid())
        // {
        //     surface_ = SDL_GetWindowSurface(window.get_window());
        // }
        // else
        // {
        //     throw InvalidWindowObj();
        // }

        SDL_Init(SDL_INIT_VIDEO);
        std::cout << int(surface_->format->BytesPerPixel) << std::endl;
    }

    ~Surface()
    {
        SDL_Quit();
    }

    void fill_background(int r, int b, int g)
    {
        SDL_FillRect(surface_, NULL, SDL_MapRGB(surface_->format, r, g, b));
    }

    // void put_image(Image *image, Rect &dst)
    // {
    //     SDL_Rect dst_ = {Sint16(dst.x), Sint16(dst.y),
    //                      Uint16(dst.w), Uint16(dst.h)};
    //     SDL_BlitSurface(image->get_image(), NULL, surface_, &dst_);
    // }

    // void put_image(Image &image, int x, int y, int w, int h)
    // {
    //     SDL_Rect dst_ = {Sint16(x), Sint16(y),
    //                      Uint16(w), Uint16(h)};
    //     SDL_BlitSurface(image.get_image(), &dst_, surface_, NULL);
    // }

private:
    SDL_Surface* surface_;
};
#endif
