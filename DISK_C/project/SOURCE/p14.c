#include <common.h>
#define p14_button_num 5
/*������������������������������������������������
				��ҽ��ѡ����桿 
��д�ˣ�������
�˽���Ϊҽ��ѡ��ͬϵͳ���ܵ�ҳ��
������������������������������������������������*/


void p14_screen(void)
{
/*����������������������������������
		����ʼ����ͼ������
��д�ˣ�����
�����ử������ı�����
������������������������������������*/
	int data[9] = {10+3,10+3,14,120,50,24,48,-28,2};
	int x;
	int y;
	int length_x;
	int length_y;
	int textsize;
	int textlength;
	x =data[0];
	y = data[1];
	length_x = data[3];
	length_y = data[4];
	textsize = data[5];
	textlength = data[6];
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	setfillstyle(1,BLUE);
	bar(0,0,190-45,480);
	setfillstyle(1,WHITE);
	bar(0,61+3,190-45,64+3);
	puthz(160,40,"����ҽ��",32,40,RED);
	puthz(161,41,"����ҽ��",32,40,RED);
	puthz(160,80,"��ӭ����ϵͳ����ҳ�棡",32,40,RED);
	puthz(161,81,"��ӭ����ϵͳ����ҳ�棡",32,40,RED);
	setlinestyle(0,0,3);
	setcolor(DARKGRAY);
	line(160,120,600,120);
	line(160,30,310,30);
	puthz(180,130,"�Һ�ͳ��",24,24,DARKGRAY);
	rectangle(155,130,175,150);
	puthz(180,160,"���ݲ�ͬ�Ĺؼ��ʼ������߾�����Ϣ�����ɲ�ѯ��һ���ߵ���ϸ��Ϣ��Ҳ��Ϊ�Һŵ�δ��ϻ����޸ĹҺ�ѡ��",16,16,DARKGRAY);

	puthz(180,210,"ҩ�����",24,24,DARKGRAY);
	rectangle(155,210,175,230);
	puthz(180,240,"����ҩ������ɲ鿴ҩ��������ҩƷ����Ϣ��ʵ�ֳ�����⣬����ɾ��������ȡҩƷ���漱��Ϣ",16,16,DARKGRAY);

	puthz(180,290,"��ҩģ��",24,24,DARKGRAY);
	rectangle(155,290,175,310);
	puthz(180,320,"�۲�ʵʱ����ҩ�����У��˽�ȡҩ����������״̬�����ɺ��л�����ȡ��ҩ�Ļ���ǰ������ȡҩ",16,16,DARKGRAY);

	puthz(180,370,"ȡҩ��¼",24,24,DARKGRAY);
	rectangle(155,370,175,390);
	puthz(180,400,"�������ڲ�ѯҩƷ����״������֪��������ҩƷ���Ը���ϵͳ��ѧ�ع���ҩ�⣬���㻼������",16,16,DARKGRAY);
	frameline2();
	setfillstyle(1,BLUE);
	bar(x, y, x+length_x,y+length_y);
	puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,"��ҳ",textsize,textlength,LIGHTBLUE);
}


int p14(void)
{
/*������������������������������������
		��ҽ��ѡ����溯����
		��д�ˣ�������
��������������������������������������*/
	int button[p14_button_num] = {1,1,1,1,1};
	int page = 0;
	int page_t = 0;
	
	int data2[9] = {10+3,150+3,26,120,70,24,26,3,2};
	int data3[9] = {10+3,220+3,16,120,70,24,26,3,2};
	int data1[9] = {10+3,80+3,15,120,70,24,26,3,2};
	int data4[9] = {10+3,290+3,23,120,70,24,26,3,2};
	clrmous(MouseX,MouseY);
	MouseS = 0;
	cleardevice();
	setbkcolor(WHITE);
	p14_screen();
	delay(300);
	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);
			
			page_t = CreateButton_OUT(600,0,-1,&button[0]);
			//���ذ�ť
			if(page_t)
			{
				//������ת����⣬����ť��������ı��ҳ����ת����page_t����page��ֵ����������ҳ��ѭ�����˳�ҳ�溯����Ȼ������ѡ��ҳ��
				page = page_t;
				break;
			}		

			page_t = CreateButton_4  ("�Һ�ͳ��",data1,& button[1]);
			if(page_t)
			{
				page = page_t;
				break;
			}			

			page_t = CreateButton_4  ("ҩ�����",data2,& button[2]);
			if(page_t)
			{
				page = page_t;
				break;
			}			
			page_t = CreateButton_4  ("��ҩģ��",data3,& button[3]);
			if(page_t)
			{
				page = page_t;
				break;
			}
			page_t = CreateButton_4  ("ȡҩ��¼",data4,& button[4]);
			if(page_t)
			{
				page = page_t;
				break;
			}				

		delay(3);
	}
	return page;    
	//�˳�ҳ�棬���ظı��ҳ��ֵ
}
