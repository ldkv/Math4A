#include "bezierqt.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	BezierQt window;
	window.showMaximized();
	return app.exec();
}