#include <common.h>

/******************************************************************
	�����غ��������� 
��д�ˣ����� 
���룺void 
������int page���ν���һ��ҳ�棩 
�������ܣ��������� 
*******************************************************************/
int load(void)
{
	int page=3;
	int i=0;
	cleardevice();
	setbkcolor(LIGHTCYAN);
	setfillstyle(11,BLUE);
	bar(0,0,640,480);
	setfillstyle(11,DARKGRAY);
	bar(0, 0, 600,40 );
    frameline();
    puthz(135, 200, "�����У����Ե�", 48, 48, DARKGRAY);
    setlinestyle(0,0,8);
    setcolor(DARKGRAY);
    setfillstyle(8,LIGHTGRAY);
    rectangle(50,250,590,280);
    for(i=0;i<54;i++)
    {
	delay(50);
	bar(50+10*i,250,60+10*i,280);
    } 
    return page;
}
