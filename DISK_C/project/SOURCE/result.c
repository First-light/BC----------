#include <common.h>

/******************************************************************
	����Ͻ�����ƺ����� 
��д�ˣ�����   ������ 
���룺PatientData* p���������ݣ� int choose���������� 
������ void 
�������ܣ�������Ͻ��ҳ�沢��ʾ��� 
*******************************************************************/

void Result_Page(PatientData* p)
{
	int i=0;
	int x=50;
	int y=73;
	int choose;
	MED*medicine = (MED*)malloc(sizeof(MED));//����һ�����߽ṹ 
	char number[5] = {0};
	char old[4] = {0};
	char hanzi[8] = {0};
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(11,LIGHTBLUE);
	bar(0,0,640,480);
	frameline();
    setfillstyle(1,WHITE);
    bar(x,y,x+540,y+334);
    setlinestyle(0,0,1);
    setcolor(DARKGRAY);
    for(i=0;i<30;i++)
    {
    	line(x+3*i+5,y+5,x+3*i+5,y+30+5);
	}
    setlinestyle(0,0,3);
    line(x+5,y+5,x+5,y+30+5);
    line(x+3*29+5,y+5,x+3*29+5,y+30+5);
    line(x+3*9+5,y+5,x+3*9+5,y+30+5);//��ά�� 
	puthz(x+105, y+30, "���пƼ���ѧУҽԺ���ﴦ����", 24, 24, DARKGRAY); 
	puthz(x+106, y+31, "���пƼ���ѧУҽԺ���ﴦ����", 24, 24, DARKGRAY); 
	setcolor(DARKGRAY);
    settextstyle(2,0,2);
	outtextxy(x+5,y+35,"*2  0  2  3  A  I  A  *" );
	setlinestyle(0,0,1);
	line(x+5,y+73,x+535,y+73);
	settextstyle(1,0,2);
	CHAR_INT_Change2(number,p->numreg,4);
	puthz(x+5, y+55, "��ţ�", 16, 16, DARKGRAY);
	outtextxy(x+5+16*3+5,y+55-5,number);
	
	puthz(x+5, y+75, "������", 16, 16, DARKGRAY);
	outtextxy(x+5+16*3+5,y+75-5,p->name);
	
	puthz(x+220, y+75, "�Ա�", 16, 16, DARKGRAY);
	if(p->sexual)
	{
		puthz(x+220+16*3+5, y+75, "Ů", 16, 16, DARKGRAY);
	}else
	{
		puthz(x+220+16*3+5, y+75, "��", 16, 16, DARKGRAY);
	}
	
	puthz(x+320, y+75, "���䣺", 16, 16, DARKGRAY);
	CHAR_INT_Change(old,p->age);
	outtextxy(x+320+16*3+5,y+75-3,old);
	
	puthz(x+270, y+95, "�������ڣ�", 16, 16, DARKGRAY);
	outtextxy(x+270+16*5+5,y+95-3,p->timer);
	
	puthz(x+5, y+95, "���ң�", 16, 16, DARKGRAY);
	DoctorShow(p->doctor,hanzi,2);
	puthz(x+5+16*3+5, y+95,hanzi, 16, 16, DARKGRAY);
	
	puthz(x+5, y+115, "�ٴ���ϣ�", 16, 16, DARKGRAY);
	choose = p->window;
			if(p->doctor[1] == '1')
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "��ð", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "����", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '2')
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "����", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "���Ĳ�", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '3')
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "����", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "�˿ڸ�Ⱦ", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '4')
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "ʹ��", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "������", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '5')
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "��������Ⱦ", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "��к", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '6')
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "����֢", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "˫������ϰ�", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '7') 
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "���䲡", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "ʳ���ж�", 16, 16, DARKGRAY);
				}
			}
	
	
	
	line(x+5,y+132,x+535,y+132);
	settextstyle(3,0,4);
	outtextxy(x+5,y+135,"RP" );
	outtextxy(x+4,y+134,"RP" );
	line(x+5,y+300,x+535,y+300);
	puthz(x+5, y+302, "���ҽʦ��", 16, 16, DARKGRAY);
	DoctorShow(p->doctor,hanzi,3);
	puthz(x+5+16*5+5, y+302,hanzi, 16, 16, DARKGRAY);
	
	puthz(x+200, y+302, "ҩƷ�ܽ�", 16, 16, DARKGRAY);
	CHAR_INT_Change2(number,p->paymed,4);
	settextstyle(1,0,3);
	outtextxy(x+200+6*16+5,y+302-5,number);
	puthz(x+200+6*16+5+60, y+302, "Ԫ", 16, 16, DARKGRAY);
	
	puthz(x+400, y+302, "�ɷѣ�", 16, 16, DARKGRAY);
	setcolor(DARKGRAY); 
	settextstyle(3,0,1);
	for(i=0;i<5;i++)
	{
		if(p->medicine_list[i][0] != 0){
			char output[25] ={0}; 
			char count[2] = {0};
			char moneyout[4] = {0};
			FILE*fp; 
			fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r");
			for(; ;)
			{	
				fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
				if(medicine->ID == (p)->medicine_list[i][0] && (p)->medicine_list[i][1] != 0)
				{		
					strcpy(output,medicine->name);
					CHAR_INT_Change2(count,(p)->medicine_list[i][1],1);
					CHAR_INT_Change2(moneyout,medicine->price,3);
						outtextxy(x+280,y+135+30*i,moneyout);
						outtextxy(x+360,y+135+30*i," *  " );
						outtextxy(x+140,y+135+30*i,output);
						outtextxy(x+400,y+135+30*i,count);
					break;
				}
				if(feof(fp))break;
			}
			fclose(fp);	
		}
	}
	
	
	if(p->payreg >= 2)
	{
		setcolor(RED);
		setlinestyle(0,0,3);
		circle(x+470, y+282,50) ;
		delay(500);
		circle(x+470, y+282,45) ;
		delay(500);
		puthz(x+445, y+278, "�ѽɷ�", 16, 16, RED);//�ѽɷ�ӡ�� 
		delay(1000);
	}
	 free(medicine);
}


/******************************************************************
	����Ͻ���������� 
��д�ˣ�����
���룺PatientData* p���������ݣ� int choose������������ʱ��ѡ�� 
������ int page(ҳ����ת�� 
�������ܣ��Һŵ�ҳ�������������ҳ����ת 
*******************************************************************/

int Result_List(PatientData* p)

{
    int x=196;
	int y=40;
	int page=0;
	clrmous(MouseX,MouseY); 
	Result_Page(p);//������Ͻ��� 
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
			else
			{
				MouseS = 0;
				break;
			}
		}

		if(mouse_press(600, 0, 600+40 , 0 + 40) == 1)
		{
		  page = 0;
		  delay(200);
		  break; 
		}//�ر� 
		else if(mouse_press(x+280,y+360,x+420,y+400) == 1)
		{
		  page = 0;
		  delay(200);
		  break; 
		}//�ر�
	}
	return page;
 }
