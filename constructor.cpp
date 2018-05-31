#include "constructor.h"

//khoi tao ran
void nhapran(ran &snack)
{
	snack.n=2;
	TextColor(13);
	snack.dot[0].x=1;
	snack.dot[0].y=0;
	snack.dot[1].x=0;
	snack.dot[1].y=0;
	snack.tt=RIGHT;
	snack.diem.a=0;
}
// khoi tao hoa qua
void nhaphoaqua(hoaqua &hq)
{
	srand(time(NULL));
	hq.td.x=rand()%ngang;
	hq.td.y=rand()%doc;
}
//khoi tao boom
void nhapboom(boom &bom)
{
	bom.m=2;
	srand(time(NULL));
	bom.vitri[0].x=rand()%10;
	bom.vitri[0].y=rand()%10;
	bom.vitri[1].x=rand()%10+5;
	bom.vitri[1].y=rand()%10+5;

}

