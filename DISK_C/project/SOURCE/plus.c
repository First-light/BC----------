#include <common.h>

/******************************************************************
	����������ƺ����� 
��д�ˣ����� 
���룺 int x,int y���������Ͻ����꣩ 
������ void 
�������ܣ����������� 
*******************************************************************/

void plus_Page(int x,int y)
{
	setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    setfillstyle(11,YELLOW);
    bar(x,y,x+360,y+240);
    setfillstyle(1,BROWN);
    bar(x,y,x+360,y+30);
    setfillstyle(1,RED);
    bar(x+330,y,x+360,y+30);
    line(x,y,x,y+240);
    line(x,y,x+360,y);
    line(x+360,y,x+360,y+240);
    line(x,y+240,x+360,y+240);
    setlinestyle(0,0,5);
    setcolor(WHITE);
    line(x+335,y+5,x+355,y+25);
    line(x+335,y+25,x+355,y+5);
    puthz(x+5, y+5, "ҩƷ��ӽ���", 24, 24, WHITE);
    puthz(x+5, y+50, "ҩƷ���ƣ�", 24, 24, DARKGRAY);
    puthz(x+5, y+100, "���������", 24, 24, DARKGRAY);
    setfillstyle(1,LIGHTGRAY);
    bar(x+130,y+150,x+230,y+180);
    puthz(x+135, y+155, "ȷ�����", 24, 24, DARKGRAY);
} 

/******************************************************************
	��ҩƷ������ִ�к����� 
��д�ˣ����� 
���룺 MED*list��ͷ�ڵ㣩,MED*medicine�����߽ṹָ�룩,char*data��������������֣� 
������ void 
�������ܣ��������ִ�в��� 
*******************************************************************/

void plus_Change(MED*list,MED*medicine,char*data)
{
	int x=120;//С��������Ͻ�x���� 
	int y=80;
	int i = 0;
  MED*posNode=list->next;
  while(1)
  {
  	if(strcmp(medicine->name,posNode->name)==0)
  	{
  	  break;	
	}
	else if(posNode->next == NULL)
	{
		i = 1;
		break;
	}
  	posNode = posNode->next;		
  }//Ѱ�ҵ���Ŀ��ҩƷ 
  if(i == 0)
  {
  	if(posNode->margin+char_trans_int(data)<=999)
  {
  	posNode->margin = posNode->margin+char_trans_int(data);
  } //δ�����޲�ִ�� 
  else
  {
  	posNode->margin = 999;
  	setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    setfillstyle(11,YELLOW);
    bar(x,y,x+360,y+240);
    setfillstyle(1,BROWN);
    bar(x,y,x+360,y+30);
    setfillstyle(1,RED);
    bar(x+330,y,x+360,y+30);
    line(x,y,x,y+240);
    line(x,y,x+360,y);
    line(x+360,y,x+360,y+240);
    line(x,y+240,x+360,y+240);
    setlinestyle(0,0,5);
    setcolor(WHITE);
    line(x+335,y+5,x+355,y+25);
    line(x+335,y+25,x+355,y+5);
    puthz(x+85, y+120, "�Ѵ��������", 32, 32, DARKGRAY);
    puthz(x+84, y+119, "�Ѵ��������", 32, 32, DARKGRAY);
  }//ҩƷ�Ѵ�������� ��ʾ��ʾ 
  }//��ӽ���жϲ�ִ�� 
  else if(i == 1)
  {
  	setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    setfillstyle(11,YELLOW);
    bar(x,y,x+360,y+240);
    setfillstyle(1,BROWN);
    bar(x,y,x+360,y+30);
    setfillstyle(1,RED);
    bar(x+330,y,x+360,y+30);
    line(x,y,x,y+240);
    line(x,y,x+360,y);
    line(x+360,y,x+360,y+240);
    line(x,y+240,x+360,y+240);
    setlinestyle(0,0,5);
    setcolor(WHITE);
    line(x+335,y+5,x+355,y+25);
    line(x+335,y+25,x+355,y+5);
    puthz(x+85, y+120, "δ�ҵ���ҩƷ", 32, 32, DARKGRAY);
    puthz(x+84, y+119, "δ�ҵ���ҩƷ", 32, 32, DARKGRAY);
  } //δ������ҩƷ����ʾ 
} 

/******************************************************************
	��ҩƷ������������ 
��д�ˣ����� 
���룺MED*medicine�����߽ṹָ�룩
������ void 
�������ܣ����������� 
*******************************************************************/
void plus(MED*medicine)
{
	int page = 0;//ҳ����ת��¼
	int i;//��������Ĳ���
	int x=120;//С��������Ͻ�x���� 
	int y=80; //С��������Ͻ�y����
	int data_name[9]={250,130,220,40,22,8,20,1,2};
	int data_num[9]={250,180,220,40,22,8,3,1,2};
	int m = 1;
	int n = 1;
	char data[4]={'\0'};
	MED*list =reopen(medicine);
	MED* mt = medicine;
	plus_Page(x,y);
	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);
		while(1)
		{
			if (MouseX > 600 && MouseY > 0 && MouseX < 640 && MouseY < 40)
			{
				MouseS = 1;
				break;
			}
			else if (MouseX > x+250 && MouseY > y && MouseX < x+280 && MouseY < y+30)
			{
				MouseS = 1;
				break;
			}
			else if (MouseX > x+130 && MouseY > y+150 && MouseX < x+230 && MouseY < 180)
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
		  delay(200);
		  break; 
		}//�˳�ҩ�� 

        else if(mouse_press(x+330,y,x+360,y+30) == 1)
		{
		  delay(200);
		  break; 
		}//�˳�С���� 
         else if(mouse_press(x+130,y+150,x+230,y+180) == 1)
		{
		 plus_Change(list,medicine,data);
		 delay(2000); 
		 break; 
		}//ȷ�����
		CreateButton_INPUT_3  (data_name,&m,medicine->name,"\0",1);
		CreateButton_INPUT_3  (data_num,&n,data,"\0",1);//�����ģ��
	}
	printlist_FILE(list);
	mt = list->next;
	while(mt != NULL)
	{
		free(list);
		list = mt;
		mt = mt->next;
	}
	free(list);
} 
