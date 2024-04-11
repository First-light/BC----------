#include <common.h>
/******************************************************************
		���������ݵ��뺯����
��д�ˣ�������
���룺PatientData* p
������void
�������ܣ����ļ���Ļ������ݵ��뵽����
*******************************************************************/
void Patient_Setup (PatientData* p)
{
PatientData* m = p;
int i = 1;
int n = 0;///ָ����Ĭ������������
char in0;
FILE * pf = fopen("C:\\project\\DATABASE\\PAT_SET.txt","r");
	if ( pf == NULL )
	{//����Ҳ����ļ���������󱨸�
		printf("can not find the data file!!!\n");
	}
	else
	{
		while(in0 != -1)
		{
			in0 = fgetc(pf);
			if(in0 == '*')//�ҵ��������
			{
				fscanf(pf,"%d",&n);
				printf("found n = %d\n",n);
				break ;
			}
		}
		while(i <= n)
		{
			rewind(pf);
			if(m->next == NULL){//����β�ڵ�
				insert(m,0);//�����µĽڵ�
			}
			ListInput(m->next,i,pf,1) ;
			m = m->next;
			i ++;
		}
		fclose(pf);
	}
}

/******************************************************************
		���������ݵ���������
��д�ˣ�������
���룺PatientData* p
������void
�������ܣ�������������ݸ�ʽ�������ļ���
*******************************************************************/
void Patient_Output (PatientData* p)
{
int n = 30;///ָ����Ĭ������������
int num = 0;
int i = 0;
int havestart = 0;
PatientData* m = p;
FILE * PF = fopen("C:\\project\\DATABASE\\PAT_SET.txt","w+");
	m = m->next;//����ͷ�ڵ�
	while( m != NULL )
	{
		m = m->next;
		i ++;
		num++;
	}
	m = (p)->next;//����ͷ�ڵ�
	n = num;
	i = 0;
	while(num>0)
		{
			int i2;
			fprintf(PF,"# %s %d %d %d %d %d %s %s %d %d $",
			(m)->name,
			((m)->payreg),
			((m)->paymed),
			((m)->numreg),
			((m)->nummed),
			((m)->window),
			((m)->doctor),
			((m)->timer),
			((m)->sexual),
			((m)->age));
			for(i2=0;i2<6;i2++)
			{
				fprintf(PF,"&%d %d %d",
				(m)->medicine_list[i2][0],
				(m)->medicine_list[i2][1],
				(m)->medicine_list[i2][2]);
			}
			fprintf(PF,"$\n");
			m = m->next;
			num--;
		}
		if(havestart)
		{
			fprintf(PF,"%d\n",n);
		}
		else
		{
			fprintf(PF,"*%d\n",n);
		}
	fprintf(PF,"| name | state | money | number | call | divide | check | time | sex | age | type count state |\n",n);
	fprintf(PF,"\n\n\n\n\n");
	fclose(PF);
}

/*
�ȴ�ȡҩ�Ļ���ģ��
# sample 2 46 53 2 2 1511 202404112049 0 12 $&5 2 1&7 2 1&12 2 1&0 0 0&0 0 0&0 0 0$
# sample 2 46 55 2 2 1511 202404112049 0 12 $&5 2 1&7 2 1&12 2 1&0 0 0&0 0 0&0 0 0$
# sample 2 46 56 2 2 1511 202404112049 0 12 $&5 2 1&7 2 1&12 2 1&0 0 0&0 0 0&0 0 0$
# sample 2 46 57 2 2 1511 202404112049 0 12 $&5 2 1&7 2 1&12 2 1&0 0 0&0 0 0&0 0 0$
# sample 2 46 58 2 2 1511 202404112049 0 12 $&5 2 1&7 2 1&12 2 1&0 0 0&0 0 0&0 0 0$
# sample 2 46 59 2 2 1511 202404112049 0 12 $&5 2 1&7 2 1&12 2 1&0 0 0&0 0 0&0 0 0$
# sample 2 46 60 2 2 1511 202404112049 0 12 $&5 2 1&7 2 1&12 2 1&0 0 0&0 0 0&0 0 0$
# sample 2 46 61 2 2 1511 202404112049 0 12 $&5 2 1&7 2 1&12 2 1&0 0 0&0 0 0&0 0 0$
# sample 2 46 62 2 2 1511 202404112049 0 12 $&5 2 1&7 2 1&12 2 1&0 0 0&0 0 0&0 0 0$
*/