#include <Core/Sunflower.h>
#include <SunflowerCollisions.cpp>
#include <string>


#define WIDTH (int)1920 / 1.5
#define HEIGHT (int)1080 / 1.5
#define MOVE_SPEED 8

class MySprite : public Sunflower::GameObject
{
public:
	void on_start(Sunflower::Info info) override
	{
		renderer = Sunflower::CreateSpriteRenderer();
		renderer.path_to_image = "Assets/guy.png";
		renderer.on_start(info);
	};

	void on_update(Sunflower::Info info) override
	{
		renderer.on_update(info);
	};

	void on_render(Sunflower::Info info) override
	{
		renderer.on_render(info);
	};

	void on_input(Sunflower::Info info, Event ev)
	{
		renderer.on_input(info, ev);

		if (ev.scancode == KEY_LEFT)
		{
			scale.x -= 0.03f;
		}
		else if (ev.scancode == KEY_RIGHT)
		{
			scale.x += 0.03f;
		}

		if (ev.scancode == KEY_UP)
		{
			scale.y -= 0.03f;
		}
		else if (ev.scancode == KEY_DOWN)
		{
			scale.y += 0.03f;
		}

		position.x = Sunflower::sunflower_get_mouse_state().x-(((w*(scale.x)))/2);
		position.y = Sunflower::sunflower_get_mouse_state().y-(((h* (scale.y)))/2);

	};
private:
	int w = 800;
	int h = 800;
	Sunflower::SpriteRenderer renderer;
};

MySprite object1;

void EventCallback(Event e)
{
	object1.on_input(Sunflower::Info(&object1), e);
};

int main(int argc, char* argv[])
{
	Sunflower::InitRenderer("Sunflower", WIDTH, HEIGHT);

	object1 = MySprite();

	object1.position = Sunflower::vec2(0, 0);
	object1.scale = Sunflower::vec2(0.3f, 0.3f);

	object1.on_start(Sunflower::Info(&object1));

	Sunflower::Font roboto = Sunflower::loadFont("Assets/Roboto-Black.ttf", 28);

	Sunflower::PreMainLoop();

	
	while (!Sunflower::quit)
	{
		Sunflower::HandleEvents(EventCallback);


		object1.on_update(Sunflower::Info(&object1));

		Sunflower::DrawBackground(134, 134, 134);

		object1.on_render(Sunflower::Info(&object1));

		Sunflower::RenderText(roboto, "Yay! UI and text.", 0, 0, 0, 0, 0);

		Sunflower::MainLoopEnd();
	}

	Sunflower::Flush();

	return 0;
};