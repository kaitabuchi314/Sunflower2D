#include <Core/Sunflower.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <string>


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
};

int main(int argc, char* argv[])
{
	Sunflower::InitRenderer("Sunflower", WIDTH, HEIGHT);

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


	Sunflower::PreMainLoop();


	while (!Sunflower::quit)
	{
		Sunflower::HandleEvents(handle_events);


		ImGui_ImplSDLRenderer2_NewFrame();
		ImGui_ImplSDL2_NewFrame();

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
