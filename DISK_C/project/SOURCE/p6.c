#include <common.h>

/******************************************************************
	�����߽ɷѺ����� 
��д�ˣ����� ������
���룺int* IDnumber
������int
�������ܣ� ���л��߽ɷ�
*******************************************************************/
int p6(int *IDnumber)
{
	int page = 0;
	int no = 0;
	int pan = 0;
	PatientData* p_patient = creat(0);
	PatientData* p_patient_head = p_patient;
	PatientData*p = p_patient->next;
	no = *IDnumber;
	Patient_Setup (p_patient_head); 
	p_patient = p_patient->next;//����ͷ�ڵ�
	p = p_patient_head->next;  				
	while(p != NULL)
	{
		if((p)->numreg == no && (p)->numreg > 0)
		{//�����ݷ���Ҫ
		  	if((p)->payreg < 1)
			{
		  		cleardevice();
				setfillstyle(1,WHITE);
				bar(0, 0,640 ,480);
		  		setfillstyle(3,DARKGRAY);
		  		bar(230, 390,260+153 ,400+34);
		  		setfillstyle(1,WHITE);
		  		bar(235, 395,255+153 ,395+34);
		  		puthz(260,400,"��δ���",24,32,RED);
		  		page = 1;
		  		delay(500);
		  		Notice_Page_p1();
		  		pan = 1;
		  		break;
		  	}
			else if((p)->payreg >= 2)
			{
		  		cleardevice();
				setfillstyle(1,WHITE);
				bar(0, 0,640 ,480);
				setfillstyle(3,DARKGRAY);
		  		bar(230, 390,260+153 ,400+34);
		  		setfillstyle(1,WHITE);
		 		bar(235, 395,255+153 ,395+34);
		  		puthz(260,400,"���ѽɷ�",24,32,RED);
		  		page = 1;
		  		delay(500);
		  		Notice_Page_p1();
		  		pan = 1;
		 		break;
			}
			else
			{
		  		pan = 1;
				if((p)->numreg == no)
				{
					int num = 0;
					int number = 1;
					PatientData*p2 =p_patient_head->next;
					while((p2) != NULL)
					{
						if((p2)->nummed == number)
						{
							number++;
							p2 = p_patient_head->next;
						}
					p2 = p2->next;
					}
					(p)->nummed = 0;
					(p)->payreg = 5;	
					for(num = 0;num < 6 ;num++)
					{
						if((p)->medicine_list[num][0] != 0)
						{
							(p)->nummed = number;
							(p)->payreg = 2;
							break;							
						}
					}
					page = Result_List(p);	  						
				}
				Patient_Output(p_patient_head);
				deletall(p_patient_head);
				page = 1;
		  		break;	
		  	}
		}
		p = p->next;
	}
	if(!pan)
	{
		cleardevice();
		setfillstyle(1,WHITE);
		bar(0, 0,640 ,480);
		setfillstyle(3,DARKGRAY);
		bar(230, 390,260+153 ,400+34);
		setfillstyle(1,WHITE);
		bar(235, 395,255+153 ,395+34);
		puthz(260,400,"���޴˺�",24,32,RED);
		page = 1;
		delay(500);
		Notice_Page_p1();
	}		
	delay(200);
	return page;
}   
