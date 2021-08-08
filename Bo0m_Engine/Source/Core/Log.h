#pragma once
#include "Core.h"
#include "../ThirdParts/spdlog/include/spdlog/spdlog.h"
#include "../ThirdParts/spdlog/include/spdlog/fmt/ostr.h"


namespace BE {
	class BE_API Log
	{
	public:
		static void init();

//		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
//		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
//		static Ref<spdlog::logger> s_CoreLogger;
//		static Ref<spdlog::logger> s_ClientLogger;
	};


}

//Core Log Macros
#define BE_CORE_TRACE(...)       ::BE::Log::GetCoreLogger()->trace(__VA_ARGV__)
#define BE_CORE_INFO(...)        ::BE::Log::GetCoreLogger()->info(__VA_ARGV__)
#define BE_CORE_WARN(...)        ::BE::Log::GetCoreLogger()->warn(__VA_ARGV__)
#define BE_CORE_ERROR(...)       ::BE::Log::GetCoreLogger()->error(__VA_ARGV__)
#define BE_CORE_FATAL(...)       ::BE::Log::GetCoreLogger()->fatal(__VA_ARGV__)

//Client Log Macros
#define BE_TRACE(...)       ::BE::Log::GetClientLogger()->trace(__VA_ARGV__)
#define BE_INFO(...)        ::BE::Log::GetClientLogger()->info(__VA_ARGV__)
#define BE_WARN(...)        ::BE::Log::GetClientLogger()->warn(__VA_ARGV__)
#define BE_ERROR(...)       ::BE::Log::GetClientLogger()->error(__VA_ARGV__)
#define BE_FATAL(...)       ::BE::Log::GetClientLogger()->fatal(__VA_ARGV__)