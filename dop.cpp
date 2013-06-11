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

QString getStringFromUnsignedChar(unsigned char *str)
{
    QString res;

    unsigned char temp;
    for (unsigned int i = 0; i < 16; i++) {
        temp = str[i] / 16;
        if (temp < 10) temp += '0';
        else {
            temp -= 10;
            temp += 'a';
        }
        res += temp;
        temp = str[i] % 16;
        if (temp < 10) {
            temp += '0';
        }
        else {
            temp -= 10;
            temp += 'a';
        }
        res += temp;
    }

    return res;
}
