#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<cstring>
#include<string.h>
#include<conio.h>
#include<ctime>
enum trangthai { UP,DOWN,LEFT,RIGHT};


struct dongchu
{
	char a[100];
	int x,y;
	trangthai tt;
} ;
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

void inchu()
{
	int i;
    //in ra mA n hA¬nh chá»? Ä‘áº§u tiAªn
    char snake[11][80]= {
               " OOOOOO   O       O        O        O    O   O O O O",
			   "O         O o     O       O O       O   O    O",
			   "O         O  o    O      O   O      O O      O",
               " OOOOOO   O   o   O     O O O O     O        O O O O",
			   "      O   O    o  O    O       O    O O      O",
               "      O   O     o O   O         O   O   O    O",
			   "OOOOOOO   O      oO  O           O  O    O   O O O O"



                            };
    char huongdan[12][80]= {          "A : left",
    								  "D :right",
    								  "W :up",
    								  "S :down",
    								  "X :let'go",
    								  "O :prey",
    								  "+ :boom"

                            };
    TextColor(11);
    for ( i=0;i<7;i++)
    {   gotoXY(5,10+i);
        cout<<snake[i];
        Sleep(200);
    }

    TextColor(12);
    for ( i=0;i<11;i++)
    {   gotoXY(5,20+i);
        cout<<huongdan[i];
        Sleep(200);
    }

    while(1)
    {
        if(kbhit())
        {
                  char key=_getch();
                if(key=='X'||key=='x')    break;
        }

    }
    system("cls");//xA³a mA n hA¬nh chá»? thá»© nháº¥t
}
void ketthuc()
{

	char game[11][80]={
			"    O O O          O        OO      OO   O O O O    ",
			"   O      O       O O       O O    O O   O          ",
			"  O              O   O      O  O  O  O   O          ",
			"  O    O        O O O O     O    O   O   O O O O    ",
			"  O    OO O    O       O    O        O   O          ",
			"   O      O   O         O	 O        O   O          ",
			"    O O O    O           O  O        O   O O O O    ",
		    "                                                    ",
			"                                                    ",
			"                                                    "
			};

	char over[13][80]={

			"     O O O     O            O   O O O O    O O O 	 ",
			"   O       O    O          O    O          O    O   ",
			"  O         O    O        O     O          O   O    ",
			"  O         O     O      O      O O O O    O OO     ",
			"  O         O      O    O       O          O   O    ",
			"   O       O        O  O        O          O    O   ",
			"     O O O           O          O O O O    O      O " };
	TextColor(9);
	for(int i=0;i<10;i++)
	{
		gotoXY(5,5+i);
		cout << game[i];
		Sleep(200);
	}
	TextColor(9);
	for(int i=0;i<7;i++)
	{
		gotoXY(5,15+i);
		cout << over[i];
		Sleep(200);
	}

}


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
//in ra con ran
void hienthiran (ran snack)
{
	clrscr();
	int i ;
	TextColor(7);
	for(i=0;i<doc;i++)
	{
		gotoXY(ngang,i);
		cout <<char(220);
	}
	TextColor(10);
	for(i=1;i<snack.n;i++)
	{

	gotoXY(snack.dot[i].x,snack.dot[i].y);
	cout <<char(148);
	}
	gotoXY(snack.dot[0].x,snack.dot[0].y);
	cout <<char(2);


}
// khoi tao hoa qua
void nhaphoaqua(hoaqua &hq)
{
	srand(time(NULL));
	hq.td.x=rand()%ngang;
	hq.td.y=rand()%doc;
}
// in ra hoa qua
void hienthihoaqua(hoaqua hq)
{
    TextColor(9);
	gotoXY(hq.td.x,hq.td.y);
	cout <<"O";
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
//in ra boom
void hienthiboom(boom bom)
{
    TextColor(4);
	gotoXY(bom.vitri[0].x,bom.vitri[0].y);
	cout <<"+";
	gotoXY(bom.vitri[1].x,bom.vitri[1].y);
	cout << "+";
}
// dieu kien game
void dieukien (ran &snack)
{
	int i;
	for(i=snack.n-1;i>0;i--)
	{
		snack.dot[i]=snack.dot[i-1];
	}

	if(kbhit())
		{
			char key=getch();
			if(key=='A'||key=='a')
			snack.tt=LEFT;
			else if(key=='D'||key=='d')
			snack.tt=RIGHT;
			else if(key=='W'||key=='w')
			snack.tt=UP;
			else if(key=='S'||key=='s')
			snack.tt=DOWN;
		}
	if(snack.tt==LEFT)
	snack.dot[0].x--;
	else if(snack.tt==RIGHT)
	snack.dot[0].x++;
	else if(snack.tt==UP)
	snack.dot[0].y--;
	else if(snack.tt==DOWN)
	snack.dot[0].y++;
}
// xu ly ran an hoa qua va tang do kho cho game
int xuly1 (ran &snack,hoaqua &hq,int &dokho,boom &bom)
{
	int i;
	snack.diem.a=0;
	bom.m=1;
	if(snack.dot[0].x==hq.td.x&&snack.dot[0].y==hq.td.y)
	{
		for(i=snack.n-1;i>0;i--)
		snack.dot[i]=snack.dot[i-1];
		snack.n++;
	if(snack.tt==LEFT)
	snack.dot[0].x--;
	else if(snack.tt==RIGHT)
	snack.dot[0].x++;
	else if(snack.tt==UP)
	snack.dot[0].y--;
	else if(snack.tt==DOWN)
	snack.dot[0].y++;
	srand(time(NULL));
	hq.td.x=rand()%ngang;
	hq.td.y=rand()%doc;
	if(dokho>50)
	{
	dokho-=20;
	}
	bom.m++;
	bom.vitri[0].x=rand()%ngang;
	bom.vitri[0].y=rand()%doc;
	bom.vitri[1].x=rand()%ngang;
	bom.vitri[1].y=rand()%doc;
	}
	snack.diem.a=snack.n-2;
}
// xu ly diem so
void hienthidiem(ran &snack)
{
    TextColor(15);
    gotoXY(ngang+1,5);
    cout << "SCORE"<<" "<<snack.diem.a ;

}
// xu ly ran an boom
void xuly2(ran &snack ,boom &bom)
{
	int i;
	if(snack.dot[0].x==bom.vitri[0].x&&snack.dot[0].y==bom.vitri[0].y||snack.dot[0].x==bom.vitri[1].x&&snack.dot[0].y==bom.vitri[1].y)
	{
		for (int i=0;i<snack.n-1;i++)
            snack.dot[i]=snack.dot[i+1];
        snack.n--;
        snack.dot[snack.n]={0,0};

	srand(time(NULL));
	bom.vitri[0].x=rand()%ngang;
	bom.vitri[0].y=rand()%doc;

	bom.vitri[1].x=rand()%ngang;
	bom.vitri[1].y=rand()%doc;
	}
}
// xy ly thua game
int gameover (ran snack)
{
	int i;
	for(i=1;i<snack.n;i++)
	{
	if(snack.dot[0].x<0||snack.dot[0].y<0||snack.dot[0].x>=ngang||snack.dot[0].y>=doc||snack.dot[0].x==snack.dot[i].x&&snack.dot[0].y==snack.dot[i].y)
	return -1;
	}
}

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
