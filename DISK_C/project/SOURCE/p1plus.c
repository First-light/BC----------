#include <common.h>

/******************************************************************
		������ѡ������ͼ������
��д�ˣ�����
���룺void
������void
�������ܣ���������
*******************************************************************/
void p1_screen(void)
{
	int x = 160;
	int y = 0;
	int i = 0;
	cleardevice();
	setbkcolor(WHITE);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	setfillstyle(11,YELLOW);
    bar(0, 0, 640 , 480);
    rectangle(x,y+210,x+30,y+245);
    rectangle(x,y+255,x+30,y+290);
	rectangle(x,y,x+80,y+200);
	puthz(x+15, y+80, "ҩ��", 24, 24, DARKGRAY);
    rectangle(x,y+300,x+120,y+480);
    puthz(x+25, y+380, "�ҺŴ�", 24, 24, DARKGRAY);
	rectangle(x+140,y,x+320,y+200);
	puthz(x+200, y+80, "����", 24, 24, DARKGRAY);
    rectangle(x+200,y+300,x+320,y+480);
    puthz(x+220, y+380, "�շѴ�", 24, 24, DARKGRAY);
    rectangle(x+220,y+200,x+320,y+300);
    puthz(x+235, y+235, "��ʿվ", 24, 24, DARKGRAY);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(160,0,160,480);
	line(480,0,480,480);
	puthz(20, 40, "������ţ�", 16, 16, DARKGRAY);
	rectangle(20,100,140,160);
	puthz(30, 115, "��Ҫȡҩ", 24, 24, DARKGRAY);
	rectangle(20,220,140,280);
	puthz(30, 235, "��ѯ״̬", 24, 24, DARKGRAY);
	rectangle(20,360,140,420);
	puthz(30, 375, "��Ҫ�Һ�", 24, 24, DARKGRAY);
	rectangle(500,60,620,120);
	puthz(510, 75, "��Ҫ����", 24, 24, DARKGRAY);
	rectangle(500,360,620,420);
	puthz(510, 375, "��Ҫ�ɷ�", 24, 24, DARKGRAY);
	rectangle(500,y+220,620,y+280);
	puthz(510, y+235, "��Ҫ��ѯ", 24, 24, DARKGRAY);
	setfillstyle(11,LIGHTRED);
	bar(280,420,360,480);
	rectangle(280,420,360,480);
	puthz(295, 435, "�뿪", 24, 24, DARKGRAY);
	setlinestyle(0, 0, 1);
	for(i=0;i<10;i++)
	{
		line(x+110,y+5*(i+1),x+140,y+5*(i+1));
	}
	line(x+110,y,x+110,y+50);
}

/******************************************************************
		����ҽ������ʾ������
��д�ˣ�����
���룺void
������void
�������ܣ�չʾ��ҽ����
*******************************************************************/
void Notice_Page_p1(void)
{
	int y = 0;
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
    bar(0, 0, 640 , 480);
    setfillstyle(1,WHITE);
    bar(160,0,480,480);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(160,40,480,40);
	line(160,0,160,480);
	line(480,0,480,480);
	rectangle(20,100,140,160);
	puthz(30, 115, "��Ҫȡҩ", 24, 24, DARKGRAY);
	rectangle(20,220,140,280);
	puthz(30, 235, "��ѯ״̬", 24, 24, DARKGRAY);
	rectangle(20,360,140,420);
	puthz(30, 375, "��Ҫ�Һ�", 24, 24, DARKGRAY);
	rectangle(500,60,620,120);
	puthz(510, 75, "��Ҫ����", 24, 24, DARKGRAY);
	rectangle(500,360,620,420);
	puthz(510, 375, "��Ҫ�ɷ�", 24, 24, DARKGRAY);
	rectangle(500,y+220,620,y+280);
	puthz(510, y+235, "��Ҫ��ѯ", 24, 24, DARKGRAY);
	
    setfillstyle(1,RED);
    bar(440,0,480,40);
    setfillstyle(11,DARKGRAY);
    bar(160,0,440,40);
    line(445,5,475,35);
	line(445,35,475,5);
    
    puthz(165, 5, "��ܰ��ʾ", 32, 32, DARKGRAY);
    puthz(245, 45, "��ҽȡҩ����", 24, 24, DARKGRAY);
    
    puthz(270, 75, "����Һ�", 24, 24, DARKGRAY);
    puthz(270, 125, "ҽ�����", 24, 24, DARKGRAY);
    puthz(270, 175, "ҩƷ�ɷ�", 24, 24, DARKGRAY);
    puthz(270, 225, "�ȴ�ȡҩ", 24, 24, DARKGRAY);
    
    rectangle(270,70,370,100);
	rectangle(270,120,370,150);
	rectangle(270,170,370,200);
	rectangle(270,220,370,250);
    
    line(320,100,320,120);
    line(315,95,320,120);
    line(325,95,320,120);
    
    line(320,150,320,170);
    line(315,145,320,170);
    line(325,145,320,170);
    
    line(320,200,320,220);
    line(315,195,320,220);
    line(325,195,320,220);
    
    puthz(170, 260, "������������̽��о���", 16, 16, DARKGRAY);
    puthz(170, 280, "������������Լ��ľ���״̬���ɵ�������", 16, 16, DARKGRAY);
    puthz(170, 300, "���ѯ������ƾ�����ѯ", 16, 16, DARKGRAY);
    puthz(170, 320, "�����ڼ䣬������ÿ��֣������������ϰ�", 16, 16, RED);
    puthz(170, 340, "ȫ����", 16, 16, RED);
    puthz(170, 380, "лл��ϣ�", 16, 16, DARKGRAY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		while(1)
		{
			if (MouseX > 280 && MouseY > 420 && MouseX < 360 && MouseY < 480)
			{
				MouseS = 1;
				break;
			}//�뿪 

			else
			{
				MouseS = 0;
				break;
			}
		}

		if(mouse_press(440,0,480,40) == 1)
		{
		  clrmous(MouseX,MouseY);
		  delay(200);
		  break;
		}//�뿪
	}
}

/******************************************************************
		��״̬��ѯ������
��д�ˣ�����
���룺int ID 
������void
�������ܣ�չʾ���ߵ�ǰ״̬
*******************************************************************/
void Inquire_Page_p2(int ID)
{
	int y = 0;
	int j = 0;
	PatientData* head = creat(0);
	PatientData* p = head->next;
	char nowchar[4]={'\0'};
	cleardevice();

	Patient_Setup (head);
	p = head->next;
	while(1)
	{
		if(p->numreg == ID)
		{
			break;
		}
		else if(p->next ==NULL)
		{
			j =1;
			break;
		}
		p = p->next;
	}

	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0, 0, 640 , 480);
	setfillstyle(1,WHITE);
	bar(160,0,480,480);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(160,40,480,40);
	line(160,0,160,480);
	line(480,0,480,480);
	rectangle(20,100,140,160);
	puthz(30, 115, "��Ҫȡҩ", 24, 24, DARKGRAY);
	rectangle(20,220,140,280);
	puthz(30, 235, "��ѯ״̬", 24, 24, DARKGRAY);
	rectangle(20,360,140,420);
	puthz(30, 375, "��Ҫ�Һ�", 24, 24, DARKGRAY);
	rectangle(500,60,620,120);
	puthz(510, 75, "��Ҫ����", 24, 24, DARKGRAY);
	rectangle(500,360,620,420);
	puthz(510, 375, "��Ҫ�ɷ�", 24, 24, DARKGRAY);
	rectangle(500,y+220,620,y+280);
	puthz(510, y+235, "��Ҫ��ѯ", 24, 24, DARKGRAY);

	setfillstyle(1,RED);
	bar(440,0,480,40);
	setfillstyle(11,DARKGRAY);
	bar(160,0,440,40);
	line(445,5,475,35);
	line(445,35,475,5);

	if(j == 0)
	{
	int_trans_char(ID,nowchar);
	settextstyle(1,0,4);
	puthz(165, 5, "��ܰ��ʾ", 32, 32, DARKGRAY);
	puthz(165, 45, "���ã�", 48, 48, DARKGRAY);
	puthz(166, 46, "���ã�", 48, 48, DARKGRAY);
	puthz(165, 105, "���ĵ���Ϊ��", 24, 24, DARKGRAY);
	outtextxy(315,95,nowchar);
	puthz(165, 150, "����״̬Ϊ��", 24, 24, DARKGRAY);
	puthz(335, 155, "�Һ�", 24, 24, DARKGRAY);
	puthz(335, 200, "��ҽ�����", 24, 24, DARKGRAY);
	puthz(335, 245, "��ҩ��", 24, 24, DARKGRAY);
	puthz(335, 290, "ȡҩƷ", 24, 24, DARKGRAY);
	puthz(165, 335, "�����Ľ��飺", 24, 24, DARKGRAY);

	while(1)
	{
		if(p->numreg == ID)
		{
			break;
		}
		p = p->next;
	}

	if(p->payreg == 0)
	{
		puthz(310, 155, "��", 24, 24, GREEN);
		puthz(310, 200, "δ", 24, 24, RED);
		puthz(310, 245, "δ", 24, 24, RED);
		puthz(310, 290, "δ", 24, 24, RED);

		puthz(200, 370, "���ȵ�������о���", 16, 16, DARKGRAY);
		puthz(200, 390, "�Ի�ȡ��Ͻ����ҩ��", 16, 16, DARKGRAY);

		puthz(185, 420, "ף�����彡����������죡", 24, 24, DARKGRAY);
		puthz(186, 421, "ף�����彡����������죡", 24, 24, DARKGRAY);
	}
	else if(p->payreg == 1)
	{
		puthz(310, 155, "��", 24, 24, GREEN);
		puthz(310, 200, "��", 24, 24, GREEN);
		puthz(310, 245, "δ", 24, 24, RED);
		puthz(310, 290, "δ", 24, 24, RED);

		puthz(200, 370, "���ȵ��շѴ����ҩƷ�ɷ�", 16, 16, DARKGRAY);
		puthz(200, 390, "�Եȴ���������ȡҩ", 16, 16, DARKGRAY);

		puthz(185, 420, "ף�����彡����������죡", 24, 24, DARKGRAY);
		puthz(186, 421, "ף�����彡����������죡", 24, 24, DARKGRAY);
	}
	else if(p->payreg == 2 || p->payreg == 3 ||p->payreg == 4|| (p->payreg == 5 && p->nummed != 0))
	{
		puthz(310, 155, "��", 24, 24, GREEN);
		puthz(310, 200, "��", 24, 24, GREEN);
		puthz(310, 245, "��", 24, 24, GREEN);
		puthz(310, 290, "δ", 24, 24, RED);

		puthz(200, 370, "��ȥҩ���ȴ�ȡҩ��ȡ������ҩƷ", 16, 16, DARKGRAY);
		puthz(200, 390, "�������ξ�������", 16, 16, DARKGRAY);

		puthz(185, 420, "ף�����彡����������죡", 24, 24, DARKGRAY);
		puthz(186, 421, "ף�����彡����������죡", 24, 24, DARKGRAY);
	}
	else if(p->nummed == 0 && p->payreg == 5 )
	{
		puthz(310, 155, "��", 24, 24, GREEN);
		puthz(310, 200, "��", 24, 24, GREEN);
		puthz(310, 245, "��", 24, 24, GREEN);
		puthz(310, 290, "��", 24, 24, GREEN);

		puthz(200, 370, "��ϲ����������������", 16, 16, DARKGRAY);
		puthz(200, 390, "���ξ������̽���", 16, 16, DARKGRAY);

		puthz(185, 420, "ף�����彡����������죡", 24, 24, DARKGRAY);
		puthz(186, 421, "ף�����彡����������죡", 24, 24, DARKGRAY);
	}

	}
	else
	{
		puthz(165, 150, "����δ�Һ�", 32, 32, DARKGRAY);
		puthz(165, 190, "���˳����ҺŴ���", 32, 32, DARKGRAY);
		puthz(165, 230, "�Ƚ��йҺ�", 32, 32, DARKGRAY);

	}

	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);

		while(1)
		{
			if (MouseX > 280 && MouseY > 420 && MouseX < 360 && MouseY < 480)
			{
				MouseS = 1;
				break;
			}//�뿪

			else
			{
				MouseS = 0;
				break;
			}
		}

		if(mouse_press(440,0,480,40) == 1)
		{
		  clrmous(MouseX,MouseY);
		  delay(200);
		  break;
		}//�뿪
	}
}



/******************************************************************
		������ѡ������
��д�ˣ�����
���룺int *IDnumber
������int page 
�������ܣ����뻼��ѡ����棬���߿���ѡ�����Լ���״̬��Ҳ���Ըı��Լ������
*******************************************************************/
int p1plus( int *IDnumber)
{
	int page = 0;
	int data[9]={20,60,120,25,10,8,3,2,6};
	char Data_Num[4]={'\0'};
	int m=1;
	clrmous(MouseX,MouseY);
	p1_screen(); 
	CHAR_INT_Change(Data_Num,*IDnumber);
	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		while(1)
		{
			if (MouseX > 280 && MouseY > 420 && MouseX < 360 && MouseY < 480)
			{
				MouseS = 1;
				break;
			}//�뿪 
			else if (MouseX > 20 && MouseY > 100 && MouseX < 140 && MouseY < 160)
			{
				MouseS = 1;
				break;
			}//��Ҫȡҩ 
			else if (MouseX > 20 && MouseY > 360 && MouseX < 140 && MouseY < 420)
			{
				MouseS = 1;
				break;
			}//��Ҫ�Һ� 
			else if (MouseX > 500 && MouseY > 60 && MouseX < 620 && MouseY < 120)
			{
				MouseS = 1;
				break;
			}//��Ҫ���� 
			else if (MouseX > 500 && MouseY > 360 && MouseX < 620 && MouseY < 420)
			{
				MouseS = 1;
				break;
			}//��Ҫ�ɷ�
			else if (MouseX > 500 && MouseY > 220 && MouseX < 620 && MouseY < 280)
			{
				MouseS = 1;
				break;
			}//��Ҫ��ѯ 
		    else if (MouseX > 20 && MouseY > 220 && MouseX < 140 && MouseY < 280)
			{
				MouseS = 1;
				break;
			}//��ѯ״̬
			else
			{
				MouseS = 0;
				break;
			}
		}

		if(mouse_press(280,420,360,480) == 1)
		{
		  page = -1;
		  delay(200);
		  break; 
		}//�뿪 
		else if(mouse_press(20,360,140,420) == 1)
		{
		  page = 2;
		  delay(200);
		  break; 
		}//�Һ� 
		else if(mouse_press(500,60,620,120) == 1)
		{
		  page = 4;
		  delay(200);
		  break; 
		}//���� 
		else if(mouse_press(500,360,620,420) == 1)
		{
		  page = 6;
		  delay(200);
		  break; 
		}//�ɷ� 
		else if(mouse_press(20,100,140,160) == 1)
		{
		  page = 7;
		  delay(200);
		  break; 
		}//ȡҩ 
		else if(mouse_press(20,220,140,280) == 1)
		{
		  Inquire_Page_p2(*IDnumber);
		  m = 1;
		  delay(200);
		  p1_screen(); 
		}//״̬��ѯ 
        else if(mouse_press(500,220,620,280) == 1)
		{
		  Notice_Page_p1(); 
		  m = 1;
		  delay(200);
		  p1_screen();
		}//��ѯ 
       CreateButton_INPUT_3  (data,&m,Data_Num,"\0",1);
       if(m == 1)
	   {
       		*IDnumber =	INT_CHAR_Change(Data_Num);
	   }
	}
	return page;
}   
