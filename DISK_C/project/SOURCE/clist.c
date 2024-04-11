#include "LVup.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/******************************************************************
		����Ϸ������뺯����
��д�ˣ�������
���룺PatientData* p,FILE * pf
������int
�������ܣ����ļ��Ļ���������ݵ�������
*******************************************************************/
int ListRead(PatientData* p,FILE * pf)
{
	int i = 0;//����
	for( ;i < 6 ;)
	{//ѭ��������Ϸ�����������6����������ֹ����Խ�磡��
		char in = fgetc(pf);
		if( in == '&')
		{//��⵽&���뷽��
		fscanf(pf,"%d %d %d",
		&((p)->medicine_list[i][0]),
		&((p)->medicine_list[i][1]),
		&((p)->medicine_list[i][2]));
		i++;
		}
		else if(in == '$'||in == -1)
		{//��������ļ���β�����ߵ��˽�������
			for(;i<6;i++)
			//i<6��ֹ����Խ��
			{//��ʣ�µ����鵥Ԫ��ʼ��Ϊ0����ֹ���δ��ʼ�������ݵ��±�����
			(p)->medicine_list[i][0] = 0;
			(p)->medicine_list[i][1] = 0;
			(p)->medicine_list[i][2] = 0;
			}
			break;//�˳�ѭ��
		}
	}	
	return -1;//��in2��ֵ���˳�ѭ��
}

/******************************************************************
		��������������
��д�ˣ�������
���룺int n��ͷ�ڵ�����Ľڵ����
������ͷ�ڵ�
�������ܣ�����ָ����С������
*******************************************************************/
PatientData* creat(int n)
{
	int i;//ѭ������
	PatientData *head, *conti , *end;//����ͷ�ڵ㣬��ͨ�ڵ㣬β���ڵ�
	head = (PatientData *)malloc(sizeof(PatientData));//�����ַ
	end = head;//����ǿ�������ͷβ�ڵ�һ��
	for(i = 0 ; i < n ;i++)
	{
		conti = (PatientData*) malloc(sizeof(PatientData));//����һ���µĽڵ�
		end->next = conti;//��β�ڵ��next�����µĽڵ�
		end = conti;//���µĽڵ㶨��Ϊβ�ڵ�
	}
	end->next = NULL;//��β�ڵ��next��Ա��������װ����
	return head;
}

/******************************************************************
		���������ݵ��뺯����
��д�ˣ�������
���룺PatientData* p,int n,FILE * pf,int state��ģʽ��
������void
�������ܣ����ļ����ݰ���ָ����ʽ��������
*******************************************************************/
void ListInput(PatientData* p,int n,FILE * pf,int state)
{//�����ȡ����
//nΪҪ�޸ĵĵ�n���ڵ�
//state ��ʾ����ģʽ
	char in2 = 0;
	if(p != NULL)
	{//���ڵ��Ƿ���ڣ���ֹ����
		for(;in2 != -1;)
		{//����ļ�������ֹͣ��ȡ
			in2 = fgetc(pf);//��char��ȡ�ļ����������
			if( in2 == '#')
			{//����#��ʼ����
				char p_name[20] = {0};
				fscanf(pf,
					" %s %d %d %d %d %d %s %s %d %d $",
					p_name,
					&((p)->payreg),
					&((p)->paymed),
					&((p)->numreg),
					&((p)->nummed),
					&((p)->window),
					(p)->doctor,
					(p)->timer,
					&((p)->sexual),
					&((p)->age)
				);//��ʽ����ȡ
				strcpy( (p)->name, p_name);
				switch (state)
				{//ģʽ���
					case 1:
						if((p)->numreg == n)
						{//�����ݷ���Ҫ��
						in2 = ListRead(p,pf);//�������ݣ�����-1��ֵ��in2���˳�ѭ�����˳�����
						}
						break;
					case 0:
						//�������ݣ�����-1��ֵ��in2���˳�ѭ�����˳�����
						in2 = ListRead(p,pf);
						break;
					default:
						break;
				}
			}
			else if(in2 == -1)
			{//������ļ�����ʱҲû�ҵ�����Ҫ������ݣ�������������ʼ��Ϊ0����ֹ����ֱ�����û�г�ʼ�����±���
				int i3=0;
				strcpy( (p)->name, "\0");
				strcpy( (p)->doctor, "\0");
				strcpy( (p)->timer, "\0");
				((p)->payreg) = 0;
				((p)->paymed)= 0;
				((p)->numreg)= 0;
				((p)->nummed)= 0;
				((p)->window)= 0;
				((p)->sexual) = 0;
				((p)->age) = 0;
				for(;i3<6;i3++){
				(p)->medicine_list[i3][0] = 0;
				(p)->medicine_list[i3][1] = 0;
				(p)->medicine_list[i3][2] = 0;
				}
			break;//�ļ������˳�ѭ��
			}
		}
	}
}



/******************************************************************
		��ɾ����������
��д�ˣ�������
���룺PatientData* list
������void
�������ܣ�������ɾ��
*******************************************************************/
void deletall(PatientData* list)
{
	int i = 0;
	PatientData* m = list;
	for(; m != NULL;i++)
	{
		list = (list)->next;
		free(m);
		m = list;
	}
}
//void delet(PatientData* list,int n){
//	PatientData*p = (list)->next;
//	PatientData*in = list;
//	int i = 0;//����ѭ������
//	while(i<n && (p)->next != NULL){
//		in = p;
//		p = p->next;
//		i ++;
//	}
//	if(p != NULL){
//		in->next = p->next;
//		free(p);
//	}
//	else{
//	}
//}


/******************************************************************
		���������ڵ㺯����
��д�ˣ�������
���룺PatientData* list,int n
������void
�������ܣ��������ָ��λ�ò���ڵ�
*******************************************************************/
void insert(PatientData* list,int n)
{
	PatientData*p = list;
	PatientData*in;
	int i = 0;
	while(i<n && (p) != NULL)
	{
		p = p->next;
		i ++;
	}
	in = (PatientData*) malloc(sizeof(PatientData));
	{
		//�����ʼ��Ϊ0�Ľڵ�
		int i3=0;
		strcpy( (in)->name, "A");
		strcpy( (in)->doctor, "A");
		strcpy( (in)->timer, "A");
		((in)->payreg) = 0;
		((in)->paymed)= 0;
		((in)->numreg)= 0;
		((in)->nummed)= 0;
		((in)->window)= 0;
		((in)->sexual)= 0;
		((in)->age)= 0;
		for(;i3<6;i3++)
		{
			(in)->medicine_list[i3][0] = 0;
			(in)->medicine_list[i3][1] = 0;
			(in)->medicine_list[i3][2] = 0;
		}
	}
	in->next = p->next;
	p->next = in;
}

/******************************************************************
		������ڵ��޸ĺ�����
��д�ˣ�������
���룺PatientData* list,PatientData* input,int n,int state
������void
�������ܣ��ڵ����ݸ���
*******************************************************************/
void Listchange(PatientData* list,PatientData* input,int n,int state)
{
	PatientData*p = list;
	int i = 0;
	switch (state)
	{//ģʽ���
		case 1:
			while((p)->next != NULL)
			{
				if((p)->numreg == n)
				{//�����ݷ���Ҫ��
					break;
				}else{
				p = p->next;
				}
			}
		case 0:
			while(i<n && p != NULL)
			{
				p = p->next;
				i ++;
			}
			break;
		default:
			break;
	}
	if(p!=NULL)
	{
	int i3 = 0;
			 strcpy( (p)->name, (input)->name);
			 strcpy( (p)->doctor, (input)->doctor);
			 strcpy( (p)->timer, (input)->timer);
			((p)->payreg) = ((input)->payreg);
			((p)->paymed)=((input)->paymed);
			((p)->numreg)= ((input)->numreg);
			((p)->nummed)= ((input)->nummed);
			((p)->window)= ((input)->window);
			((p)->sexual)= ((input)->sexual);
			((p)->age)= ((input)->age);
			for(;i3<6;i3++)
			{
				(p)->medicine_list[i3][0] = (input)->medicine_list[i3][0];/////////////
				(p)->medicine_list[i3][1] = (input)->medicine_list[i3][1];///////////////
				(p)->medicine_list[i3][2] = (input)->medicine_list[i3][2];///////////////
			}
	}
}
