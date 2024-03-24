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

void BAL2D::renderFrame()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

} // namespace BAL
