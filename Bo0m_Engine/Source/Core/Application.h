#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace BE {

	class BE_API Application
	{
	public:
		Application();
		virtual ~Application();

	void Run();
	};

	//To be defiend in Client
	Application* CreateApplication();

}
