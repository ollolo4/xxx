#include "mainwindow.h"
#include <QFile>

using namespace std;

QString FileToQString( QString filename )
{
    QString str;

    FILE *f;
    f = fopen( filename.toUtf8().constData(), "rb" );
    unsigned char c[1024];
    unsigned int size = fread( c, 1, 1024, f );
    fclose(f);

    for ( unsigned int i = 0; i < size; i++ ) {
        str += c[i];
    }

    return str;
}

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

    QString s;
    QString result = "";
    int rev = 16;

    // Print String in Reverse order....
    for ( int i = 0; i<rev; i++)
        {
           s = QString("%1").arg(str[i],0,16);

           if(s == "0"){
              s="00";
             }
         result.append(s);

         }
   return result;
}
