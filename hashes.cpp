#include "md5.h"
#include "sha.h"
#include "ripemd.h"
#include <QString>
#include <QDataStream>
#include <fstream>

using namespace std;

#define size_max 1024

void MD5( const QString filename_i, unsigned char *str )
{
    QFile file(filename_i.toUtf8().data());
    file.open(QIODevice::ReadOnly);

    MD5_CTX c;
    unsigned char i[size_max] = {0};

    QDataStream in(&file);

    unsigned int size = in.readRawData((char*)i,size_max);

    MD5_Pre(&c);
    MD5_Do(&c, i, size);
    MD5_Res(str, &c);

    file.close();

}

QString Sha1( const QString filename_i )
{
    return sha1(filename_i.toUtf8().data());
}

QString Ripemd( const QString filename_i )
{
    return ripemd(filename_i.toUtf8().data());
}
