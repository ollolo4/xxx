#include "mainwindow.h"
#include <QFile>

using namespace std;

char * QStringToCharStr(QString str)
{
    char * charstr = new char [str.size()];
    string stdstr = str.toStdString();
    for (int i = 0; i < str.size(); i++) {
        charstr[i] = stdstr[i];
    }
    return charstr;
}
