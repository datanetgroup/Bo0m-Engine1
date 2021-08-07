#pragma once
#include "Application.h"

#ifdef BE_PLATFORM_WINDOWS

extern BE::Application* BE::CreateApplication();


int main(int argc, char** argv) {

// Das Bitte nach Import von spdlog aktivieren
//	BE::Log::Init();
//	BE_CORE_WARN("Initialized Log!");
//	BE_INFO("Initialized Log!");


	auto app = BE::CreateApplication();
	app->Run();
	delete app;

}
#endif

