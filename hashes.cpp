#include "md5.h"
#include "sha.h"
#include <QString>
#include <fstream>

using namespace std;

#define size_max 1024

void MD5( const QString filename_i, unsigned char *str )
{
    QFile file(filename_i.toUtf8().constData());
    file.open(QIODevice::ReadWrite);

    MD5_CTX c;
    unsigned char *i = (unsigned char*)QString(file.read(size_max)).toUtf8().data();
    unsigned int size = file.size();

    MD5_Pre(&c);
    MD5_Do(&c, i, size);
    MD5_Res(str, &c);

    file.close();

}

QString Sha1( const QString filename_i)
{
    return sha1(filename_i.toUtf8().data());
}
