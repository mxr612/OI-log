#include <cstdio>
#include <windows.h>
#define qdo 262
#define qri 294
#define qmi 330     //q前缀为低音，1后缀为高音
#define qfa 349
#define qso 392
#define qla 440
#define qxi 494
#define doo 523
#define ri 578
#define mi 659
#define fa 698
#define so 784
#define la 880
#define xi 988
#define do1 1046
#define ri1 1175
#define mi1 1318
#define fa1 1480
#define so1 1568
#define la1 1760
#define xi1 1976
#define do11 2092
#define ri11 2350
#define mi11 2636
#define fa11 2960
#define so11 3136
#define la11 3560
#define xi11 3952
int main() {
    int pai=400,ban=200;
    int ting=128;
    Beep(ri1,pai);
    Beep(mi1,ban);
    Beep(do1,ban);
    Beep(ri1,pai*3);
    Beep(mi1,pai);
    Beep(fa1,pai);
    Beep(so1,pai);
    Beep(mi1,pai);
    Beep(do1,pai);
    Beep(ri1,pai);
    Beep(mi1,ban);
    Beep(do1,ban);
    Beep(ri1,pai*3);
    Sleep(ting);
    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(fa,ban>>1);
    Beep(so,ban>>1);
    Beep(la,ban);
    Beep(so,ban);
    Beep(fa,ban>>1);
    Beep(mi,ban>>1);
    Beep(ri,pai*2);

    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(fa,ban>>1);
    Beep(so,ban>>1);
    Beep(la,ban);
    Beep(so,ban);
    Beep(fa,ban>>1);
    Beep(mi,ban>>1);
    Beep(ri,pai*3);//

    Beep(qla,pai);
    Beep(ri,pai*3);
    Beep(mi,ban);
    Beep(fa,ban);
    Beep(so,pai*2);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(fa,ban>>1);
    Beep(mi,ban>>1);
    Beep(ri,ban>>1);
    Beep(doo,ban>>1);
    Beep(ri,pai*2);
    Beep(qla,pai*4);
    Beep(qso,pai);
    Beep(ri,pai*3);
    Beep(mi,ban);
    Beep(fa,ban);
    Beep(so,pai*2);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(fa,ban>>1);
    Beep(mi,ban>>1);
    Beep(ri,ban>>1);
    Beep(doo,ban>>1);
    Beep(ri,pai*2);
    Beep(la,pai*2);
    Beep(so,pai*2);
    Beep(do1,pai*2);

    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(fa,ban>>1);
    Beep(so,ban>>1);
    Beep(la,ban);
    Beep(so,ban);
    Beep(fa,ban>>1);
    Beep(mi,ban>>1);
    Beep(ri,pai*3);

    Beep(qla,pai);
    Beep(ri,pai*3);
    Beep(mi,ban);
    Beep(fa,ban);
    Beep(so,pai*2);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(fa,ban>>1);
    Beep(mi,ban>>1);
    Beep(ri,ban>>1);
    Beep(doo,ban>>1);
    Beep(ri,pai*2);
    Beep(qla,pai*4);
    Beep(qso,pai);
    Beep(ri,pai*3);
    Beep(mi,ban);
    Beep(fa,ban);
    Beep(so,pai*2);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(fa,ban>>1);
    Beep(mi,ban>>1);
    Beep(ri,ban>>1);
    Beep(doo,ban>>1);
    Beep(ri,pai*2);
    Beep(la,pai*2);
    Beep(so,pai*2);
    Beep(do1,pai*2);

    Beep(ri1,pai*3);
    Beep(mi1,ban);
    Beep(fa1,ban);
    Beep(so1,pai*2);
    Beep(la1,ban>>1);
    Beep(so1,ban>>1);
    Beep(fa1,ban>>1);
    Beep(mi1,ban>>1);
    Beep(ri1,ban>>1);
    Beep(do1,ban>>1);
    Beep(ri1,pai*2);
    Beep(la,pai*4);
    Beep(so,pai);
    Beep(ri,pai*3);
    Beep(mi,ban);
    Beep(fa,ban);
    Beep(so,pai*2);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(fa,ban>>1);
    Beep(mi,ban>>1);
    Beep(ri,ban>>1);
    Beep(doo,ban>>1);
    Beep(ri,pai*2);
    Beep(la,pai*2);
    Beep(so,pai*2);
    Beep(do1,pai*2);

    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(ri1,ban);
    Beep(ri1,ban);
    Beep(ri,ban);
    Beep(ri1,ban);
    Beep(do1,ban);
    Beep(xi,ban>>1);
    Beep(la,ban>>1);
    Beep(xi,ban);
    Beep(la,ban>>1);
    Beep(so,ban>>1);
    Beep(ri1,pai);
    Beep(ri1,pai*6);
    return 0;
}