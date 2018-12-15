/********************************************************************************
** Form generated from reading UI file 'MazeSolverGUIVer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAZESOLVERGUIVER_H
#define UI_MAZESOLVERGUIVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MazeSolverGUIVerClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MazeSolverGUIVerClass)
    {
        if (MazeSolverGUIVerClass->objectName().isEmpty())
            MazeSolverGUIVerClass->setObjectName(QStringLiteral("MazeSolverGUIVerClass"));
        MazeSolverGUIVerClass->resize(900, 900);
        MazeSolverGUIVerClass->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.05 rgba(14, 8, 73, 255), stop:0.369318 rgba(28, 17, 145, 255), stop:0.630682 rgba(126, 14, 81, 255), stop:0.767045 rgba(234, 11, 11, 255), stop:0.79 rgba(244, 70, 5, 255), stop:1 rgba(255, 136, 0, 255));"));
        centralWidget = new QWidget(MazeSolverGUIVerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 730, 131, 61));
        pushButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.318182, x2:0, y2:0.648, stop:0 rgba(255, 0, 0, 255), stop:1 rgba(144, 0, 0, 255));"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(710, 730, 131, 61));
        pushButton_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.318182, x2:0, y2:0.648, stop:0 rgba(255, 0, 0, 255), stop:1 rgba(144, 0, 0, 255));"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(50, 40, 791, 671));
        plainTextEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(50, 730, 131, 61));
        pushButton_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.318182, x2:0, y2:0.648, stop:0 rgba(255, 0, 0, 255), stop:1 rgba(144, 0, 0, 255));"));
        MazeSolverGUIVerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MazeSolverGUIVerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 22));
        MazeSolverGUIVerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MazeSolverGUIVerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MazeSolverGUIVerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MazeSolverGUIVerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MazeSolverGUIVerClass->setStatusBar(statusBar);

        retranslateUi(MazeSolverGUIVerClass);

        QMetaObject::connectSlotsByName(MazeSolverGUIVerClass);
    } // setupUi

    void retranslateUi(QMainWindow *MazeSolverGUIVerClass)
    {
        MazeSolverGUIVerClass->setWindowTitle(QApplication::translate("MazeSolverGUIVerClass", "MazeSolverGUIVer", nullptr));
        pushButton->setText(QApplication::translate("MazeSolverGUIVerClass", "Open File", nullptr));
        pushButton_2->setText(QApplication::translate("MazeSolverGUIVerClass", "Solve Maze", nullptr));
        pushButton_3->setText(QApplication::translate("MazeSolverGUIVerClass", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MazeSolverGUIVerClass: public Ui_MazeSolverGUIVerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAZESOLVERGUIVER_H
