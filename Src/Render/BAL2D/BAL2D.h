
class SDL_Renderer;
namespace BAL
{

class Window;

class BAL2D
{
public:
	BAL2D();
	~BAL2D();
	bool initialize(Window* i_window);
	bool destroy();

private:
	SDL_Renderer* m_renderer;
};
} // namespace BAL
