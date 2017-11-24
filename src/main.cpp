#include "app/App.h"

int main() {
	App app;
	app.initApp();
	app.getRoot()->startRendering();
	app.closeApp();
	return 0;
}