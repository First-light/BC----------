#include <common.h>

/******************************************************************
	������ѡ��������ɺ����� 
��д�ˣ�����
���룺int num,int*Outpatient��������Ϣ����Ƿ�ѡ��,int*Department��������Ϣ�� 
������int num������ѡ�Ŀ��Һ�����ɴ����� 
�������ܣ����¸������ﰴť��״̬��������ѡ���ҵĺ��� 
*******************************************************************/
int Department_Choose(int num,int*Outpatient,int*Department)
{
	int x=20;
	int y=20;
	int i=0;
	if(Outpatient[2]==0&&(Outpatient[0]==1||Outpatient[1]==1))
		{
			  
			setlinestyle(0,0,5);
            setcolor(DARKGRAY);
            for(i=0;i<6;i++)
		    {
				Department[i] = 0;
			}
		  	Department[num-1]=1;//�������Ҹ���ѡ��״̬���� 
		  	clrmous(MouseX,MouseY);
		  	if(Department[0]==0)
		    {
		  			setfillstyle(1,WHITE);
		  	        bar(x+205,y+75,x+395,y+75+54);
			        puthz(x+215, y+85, "ȫ��ҽѧ��", 24, 24, DARKGRAY);
			}
			else 
		    {
		  			setfillstyle(1,LIGHTGRAY);
		  	        bar(x+205,y+75,x+395,y+75+54);
			        puthz(x+215, y+85, "ȫ��ҽѧ��", 24, 24, WHITE);
			}
            if(Department[1]==0)
		    {
		  			setfillstyle(1,WHITE);
		  	        bar(x+205,y+75+54,x+395,y+75+54*2);
			        puthz(x+215, y+85+54, "�ڿ�", 24, 24, DARKGRAY);
			}
			else 
		    {
		  			setfillstyle(1,LIGHTGRAY);
		  	        bar(x+205,y+75+54,x+395,y+75+54*2);
			        puthz(x+215, y+85+54, "�ڿ�", 24, 24, WHITE);
			}
			if(Department[2]==0)
		    {
		  			setfillstyle(1,WHITE);
		  	        bar(x+205,y+75+54*2,x+395,y+75+54*3);
			        puthz(x+215, y+85+54*2, "���", 24, 24, DARKGRAY);
			}
			else 
		    {
		  			setfillstyle(1,LIGHTGRAY);
		  	        bar(x+205,y+75+54*2,x+395,y+75+54*3);
			        puthz(x+215, y+85+54*2, "���", 24, 24, WHITE);
			}
			if(Department[3]==0)
		    {
		  			setfillstyle(1,WHITE);
		  	        bar(x+205,y+75+54*3,x+395,y+75+54*4);
			        puthz(x+215, y+85+54*3, "����", 24, 24, DARKGRAY);
			}
			else 
		    {
		  			setfillstyle(1,LIGHTGRAY);
		  	        bar(x+205,y+75+54*3,x+395,y+75+54*4);
			        puthz(x+215, y+85+54*3, "����", 24, 24, WHITE);
			}
			if(Department[4]==0)
		    {
		  			setfillstyle(1,WHITE);
		  	        bar(x+205,y+75+54*4,x+395,y+75+54*5);
			        puthz(x+215, y+85+54*4, "����", 24, 24, DARKGRAY);
			}
			else 
		    {
		  			setfillstyle(1,LIGHTGRAY);
		  	        bar(x+205,y+75+54*4,x+395,y+75+54*5);
			        puthz(x+215, y+85+54*4, "����", 24, 24, WHITE);
			}
			if(Department[5]==0)
		    {
		  			setfillstyle(1,WHITE);
		  	        bar(x+205,y+75+54*5,x+395,y+75+54*6);
			        puthz(x+215, y+85+54*5, "��������", 24, 24, DARKGRAY);
			}
			else 
		    {
		  			setfillstyle(1,LIGHTGRAY);
		  	        bar(x+205,y+75+54*5,x+395,y+75+54*6);
			        puthz(x+215, y+85+54*5, "��������", 24, 24, WHITE);
			}//���¸������Ұ�ť����״̬ 
			for(i=0;i<6;i++) 
			{
				rectangle(x+205,y+75,x+395,y+75+54*i);
			}//�ػ��߿� 
	   } 
	   return num;
}
