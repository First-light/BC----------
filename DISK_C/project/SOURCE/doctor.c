#include "LVup.h"
#include <stdio.h>
#include <string.h>


/******************************************************************
		������ҽ������������
��д�ˣ�������
���룺char* input,char* check
������int���ȽϽ����
�������ܣ�������ҽ��������Աȣ�����Ƿ����Ҫ��
*******************************************************************/
int DoctorCheck(char* input,char* check)
{
	int back = 0;
	char KS; 
	char* doctor;
	int DC;
	char MZ_2 ;
	char KS_2; 
	char* doctor_2;
	int DC_2;
	MZ_2 = input[0];
	KS_2 = input[1]; 
	doctor_2 = &input[1];
	DC_2 = INT_CHAR_Change2(doctor_2,3);
	KS = check[1]; 
	doctor = &check[1];
	DC = INT_CHAR_Change2(doctor,3);
	if(DC_2%100  == 0)
	{
		if(KS_2 == '0')
		{
			if(MZ_2 == '0')
			{
				back = 1;
			}
			else if(MZ_2 == '1')
			{
				if((DC%100)/10 == 1)
				{
					back = 1;
				}
			}
			else if(MZ_2 == '2')
			{
				if((DC%100)/10 == 0)
				{
					back = 1;
				}
			}
			else if(MZ_2 == '3')
			{
				if(DC == 701)
				{
					back = 1;
				}
			}	
		}
		else
		{
			if(KS_2 == KS)
			{	
				back = 1;
			}			
		}
	}
	else
	{
		if(DC == DC_2)
		{	
			back = 1;
		}
	}
	return back;
}

/******************************************************************
		������ҽ��չʾ������
��д�ˣ�������
���룺char* input,char* output,int mode
������void
�������ܣ�������ҽ���ڽṹ���еĴ�������char��ת��Ϊ���֣�������output
*******************************************************************/
void DoctorShow(char* input,char* output,int mode)
{
	char MZ ;
	char KS; 
	char* doctor;
	int DC;
	MZ = input[0];
	KS = input[1]; 
	doctor = &input[1];
	DC = INT_CHAR_Change2(doctor,3);
	strcpy(output,"\0");
	switch (mode) 
	{
	case 1:
		switch (MZ) 
		{
			case '1':strcpy(output,"��ͨ����");break;
			case '2':strcpy(output,"ר������");break;
			case '3':strcpy(output,"����");break;
			default:strcpy(output,"δ֪");break;
		}
		break;
	case 2:
		switch (KS) 
		{
			case '1':strcpy(output,"ȫ��ҽѧ��");break;
			case '2':strcpy(output,"�ڿ�");break;
			case '3':strcpy(output,"���");break;
			case '4':strcpy(output,"����");break;
			case '5':strcpy(output,"����");break;
			case '6':strcpy(output,"��������");break;
			case '7':strcpy(output,"����");break;
			default:strcpy(output,"δ֪");break;
		}		
		break;
	case 3:
		switch (DC) 
		{
			case 701:strcpy(output,"Ф����");break;
			
			case 101:strcpy(output,"�ܷ���");break;
			case 102:strcpy(output,"����");break;
			case 103:strcpy(output,"ղ�̶�");break;
			case 111:strcpy(output,"������");break;
			case 112:strcpy(output,"Ф��");break;
			case 113:strcpy(output,"������");break;
			case 114:strcpy(output,"������");break;
			
			case 201:strcpy(output,"��Ԫ");break;
			case 202:strcpy(output,"���");break;
			case 211:strcpy(output,"�ű��");break;
			case 212:strcpy(output,"����");break;
			case 213:strcpy(output,"�����");break;
			case 214:strcpy(output,"����");break;
			
			case 301:strcpy(output,"����");break;
			case 302:strcpy(output,"³���");break;
			case 311:strcpy(output,"�½�");break;
			case 312:strcpy(output,"�");break;
			case 313:strcpy(output,"��ʢ");break;
			case 314:strcpy(output,"����");break;
			
			case 401:strcpy(output,"�²�");break;
			case 411:strcpy(output,"������");break;
			case 412:strcpy(output,"���");break;
			
			case 501:strcpy(output,"����");break;
			case 502:strcpy(output,"������");break;
			case 511:strcpy(output,"�־�");break;
			case 512:strcpy(output,"������");break;
			
			case 601:strcpy(output,"����ƽ");break;
			case 602:strcpy(output,"Ԭ����");break;
			case 603:strcpy(output,"Фǿ");break;
			case 604:strcpy(output,"����");break;
			case 605:strcpy(output,"����");break;
			case 606:strcpy(output,"�׺�ƽ");break;			
			case 611:strcpy(output,"����");break;
			case 612:strcpy(output,"���");break;
			default:strcpy(output,"δ֪");break;
		}	
		break;
	default:
		break;
	}
}
