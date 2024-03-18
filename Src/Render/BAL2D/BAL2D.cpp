#include "SDL_render.h"
#include <BAL2D.h>
#include <SDL.h>
#include <Window.h>
namespace BAL
{

BAL2D::BAL2D() {}
BAL2D::~BAL2D() { destroy(); }
bool BAL2D::initialize(Window* i_window)
{
	m_renderer = SDL_CreateRenderer(i_window->getNativeWindow(), -1, SDL_RENDERER_ACCELERATED);
	return false;
}
bool BAL2D::destroy()
{
	SDL_DestroyRenderer(m_renderer);
	return false;
}
} // namespace BAL
