#pragma once
#include "Core.h";
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace LGE {
	class LGE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define LGE_CORE_WARN(...)	::LGE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LGE_CORE_INFO(...)	::LGE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LGE_CORE_TRACE(...) ::LGE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LGE_CORE_FATAL(...) ::LGE::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define LGE_CORE_ERROR(...) ::LGE::Log::GetCoreLogger()->error(__VA_ARGS__)

#define LGE_WARN(...)		::LGE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LGE_INFO(...)		::LGE::Log::GetClientLogger()->info(__VA_ARGS__)
#define LGE_TRACE(...)		::LGE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LGE_FATAL(...)		::LGE::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define LGE_ERROR(...)		::LGE::Log::GetClientLogger()->error(__VA_ARGS__)

