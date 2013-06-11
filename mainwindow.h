#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

private slots:
    void display();
    void openInput();
    void clickedMD5();
    void clickedSha();
    void clickedRipemd();
};

void MD5 (const QString, unsigned char*);
QString Sha1 (const QString);
QString Ripemd (const QString);

QString FileToQString(QString);
char * QStringToCharStr(QString);
QString getStringFromUnsignedChar(unsigned char*);

#endif // MAINWINDOW_H
