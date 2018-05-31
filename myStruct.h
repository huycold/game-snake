#ifndef MYSTRUCT_H
#define MYSTRUCT_H

#include "console.h"

struct diemso
{
    int a;
};

struct toado
{
	int x,y;
};
struct hoaqua
{
	toado td;
};
struct ran
{
	toado dot[100];
	int n;
	trangthai tt;
	diemso diem;
};

struct boom
{
	toado vitri[100];
	int m;
};

#endif // MYSTRUCT_H
