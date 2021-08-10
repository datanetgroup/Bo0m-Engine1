#include "../Bo0m_Engine/Source/bepch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"
#include "../ThirdParty/GLFW/include/GLFW/glfw3.h"

namespace BE {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}



	Application::~Application()
	{

	}


	void Application::Run()
	{


		while (m_Running)
		{
			m_Window->OnUpdate();

		}
	}
}