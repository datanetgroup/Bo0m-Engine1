#include "bepch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace BE {
	Application::Application()
	{

	}



	Application::~Application()
	{

	}


	void Application::Run()
	{

		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			BE_TRACE(e);

		}
		if (e.IsInCategory(EventCategoryInput))
		{
			BE_TRACE(e);
		}

		while (true);
	}
}