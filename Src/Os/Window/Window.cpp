#include <SDL.h>

#include <Window.h>
namespace BAL
{
Window::Window()
	: m_width(0u)
	, m_height(0u)
{
}
Window::~Window() { destroy(); }

bool Window::initialize(const uint32 i_width, const uint32 i_height)
{
	m_width = i_width;
	m_height = i_height;
	m_window = SDL_CreateWindow("SDL2Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, static_cast<int>(i_width),
								static_cast<int>(i_height), SDL_WINDOW_SHOWN);
	return true;
}
bool Window::destroy()
{
	SDL_DestroyWindow(m_window);
	return false;
}

} // namespace BAL
