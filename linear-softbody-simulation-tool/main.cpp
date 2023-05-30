#include "Lsst.h"

#include "Application.h"

Application& app = Application::Instance();

int main()
{
	app.Init();
	app.Run();

	return EXIT_SUCCESS;
}