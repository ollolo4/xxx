#include "md5.h"
#include "sha.h"
#include "ripemd.h"
#include <QString>
#include <QDataStream>
#include <fstream>

using namespace std;

#define size_max 1024

QString MD5( const QString filename_i)
{
    return md5(filename_i.toUtf8().data());
}

QString Sha1( const QString filename_i )
{
    return sha1(filename_i.toUtf8().data());
}

QString Ripemd( const QString filename_i )
{
    return ripemd(filename_i.toUtf8().data());
}
