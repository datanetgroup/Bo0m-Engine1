#pragma once
#include "Application.h"

#ifdef BE_PLATFORM_WINDOWS

extern BE::Application* BE::CreateApplication();


int main(int argc, char** argv) {

// Das Bitte nach Import von spdlog aktivieren
	BE::Log::init();
	BE::Log::GetCoreLogger()->warn("Initialized Log");
	BE::Log::GetClientLogger()->info("Hello!");


	auto app = BE::CreateApplication();
	app->Run();
	delete app;

}
#endif

