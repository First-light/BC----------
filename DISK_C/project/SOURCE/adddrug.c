#include <common.h>
/******************************************************************
	��ҩƷ����滭������ 
��д�ˣ�����
���룺void
������void
�������ܣ����ƻ���ҩƷ���ҳ�� 
*******************************************************************/

void adddrug_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
    frameline();
    setfillstyle(1,LIGHTGRAY);
    bar(40, 150, 440, 190);
    bar(40,230,440,270) ;
    bar(40,310,440,350);
    bar(40,390,440,430);
    bar(460,230,560,260); 
    puthz(40,40, "���ҩƷ����", 48, 48, DARKGRAY);
    puthz(40, 120, "��ҩƷ���ƣ�", 24, 24, DARKGRAY);
    puthz(40, 200, "��ҩƷ��棺", 24, 24, DARKGRAY);
    puthz(40, 280, "��ҩƷ���ۣ�", 24, 24, DARKGRAY);
    puthz(40, 360, "��ҩƷ���ҩ��������ʮ�ģ���", 24, 24, DARKGRAY);
    puthz(460, 230, "ȷ�����", 24, 24, DARKGRAY);
    setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
}

/******************************************************************
	��ҩƷ����ҳ����������� 
��д�ˣ�����
���룺void
������int page(ҳ��page��ת) 
�������ܣ�ҳ����ת��ҩƷ���ҳ���������������Ķ���ҩƷ���� 
*******************************************************************/
int adddrug(void)
{
	MED*medicine = (MED*)malloc(sizeof(MED));//����һ�����߽ṹ 
	MED*list =reopen(medicine);//��ʼ��ҩƷ���� 
	MED*mt = NULL;
	int page = 0;
	int data1[9]={40,150,400,40,22,8,18,1,2};
	int data2[9]={40,230,400,40,22,8,3,1,2};
	int data3[9]={40,310,400,40,22,8,3,1,2};
	int data4[9]={40,390,400,40,22,8,2,1,2};
	int x=1;
	int y=1;
	int z=1;
	int q=1; 
	int k=0;
	char data_inventory[4]={'\0'};
	char data_price[7]={'\0'};
	char data_drugno[3]={'\0'};//�ĸ����ɶ�ȡ���ݵĴ������ 
	clrmous(MouseX,MouseY);
	adddrug_screen();//��ʾ����ҳ�� 
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
			else if(MouseX > 460 && MouseY > 230 && MouseX < 560 && MouseY < 260)
			{
				MouseS = 1;
				break;
			}
			else if(MouseX > 40 && MouseY > 150 && MouseX < 440 && MouseY < 190)
			{
				MouseS = 2;
				break;
			}
			else if(MouseX > 40 && MouseY > 230 && MouseX < 440 && MouseY < 270)
			{
				MouseS = 2;
				break;
			}
			else if(MouseX > 40 && MouseY > 310 && MouseX < 440 && MouseY < 350)
			{
				MouseS = 2;
				break;
			}
			else if(MouseX > 40 && MouseY > 390 && MouseX < 440 && MouseY < 430)
			{
				MouseS = 2;
				break;
			}
			else
			{
				MouseS = 0;
				break;
			}
		}//while�������λ����ʾ���״̬ 

		if(mouse_press(600, 0, 600+40 , 0 + 40) == 1)
		{
		  page = 26;
		  delay(200);
		  break; 
		}//�˳����� 
		else if(mouse_press(460,230,560,260) == 1)
		{	
		  medicine->inventory = INT_CHAR_Change(data_inventory);
		  medicine->price = INT_CHAR_Change(data_price);
		  medicine->Store_No = INT_CHAR_Change(data_drugno);//����ȡ������������ʱ�����½ṹ�� 
		  k = add(medicine,list);//�����߼��ж���ʾ����������д���ļ����� 
          if(k == 1)
          {
          	puthz(460,310, "ҩƷ��ӳɹ�", 16, 16, RED);
		  }
		  delay(500);
		  page=26; 
		  break; 
		}//ִ����Ӳ����жϣ����ҳɹ��������ݣ�����ʾ�ɹ� 
		    CreateButton_INPUT_3  (data1,&x,medicine->name,"\0",1);
			CreateButton_INPUT_3  (data2,&y,data_inventory,"\0",1);
			CreateButton_INPUT_3  (data3,&z,data_price,"\0",1); 
			CreateButton_INPUT_3  (data4,&q,data_drugno,"\0",1); //��ť���ɶ�ȡ 
	}
		mt = list->next;
		while(mt != NULL)
		{
			free(list);
			list = mt;
			mt = mt->next;
		}
		free(list);
		free(medicine);//���սṹ��free�� 
	return page;//����page��ת���� 
}    
