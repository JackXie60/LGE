#pragma once
#include "Application.h"
extern LGE::Application* LGE::createApplication();

#ifdef LGE_PALTFORM_WINDOWS
void main() {
	LGE::Log::Init();
	LGE_CORE_WARN("Engine Initialed");
	LGE_CORE_INFO("Hello!");
	auto app = LGE::createApplication();
	app->run();
	delete app;
};
#endif