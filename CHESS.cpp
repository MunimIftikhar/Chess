#include <iostream>

#include <stdio.h>

#include "windows.h"

#include <math.h>

using namespace std;





//*********************************************************************

//                PROGRAM FOR CHESS BY MUNIM IFTIKHAR

//*********************************************************************



//|||||||||||||||WHEN COMPLIE THE PROGRAM PLEASE MAKE COMPLIER BIG SCREEN||||||||||||||||



//**************************************************************

//                FUNCTION FOR ANIMATION

//**************************************************************





void animation()

{

  cout << "*";

  Sleep(0);

}



void gotoxy(int x, int y)

{

  printf("\033[%d;%dH", x, y);

}



void gotoRowCol(int rpos, int cpos)

{

  int xpos=cpos, ypos = rpos;

  COORD scrn;



  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);



  scrn.X = xpos; scrn.Y = ypos;

  SetConsoleCursorPosition(hOuput,scrn);

}



//*******************************************************

//               FUNCTION FOR LINES

//*******************************************************



void printLine(int L,int x,int y,bool type)

{

	if(type==true)

	{

		for (int b = 0; b<L; b++)

		{

			gotoRowCol(x,y+b);	

			animation();

		}

	}

	else

	{

		for (int b = 0; b<L; b++)

		{

			gotoRowCol(x+b,y);	

			animation();

		}

	}

}



//*********************************************************

//            FUNCTION FOR FILLED SQUARE

//**********************************************************



int printFullSquare(int L,int x,int y)

{

	bool type;

	gotoRowCol(x,y);

	int count=0;

	while(count<7)

	{

		printLine(L+1,x,y,true);

		x++;

		count++;

	}

}



//*********************************************************

//            FUNCTION FOR HOLLOW SQUARE

//**********************************************************



void printHollowSquare(int L,int x,int y)

{

	bool type;

	gotoRowCol(x,y);

	printLine(L+1,x,y,true);

	int a=L-3;

	printLine(a,x,y,false);

	int b=0;

	b=x+a;

	printLine(L+1,b,y,true);

	int c=0;

	c=y+L;

	printLine(a,x,c,false);

	

}



//*********************************************************

//          FUNCTION TO PRINT ONE OF THE SQUARE

//**********************************************************



void printSquare(int L,int x,int y,bool wype)

{

	if(wype==true)

	{

		printFullSquare(L,x,y);	

	}

	else

	{

		printHollowSquare(L,x,y);

	}

}

//**************************************************************************

//FUNCTION TO PRINT ONE ROW OF THE CHESS BOARD THAT START WITH FILLED SQUARE

//**************************************************************************



void print1Row(int L,int x,int y)

{

	bool wype;

	int counter=0,k=0;

	printSquare(L,x,y,true);

	y=y+L;

	printSquare(L,x,y,false);

	while(counter<3)

	{

		y=y+L;

		printSquare(L,x,y,true);

		y=y+L;

		printSquare(L,x,y,false);

		counter++;

	}

	

	

}

//***************************************************************************

//FUNCTION TO PRINT ONE ROW OF THE CHESS BOARD THAT START WITH HOLLOW SQUARE

//***************************************************************************



void print2Row(int L,int x,int y)

{

		bool wype;

	int count=0;

	printSquare(L,x,y,false);

	y=y+L;

	printSquare(L,x,y,true);

	while(count<3)

	{

		y=y+L;

		printSquare(L,x,y,false);

		y=y+L;

		printSquare(L,x,y,true);

		count++;

	}

}



//**************************************************************************

//FUNCTION TO PRINT CHESS BOARD WITH THE HELP OF FUNCTIONS OF TWO ROWS

//**************************************************************************



void drawChessBoard()

{

	system("cls");

	gotoRowCol(2,32);

	cout<<"***CHESS BOARD***";

	int x=5,y=4,L=9,i=0,ctr=0,a=1,x1=4,y1=10,x2=8,y2=3,b=1;

	gotoRowCol(4,0);

	cout<<"COLOM NO:";

	gotoRowCol(8,1);

	cout<<"R";

	gotoRowCol(9,1);

	cout<<"O";

	gotoRowCol(10,1);

	cout<<"W";

	gotoRowCol(12,1);

	cout<<"N";

	gotoRowCol(13,1);

	cout<<"O";

	

	while(a<=8)

	{

		gotoRowCol(x1,y1);

		cout<<a;

		y1=y1+9;

		a++;	

	}

	while(b<=8)

	{

		gotoRowCol(x2,y2);

		cout<<b;

		x2=x2+6;

		b++;

	}

	i=L-3;

	print1Row(L,x,y);

	x=x+i;

	print2Row(L,x,y);

	while(ctr<3)

	{

		x=x+i;

		print1Row(L,x,y);

		x=x+i;

		print2Row(L,x,y);

		ctr++;

	}

}

//*******************************************************************************************

//FUNCTION TO PRINT MENU TO START GAME BEAUTIFULLY IN WHICH FUNTION OF DRAW CHESS BOARD USED

//********************************************************************************************



int printMenu()

{

	gotoRowCol(1,20);

	cout<<"*****************************************";

	gotoRowCol(2,20);

	cout<<"                LET START";

	gotoRowCol(4,20);

	cout<<"                  CHESS";

	gotoRowCol(6,20);

	cout<<"                   BY";

	gotoRowCol(8,20);

	cout<<"              MUNIM IFTIKHAR";

	gotoRowCol(10,20);

	cout<<"*****************************************";

	gotoRowCol(13,20);

	cout<<"*****CHRACTERS USE IN CHESS BOARD*****";

	gotoRowCol(15,3);

	cout<<"C-Castle";

	gotoRowCol(17,3);

	cout<<"N-Knight";

	gotoRowCol(19,3);

	cout<<"B-Bishop";

	gotoRowCol(21,3);

	cout<<"K-King";

	gotoRowCol(15,17);

	cout<<"Q-Queen";

	gotoRowCol(17,17);

	cout<<"P-Pawn";

	gotoRowCol(19,17);

	cout<<"Info-Capital letters for Player 1";

	gotoRowCol(21,17);

	cout<<"Info-Small letters for Player 2";

	

	Sleep(8000);

	drawChessBoard();

}

//**************************************************************************

//        FUNCTION TO CONVERT ROW AND COLOM NO INT0 BOX NO

//**************************************************************************+



int twoDto1D(int ri,int ci)

{

	int d=0,i=0;

	d=(8*ri);

	i=d+ci;

	return i;

	

}

//**************************************************************************

//        FUNCTION TO SET POSITIONS OF BOXES

//**************************************************************************

void setPosOfBox(int m)

{

	int x=0,y=0;

		if(m==1)

		{

		//	x=8,y=8;

			gotoRowCol(8,8);

		}

		if(m==2)

		{

		//	x=8,y=17;

			gotoRowCol(8,17);

		}

		if(m==3)

		{

		//																																																																																																									x=8,y=26;

			gotoRowCol(8,26);

		}

		if(m==4)

		{

		//	x=8,y=35;

			gotoRowCol(8,35);

		}

		if(m==5)

		{

		//	x=8,44;

			gotoRowCol(8,44);

		}

		if(m==6)

		{

		//	x=8,y=53;

			gotoRowCol(8,53);

		}

		if(m==7)

		{

		//	x=8,y=62;

			gotoRowCol(8,62);

		}

		if(m==8)

		{

		//	x=8,y=71;

			gotoRowCol(8,71);

		}

		if(m==9)

		{

		//	x=14,y=8;

			gotoRowCol(14,8);

		}

		if(m==10)

		{

		//	x=14,y=17;

			gotoRowCol(14,17);

		}

		if(m==11)

		{

		//	x=14,y=26;

			gotoRowCol(14,26);

		}

		if(m==12)

		{

		//	x=14,y=35;

			gotoRowCol(14,35);

		}

		if(m==13)

		{

		//	x=14,y=44;

			gotoRowCol(14,44);

		}

		if(m==14)

		{

		//	x=14,y=53;

			gotoRowCol(14,53);

		}

		if(m==15)

		{

		//	x=14,y=62;

			gotoRowCol(14,62);

		}

		if(m==16)

		{

		//	x=14,y=71;

			gotoRowCol(14,71);

		}

		if(m==17)

		{

		//	x=20,y=8;

			gotoRowCol(20,8);

		}

		if(m==18)

		{

		//	x=20,y=17;

			gotoRowCol(20,17);

		}

		if(m==19)

		{

		//	x=20,y=26;

			gotoRowCol(20,26);

		}

		if(m==20)

		{

		//	x=20,y=35;

			gotoRowCol(20,35);

		}

		if(m==21)

		{

		//	x=20,y=44;

			gotoRowCol(20,44);

		}

		if(m==22)

		{

		//	x=20,y=53;

			gotoRowCol(20,53);

		}

		if(m==23)

		{

		//	x=20,y=62;

			gotoRowCol(20,62);

		}

		if(m==24)

		{

		//	x=20,y=71;

			gotoRowCol(20,71);

		}

		if(m==25)

		{

		//	x=26,y=8;

			gotoRowCol(26,8);

		}

		if(m==26)

		{

		//	x=26,y=17;

			gotoRowCol(26,17);

		}

		if(m==27)

		{

		//	x=26,y=26;

			gotoRowCol(26,26);

		}

		if(m==28)

		{

		//	x=26,y=35;

			gotoRowCol(26,35);

		}

		if(m==29)

		{

		//	x=26,y=44;

			gotoRowCol(26,44);

		}

		if(m==30)

		{

		//	x=26,y=53;

			gotoRowCol(26,53);

		}

		if(m==31)

		{

		//	x=26,y=62;

			gotoRowCol(26,62);

		}

		if(m==32)

		{

		//	x=26,y=71;

			gotoRowCol(26,71);

		}

		if(m==33)

		{

		//	x=32,y=8;

			gotoRowCol(32,8);

		}

		if(m==34)

		{

		//	x=32,y=17;

			gotoRowCol(32,17);

		}

		if(m==35)

		{

		//	x=32,y=26;

			gotoRowCol(32,26);

		}

		if(m==36)

		{

		//	x=32,y=35;

			gotoRowCol(32,35);

		}

		if(m==37)

		{

		//	x=32,y=44;

			gotoRowCol(32,44);

		}

		if(m==38)

		{

		//	x=32,y=53;

			gotoRowCol(32,53);

		}

		if(m==39)

		{

		//	x=32,y=62;

			gotoRowCol(32,62);

		}

		if(m==40)

		{

		//	x=32,y=71;

			gotoRowCol(32,71);

		}

		if(m==41)

		{

		//	x=38,y=8;

			gotoRowCol(38,8);

		}

		if(m==42)

		{

		//	x=38,y=17;

			gotoRowCol(38,17);

		}

		if(m==43)

		{

		//	x=38,y=26;

			gotoRowCol(38,26);

		}

		if(m==44)

		{

		//	x=38,y=35;

			gotoRowCol(38,35);

		}

		if(m==45)

 		{

		//	x=38,y=44;

			gotoRowCol(38,44);

		}

		if(m==46)

		{

		//	x=38,y=53;

			gotoRowCol(38,53);

		}

		if(m==47)

		{

		//	x=38,y=62;

			gotoRowCol(38,62);

		}

		if(m==48)

		{

		//	x=38,y=71;

			gotoRowCol(38,71);

		}

		if(m==49)

		{

		//	x=44,y=8;

			gotoRowCol(44,8);

		}

		if(m==50)

		{

		//	x=44,y=17;	

			gotoRowCol(44,17);

		}

		if(m==51)

		{

		//	x=44,y=26;

			gotoRowCol(44,26);

		}

		if(m==52)

		{

		//	x=44,y=35;

			gotoRowCol(44,35);

		}

		if(m==53)

		{

		//	x=44,y=44;

			gotoRowCol(44,44);

		}

		if(m==54)

		{

		//	x=44,y=53;

			gotoRowCol(44,53);

		}

		if(m==55)

		{

		//	x=44,y=62;

			gotoRowCol(44,62);

		}

		if(m==56)

		{

		//	x=44,y=71;

			gotoRowCol(44,71);

		}

		if(m==57)

		{

		//	x=50,y=8;

			gotoRowCol(50,8);

		}

		if(m==58)

		{

		//	x=50,y=17;

			gotoRowCol(50,17);

		}

		if(m==59)

		{

		//	x=50,y=26;

			gotoRowCol(50,26);

		}

		if(m==60)

		{

		//	x=50,y=35;

			gotoRowCol(50,35);

		}

		if(m==61)

		{

		//	x=50,y=44;

			gotoRowCol(50,44);

		}

		if(m==62)

		{

		//	x=50,y=53;

			gotoRowCol(50,53);

		}

		if(m==63)

		{

		//	x=50,y=62;

			gotoRowCol(50,62);

		}

		if(m==64)

		{

		//	x=50,y=71;

			gotoRowCol(50,71);

		}

		

}



//**************************************************************************

//                FUNCTION TO INITIALISE ARRAY

//**************************************************************************

void initB(char B[])

{

	int ri=0,ci=0,m=0;

	for(ri=2;ri<6;ri++)

	{

		for(ci=1;ci<=8;ci++)

		{

			m=twoDto1D(ri,ci);

			B[m]='_';

		}

	}

	for(ci=1;ci<=8;ci++)

	{

		ri=1;

		m=twoDto1D(ri,ci);

		B[m]='P';

	}

	for(ci=1;ci<=8;ci++)

	{

		ri=6;

		m=twoDto1D(ri,ci);

		B[m]='p';

	}

	

	m=twoDto1D(0,1);

	B[m]='C';

	m=twoDto1D(7,1);

	B[m]='c';

	m=twoDto1D(0,2);

	B[m]='B';

	m=twoDto1D(7,2);

	B[m]='b';

	m=twoDto1D(0,3);

	B[m]='N';

	m=twoDto1D(7,3);

	B[m]='n';

		m=twoDto1D(0,4);

		B[m]='K';

		m=twoDto1D(7,4);

		B[m]='k';

		m=twoDto1D(0,5);

		B[m]='Q';

		m=twoDto1D(7,5);

		B[m]='q';

		m=twoDto1D(0,6);

		B[m]='B';

		m=twoDto1D(7,6);	

		B[m]='b';

		m=twoDto1D(0,7);

		B[m]='N';

		m=twoDto1D(7,7);

		B[m]='n';

		m=twoDto1D(0,8);

		B[m]='C';

		m=twoDto1D(7,8);

		B[m]='c';

}

//**************************************************************************

//                  FUNCTION TO DISPLAY ARRAY ON SCREEN

//**************************************************************************

void printBoard(char B[])

{



	for(int ri=0;ri<=9;ri++)

	{

		for(int ci=1;ci<=8;ci++)

		{

			

			int m=twoDto1D(ri,ci);

			setPosOfBox(m);	

			cout<<B[m];	

		}

	}

}

//**************************************************************************

//        FUNCTION TO CHECK LEGAL MOVES OF PAWN

//**************************************************************************

bool isPawnMoveLegal(int ri,int ci,int mr, int mc, int m,char B[])

{

	bool a=false;

	if(B[m]=='P')

	{

		a=(mr==ri+1 && ci==mc);

		a=true;

	}

	if(B[m]=='p')

	{

		a=(mr==ri-1 && ci==mc);

		a=true;

	}

	return a;

}

//**************************************************************************

//        FUNCTION TO CHECK LEGAL MOVES OF CATSLE

//**************************************************************************

bool isCastleMoveLegal(int ri, int ci, int mc, int mr,int m,char B[])

{

	bool a=false;

	if(B[m]=='C'||B[m]=='c')

	{

		a=(mr==ri || mc==ci);

		return a;

	}

	

}

//**************************************************************************

//        PROGRAM TO CHECK LEGAL MOVES OF BISHOP

//**************************************************************************

bool isBishopMoveLegal(int ri,int ci,int mr,int mc,int m,char B[],int u)

{

	bool a=false;

	if(B[m]=='b'||B[m]=='B')

	{

		

		

			a=((ri-mr==ci-mc)||(-(ri-mr)==(ci-mc))||((ci-mc)==-(ri-mr))||(-(ci-mc)==-(ri-mr)));

			return a;

	}

}

//**************************************************************************

//        PROGRAM TO CHECK LEGAL MOVES OF KNIGHT

//**************************************************************************

bool isNightMoveLeagal(int ri, int ci, int mr, int mc,int m,char B[])

{

	bool a=false;

	if(B[m]=='N'||B[m]=='n')

	{

		a=((mr==ri-2 && mc==ci-1)||(mr==ri-2 && mc==ci+1)||(mr==ri+1 && mc==ci+2)||(mr==ri-1 && mc==ci-2)||(mr==ri+1 && mc==ci-2)||(mr==ri+1 && mc==ci-2)||(mr==ri+2 && mc==ci-1)||(mr==ri+2 && mc==ci+1)||(mr==ri+1 && mc==ci+2)||(mr==ri+2 && mc==ci+1)||(mr==ri+1&&mc==ci+2));

		return a;

	}

}

//**************************************************************************

//        PROGRAM TO CHECK LEGAL MOVES OF KING

//**************************************************************************

bool isKingMoveLegal(int ri,int ci,int mr,int mc,int m,char B[])

{

	bool a=false;

	if(B[m]=='K'||B[m]=='k')

	{

		a=((mc==ci+1&&mr==ri)||(mc==ci-1&&mr==ri)||(mr==ri+1&&mc==ci)||(mr==ri-1&&mc==ci)||(mr==ri-1&&mc==ci+1)||(mr==ri+1&&mc==ci+1)||(mr==ri-1&&mc==ci+1)||(mr==ri+1&&mc==ci-1));

		return a;	

	}

	return a;

}

//**************************************************************************

//        PROGRAM TO CHECK LEGAL MOVES OF QUEEN

//**************************************************************************

bool isQueenMoveLegal(int ri,int ci,int mr,int mc,int m,char B[])

{

	bool a=false;

	if(B[m]=='q'||B[m]=='Q')

	{

		a=((mc==ci-2 && mr==ri-1)||(mc==ci-2 && mr==ri+1)||(mc==ci+1 && mr==ri+2)||(mc==ci-1 && mr==ri-2)||(mc==ci+1 && mr==ri-2)||(mc==ci+1 && mr==ri-2)||(mc==ci+2 && mr==ri-1)||(mc==ci+2 && mr==ri+1)||(mc==ci+1 && mr==ri+2)||(mc==ci+2 && mr==ri+1)||(mr==ri || mc==ci)||(mr==ri-1 && ci==mc)||(mr==ri+1 && ci==mc));

		return a;

	}

	

}

//**************************************************************************

//        PROGRAM TO CHECK LEGAL MOVES OF CHARECTERS

//**************************************************************************

bool checkCharacter(int m,int u,char B[])

{

	bool a=false;

	if(B[u]==B[m])

	{

		return a;

	}

}

//**************************************************************************

//        PROGRAM TO ASK USER FOR STARTING ROW COLOM

//                  FOR ENDING ROW COLOM

//                 AND TO MOVE CHARACTERS

//                 ACCORDING TO LEGALITY

//                     OF CHARACTERS

//**************************************************************************

int AskAndGetCord(char B[],int turn)

{

	int ri=0,ci=0,mr,mc,m,u;

	bool a=false,b=false,c=false,d=false,e=false,f=false,g=false;

	gotoRowCol(56,10);

	cout<<"Please enter COLON NO to select starting point: ";

	cin>>ci;

	cout<<"Please enter ROW NO to select starting point: ";

	cin>>ri;

	gotoRowCol(58,10);

	cout<<" Please enter COLON NO to select ending point:";

	cin>>mc;

	cout<<"Please enter ROW NO to select ending point: ";

	cin>>mr;

	m=twoDto1D(ri-1,ci);

	u=twoDto1D(mr-1,mc);

	a=isPawnMoveLegal(ri-1,ci,mr-1,mc,m,B);

	b=isCastleMoveLegal(ri-1,ci,mc,mr-1,m,B);

	c=isBishopMoveLegal(ri-1,ci,mr-1,mc,m,B,u);

	d=isNightMoveLeagal(ri-1,ci,mr-1,mc,m,B);

	e=isKingMoveLegal(ri-1,ci,mr-1,mc,m,B);

	f=isQueenMoveLegal(ri-1,ci,mr-1,mc,m,B);

	g=checkCharacter(m,u,B);

	if((f==true||g==true||c==true||b==true||e==true)&&a==true||d==true)

	{

		if(B[m]>='A' && B[m]<='Z')

		{

			if(B[u]>='A' && B[u]<='Z')

			{

			//illegal move specific pos n turn of that player again

				int d=0;

				gotoRowCol(61,15);

				cout<<"****iLLEGAL MOVE****";

				Sleep(1200);

				d=turn;

				if(d==1)

				{

					

					d=2;

				}

				else

				{

					d=1;

				}

				return d;

						

			}

			else 

			{

				setPosOfBox(m);

				cout<<"_";

				setPosOfBox(u);

				B[u]=B[m];

				cout<<B[u];

				B[m]='_';

			}

		}

		if(B[m]>='a' && B[m]<='z')

		{

			if(B[u]>='a' && B[u]<='z')

			{

				//illegal move specific pos n turn of that player again

					int d=0;

				gotoRowCol(61,15);

				cout<<"****iLLEGAL MOVE****";

				Sleep(1200);

				d=turn;

				if(d==1)

				{

					

					d=2;

				}

				else

				{

					d=1;

				}

				return d;

			}

			else

			{

				setPosOfBox(m);

				cout<<"_";

				setPosOfBox(u);

				B[u]=B[m];

				cout<<B[u];

				B[m]='_';

			}

		}

	

	

		int d=turn;

		if(d==2)

		{

			d=2;

		}

		else

		{

			d=1;

		}

		return d;

	}

	else

	{

		int d=0;

		gotoRowCol(61,15);

		cout<<"****iLLEGAL MOVE****";

		Sleep(1200);

		d=turn;

		if(d==1)

		{

			

			d=2;

		}

		else

		{

			d=1;

		}

		return d;

		

	}

}

//**************************************************************************

//        FUNCTION TO CHECK WIN LOSE OF GAME

//              AND TO FINISH THE GAME

//**************************************************************************

int checkWinLose(int count,char B[])

{

	int i=0;

	for(i=0;i<64;i++)

	{

		if(B[i]=='k')

		{

			return count++;

		}

	}

	for(i=0;i<64;i++)

	{

		if(B[i]=='K')

		{

			return count++;

		}

	}

	if(count==1)

	{

		if(B[i]=='k')

		{

			cout<<"PLYER 2 WON";

		}

		else

		{

			cout<<"PLYER 1 WON";

		}

	}

	

}

//**************************************************************************

//                          MAIN  PROGRAM 

//**************************************************************************

int main()

{

	printMenu();

	char B[65];

	initB(B);

	printBoard(B);

	int turn=1,a=0;

	while(true)

	{

		int count=0;

		gotoRowCol(54,20);

		cout<<"****PLAYER "<<turn<<" TURN****";

		a=AskAndGetCord(B,turn);

		gotoRowCol(61,15);

		cout<<"                       ";

		turn=a;

		if(turn==1)

		{

			turn=2;

		}

		else

		{

			turn=1;

		}

		checkWinLose(count,B);

	}

	return 0;

}



