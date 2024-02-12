#include <Core/Engine.h>

const int WIDTH = (int)1920 / 1.5;
const int HEIGHT = (int)1080 / 1.5;

int main(int argc, char* argv[])
{
	Engine::InitRenderer("Brackeys Game Jam", WIDTH, HEIGHT);
	
	Engine::PreMainLoop();
	Engine::Image image = Engine::LoadImage("Assets/kitten.png");

	Engine::vec2 img_scale(1,1);
	Engine::vec2 img_pos(0,0);

	while (!Engine::quit)
	{
		Engine::HandleEvents();

		Engine::DrawBackground(0, 180, 250);

		Engine::DrawImage(image, img_scale, img_pos);
		img_pos.a += 2;
		img_pos.a = (int)img_pos.a % WIDTH;
	}

	return 0;
}