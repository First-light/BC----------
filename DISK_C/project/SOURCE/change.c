#include <common.h>

/******************************************************************
	���������ȱҩ����ͳ�ƺ����� 
��д�ˣ�����
���룺MED*medicine�����߽ṹ��ָ�룩 
������int j(ȱҩ������ʾ) 
�������ܣ�ͳ��ȱҩ��ҩƷ���� 
*******************************************************************/

int check_em( MED* medicine)
{
		int j = 0; 
		FILE*fp; 
		fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r");
			while(1)
			{
			    while(1)
			    {
			    	if(feof(fp))
	                {	
	                	break;
					}
			    	fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
			    	if(medicine->inventory/10>=medicine->margin)
		            {
		            	j++;
                        break;
	                }//��⵽һ��ȱҩj��һ��������ѭ�� 
	                else if(feof(fp))
	                {	
	                	break;
					}//���ļ�ĩβ�˳� 
				}
                if(feof(fp))
				break;//�ļ�ĩβ�˳��������� 
           }
		fclose(fp);	
		return j;
}

/******************************************************************
	��ȱҩ���ѽ�����ƺ����� 
��д�ˣ�����
���룺 int x,int y��ҳ����ʾ�����Ͻ����꣩,int mark��ˢ��ҩ����ҳ������
������void 
�������ܣ�ȱҩ���ѽ������
*******************************************************************/


void Notice_Page(int x,int y,int mark)
{
	int i = 0;
	char nowchar[2]={0};
	setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    setfillstyle(1,LIGHTBLUE);
    bar(x,y,x+360,y+320);
    setfillstyle(1,BLUE);
    bar(x,y,x+360,y+30);
    setfillstyle(1,RED);
    bar(x+330,y,x+360,y+30);
    line(x,y,x,y+320);
    line(x,y,x+360,y);
    line(x+360,y,x+360,y+320);
    line(x,y+320,x+360,y+320);
    setlinestyle(0,0,3);
    setcolor(WHITE);
    line(x+335,y+5,x+355,y+25);
    line(x+335,y+25,x+355,y+5);
    puthz(x+5, y+5, "ҩƷ�漱����", 24, 24, WHITE);
    puthz(x+5, y+45, "���", 16, 16, YELLOW);
    puthz(x+45, y+45, "ҩƷ����", 16, 16, YELLOW);
    puthz(x+315, y+45, "����", 16, 16, YELLOW);
    puthz(x+120,y+280, "�뾡�������ʾ", 16, 16, RED);
    puthz(x+120,y+300, "��Ϣ����ҩƷ��", 16, 16, RED);
    puthz(x+260,y+290, "ҳ�棺", 16, 16, WHITE);
    setlinestyle(1,0,1);
    setcolor(WHITE);
    for(i=0;i<6;i++)
    {
		line(x+10,y+30+40*(i+1),x+350,y+30+40*(i+1));
	}
	setfillstyle(1,LIGHTGRAY);
    bar(x+10,y+290,x+50,y+310);
    bar(x+60,y+290,x+100,y+310);
    int_trans_char(mark,nowchar);//������ҳ��ת��Ϊchar 
    setcolor(WHITE);
    settextstyle(1,0,2) ;
    outtextxy(x+310,y+283,nowchar);//��char��ʾ�ڽ����� 
    strcpy(nowchar,"\0");
}

/******************************************************************
	��ȱҩ���ѽ������������ 
��д�ˣ�����
���룺void 
������void 
�������ܣ�ȱҩ���ѽ���ķ�ҳ���˳��������ʾ���� 
*******************************************************************/

void Notice(void)
{
	int mark=1;//ָʾÿһҳҩ����ʾ�ı�� 
	int check = 1;
	MED*medicine = (MED*)malloc(sizeof(MED));//����һ�����߽ṹ
	int i;//��������Ĳ���
	int x=120;//С��������Ͻ�x���� 
	int y=80; //С��������Ͻ�y����
	Notice_Page(x,y,mark);	
    while(1)
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
			else if (MouseX > x+10 && MouseY > y+290 && MouseX < x+50 && MouseY < 310)
			{
				MouseS = 1;
				break;
			}
			else if (MouseX > x+60 && MouseY > y+290 && MouseX < x+100 && MouseY < 310)
			{
				MouseS = 1;
				break;
			}
			else
			{
				MouseS = 0;
				break;
			}
		}//while�������λ����ʾ���״̬ 
		
		
		if(check)
		{
			char nowchar[6]={0};//��������ת�������� 
			int cell_num = 5;//ҳ�������Ŀ���� 
			FILE*fp;
			int k = 0; 
			fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r");
			clrmous(MouseX,MouseY);
			settextstyle(1,0,2);
			Notice_Page(x,y,mark); //���»��ƽ��� 
			for(i= 1;i < cell_num + (mark-1)*cell_num +1 ;i++)
			{	
			    while(1)
			    {
			    	fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
			    	if(medicine->inventory/10>=medicine->margin)
		            {
                        break;
	                }
	                else if(feof(fp))
	                {
	                	
	                	break;
					}
				}//��Ѱȱҩ����Ŀ 
			if(!feof(fp)||medicine->inventory/10>=medicine->margin)
			{
					if( i < (mark-1)*cell_num +1 )
				{		
				}
				else
				{
					if(medicine->ID<1000&&medicine->ID>0)
					{
						int_trans_char(i/*5*(mark-1)+k+1*/,nowchar);
						outtextxy(x+15,y+85+40*k,nowchar);
						strcpy(nowchar,"\0");
						outtextxy(x+45,y+85+40*k,medicine->name);
						int_trans_char(medicine->margin,nowchar);
						outtextxy(x+315,y+85+40*k,nowchar);
						strcpy(nowchar,"\0");						
					}
					k++ ;
				}
			}//��ȱҩ��Ŀ������� 
				if(feof(fp))break;
			}
			fclose(fp);		
			check = 0;//����״̬ 
		}
		
        if(mouse_press(x+330,y,x+360,y+30) == 1)
		{
		  delay(200);
		  break; 
		}//�˳�С���� 
        else if(mouse_press(x+10,y+290,x+50,y+310) == 1)
		{
			mark--;//mark��fscanf��ȡ��Ŀ���٣��ļ�ָ����ǰ��ˢ��ʱʵ�ַ�ҳ 
			mark = max(mark,1);//��ֹmark���0 
		  strcpy(medicine->name,"\0");
		  medicine->margin=0;
		  medicine->price=0;
		  medicine->inventory=0;//��ҳʱ���ù���ָ�� 
		  check = 1;//����Ҫ�ı�״̬ 
		  delay(200);
		  continue; 
		}//��ҩ�� 
		else if(mouse_press(x+60,y+290,x+100,y+310) == 1)
		{
			mark++;//mark��fscanf��ȡ��Ŀ���ӣ��ļ�ָ�뿿��ˢ��ʱʵ�ַ�ҳ 
		  strcpy(medicine->name,"\0");
		  medicine->margin=0;
		  medicine->price=0;
		  medicine->inventory=0;//��ҳʱ���ù���ָ�� 
		  delay(200);
		  check = 1;//����Ҫ�ı�״̬ 
		  continue; 
		}//�ҷ�ҩ�� 
  }
}
