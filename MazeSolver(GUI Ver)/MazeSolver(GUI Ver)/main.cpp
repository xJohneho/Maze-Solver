#include "MazeSolverGUIVer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	//Q_INIT_RESOURCE(undoframework);
	QApplication a(argc, argv);
	MazeSolverGUIVer w;
	w.show();
	return a.exec();
}
