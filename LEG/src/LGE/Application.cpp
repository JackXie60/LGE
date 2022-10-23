#include "lgepch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace LGE {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			LGE_INFO(e);
		}
		else {
			LGE_WARN(e);
		}
		while (true)
		{
		}
	}
}
