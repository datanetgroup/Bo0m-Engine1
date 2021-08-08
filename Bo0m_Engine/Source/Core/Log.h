#pragma once
#include "Core.h"
#include "bepch.h"
#include "../ThirdParty/SPDLOG/include/spdlog/spdlog.h"
#include "../ThirdParty/SPDLOG/include/spdlog/fmt/ostr.h"


namespace BE {
	class BE_API Log
	{
	public:
		static void init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr< spdlog::logger > s_CoreLogger;
		static std::shared_ptr< spdlog::logger > s_ClientLogger;
		
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