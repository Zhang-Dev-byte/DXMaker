#pragma once
#include "dxpch.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace DX {
	class DX_API Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define DX_CORE_TRACE(...)    ::DX::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DX_CORE_INFO(...)     ::DX::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DX_CORE_WARN(...)     ::DX::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DX_CORE_ERROR(...)    ::DX::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DX_CORE_CRITICAL(...) ::DX::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define DX_TRACE(...)         ::DX::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DX_INFO(...)          ::DX::Log::GetClientLogger()->info(__VA_ARGS__)
#define DX_WARN(...)          ::DX::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DX_ERROR(...)         ::DX::Log::GetClientLogger()->error(__VA_ARGS__)
#define DX_CRITICAL(...)      ::DX::Log::GetClientLogger()->critical(__VA_ARGS__)

namespace DX {
	class DX_API Debug {
	public:
		template<typename T, typename... Args>
		static void Log(T t, Args... args) {
			DX_INFO(t, args...);
		}
		template<typename T, typename... Args>
		static void LogError(T t, Args... args) {
			DX_ERROR(t, args...);
		}
		template<typename T, typename... Args>
		static void LogWarn(T t, Args... args) {
			DX_WARN(t, args...);
		}
		template<typename T, typename... Args>
		static void LogCritical(T t, Args... args) {
			DX_CRITICAL(t, args...);
		}
		template<typename T, typename... Args>
		static void LogTrace(T t, Args... args) {
			DX_TRACE(t, args...);
		}
	};
}