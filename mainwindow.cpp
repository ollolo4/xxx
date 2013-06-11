#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QRegExp>
#include <QMessageBox>
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    display();
    connect(ui->openFBut, SIGNAL( clicked() ), SLOT( openInput() ));
    connect(ui->pushMd5, SIGNAL( clicked() ), SLOT( clickedMD5() ));
    connect(ui->pushSha, SIGNAL( clicked() ), SLOT( clickedSha() ));
    connect(ui->pushRipmd, SIGNAL( clicked() ), SLOT( clickedRipemd() ));
}

void MainWindow::display()
{
    ui->openFBut->setVisible( true );
    ui->openF->setVisible( false );
    ui->label1->setVisible( false );
    ui->pushMd5->setVisible( false );
    ui->pushSha->setVisible( false );
    ui->pushRipmd->setVisible( false );
    ui->textOut->setVisible( false );

}

void MainWindow::openInput()
{
    QString str = QFileDialog::getOpenFileName( this, QString::fromLocal8Bit( "Выбрать файл для хешировнаия" ) );
    if ( !str.isEmpty() ) {
        ui->openF->setText( str );
        ui->openF->setVisible( true );
        ui->label1->setVisible( true );
        ui->pushMd5->setVisible( true );
        ui->pushSha->setVisible( true );
        ui->pushRipmd->setVisible( true );
    }
}

void MainWindow::clickedMD5()
{
    ui->textOut->setVisible( true );
    unsigned char str[16];
    MD5( ui->openF->text(), str );

    ui->textOut->setText( getStringFromUnsignedChar( str ) );
}

void MainWindow::clickedSha()
{
    ui->textOut->setVisible( true );
    QString str;
    str = Sha1( ui->openF->text());

    ui->textOut->setText( str );

}

void MainWindow::clickedRipemd()
{
    ui->textOut->setVisible( true );
    QString str;
    str = Ripemd( ui->openF->text());

    ui->textOut->setText( str );

}

MainWindow::~MainWindow()
{
    delete ui;
}
