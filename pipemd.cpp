#include "ripemd.h"

unsigned int shll(unsigned int a, unsigned int s)
{
    return ((a<<s)|(a>>(32-s)));
}

unsigned int f(int j, unsigned int x, unsigned int y, unsigned int z)
{
    if (j > 63) return x ^ (y | (~z));
    if (j > 47) return (x & z) | (y & (~z));
    if (j > 31) return (x | (~y)) ^ z;
    if (j > 15) return (x & y) | ((~x) & z);
    if (j > -1) return x ^ y ^ z;
}

unsigned int K(int j)
{
    if (j > 63) return 0xa953fd4e;
    if (j > 47) return 0x8f1bbcdc;
    if (j > 31) return 0x6ed9eba1;
    if (j > 15) return 0x5a827999;
    if (j > -1) return 0x00000000;
}

unsigned int K_(int j)
{
    if (j > 63) return 0x00000000;
    if (j > 47) return 0x7a6d76e9;
    if (j > 31) return 0x6d703ef3;
    if (j > 15) return 0x5c4dd124;
    if (j > -1) return 0x50a28be6;
}

unsigned int r(int j)
{
    if (j > 63)
    {
        int r[16] = {4, 0, 5, 9, 7, 12, 2, 10, 14, 1, 3, 8, 11, 6, 15, 13};
        return r[j % 16];
    }
    if (j > 47)
    {
        int r[16] = {1, 9, 11, 10, 0, 8, 12, 4, 13, 3, 7, 15, 14, 5, 6, 2};
        return r[j % 16];
    }
    if (j > 31)
    {
        int r[16] = {3, 10, 14, 4, 9, 15, 8, 1, 2, 7, 0, 6, 13, 11, 5, 12};
        return r[j % 16];
    }
    if (j > 15)
    {
        int r[16] = {7, 4, 13, 1, 10, 6, 15, 3, 12, 0, 9, 5, 2, 14, 11, 8};
        return r[j % 16];
    }
    if (j > -1)
    {
        int r[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        return r[j % 16];
    }
}

unsigned int r_(int j)
{
    if (j > 63)
    {
        int r_[16] = {12, 15, 10, 4, 1, 5, 8, 7, 6, 2, 13, 14, 0, 3, 9, 11};
        return r_[j % 16];
    }
    if (j > 47)
    {
        int r_[16] = {8, 6, 4, 1, 3, 11, 15, 0, 5, 12, 2, 13, 9, 7, 10, 14};
        return r_[j % 16];
    }
    if (j > 31)
    {
        int r_[16] = {15, 5, 1, 3, 7, 14, 6, 9, 11, 8, 12, 2, 10, 0, 4, 13};
        return r_[j % 16];
    }
    if (j > 15)
    {
        int r_[16] = {6, 11, 3, 7, 0, 13, 5, 10, 14, 15, 8, 12, 4, 9, 1, 2};
        return r_[j % 16];
    }
    if (j > -1)
    {
        int r_[16] = {5, 14, 7, 0, 9, 2, 11, 4, 13, 6, 15, 8, 1, 10, 3, 12};
        return r_[j % 16];
    }
}

unsigned int s(int j)
{
    if (j > 63)
    {
        int s[16] = {9, 15, 5, 11, 6, 8, 13, 12, 5, 12, 13, 14, 11, 8, 5, 6};
        return s[j % 16];
    }
    if (j > 47)
    {
        int s[16] = {11, 12, 14, 15, 14, 15, 9, 8, 9, 14, 5, 6, 8, 6, 5, 12};
        return s[j % 16];
    }
    if (j > 31)
    {
        int s[16] = {11, 13, 6, 7, 14, 9, 13, 15, 14, 8, 13, 6, 5, 12, 7, 5};
        return s[j % 16];
    }
    if (j > 15)
    {
        int s[16] = {7, 6, 8, 13, 11, 9, 7, 15, 7, 12, 15, 9, 11, 7, 13, 12};
        return s[j % 16];
    }
    if (j > -1)
    {
        int s[16] = {11, 14, 15, 12, 5, 8, 7, 9, 11, 13, 14, 15, 6, 7, 9, 8};
        return s[j % 16];
    }
}

unsigned int s_(int j)
{
    if (j > 63)
    {
        int s_[16] = {8, 5, 12, 9, 12, 5, 14, 6, 8, 13, 6, 5, 15, 13, 11, 11};
        return s_[j % 16];
    }
    if (j > 47)
    {
        int s_[16] = {15, 5, 8, 11, 14, 14, 6, 14, 6, 9, 12, 9, 12, 5, 15, 8};
        return s_[j % 16];
    }
    if (j > 31)
    {
        int s_[16] = {9, 7, 15, 11, 8, 6, 6, 14, 12, 13, 5, 14, 13, 13, 7, 5};
        return s_[j % 16];
    }
    if (j > 15)
    {
        int s_[16] = {9, 13, 15, 7, 12, 8, 9, 11, 7, 7, 12, 7, 6, 15, 13, 11};
        return s_[j % 16];
    }
    if (j > -1)
    {
        int s_[16] = {8, 9, 9, 11, 13, 15, 15, 5, 7, 7, 8, 11, 14, 14, 12, 6};
        return s_[j % 16];
    }
}

void hash_rip_one(unsigned int *X, unsigned int &H0, unsigned int &H1, unsigned int &H2, unsigned int &H3, unsigned int &H4)
{
    //Вспомогательные переменные
    unsigned int A, B, C, D, E, A_, B_, C_, D_, E_, T;
    A = A_ = H0;
    B = B_ = H1;
    C = C_ = H2;
    D = D_ = H3;
    E = E_ = H4;

    for(int j = 0; j < 80 ; j++)
    {
        T = shll(A + f(j, B, C, D) + X[r(j)] + K(j), s(j)) + E;
        A = E;
        E = D;
        D = shll(C, 10);
        C = B;
        B = T;

        T = shll(A_ + f(79 - j, B_, C_, D_) + X[r_(j)] + K_(j), s_(j)) + E_;
        A_ = E_;
        E_ = D_;
        D_ = shll(C_, 10);
        C_ = B_;
        B_ = T;
    }

    T = H1 + C + D_;
    H1 = H2 + D + E_;
    H2 = H3 + E + A_;
    H3 = H4 + A + B_;
    H4 = H0 + B + C_;
    H0 = T;
}

QString ripemd(char *name)
{
    //Открываем файл
    QFile file(name);
    file.open(QIODevice::ReadWrite);

    //Запоминаем размер файла
    quint64 file_size = file.size();
    file.close();

    //Считаем сколько сколько байт дописать
    int last_size = file_size % SIZE_OF_BLOCK;

    int zero_size;
    if (last_size < 56) zero_size = 56 - last_size;
    else zero_size = SIZE_OF_BLOCK - last_size + 56;

    //Считаем количество блоков
    quint64 num_of_blocks = (file_size + zero_size + 8) / SIZE_OF_BLOCK;

    //Сколько последних блоков должны быть модифицированы
    int blocks_mod = 1;
    if (last_size >= 56)
        blocks_mod++;

    //Начинаем преобразования

    //Начальные значения констант
    unsigned int H0 = 0x67452301;
    unsigned int H1 = 0xefcdab89;
    unsigned int H2 = 0x98badcfe;
    unsigned int H3 = 0x10325476;
    unsigned int H4 = 0xc3d2e1f0;

    //Читаем из файла блоками по 64 байта
    FILE *ff = fopen(name, "rb");
    unsigned int R[16];
    for(qint64 i = 0; i < num_of_blocks - blocks_mod; i++)
    {
        //Читаем блоки из файла
        fread(R, 4, 16, ff);
        hash_rip_one(R, H0, H1, H2, H3, H4);
    }

    //Читаем последние блоки
    if (last_size < 56)
    {
        //Последний блок модифицируются
        unsigned char buf[64];
        //Читаем остатки файла и закрываем его
        fread(buf, 1, last_size, ff);
        fclose(ff);

        //Дописываем заполнители
        int it = last_size;
        buf[it++] = 0x80;
        for(int i = 0; i < zero_size - 1; buf[it++] = 0, i++);

        //Дописываем длину в битах
        quint64 bit_file_size = file_size*8;
        for(int i = 0; i < 8; i++) {
            buf[it++] = bit_file_size & 0xFF;
            bit_file_size /= 256;
        }

        //Хешируем последний блок - представляем его как массив int значений
        for(int i = 0; i < 16; i++) {
            R[i] = 256*256*256*buf[4*i + 3] + 256*256*buf[4*i + 2] + 256*buf[4*i + 1] + buf[4*i];
        }
        hash_rip_one(R, H0, H1, H2, H3, H4);
    }
    else
    {
        //Последние 2 блока модифицируются
        unsigned char buf[128];
        //Читаем остатки файла и закрываем его
        fread(buf, 1, last_size, ff);
        fclose(ff);

        //Дописываем биты заполнители
        int it = last_size;
        buf[it++] = 0x80;
        for(int i = 0; i < zero_size - 1; buf[it++] = 0, i++);

        //Дописываем длину в битах
        quint64 bit_file_size = file_size*8;
        for(int i = 0; i < 8; i++) {
            buf[it++] = bit_file_size & 0xFF;
            bit_file_size /= 256;
        }

        //Хешируем 1-й из последних блоков - представляем его как массив int значений
        for(int i = 0; i < 16; i++) {
            R[i] = 256*256*256*buf[4*i + 3] + 256*256*buf[4*i + 2] + 256*buf[4*i + 1] + buf[4*i];
        }
        hash_rip_one(R, H0, H1, H2, H3, H4);

        //Хешируем 2-й из последних блоков - представляем его как массив int значений
        for(int i = 16; i < 32; i++) {
            R[i - 16] = 256*256*256*buf[4*i + 3] + 256*256*buf[4*i + 2] + 256*buf[4*i + 1] + buf[4*i];
        }
        hash_rip_one(R, H0, H1, H2, H3, H4);
    }

    H0 = qToBigEndian(H0);
    H1 = qToBigEndian(H1);
    H2 = qToBigEndian(H2);
    H3 = qToBigEndian(H3);
    H4 = qToBigEndian(H4);
    //Выводим хеш
    QString str = QString ("%1%2%3%4%5").arg(H0,-1,16).arg(H1,-1,16).arg(H2,-1,16).arg(H3,-1,16).arg(H4,-1,16);
    return str;
}

