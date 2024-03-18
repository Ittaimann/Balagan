#include <CoreDefs.h>

class SDL_Window;
namespace BAL
{
class Window
{
public:
	Window();
	~Window();
	bool initialize(const uint32 i_width, const uint32 i_height);
	bool destroy();

	SDL_Window* getNativeWindow() const { return m_window; }

private:
	uint32 m_width;
	uint32 m_height;
	SDL_Window* m_window;
};
} // namespace BAL
