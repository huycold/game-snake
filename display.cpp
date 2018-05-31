#include "display.h"

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
    char huongdan[12][80]= {          "A :left",
    								  "D :right",
    								  "W :up",
    								  "S :down",
    								  "X :let's go",
    								  "O :prey",
    								  "+ :boom"


                            };
    TextColor(11);
    for ( i=0;i<7;i++)
    {   gotoXY(5,5+i);
        cout<<snake[i];
        Sleep(200);
    }

    TextColor(12);
    for ( i=0;i<11;i++)
    {   gotoXY(5,15+i);
        cout<<huongdan[i];
        Sleep(200);
    }

    while(1)
    {
        if(kbhit())
        {
                  char key=_getch();
                if(key=='x'||key=='	X')    break;
        }

    }
    system("cls");//xA³a mA n hA¬nh chá»? thá»© nháº¥t
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
// in ra hoa qua
void hienthihoaqua(hoaqua hq)
{
    TextColor(9);
	gotoXY(hq.td.x,hq.td.y);
	cout <<"O";
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
// xu ly diem so
void hienthidiem(ran &snack)
{
    TextColor(15);
    gotoXY(ngang+1,5);
    cout << "SCORE"<<" "<<snack.diem.a ;
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
