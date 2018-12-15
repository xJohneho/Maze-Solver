#pragma once
#ifndef MAZESOLVERGUIVER_H
#define MAZESOLVERGUIVER_H

#include <QtWidgets/QMainWindow>
#include "ui_MazeSolverGUIVer.h"
#include <QDesktopWidget>
#include <QMainWindow>
#include <qundostack.h>
#include <qundoview.h>
#include <qplaintextedit.h>


class MazeSolverGUIVer : public QMainWindow
{
	Q_OBJECT

public:
	MazeSolverGUIVer(QWidget *parent = Q_NULLPTR);
	
private:
	Ui::MazeSolverGUIVerClass ui;
	

private slots:
	void on_pushbutton_clicked();
	void on_pushbutton_clicked2();
	void on_pushbutton_clicked3();
};
#endif // MAZESOLVERGUIVER_H