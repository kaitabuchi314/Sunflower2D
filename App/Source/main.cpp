#include <Core/Sunflower.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <string>

<<<<<<< Updated upstream

const int WIDTH = (int)1920 / 1.5;
const int HEIGHT = (int)1080 / 1.5;

Sunflower::vec2 img_scale;
Sunflower::vec2 img_pos;

bool on = true;
float move_speed = 4;
int handle_events(Event e)
{
	ImGui_ImplSDL2_ProcessEvent(e.ev);
	if (on)
	{
		if (e.scancode == KEY_RIGHT)
		{
			img_pos.x += move_speed;
		}
		else if (e.scancode == KEY_LEFT)
		{
			img_pos.x += -move_speed;
		}
		if (e.scancode == KEY_UP)
		{
			img_pos.y -= move_speed;
		}
		else if (e.scancode == KEY_DOWN)
		{
			img_pos.y -= -move_speed;
		}
	}
	return 0;
=======
// Lalalalala
// snake_case
// Snakes seperated by underscores
// snake_case is the_case_for_me
// In other words:
// Case the_case_for_me = snake_case;
// Except for classes tho... That's just odd.


#define WIDTH (int)1920 / 1.5
#define HEIGHT (int)1080 / 1.5
#define MOVE_SPEED 8

class SpriteRenderer : public Sunflower::Extender
{
public:
	std::string path_to_image;

	void on_start(Sunflower::Info info) override
	{
		image = Sunflower::load_image(path_to_image.c_str());

	};
	void on_update(Sunflower::Info info) override
	{

	};
	void on_render(Sunflower::Info info) override
	{
		Sunflower::draw_image(image, info.self->scale, info.self->position);
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
>>>>>>> Stashed changes
};

int main(int argc, char* argv[])
{
	Sunflower::InitRenderer("Sunflower", WIDTH, HEIGHT);

<<<<<<< Updated upstream
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigDockingWithShift = false;

	ImGui::StyleColorsDark();

	ImGui_ImplSDL2_InitForSDLRenderer(Sunflower::GetWindow(), Sunflower::GetRenderer());
	ImGui_ImplSDLRenderer2_Init(Sunflower::GetRenderer());

	io.Fonts->AddFontDefault();

	Sunflower::Image image = Sunflower::LoadImage("Assets/kitten.png");
	
	img_scale.x = 0.3f;
	img_scale.y = 0.3f;
=======

	MySprite object1;

	object1.position = Sunflower::vec2(0, 0);
	object1.scale = Sunflower::vec2(0.3f, 0.3f);

	object1.on_start(Sunflower::Info(&object1));
>>>>>>> Stashed changes


	Sunflower::PreMainLoop();


	while (!Sunflower::quit)
	{
<<<<<<< Updated upstream
		Sunflower::HandleEvents(handle_events);


		ImGui_ImplSDLRenderer2_NewFrame();
		ImGui_ImplSDL2_NewFrame();
=======
		Sunflower::handle_events();

		object1.on_update(Sunflower::Info(&object1));

		Sunflower::draw_background(53, 90, 222);

		object1.on_render(Sunflower::Info(&object1));
		
>>>>>>> Stashed changes

		ImGui::NewFrame();
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);

		Sunflower::DrawBackground(53, 90, 222);


		Sunflower::DrawImage(image, img_scale, img_pos);

		ImGui::Begin("Settings");
		ImGui::Checkbox("Move using arrow keys", &on);

		if (!on)
		{
			ImGui::InputFloat("X: ", &img_pos.x);
			ImGui::InputFloat("Y: ", &img_pos.y);
		}
		ImGui::Space();

		ImGui::InputFloat("Scale X: ", &img_scale.x);
		ImGui::InputFloat("Scale Y: ", &img_scale.y);

		ImGui::Space();

		ImGui::InputFloat("Move Speed: ", &move_speed);

		ImGui::End();

		ImGui::Render();
		ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());

		Sunflower::MainLoopEnd();
	}

	Sunflower::Flush();

	return 0;
};
