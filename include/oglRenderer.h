#pragma once
#include <internal.h>
#include <renderer.h>

namespace VisualConstruct
{
	class OglRenderer: public Renderer
	{
	public:
		OglRenderer();
		~OglRenderer();
		void render();
		void render(int height, int width);
		void getRender(void** renderedTextureID);
	private:
		GLuint frameBuffer;
		GLuint renderedTexture;
		GLuint renderBuffer;
	};
}