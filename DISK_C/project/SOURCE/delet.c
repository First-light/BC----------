#include <common.h>

/******************************************************************
	��ҩ���ѡ���������� 
��д�ˣ�����
���룺int x,int y���жϵ���λ�ã� 
������void 
�������ܣ�����ѡ��ҩƷ 
*******************************************************************/
void choose(int x,int y)
{
	setfillstyle(1,YELLOW);
	bar(x, y, x+20,y+20 );
} 
 
 /******************************************************************
	������ѡ�Ƿ��ظ������� 
��д��: ������
���룺int*a,int k,int b 
������int back 
�������ܣ�����ѡ��ҩƷ 
*******************************************************************/
 int check(int*a,int k,int b)
 {
 	int back = 1;
 	int i=0;
	k = 34;
 	for(i=0;i<k;i++)
 	{
     if(a[i]==b)
	 {
	 	back = 0;
	 	break;
	 } 
	}
	return back;
 } 

/******************************************************************
	��ɾ��ѡ������ 
��д�ˣ������� 
���룺int*Delet_Item,int ID_t,int *ifdelet,int num
������void 
�������ܣ��洢��ѡģʽ��Ҫɾ����ҩ��ID,�����б������,��ѡ���ҩ�����
*******************************************************************/
void deletcheck(int*Delet_Item,int ID_t,int *ifdelet,int num)
{
	int j = 34;
	int in = 0;
			if(check(Delet_Item,j,ID_t))
			{
				while(in < 34){
					if(Delet_Item[in] == 0)
					{
						Delet_Item[in]=ID_t;
						break;
					}
				in++;
				}
				in = 0;
				while(in < 34)
				{
					if(ifdelet[in] == 0)
					{
						ifdelet[in]=num;
						break;
					}
				in++;
				}
			}
			else
			{
				while(in < 34){
					if(Delet_Item[in] == ID_t)
					{
						Delet_Item[in]= 0 ;
						break;
					}
				in++;
				}
				in = 0;
				while(in < 34)
				{
					if(ifdelet[in] == num)
					{
						ifdelet[in]= 0;
						break;
					}
				in++;
				}		
			}	
}

/******************************************************************
	��ҩ���ѡɾ����ģʽ������ 
��д�ˣ�����  ������ 
���룺MED*medicine ,int* markout
������void 
�������ܣ�����ҩƷ��ѡɾ��ģʽ��ʵ��ҩƷ�Ķ�ѡ��ɾ������ҳ���˳� 
*******************************************************************/
void DrugDelet(MED*medicine ,int* markout)
{
	int page = 0;
	int mark = *markout;//ָʾÿһҳҩ����ʾ�ı��
	int i=0;//ѭ��������
	int ID_t[5]={0};
	int j=0;//���Ŀǰ��ѡ���������
	int ifdelet[34] = {0};
	int Delet_Item[34]={0};
	int cell_num = 5;
	int flash = 1;

	MED*list = reopen(medicine);
	MED*m = list->next;
	clrmous(MouseX,MouseY);
	settextstyle(1,0,2);

	strcpy(medicine->name,"\0");
	medicine->margin=0;
	medicine->price=0;
	medicine->inventory=0;

	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);
		while(1)
		{

			if (MouseX > 600 && MouseY > 0 && MouseX < 640 && MouseY < 40)
			{
				MouseS = 1;
				break;
			}//�˳�
			else if (MouseX > 160 && MouseY > 360 && MouseX < 220 && MouseY < 400)
			{
				MouseS = 1;
				break;
			}//ɾ��
			else if (MouseX > 320 && MouseY > 360 && MouseX < 360 && MouseY < 400)
			{
				MouseS = 1;
				break;
			}//��
			else if (MouseX > 380 && MouseY > 360 && MouseX < 420 && MouseY < 400)
			{
				MouseS = 1;
				break;
			}//�ҷ�
			else if (MouseX > 80 && MouseY > 80 && MouseX < 120 && MouseY < 120)
			{
				MouseS = 1;
				break;
			}//��ѡ��һ��
			else if (MouseX > 80 && MouseY > 120 && MouseX < 120 && MouseY < 160)
			{
				MouseS = 1;
				break;
			}//��ѡ�ڶ���
			else if (MouseX > 80 && MouseY > 160 && MouseX < 120 && MouseY < 200)
			{
				MouseS = 1;
				break;
			}//��ѡ������
			else if (MouseX > 80 && MouseY > 200 && MouseX < 120 && MouseY < 240)
			{
				MouseS = 1;
				break;
			}//��ѡ���ĸ�
			else if (MouseX > 80 && MouseY > 240 && MouseX < 120 && MouseY < 280)
			{
				MouseS = 1;
				break;
			}//��ѡ�����
			else
			{
				MouseS = 0;
				break;
			}
		}//while�������λ����ʾ���״̬

		for(i=0;i<34;i++)
		{
			if(Delet_Item[j]!=0)
			{
				j++;
			}
		} //�ж�������

		if(flash)
		{
				char nowchar[6]={0};//��������ת��������
				int k = 0;
				FILE*fp;
				fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r+");
				clrmous(MouseX,MouseY);
				settextstyle(1,0,2);
				DrugStorManagePg(medicine);
				for(i= 1;i<cell_num + (mark-1)*cell_num +1;i++)
				{
					fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
					if( i <=(mark-1)*cell_num )
					{
					}
					else
					{
						if(medicine->ID<1000&&medicine->ID>0)
						{

							int_trans_char(5*(mark-1)+k+1,nowchar);
							outtextxy(120,120+40*k,nowchar);
							ID_t[k] =medicine->ID;
							strcpy(nowchar,"\0");
							outtextxy(160,120+40*k,medicine->name);
							strcpy(nowchar,"\0");
							int_trans_char(medicine->price,nowchar);
							outtextxy(440,120+40*k,nowchar);
							strcpy(nowchar,"\0");
							int_trans_char(medicine->Store_No,nowchar) ;
							outtextxy(480,120+40*k,nowchar);
							strcpy(nowchar,"\0");
							int_trans_char(medicine->margin,nowchar);
							outtextxy(520,120+40*k,nowchar);
							strcpy(nowchar,"\0");
						}
						k++ ;
					}
					if(feof(fp))break;
				}

			fclose(fp);
			for(i=(mark-1)*5+1;i<mark*5+1;i++)
			{
				int go = 0;
				while(go<34){
					if(ifdelet[go]==i)
					{
						choose(90,90+40*((i-1)%cell_num + 1));
					}
					go++;
				}
			} //��ѡ��������
			flash = 0;
		}

		if(mouse_press(600, 0, 600+40 , 0 + 40) == 1)
		{
		  delay(200);
		  break;
		}//�˳�ɾ��ģʽ
		else if(mouse_press(160,360,220,400) == 1)
		{
		  if(j == 0)
			{
				puthz(230, 430, "��ѡ��Ҫɾ����ҩƷ", 16, 16, DARKGRAY);
				delay(600);
				setfillstyle(1,WHITE);
				bar(230, 430, 410,450 );
				delay(200);
			}
		  else
			{
				deletNode(list,Delet_Item);
				puthz(230, 430, "ɾ���ɹ�", 16, 16, DARKGRAY);
				delay(600);
				setfillstyle(1,WHITE);
				bar(230, 430, 410,450 );
				delay(200);
				break;
			}
		}//ҩƷɾ��
		else if(mouse_press(250,360,290,400) == 1)
		{
			mark--;
			mark = max(mark,1);
//		  mark=turnleft(medicine,nowchar,mark);
			strcpy(medicine->name,"\0");
			medicine->margin=0;
			medicine->price=0;
			medicine->inventory=0;
			flash = 1;
			delay(200);
		}//��ҩ��
		else if(mouse_press(310,360,350,400) == 1)
		{
			mark++;
			strcpy(medicine->name,"\0");
			medicine->margin=0;
			medicine->price=0;
			medicine->inventory=0;
			flash = 1;
			delay(200);
		}//�ҷ�ҩ�� 
		else if(mouse_press(80,120,120,160) == 1)
		{
			deletcheck(Delet_Item,ID_t[0],ifdelet,5*(mark-1)+1);
			flash = 1;
		  delay(200);
		}//ѡ������һ��
		 
		else if(mouse_press(80,120+40,120,160+40) == 1)
		{
			deletcheck(Delet_Item,ID_t[1],ifdelet,5*(mark-1)+2);
			flash = 1;
		  delay(200);
		}//ѡ�����ڶ���
		else if(mouse_press(80,160+40,120,200+40) == 1)
		{
			deletcheck(Delet_Item,ID_t[2],ifdelet,5*(mark-1)+3);
			flash = 1;
		  delay(200);
		}//ѡ����������
		else if(mouse_press(80,200+40,120,240+40) == 1)
		{
			deletcheck(Delet_Item,ID_t[3],ifdelet,5*(mark-1)+4);
			flash = 1;
		  delay(200);
		}//ѡ�������ĸ�
		else if(mouse_press(80,240+40,120,280+40) == 1)
		{
			deletcheck(Delet_Item,ID_t[4],ifdelet,5*(mark-1)+5);
			flash = 1;
		  delay(200);
		}//ѡ��������� 
		else
		{
		}
		j = 0;
   }
   m = list->next;
	while(m != NULL)
	{
		free(list);
		list = m;
		m = m->next;
	}
	free(list);//�ͷ��������
   *markout = mark;
}
