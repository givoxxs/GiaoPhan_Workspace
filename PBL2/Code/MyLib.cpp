
#include<bits/stdc++.h>
#include <windows.h>
#include "MyLib.h"

using namespace std;
// BOX
void box(int x,int y,int w,int h,int t_color,int b_color,string nd)
{
    SetColor(b_color);
    for (int i=x;i<=x+w;i++)
    {
        for(int j=y;j<=y+h;j++)
        {
            gotoXY(i,j);cout << " ";
        }
    }
    SetColor(t_color);
    gotoXY(x+1,y+1);
    cout << nd;
    SetColor(b_color%t_color);
    if (h<=1 || w<=1) return;
    for(int i=x;i<=x+w;i++)
    {
        gotoXY(i,y);
        cout << char(196);
        gotoXY(i,y+h);
        cout << char(196);
    }
    for (int i=y;i<=y+h;i++)
    {
        gotoXY(x,i);
        cout << char(179);
        gotoXY(x+w,i);
        cout << char(179);
    }
    gotoXY(x,y);cout << char(218);
    gotoXY(x+w,y);cout << char(191);
    gotoXY(x,y+h);cout << char(192);
    gotoXY(x+w,y+h);cout << char(217);
}
// MUL BOX
void MulBox(int x,int y,int w,int h,int t_color,int b_color,string nd[],int n)
{
    for (int i=0;i<n;i++)
    {
        box(x,y+h*i,w,h,t_color,b_color,nd[i]);
        if(i!=0)
        {
            gotoXY(x,y+h*i); cout << char(195);
            gotoXY(x+w,y+h*i); cout << char(180);
        }
    }
}
// Thanh sáng
void thanh_sang(int x,int y,int w,int h,int b_color,string nd)
{
    SetColor(b_color);
    for (int i=x+1;i<x+w;i++)
    {
        for(int j=y+1;j<y+h;j++)
        {
            gotoXY(i,j);cout << " ";
        }
    }
    SetColor(b_color);
    gotoXY(x+1,y+1);
    cout << nd;
}
// MENU chinh
int Menu(int x,int y,int w,int h,int t_color,int b_color,string nd[],int n)
{
    ShowCur(0);
    MulBox(x,y,w,h,t_color,b_color,nd,n);

    int posbefore=0,pos=0;
    int xpoint=x,ypoint=y;
    int xbefore=x,ybefore=y;
    bool check=false;

    thanh_sang(xpoint,ypoint,w,h,4,nd[pos]);
    while (true)
    {
        if (check==true)
        {
            gotoXY(xbefore,ybefore);
            thanh_sang(xbefore,ybefore,w,h,b_color,nd[posbefore]);
            thanh_sang(xpoint,ypoint,w,h,4,nd[pos]);
            check=false;
        }
        if (_kbhit())
        {
            char c=_getch();
            if (c==13) break;
            if (c==-32)
            {
                check=true;
                c=_getch();
                ybefore=ypoint;
                posbefore=pos;
                if (c==72)
                {
                    if (ypoint!=y) {
                        ypoint-=h;
                        pos--;
                    }
                    else {
                        pos=n-1;
                        ypoint = y+h*(n-1);
                    }
                }
                if(c==80)
                {
                    if (ypoint != y+h*(n-1)) {
                        ypoint+=h;
                        pos++;
                    }
                    else {
                        pos=0;
                        ypoint=y;
                    }
                }
            }
        }
    }
    SetColor(7);
    ShowCur(1);
    return pos;
}
// Toa do X
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
// Toa do Y
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= đặt màu cho chữ =========
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

//============= đặt màu cho nền =========
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= trả về mã phím người dùng bấm =========
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}

	return KEY_NONE;
}
