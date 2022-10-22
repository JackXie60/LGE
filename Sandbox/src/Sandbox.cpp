#include <LGE.h>

class Sandbox : public LGE::Application
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};


LGE::Application* LGE::createApplication() {
	return new Sandbox();
}