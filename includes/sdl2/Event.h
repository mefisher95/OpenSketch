#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>

const Uint32 QUIT        = SDL_QUIT;
const Uint32 KEYDOWN     = SDL_KEYDOWN;
const Uint32 KEYUP       = SDL_KEYUP;
const Uint32 LEFTARROW   = SDLK_LEFT;
const Uint32 RIGHTARROW  = SDLK_RIGHT;
const Uint32 UPARROW     = SDLK_UP;
const Uint32 DOWNARROW   = SDLK_DOWN;
const Uint32 SPACE       = SDLK_SPACE;
const Uint32 TAB	     = SDLK_TAB;

const Uint32 ESC         = SDLK_ESCAPE;
const Uint32 ENTER       = SDLK_RETURN;
const Uint32 a           = SDLK_a;
const Uint32 d           = SDLK_d;
const Uint32 s           = SDLK_s;
const Uint32 w           = SDLK_w;
const Uint32 BACKQUOTE   = SDLK_BACKQUOTE;
const Uint32 F           = SDLK_f;

const Uint32 MOUSEMOTION = SDL_MOUSEMOTION;
const Uint32 MOUSEBUTTONUP = SDL_MOUSEBUTTONUP;
const Uint32 MOUSEBUTTONDOWN = SDL_MOUSEBUTTONDOWN;


class Event
{
public:

	int poll() { return SDL_PollEvent(&event); }
    Uint32 type() { return event.type; }
    Uint8 keypressed(int code) { return SDL_GetKeyboardState(NULL)[ code ];	}
    SDL_KeyboardEvent * get_key() { return &event.key; }
	SDL_MouseMotionEvent * motion()	{ return &event.motion;	}
    SDL_MouseButtonEvent * button() { return &event.button; }
    SDL_Event * get_event() { return &event; }
	SDL_Event event;

    bool quit() { return poll() && type() == QUIT; }
	bool mouse_click_down() { return poll() && type() == MOUSEBUTTONDOWN;}

// private:
	// const Uint8 * kbd;
};

class Keyboard
{
public:
	Keyboard(Event & event) : keydown(false) {}

	void update(Event & event)
	{
		SDL_KeyboardEvent * key = event.get_key();
		switch (key->type)
		{
			case KEYDOWN:
			{
				if (!keydown)
				{
					keydown = true;
					sym = key->keysym.sym;
				}
				break;
			}

			case KEYUP:
			{
				if (keydown && key->keysym.sym == sym)
				{
					keydown = false;
				}
				break;
			}
		}
	}

	int get_sym() { return sym; }
	bool keypressed(int sym0) { return keydown && (sym == sym0); }

private:
	bool keydown;
	int sym;
};

#endif
