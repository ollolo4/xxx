/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 26. May 10:59:52 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *openFBut;
    QLineEdit *openF;
    QLabel *label1;
    QPushButton *pushMd5;
    QTextBrowser *textOut;
    QPushButton *pushSha;
    QPushButton *pushRipmd;
    QPushButton *pushGost;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(671, 381);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(190, 236, 233, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        MainWindow->setAcceptDrops(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        openFBut = new QPushButton(centralWidget);
        openFBut->setObjectName(QString::fromUtf8("openFBut"));
        openFBut->setGeometry(QRect(20, 10, 311, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(10);
        openFBut->setFont(font);
        openF = new QLineEdit(centralWidget);
        openF->setObjectName(QString::fromUtf8("openF"));
        openF->setGeometry(QRect(350, 10, 311, 31));
        openF->setDragEnabled(true);
        openF->setReadOnly(true);
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(240, 60, 211, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Sans Serif"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label1->setFont(font1);
        pushMd5 = new QPushButton(centralWidget);
        pushMd5->setObjectName(QString::fromUtf8("pushMd5"));
        pushMd5->setGeometry(QRect(40, 100, 131, 31));
        textOut = new QTextBrowser(centralWidget);
        textOut->setObjectName(QString::fromUtf8("textOut"));
        textOut->setGeometry(QRect(90, 170, 501, 141));
        pushSha = new QPushButton(centralWidget);
        pushSha->setObjectName(QString::fromUtf8("pushSha"));
        pushSha->setGeometry(QRect(190, 100, 131, 31));
        pushRipmd = new QPushButton(centralWidget);
        pushRipmd->setObjectName(QString::fromUtf8("pushRipmd"));
        pushRipmd->setGeometry(QRect(360, 100, 131, 31));
        pushGost = new QPushButton(centralWidget);
        pushGost->setObjectName(QString::fromUtf8("pushGost"));
        pushGost->setGeometry(QRect(510, 100, 131, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 671, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "xxx", 0, QApplication::UnicodeUTF8));
        openFBut->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273 \320\264\320\273\321\217 \320\276\321\202\320\272\321\200\321\213\321\202\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label1->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\205\320\265\321\210-\321\204\321\203\320\275\320\272\321\206\320\270\321\216", 0, QApplication::UnicodeUTF8));
        pushMd5->setText(QApplication::translate("MainWindow", "MD-5", 0, QApplication::UnicodeUTF8));
        pushSha->setText(QApplication::translate("MainWindow", "SHA-1", 0, QApplication::UnicodeUTF8));
        pushRipmd->setText(QApplication::translate("MainWindow", "RIPMD", 0, QApplication::UnicodeUTF8));
        pushGost->setText(QApplication::translate("MainWindow", "\320\223\320\236\320\241\320\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
