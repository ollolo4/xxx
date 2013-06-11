#ifndef RIPEMD_H
#define RIPEMD_H

#include <QFile>
#include <iostream>
#include <QByteArray>
#include <QtEndian>

#define SIZE_OF_BLOCK 64

using namespace std;

QString ripemd(char *str);

#endif // RIPEMD_H
