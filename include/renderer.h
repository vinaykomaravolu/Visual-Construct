#pragma once

namespace VisualConstruct
{
	class Renderer 
	{
	public:
		virtual void render() = 0;
		virtual void render(int height, int width) = 0;
		virtual void getRender(void** renderedTextureID) = 0;
	protected:
		int baseHeight = 1080;
		int baseWidth = 1920;
	};
}