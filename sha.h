#ifndef SHA_H
#define SHA_H

#include <QFile>
#include <iostream>
#include <QtEndian>
#include <QTemporaryFile>

#define SIZE_OF_BLOCK 64

using namespace std;

QString sha1(char *name);

#endif // SHA_H
