#include "md5.h"
#include "sha.h"
#include <QString>
#include <fstream>

using namespace std;

#define size_max 1024

void MD5( const QString filename_i, unsigned char *str )
{
    FILE *in;

    in = fopen( filename_i.toUtf8().constData(), "rb" );

    MD5_CTX c;
    unsigned char i[size_max] = {0};

    unsigned int size = fread(i, 1, size_max, in);

    MD5_Pre(&c);
    MD5_Do(&c, i, size);
    MD5_Res(str, &c);

    fclose(in);

}

QString Sha1( const QString filename_i)
{
    return sha1(filename_i.toUtf8().data());
}
