#include <Core/Sunflower.h>
#include <string>


#define WIDTH (int)1920 / 1.5
#define HEIGHT (int)1080 / 1.5
#define MOVE_SPEED 8

class SpriteRenderer : public Sunflower::Extender
{
public:
	std::string path_to_image;

	void on_start(Sunflower::Info info) override
	{
		image = Sunflower::LoadImage(path_to_image.c_str());

	};
	void on_update(Sunflower::Info info) override
	{

	};
	void on_render(Sunflower::Info info) override
	{
		Sunflower::DrawImage(image, info.self->scale, info.self->position);
	};
	void on_input(Sunflower::Info info, Event ev) override
	{

	};

private:
	Sunflower::Image image;
};

static SpriteRenderer CreateSpriteRenderer()
{
	return SpriteRenderer();
}

class MySprite : public Sunflower::GameObject
{
public:
	virtual void on_start(Sunflower::Info info) override
	{
		renderer = CreateSpriteRenderer();
		renderer.path_to_image = "Assets/kitten.png";
		renderer.on_start(info);
	};
	virtual void on_update(Sunflower::Info info) override
	{
		renderer.on_update(info);
	};
	virtual void on_render(Sunflower::Info info) override
	{
		renderer.on_render(info);
	};
	virtual void on_input(Sunflower::Info info, Event ev) override
	{
		renderer.on_input(info, Event());
	};
private:
	SpriteRenderer renderer;
};

int main(int argc, char* argv[])
{
	Sunflower::InitRenderer("Sunflower", WIDTH, HEIGHT);

	MySprite object1;

	object1.position = Sunflower::vec2(0, 0);
	object1.scale = Sunflower::vec2(0.3f, 0.3f);

	object1.on_start(Sunflower::Info(&object1));


	Sunflower::PreMainLoop();


	while (!Sunflower::quit)
	{
		Sunflower::HandleEvents();


		object1.on_update(Sunflower::Info(&object1));

		Sunflower::DrawBackground(53, 90, 222);

		object1.on_render(Sunflower::Info(&object1));

		Sunflower::MainLoopEnd();
	}

	Sunflower::Flush();

	return 0;
};
