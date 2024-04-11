#include "string.h"
#include "LVup.h"
#include "struct.h"
#include <stdio.h>

/******************************************************************
		�����һ��ߺ�����
��д�ˣ�������
���룺int* input,char* inputc,PatientData* head,int style
������PatientData*
�������ܣ����ҵ�ָ���Һź���Ļ���
*******************************************************************/
PatientData* findpat(char* inputc,PatientData* head,int style)//head
{
	PatientData* back = NULL;
	PatientData* m = head->next;
	int ruler = 0;
	int check = 0;
	while(m != NULL)
	{
		if(style)
		{
			char rulerc[5] = {0};
			strcpy(rulerc,inputc);
			ruler = INT_CHAR_Change(rulerc);
			check = (m)->numreg; 
			if(check == ruler)//>_<) 
			{//�����ݷ���Ҫ��
				back = m;
				break;
			}
		}
		m = m->next;
	}		
	return back;
}

/******************************************************************
		��ȡҩ������������
��д�ˣ�������
���룺PatientData* m,int start
������void
�������ܣ���Ҫ�������ߵ�ȡҩ���룬���������������򣬱�֤�����Ҵ�1��ʼ
*******************************************************************/
void Number_no_same(PatientData* m,int start)//head
{
	PatientData*p2 = m;
	PatientData*p = m->next;
	int n = 0;
	do{//ð������
		n = 0;
		p2 = m;
		p = p2->next;
		while((p->next)->next != NULL && p->next != NULL)
		{
			if(p->nummed > (p->next)->nummed)
			{
				PatientData* t1 = p;
				PatientData* t2 = p->next;
				PatientData* t3 = (p->next)->next;
				p2->next = t2;
				t2 ->next = t1;
				t1 ->next = t3;
				p = p2->next;
				n = 1;
			}
			p2 = p2->next;
			p = p2->next;
		}	
	}while(n != 0);
	p = m->next;
	n = start;
	while(p != NULL)
	{
		if(p->payreg >= 2 &&p->nummed != 0)//��ȡҩ���벻Ϊ0�Ļ�����������
		{
			p->nummed = n;
			n++;
		}
		else
		{
			p->nummed = 0;
		}
		p = p->next;
	}
}


/******************************************************************
		��ҩ������ת�亯��������
��д�ˣ�������
���룺MED* m
������void
�������ܣ���ҩ��ҩ�����ݶ�ȡ��ת��Ϊx y����λ�ã����ڻ����˶���
*******************************************************************/
void NO_XY_flash(MED* m)
{
	MED* m2 = m;
	while(m2 != NULL)
	{
		(m2)->x =((m2)->Store_No) % 6 ;
		(m2)->y =((m2)->Store_No) / 6 ;
		if((m2)-> Store_No >= 18) 
		{
		 	(m2)->y += 2;
		}
		m2 = m2->next;
	}
}

/******************************************************************
		��charתint������
��д�ˣ�������
���룺char* ar
������void
�������ܣ���ֵ����ת��
*******************************************************************/
int INT_CHAR_Change(char* ar)
{
	int i = 0;
	int back = 0;
	int m = 0;
	
	while(ar[i] != '\0')
	{
		i++;
	}
	for(;i>0;i--)
	{
		int num = 1;
		int j = 0;
		for(j=i;j>1;j--)
		{
			num *= 10;
		}
		back += num*(ar[m] - '0');
		
		m++;
	}
	return back;
}
/******************************************************************
		������0����charתint������
��д�ˣ�������
���룺char* ar��n��ȡλ��
������void
�������ܣ���ֵ����ת��
*******************************************************************/
int INT_CHAR_Change2(char* ar,int n)
{
	int i = 0;
	int back = 0;
	int m = 0;
	while(ar[i] == '0' && ar[i] != '\0'&& i<n)
	{
		i++;
	}
	while(ar[i] != '\0'&& i<n)
	{
		i++;
	}
	for(;i>0;i--)
	{
		int num = 1;
		int j = 0;
		for(j=i;j>1;j--)
		{
			num *= 10;
		}
		back += num*(ar[m] - '0');
		m++;
	}
	return back;
}

/******************************************************************
		��intת����0����char������
��д�ˣ�������
���룺char* ar2,int b,int n��ȡλ��
������void
�������ܣ���ֵ����ת��
*******************************************************************/
void CHAR_INT_Change2(char* ar2,int b,int n)
{//intתchar*���ͺ���
	int i;
	int j;
	char ar[30] = {0};
	for(i=0;i <n;i++)
	{//��int��λת��Ϊchar��
		ar[i] = '0' + (b % 10);
		b /= 10;
		if(b == 0)
		{//���int���꣬����ѭ��
			break;
		}
	}
	strcpy(ar2,"\0");
	i = 0;
	for(j = n-1;j>=0;j--,i++)
	{
		ar2[j] = ar[i];//�����鵹��
		if(ar[i] == 0){
			ar2[j] = '0';
		}
	} 
}//����޸ģ�2023/4/13

/******************************************************************
		��intתchar������
��д�ˣ�������
���룺char* ar2,int b
������void
�������ܣ���ֵ����ת��
*******************************************************************/
void CHAR_INT_Change(char* ar2,int b)
{//intתchar*���ͺ���

	int i;
	int j;
	char ar[30] = {0};
	for(i=0;i <30;i++)
	{//��int��λת��Ϊchar��
		ar[i] = '0' + (b % 10);
		b /= 10;
		if(b == 0)
		{//���int���꣬����ѭ��
			break;
		}
	}
	strcpy(ar2,"\0");
	for(j = 0;i>=0;i--,j++){
		ar2[i] = ar[j];//�����鵹��
	} 
}//����޸ģ�2023/4/1
