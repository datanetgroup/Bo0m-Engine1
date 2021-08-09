#include "../Bo0m_Engine/Source/bepch.h"
#include "WindowsWindow.h"

namespace BE {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
	}

	void WindowsWindow::init(const WindowsProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		BE_CORE_INFO("Creating window {0} ({1}, {2}", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			// TODO : glfwTerminate on System Shutdown
			init success = glfwInit();
			BE_CORE_ASSERT(success, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((init)props.Width, (init)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}
	void WindowsWindow::Shutdown()
	{

	}
	void WindowsWindow::OnUpdate()
	{

	}
}