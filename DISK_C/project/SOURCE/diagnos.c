#include <common.h>
/******************************************************************
	��ҽ�����ﺯ���� 
��д�ˣ����� 
���룺PatientData* p��������Ϣ�� 
������int choose�����˸��ݶ�Ӧ��֢��ѡ�� 
�������ܣ�ʵ��ҽ��ģ��������������˵�ѡ�� 
*******************************************************************/

int Diagnos_dotor(PatientData* p)
{ 
    int x = 160;
	int y = 120;
	int choose = 0;
	clrmous(MouseX,MouseY); 
	setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    setfillstyle(1,WHITE);
    bar(x,y,x+320,y+240);
    setfillstyle(1,BROWN);
    bar(x,y,x+320,y+40);
    puthz(x+5, y+5, "ҽ������", 32, 32, DARKGRAY);
	puthz(x+5,y+ 55, "�����ڸо���ô����", 24, 24, DARKGRAY);
	rectangle(x,y,x+320,y+240);
	rectangle(x+30,y+140,x+150,y+200);
	rectangle(x+170,y+140,x+290,y+200);
		
	if(p->doctor[1] == '1')
	{
		puthz(x+35,y+ 145, "������", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "������", 24, 24, DARKGRAY);
	}
	else if(p->doctor[1] == '2')
	{
		puthz(x+35,y+ 145, "��������", 24, 24, DARKGRAY);
		puthz(x+35,y+ 170, "����", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "��ʹ�ļ�", 24, 24, DARKGRAY);
	}
	else if(p->doctor[1] == '3')
	{
		puthz(x+35,y+ 145, "֫�徭����", 24, 24, DARKGRAY);
		puthz(x+35,y+ 170, "������ʹ", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "�˿ڻ�ŧ", 24, 24, DARKGRAY);
	}
	else if(p->doctor[1] == '4')
	{
		puthz(x+35,y+ 145, "�¾��ڸ���", 24, 24, DARKGRAY);
		puthz(x+35,y+ 170, "������ʹ", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "����������", 24, 24, DARKGRAY);
		puthz(x+175,y+ 170, "�쳣", 24, 24, DARKGRAY);
	}
	else if(p->doctor[1] == '5')
	{
		puthz(x+35,y+ 145, "С����", 24, 24, DARKGRAY);
		puthz(x+35,y+ 170, "��������", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "С����", 24, 24, DARKGRAY);
		puthz(x+175,y+ 170, "����������", 24, 24, DARKGRAY);
	}
	else if(p->doctor[1] == '6')
	{
		puthz(x+35,y+ 145, "����", 24, 24, DARKGRAY);
		puthz(x+35,y+ 170, "��������", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "ʱ������", 24, 24, DARKGRAY);
		puthz(x+175,y+ 170, "ʱ������", 24, 24, DARKGRAY);
	}
	else if(p->doctor[1] == '7')
	{
		puthz(x+35,y+ 145, "ͷ�ζູ", 24, 24, DARKGRAY);
		puthz(x+35,y+ 170, "��֫ʪ��", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "����Ż��", 24, 24, DARKGRAY);
		puthz(x+175,y+ 170, "��ʹ����", 24, 24, DARKGRAY);
	}//�������Ļ��� 

	while(choose == 0)
	{
		newmouse(&MouseX,&MouseY,&press);

		while(1)
		{
			if (MouseX > x+30 && MouseY > y+140 && MouseX < x+150 && MouseY < y+200)
			{
				MouseS = 1;
				break;
			}// ѡ��һ 
			else if (MouseX > x+170 && MouseY > y+140 && MouseX < x+290 && MouseY < y+200)
			{
				MouseS = 1;
				break;
			}//ѡ��� 
			else
			{
				MouseS = 0;
				break;
			}
		}

		if(mouse_press(x+30,y+140,x+150,y+200) == 1)
		{
		  choose = 1;
		  delay(200);
		  break; 
		}//�뿪 
		else if(mouse_press(x+170,y+140,x+290,y+200) == 1)
		{
		  choose = 2;
		  delay(200);
		  break; 
		}//�뿪 
	}
	clrmous(MouseX,MouseY);
	return choose; //����ѡ�� 
}


/******************************************************************
	��ҽ������к����� 
��д�ˣ����� 
���룺PatientData* p��������Ϣ�� 
������int choose�����˸��ݶ�Ӧ��֢��ѡ�� 
�������ܣ�ʵ��ҽ��ģ�����ȫ���̣����������˵�ѡ�� 
*******************************************************************/


int Diagnos_screen(PatientData* p)
{

	int i=11;
	int choose=0;
	char nowchar[4]="\0";//�ٷֱȼ�¼
	char nowchar_d[4]="\0";//��������char��
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0, 0, 640 , 480);
	puthz(35, 35, "����С���������", 48, 48, DARKGRAY);
	settextstyle(1,0,3);
	setcolor(DARKGRAY);
	rectangle(69,369,571,421);
	for(i=0;i<100;i++)
	{
		setfillstyle(4,LIGHTBLUE);
		bar(70,370,75+5*i,420);
		int_trans_char(i+1,nowchar);
		outtextxy(500,340,nowchar);
		outtextxy(550,340,"%");
		delay(100);
		if(i==99)
		{
			break;
		}
		else if(i==10)
		{
			puthz(35, 100, "������", 24, 24, DARKGRAY);
			outtextxy(110,100,p->name);

		}
		else if(i==20)
		{
			puthz(35, 140, "���䣺", 24, 24, DARKGRAY);
			int_trans_char(p->age,nowchar_d);
			outtextxy(110,140,nowchar_d);
		}
		else if(i==25)
		{
				choose = Diagnos_dotor(p);
					cleardevice();
			   setbkcolor(WHITE);
			  setfillstyle(11,YELLOW);
				  bar(0, 0, 640 , 480);
			 puthz(35, 35, "����С���������", 48, 48, DARKGRAY);
		 settextstyle(1,0,3);
			setcolor(DARKGRAY);
		  rectangle(69,369,571,421);
			puthz(35, 100, "������", 24, 24, DARKGRAY);
			outtextxy(110,100,p->name);

			puthz(35, 140, "���䣺", 24, 24, DARKGRAY);
			int_trans_char(p->age,nowchar_d);
			outtextxy(110,140,nowchar_d);
	}//��ʾ���߻�����Ϣ
		else if(i==30)
		{
			puthz(35, 180, "��֢��", 24, 24, DARKGRAY);
		}
		else if(i==60)
		{
			if(p->doctor[1] == '1')
			{
				if(choose == 1)
				{
					puthz(110, 180, "��ð", 24, 24, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "����", 24, 24, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '2')
			{
				if(choose == 1)
				{
					puthz(110, 180, "����", 24, 24, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "���Ĳ�", 24, 24, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '3')
			{
				if(choose == 1)
				{
					puthz(110, 180, "����", 24, 24, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "�˿ڸ�Ⱦ", 24, 24, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '4')
			{
				if(choose == 1)
				{
					puthz(110, 180, "ʹ��", 24, 24, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "������", 24, 24, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '5')
			{
				if(choose == 1)
				{
					puthz(110, 180, "��������Ⱦ", 24, 24, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "��к", 24, 24, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '6')
			{
				if(choose == 1)
				{
					puthz(110, 180, "����֢", 24, 24, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "˫������ϰ�", 24, 24, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '7')
			{
				if(choose == 1)
				{
					puthz(110, 180, "���䲡", 24, 24, RED);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "ʳ���ж�", 24, 24,RED);
				}
			}
		}//��ʾ����ϵĲ�֢
		else if(i==80)
		{
			if(p->doctor[1] == '7'){
				puthz(35, 240, "���ڽ��н��������;��Σ�����������������������", 24, 24,RED);
			}else{
				puthz(35, 240, "���ڽ���������飬������ҩ����������", 24, 24, DARKGRAY);
			}
		}//��ʾ�������
		else if(i==80)
		{
			puthz(35, 240, "���ڽ���������ϣ�������ҩ����������", 24, 24, DARKGRAY);
		}//��ʾ��������
		else if(i==90)
		{
			puthz(35, 300, "ҽ�����飺", 24, 24, DARKGRAY);
		}
		else if(i==98)
		{
			if(p->doctor[1] == '1')
			{
				if(choose == 1)
				{
					puthz(160, 300, "ע����Ϣ�����ⳤʱ�䰾ҹ����֤�����˯�ߣ�", 16, 16, DARKGRAY);
					puthz(160, 320, "ʹ�����õ��ָ�����Ը�ά���ظߵ���ʳ��", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(160, 300, "���ˮ�������򣬺������ʿ�������������������", 16, 16, DARKGRAY);
					puthz(160, 320, "һ��Ҫ����Ϣ���嵭��ʳ��������������泩", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '2')
			{
				if(choose == 1)
				{
					puthz(160, 300, "����Ӵ�����ԭ��ע��������������������ҩ���棬", 16, 16, DARKGRAY);
					puthz(160, 320, "���߲�Ҫ����ͣҩ", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(160, 300, "���߱����ַ�ҩ������Ѫѹ��Ѫ�ǣ�Ѫ֬��", 16, 16, DARKGRAY);
					puthz(160, 320, "�����޾ƣ��Լ��������ʽ���ʵ����л", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '3')
			{
				if(choose == 1)
				{
					puthz(160, 300, "Ӧ���ֹ����ȶ��ԣ�������Ӱ��������ϵı������", 16, 16, DARKGRAY);
					puthz(160, 320, "����ǣ�������縺�أ��Լ�����Χ���", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(160, 300, "�崴������ȥ����������֯����ֵ����������ڽ��л�ҩ��", 16, 16, DARKGRAY);
					puthz(160, 320, "ע����ʳ�����ʵ��Ĳ���Ӫ��", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '4')
			{
				if(choose == 1)
				{
					puthz(160, 300, "������Ժ�һЩ�ȵĺ�������ˮ��Ҳ��������ˮ", 16, 16, DARKGRAY);
					puthz(160, 320, "���ȷ󸹲�����Ҫʱ��ҽ����ָ���·�����ʹ��ҩ��", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(160, 300, "�����к;ֲ���ҩ�Ϳڷ���ҩ�����ָо�������", 16, 16, DARKGRAY);
					puthz(160, 320, "����˯������", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '5')
			{
				if(choose == 1)
				{
					puthz(160, 300, "����ҽ�����ð�Ī���֡��޺�ù�صȿ�������ҩ�", 16, 16, DARKGRAY);
					puthz(160, 320, "�ں�������Ⱦ�ڼ�Ҫ��֤�������Ϣʱ��", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(160, 300, "ע��������ע����ʳ���������ҩ�ﲢ�ʵ���Ϣ��", 16, 16, DARKGRAY);
					puthz(160, 320, "���Ը��԰�Ħ����", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '6')
			{
				if(choose == 1)
				{
					puthz(160, 300, "����רҵ������ҽ���������赼���ɶ�ͼ��ˡ�����", 16, 16, DARKGRAY);
					puthz(160, 320, "���й�ͨ�����ֻ����ֹ۵���̬����Ҫʱ����ҩ������", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(160, 300, "����ѹ���������ʵ������������赼����ȥ����", 16, 16, DARKGRAY);
					puthz(160, 320, "��������ģ��嵭��ʳ", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '7')
			{
				puthz(160, 300, "���ܽ�һ����������", 24, 24, RED);
			}
		}//��ʾҽ������
		setfillstyle(11,YELLOW);
		bar(500,345,530,365);
	}//ȫ���̼��ؽ�������ڵ����Ϣ��ʾ
	setfillstyle(11,YELLOW);
	bar(35,35,500,100);
	puthz(35, 35, "�����ɣ����ѯ���", 48, 48, DARKGRAY);
	setfillstyle(1,LIGHTBLUE);
	bar(470,430,590,470);
	puthz(480, 440, "ȷ��֪��", 24, 24, WHITE);
	rectangle(470,430,590,470);
	return choose;
}

/******************************************************************
	��ҽ����Ͻ�����Ĳ���������
��д�ˣ����� 
���룺PatientData* p��������Ϣ�� 
������int choose�����˸��ݶ�Ӧ��֢��ѡ�� 
�������ܣ�ʵ��ҽ��ģ�����ȫ���̽�����Ĳ��������������˵�ѡ�� 
*******************************************************************/

int diagnosising(PatientData* p)
{
	int page = 0;
	int choose = Diagnos_screen(p);
	clrmous(MouseX,MouseY);
	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);

		while(1)
		{
			if (MouseX > 470 && MouseY > 430 && MouseX < 590 && MouseY < 470)
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

		if(mouse_press(470,430,590,470) == 1)
		{
		  page = 0;
		  delay(200);
		  break; 
		}//�뿪 
	}
	return choose;
}   
