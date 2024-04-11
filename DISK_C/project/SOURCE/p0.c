
#include <common.h>

/******************************************************************
	��p0��ť���������� 
��д�ˣ�����
���룺int x1,int y1,char*s 
������void 
�������ܣ�ʵ�ָ�ҳ�水ť���� 
*******************************************************************/
void page0light(int x1,int y1,char*s)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, YELLOW);
	bar(x1, y1, x1 + 240, y1 + 120);
	puthz(x1+55, y1 + 40, s, 32, 32, WHITE);
}

/******************************************************************
	��p0��ť�����ָ������� 
��д�ˣ�����
���룺int x1,int y1,char*s 
������void 
�������ܣ�ʵ�ָ�ҳ�水ť�����ָ� 
*******************************************************************/
void page0recover(int x1,int y1,char*s)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, WHITE);
	bar(x1, y1, x1 + 240, y1 + 120);
	puthz(x1+55, y1 + 40, s, 32, 32, DARKGRAY);
}

/******************************************************************
	��p0ҳ����ƺ����� 
��д�ˣ�����
���룺void 
������void 
�������ܣ�����p0ҳ�� 
*******************************************************************/

void page0_screen(void)
{
	cleardevice();
	setbkcolor(LIGHTCYAN);

	setfillstyle(1,RED);
	bar(80, 100, 80 + 160, 100 + 40);
    bar(140, 40, 140 + 40,40+ 160);
	bar(600, 0, 600+40 , 0 + 40);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(605,5,635,35);
	line(605,35,635,5);
	setcolor(LIGHTBLUE);
	puthz(40, 240, "���пƼ���ѧ", 48, 48, BLUE);
	puthz(40, 300, "УҽԺ", 48, 48, BLUE);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(40,350,320,350) ;
	line(40,230,320,230) ;
	line(0,0,600,0) ;
	line(0,10,600,10) ;
	line(0,0,0,480) ;
	line(10,0,10,480) ;
	line(0,470,640,470) ;
	line(0,480,640,480) ;
	line(630,40,630,480) ;
	line(640,40,640,480) ;
	puthz(40, 370, "����ҩ�����ϵͳ", 24, 24, BLUE);
	setfillstyle(7,DARKGRAY);
	bar(360, 85, 600,205 );
	bar(360, 315, 600, 435);
	rectangle(360, 85, 600,205 );
	rectangle(360, 315, 600, 435);
	setfillstyle(1,WHITE);
	bar(340, 65, 580,185 );
	bar(340, 295, 580, 415);
	rectangle(340, 65, 580,185 );
	rectangle(340, 295, 580, 415);
	puthz(340+55, 65+40, "���ǻ���", 32, 32, DARKGRAY);
	puthz(340+55, 295+40, "����ҽ��", 32, 32, DARKGRAY);

}
/******************************************************************
	��p0���溯���� 
��д�ˣ�����
���룺void 
������int page 
�������ܣ�ʵ��p0ҳ����� 
*******************************************************************/
int p0(void)
{
	int page = 0;
	int mouse = 0;
	int flag = 0;

	clrmous(MouseX,MouseY);
	page0_screen(); 
	while(page == 0)
	{
		delay(3);
		newmouse(&MouseX,&MouseY,&press);

		while(1)
		{
			if (MouseX > 600 && MouseY > 0 && MouseX < 640 && MouseY < 40)
			{
				MouseS = 1;
				break;
			}

			else if(MouseX > 340 && MouseY > 65 && MouseX < 580 && MouseY < 185)
			{
				MouseS = 1;
				break;
			}

            else if(MouseX > 340 && MouseY > 295 && MouseX < 580 && MouseY < 415)
			{
				MouseS = 1;
				break;
			}

			else
			{
				MouseS = 0;
				break;
			}
		}

		if(mouse_press(600, 0, 600+40 , 0 + 40) == 1)
		{
		  page = 20;
		}
		else if(mouse_press(340, 295, 580, 415) == 1)
		{
		 	page = 13;
		}
		else if (mouse_press(340, 65, 580,185 ) == 1)
		{
			delay(200);
			page = 1;
		}

		 if (mouse_press(340, 65, 580,185 ) == 2)
		{
			if (flag == 0)
			{
				page0light(340, 65, "���ǻ���");
				flag = 1;
			}
			continue;
		}

		else if (mouse_press(340, 295, 580, 415) == 2)
		{
			if (flag == 0)
			{
				page0light(340, 295, "����ҽ��");
				flag = 2;
			}
			continue;
		}
		if (mouse == 0)
		{
			if (flag == 1)
			{
				page0recover(340,65, "���ǻ���");
				flag = 0;
			}

			if (flag == 2)
			{
				page0recover(340, 295, "����ҽ��");
				flag = 0;
			}

		}
	}
	return page;
}   
