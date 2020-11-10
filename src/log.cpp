#include <log.h>

namespace VisualConstruct
{
	std::shared_ptr<spdlog::logger> VCLog::s_CoreLogger;
	std::shared_ptr<spdlog::logger> VCLog::s_ClientLogger;
	std::shared_ptr<spdlog::logger> VCLog::s_RendererLogger;
	std::shared_ptr<spdlog::logger> VCLog::s_VulkanLogger;
	std::shared_ptr<spdlog::logger> VCLog::s_OpenglLogger;

	bool VCLog::Init() 
	{
		spdlog::set_pattern("%^[%T][%l][%n]: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("VisualConstruct");
		s_ClientLogger = spdlog::stdout_color_mt("Application");
		s_RendererLogger = spdlog::stdout_color_mt("Renderer");
		s_VulkanLogger = spdlog::stdout_color_mt("Vulkan");
		s_OpenglLogger = spdlog::stdout_color_mt("OpenGL");
		return true;
	}

	bool VCLog::isInit = VCLog::Init();
}