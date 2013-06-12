#include "md5.h"
#include "sha.h"
#include "ripemd.h"
#include <QString>
#include <fstream>

using namespace std;

#define size_max 1024

void MD5( const QString filename_i, unsigned char *str )
{
   // QFile file(filename_i.toUtf8().data());
   // file.open(QIODevice::ReadOnly);

    MD5_CTX c;
   // QString d = QString(file.read(size_max));
    unsigned char i[size_max] = {0};
  //  memcpy(i, d.toLocal8Bit().data(), size_max);
  //unsigned int size = d.length();

    FILE *in;

    in = fopen( filename_i.toUtf8().data(), "rb" );
    unsigned int size = fread(i, 1, size_max, in);

    MD5_Pre(&c);
    MD5_Do(&c, i, size);
    MD5_Res(str, &c);
    fclose(in);
    //file.close();

}

QString Sha1( const QString filename_i )
{
    return sha1(filename_i.toUtf8().data());
}

QString Ripemd( const QString filename_i )
{
    return ripemd(filename_i.toUtf8().data());
}
