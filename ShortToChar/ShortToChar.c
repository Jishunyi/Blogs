#include <stdio.h>
#include <stdlib.h>

unsigned char *ShortToChar(const unsigned short *ShortData, unsigned int Lenth)
{
    int i, j;
    unsigned char *CharData;
    CharData = (unsigned char *)malloc(Lenth * sizeof(unsigned char));
    printf("ShortData Size: %zd Byte.\n", Lenth);
    for (i = 0, j = 0; i < Lenth; i += 2, j++) //i+2是错误的
    {
        CharData[i] = ShortData[j] & 0xff;            //低八位 00
        CharData[i + 1] = (ShortData[j] >> 8) & 0xff; //高八位 11
    }
    return CharData;
}

int main(void)
{
    int i;
    unsigned short ShortData[4] = {0x0011223344556677};
    unsigned char *CharData;
    CharData = ShortToChar(ShortData, sizeof(ShortData));
    for (i = 0; i < (unsigned int)sizeof(ShortData); i++)
    {
        printf("%x ", CharData[i]);
    }

    return 0;
}