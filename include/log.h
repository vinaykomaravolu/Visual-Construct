#pragma once
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace VisualConstruct
{
	class VCLog
	{
	public:
		static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		};

		static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		};

		static std::shared_ptr<spdlog::logger>& GetRendererLogger()
		{
			return s_RendererLogger;
		};

		static std::shared_ptr<spdlog::logger>& GetVulkanLogger()
		{
			return s_VulkanLogger;
		};

		static std::shared_ptr<spdlog::logger>& GetOpenglLogger()
		{
			return s_OpenglLogger;
		};

	private:
		static bool Init();
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_RendererLogger;
		static std::shared_ptr<spdlog::logger> s_VulkanLogger;
		static std::shared_ptr<spdlog::logger> s_OpenglLogger;

		static bool isInit;
	};
}

#ifdef VC_DEBUG
// Core log Macros
#define VC_LOG_CORE_FATAL(...) ::VisualConstruct::VCLog::GetCoreLogger()->fatal(__VA_ARGS__);
#define VC_LOG_CORE_ERROR(...) ::VisualConstruct::VCLog::GetCoreLogger()->error(__VA_ARGS__);
#define VC_LOG_CORE_WARN(...) ::VisualConstruct::VCLog::GetCoreLogger()->warn(__VA_ARGS__);
#define VC_LOG_CORE_INFO(...) ::VisualConstruct::VCLog::GetCoreLogger()->info(__VA_ARGS__);
#define VC_LOG_CORE_TRACE(...) ::VisualConstruct::VCLog::GetCoreLogger()->trace(__VA_ARGS__);

// Client log Macros
#define VC_LOG_CLIENT_FATAL(...) ::VisualConstruct::VCLog::GetClientLogger()->fatal(__VA_ARGS__);
#define VC_LOG_CLIENT_ERROR(...) ::VisualConstruct::VCLog::GetClientLogger()->error(__VA_ARGS__);
#define VC_LOG_CLIENT_WARN(...) ::VisualConstruct::VCLog::GetClientLogger()->warn(__VA_ARGS__);
#define VC_LOG_CLIENT_INFO(...) ::VisualConstruct::VCLog::GetClientLogger()->info(__VA_ARGS__);
#define VC_LOG_CLIENT_TRACE(...) ::VisualConstruct::VCLog::GetClientLogger()->trace(__VA_ARGS__);

// Renderer log Macros
#define VC_LOG_RENDERER_FATAL(...) ::VisualConstruct::VCLog::GetRendererLogger()->fatal(__VA_ARGS__);
#define VC_LOG_RENDERER_ERROR(...) ::VisualConstruct::VCLog::GetRendererLogger()->error(__VA_ARGS__);
#define VC_LOG_RENDERER_WARN(...) ::VisualConstruct::VCLog::GetRendererLogger()->warn(__VA_ARGS__);
#define VC_LOG_RENDERER_INFO(...) ::VisualConstruct::VCLog::GetRendererLogger()->info(__VA_ARGS__);
#define VC_LOG_RENDERER_TRACE(...) ::VisualConstruct::VCLog::GetRendererLogger()->trace(__VA_ARGS__);

// Vulkan log Macros
#define VC_LOG_VULKAN_FATAL(...) ::VisualConstruct::VCLog::GetVulkanLogger()->fatal(__VA_ARGS__);
#define VC_LOG_VULKAN_ERROR(...) ::VisualConstruct::VCLog::GetVulkanLogger()->error(__VA_ARGS__);
#define VC_LOG_VULKAN_WARN(...) ::VisualConstruct::VCLog::GetVulkanLogger()->warn(__VA_ARGS__);
#define VC_LOG_VULKAN_INFO(...) ::VisualConstruct::VCLog::GetVulkanLogger()->info(__VA_ARGS__);
#define VC_LOG_VULKAN_TRACE(...) ::VisualConstruct::VCLog::GetVulkanLogger()->trace(__VA_ARGS__);

// OpenGL log Macros
#define VC_LOG_OPENGL_FATAL(...) ::VisualConstruct::VCLog::GetOpenglLogger()->fatal(__VA_ARGS__);
#define VC_LOG_OPENGL_ERROR(...) ::VisualConstruct::VCLog::GetOpenglLogger()->error(__VA_ARGS__);
#define VC_LOG_OPENGL_WARN(...) ::VisualConstruct::VCLog::GetOpenglLogger()->warn(__VA_ARGS__);
#define VC_LOG_OPENGL_INFO(...) ::VisualConstruct::VCLog::GetOpenglLogger()->info(__VA_ARGS__);
#define VC_LOG_OPENGL_TRACE(...) ::VisualConstruct::VCLog::GetOpenglLogger()->trace(__VA_ARGS__);
#else

// Core log Macros
#define VC_LOG_CORE_FATAL
#define VC_LOG_CORE_ERROR
#define VC_LOG_CORE_WARN
#define VC_LOG_CORE_INFO 
#define VC_LOG_CORE_TRACE

// Client log Macros
#define VC_LOG_CLIENT_FATAL 
#define VC_LOG_CLIENT_ERROR
#define VC_LOG_CLIENT_WARN
#define VC_LOG_CLIENT_INFO 
#define VC_LOG_CLIENT_TRACE

// Renderer log Macros
#define VC_LOG_RENDERER_FATAL
#define VC_LOG_RENDERER_ERROR
#define VC_LOG_RENDERER_WARN
#define VC_LOG_RENDERER_INFO
#define VC_LOG_RENDERER_TRACE

// Vulkan log Macros
#define VC_LOG_VULKAN_FATAL
#define VC_LOG_VULKAN_ERROR
#define VC_LOG_VULKAN_WARN
#define VC_LOG_VULKAN_INFO
#define VC_LOG_VULKAN_TRACE

// OpenGL log Macros
#define VC_LOG_OPENGL_FATAL
#define VC_LOG_OPENGL_ERROR
#define VC_LOG_OPENGL_WARN
#define VC_LOG_OPENGL_INFO
#define VC_LOG_OPENGL_TRACE
#endif
