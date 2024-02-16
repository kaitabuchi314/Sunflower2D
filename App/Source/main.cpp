#include <Core/Engine.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <string>

const int WIDTH = (int)1920 / 1.5;
const int HEIGHT = (int)1080 / 1.5;

Engine::vec2 img_scale;
Engine::vec2 img_pos;

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
};

int main(int argc, char* argv[])
{
	Engine::InitRenderer("Brackeys Game Jam", WIDTH, HEIGHT);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigDockingWithShift = false;

	ImGui::StyleColorsDark();

	ImGui_ImplSDL2_InitForSDLRenderer(Engine::GetWindow(), Engine::GetRenderer());
	ImGui_ImplSDLRenderer2_Init(Engine::GetRenderer());

	io.Fonts->AddFontDefault();

	Engine::Image image = Engine::LoadImage("Assets/kitten.png");
	
	img_scale.x = 0.3f;
	img_scale.y = 0.3f;


	Engine::PreMainLoop();


	while (!Engine::quit)
	{
		Engine::HandleEvents(handle_events);


		ImGui_ImplSDLRenderer2_NewFrame();
		ImGui_ImplSDL2_NewFrame();

		ImGui::NewFrame();
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);

		Engine::DrawBackground(53, 90, 222);


		Engine::DrawImage(image, img_scale, img_pos);

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

		Engine::MainLoopEnd();
	}

	Engine::Flush();

	return 0;
};
