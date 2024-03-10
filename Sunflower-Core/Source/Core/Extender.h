#pragma once
#include "GameObject.h"

namespace Sunflower
{
	class Extender
	{
	public:
		virtual void on_start(Info info) {};
		virtual void on_update(Info info) {};
		virtual void on_render(Sunflower::Info info) {};
		virtual void on_input(Info info, Event ev) {};
	};

    class SpriteRenderer : public Extender
    {
    public:
        std::string path_to_image;

        void on_start(Info info) override;
        void on_update(Info info) override {};
        void on_render(Info info) override;

        void on_input(Sunflower::Info info, Event ev) override {};

    private:
        Image image;
    };

    static SpriteRenderer CreateSpriteRenderer()
    {
        return SpriteRenderer();
    }

    void SpriteRenderer::on_start(Sunflower::Info info)
    {
        image = Sunflower::LoadImage(path_to_image.c_str());
    };

    void SpriteRenderer::on_render(Sunflower::Info info)
    {
        Sunflower::DrawImage(image, info.self->scale, info.self->position);
    };
};