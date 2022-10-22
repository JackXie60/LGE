#pragma once
#include "Application.h"
extern LGE::Application* LGE::createApplication();

#ifdef LGE_PALTFORM_WINDOWS
void main() {
	auto app = LGE::createApplication();
	app->run();
	delete app;
};
#endif