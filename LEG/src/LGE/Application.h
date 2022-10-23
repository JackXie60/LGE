#pragma once

#include "Core.h"
#include "Events/Event.h"


namespace LGE {
	class LGE_API Application {
	public:
		Application();
		virtual ~Application();
		void run();
	};

	Application* createApplication();
}

