#include "../Source/Bo0mEngine.h"

class SampleProject : public::BE::Application
{
public:
	SampleProject()
	{

	}

	~SampleProject()
	{

	}
};



BE::Application* BE::CreateApplication()
{
	return new SampleProject();
}