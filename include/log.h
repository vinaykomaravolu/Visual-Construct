#pragma once
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

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

#ifdef VC_DEBUG
// Core log Macros
#define VC_LOG_CORE_FATAL(...) ::VCLog::GetCoreLogger()->fatal(__VA_ARGS__);
#define VC_LOG_CORE_ERROR(...) ::VCLog::GetCoreLogger()->error(__VA_ARGS__);
#define VC_LOG_CORE_WARN(...) ::VCLog::GetCoreLogger()->warn(__VA_ARGS__);
#define VC_LOG_CORE_INFO(...) ::VCLog::GetCoreLogger()->info(__VA_ARGS__);
#define VC_LOG_CORE_TRACE(...) ::VCLog::GetCoreLogger()->trace(__VA_ARGS__);

// Client log Macros
#define VC_LOG_CLIENT_FATAL(...) ::VCLog::GetClientLogger()->fatal(__VA_ARGS__);
#define VC_LOG_CLIENT_ERROR(...) ::VCLog::GetClientLogger()->error(__VA_ARGS__);
#define VC_LOG_CLIENT_WARN(...) ::VCLog::GetClientLogger()->warn(__VA_ARGS__);
#define VC_LOG_CLIENT_INFO(...) ::VCLog::GetClientLogger()->info(__VA_ARGS__);
#define VC_LOG_CLIENT_TRACE(...) ::VCLog::GetClientLogger()->trace(__VA_ARGS__);

// Renderer log Macros
#define VC_LOG_RENDERER_FATAL(...) ::VCLog::GetRendererLogger()->fatal(__VA_ARGS__);
#define VC_LOG_RENDERER_ERROR(...) ::VCLog::GetRendererLogger()->error(__VA_ARGS__);
#define VC_LOG_RENDERER_WARN(...) ::VCLog::GetRendererLogger()->warn(__VA_ARGS__);
#define VC_LOG_RENDERER_INFO(...) ::VCLog::GetRendererLogger()->info(__VA_ARGS__);
#define VC_LOG_RENDERER_TRACE(...) ::VCLog::GetRendererLogger()->trace(__VA_ARGS__);

// Vulkan log Macros
#define VC_LOG_VULKAN_FATAL(...) ::VCLog::GetVulkanLogger()->fatal(__VA_ARGS__);
#define VC_LOG_VULKAN_ERROR(...) ::VCLog::GetVulkanLogger()->error(__VA_ARGS__);
#define VC_LOG_VULKAN_WARN(...) ::VCLog::GetVulkanLogger()->warn(__VA_ARGS__);
#define VC_LOG_VULKAN_INFO(...) ::VCLog::GetVulkanLogger()->info(__VA_ARGS__);
#define VC_LOG_VULKAN_TRACE(...) ::VCLog::GetVulkanLogger()->trace(__VA_ARGS__);

// OpenGL log Macros
#define VC_LOG_OPENGL_FATAL(...) ::VCLog::GetOpenglLogger()->fatal(__VA_ARGS__);
#define VC_LOG_OPENGL_ERROR(...) ::VCLog::GetOpenglLogger()->error(__VA_ARGS__);
#define VC_LOG_OPENGL_WARN(...) ::VCLog::GetOpenglLogger()->warn(__VA_ARGS__);
#define VC_LOG_OPENGL_INFO(...) ::VCLog::GetOpenglLogger()->info(__VA_ARGS__);
#define VC_LOG_OPENGL_TRACE(...) ::VCLog::GetOpenglLogger()->trace(__VA_ARGS__);
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