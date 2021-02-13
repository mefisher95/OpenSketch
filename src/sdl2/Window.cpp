#include "Window.h"

Window::Window(int width, int height, const Color &fill):
               WIDTH(width), HEIGHT(height), FILL(fill)
{
    if (SDL_Init(SDL_INIT_VIDEO)) throw WindowError(0);

    SDL_CreateWindowAndRenderer(width, height, 0, &window_, &render_);
    SDL_SetWindowTitle(window_, "OpenSketch");
    texture_ = SDL_CreateTexture(render_, 
               SDL_WINDOWPOS_UNDEFINED,
               SDL_WINDOWPOS_UNDEFINED,
               width, height);
    // window_->title = "OpenSketch";
    if (window_ == NULL) throw WindowError(1);
    if (render_ == NULL) throw WindowError(2);

    clear_window();
    srand((unsigned int) time(NULL));
}

Window::~Window() 
{
    SDL_DestroyTexture(texture_);
    SDL_DestroyRenderer(render_);
    SDL_DestroyWindow(window_); 
    SDL_Quit();
}

int Window::width() const { return WIDTH; }
int Window::height() const { return HEIGHT; }
void Window::delay(int t) const { SDL_Delay(t); }

void Window::set_fullscreen() { SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN); }
void Window::set_fullscreen_desktop() { SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN_DESKTOP); }


void Window::render() { SDL_RenderPresent(render_); }

void Window::clear_window()
{
    SDL_SetRenderDrawColor(render_, FILL.r, FILL.g, FILL.b,FILL.a);
    SDL_RenderClear(render_);
}

void Window::set_pixel(int x, int y, const Color & c)
{    
    set_color(c);
    SDL_RenderDrawPoint(render_, x, y);
}

void Window::set_line(const Vertex* v0, const Vertex* v1, const Color & c)
{
    set_color(c);
    SDL_RenderDrawLine(render_, v0->x(), v0->y(), v1->x(), v1->y());
}

void Window::set_shape(const Shape* shape)
{
    Verticies v = shape->get_verticies();
    for (int i = 0; i < v.size() - 1; ++i)
    {
        set_line(v[i], v[i + 1], shape->get_color());
    }
    set_line(v[0], v[v.size() - 1], shape->get_color());
    if (v.size() == 1) set_pixel(v[0]->x(), v[0]->y(), shape->get_color());
}

void Window::set_color(const Color &c)
{
    SDL_SetRenderDrawColor(render_, c.r, c.g, c.b, c.a);
}

std::ostream &operator<<(std::ostream &cout, Window &window)
{
    cout << "{Window objecect: " << &window
         << " Width: " << window.width()
         << " Height: " << window.height()
         << "}";
    return cout;
}