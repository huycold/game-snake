#include "console.h"
#include "myStruct.h"
#include "display.h"
#include "constructor.h"
#include "handl.h"

int main ()
{
    int kt=0;
    int dokho=150;
    diemso diem;
	ran snack;
	hoaqua hq;
	boom bom;
	inchu();
	nhapran(snack);
	nhaphoaqua(hq);
	nhapboom(bom);
	while(1)
	{

	hienthiran( snack);
	hienthihoaqua(hq);
	hienthiboom(bom);
	hienthidiem(snack);
	dieukien(snack);
	xuly1(snack,hq,dokho,bom);
	xuly2(snack,bom);
	kt=gameover(snack);
	if(kt==-1)
	{
		clrscr();
		ketthuc();
		break;
	}

    Sleep(dokho);
	}
return 0;
}
