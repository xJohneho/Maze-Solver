#include "MazeSolverGUIVer.h"
#include "ui_MazeSolverGUIVer.h"
#include <qfile.h>
#include <qtextstream.h>
#include <qmessagebox.h>
#include <QInputDialog>
#include "MazeSolverDFS.h"

MazeSolverGUIVer::MazeSolverGUIVer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_pushbutton_clicked()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushbutton_clicked2()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushbutton_clicked3()));

}
//Example of command pattern being used
//Open File Button
void MazeSolverGUIVer::on_pushbutton_clicked() {
	MazeSolver *test = new MazeSolver();
	QString text = QInputDialog::getText(NULL, "Load File", "Input name for file and add .txt at the end");
	std::string textver2 = text.toUtf8().constData();
	QFile file(text);
	if (!file.open(QIODevice::ReadOnly))
		QMessageBox::information(0, "info", file.errorString());
	
	QTextStream in(&file);
	//test->testMazeSolver(textver2);
	ui.plainTextEdit->setPlainText(file.readAll());
	
}
//Maze Solver and Display
void MazeSolverGUIVer::on_pushbutton_clicked2() {
	MazeSolver *test = new MazeSolver();
	QString text = QInputDialog::getText(NULL, "Load File", "Input name for file and add .txt at the end");
	std::string textver2 = text.toUtf8().constData();
	QFile file(text);
	if (!file.open(QIODevice::ReadOnly))
		QMessageBox::information(0, "info", file.errorString());

	QTextStream in(&file);
	QString result = QString::fromStdString(test->testMazeSolver(textver2));
	ui.plainTextEdit->setPlainText(result);
}
//Generate Button
void MazeSolverGUIVer::on_pushbutton_clicked3() {
	MazeGenerator *test = new MazeGenerator();
	MazeGenerator Level[MAZESIZE][MAZESIZE];
	QString text = QInputDialog::getText(NULL, "Generate", "Input name for file and add .txt at the end");
	if (text != NULL) {
		std::string textver2 = text.toUtf8().constData();
		test->runMazeGen(Level, textver2);
	}
	
}