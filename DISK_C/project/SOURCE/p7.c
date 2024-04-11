#include "common.h"
#include<bios.h>

void page7_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0, 0, 640,480 );
    frameline2();
}
int p7(int *IDnumber)
{
		int button[5] = {1,1,1,1,1}	;
		int page = 0;
		int page_t = 0;
		int robotflash = 1;
		int robotflash2 = 1;
		int show = -1;
		int button2[3]={1,1,1};
		int buttondata3[9] = {485,70,1,127,62,24,32,-25,2};
		int sheet_page = 1;
		int sheet_data[7]= {30,30,120,80,380,185,0};
		int check2[10] = {1,1,1,1,1,1,1,1,1,1};
		int yes = 0;
		int ID = 0;
		int IN = 1;
		struct robot ro[2] =
		{
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0}
		};
		int timing2 = 5;
		int timing = 201;
		int pan = 1;
		int drawdata[2] = {20,140};
		char a[7] = {0};
		
		MED* medicine = (MED*)malloc(sizeof(MED));
		MED* medi_head =reopen(medicine);
		MED* mt = medi_head->next;
		
		PatientData* p16_patient = creat(0);
		PatientData* p16_patient_head = p16_patient;
		PatientData*p;
		p16_patient = p16_patient->next;//����ͷ�ڵ�
		
		Patient_Setup (p16_patient_head);
		Robot_Setup (&ro[0],0);
		Robot_Setup (&ro[1],1);
		ID = *IDnumber;
		p16_patient = p16_patient_head->next;
		p = p16_patient_head->next;;
		while(p != NULL)
		  		{
		  			if((p)->numreg == ID && (p)->numreg > 0 )
		  			{//�����ݷ���Ҫ��
				//test
						if((p)->nummed == 0 && p->payreg >= 4){
							cleardevice();
				  			setfillstyle(1,WHITE);
				  			bar(0, 0,640 ,480);
							setfillstyle(3,DARKGRAY);
							bar(230, 390,260+153 ,400+34);
							setfillstyle(1,WHITE);
							bar(235, 395,255+153 ,395+34);
							puthz(260,400,"����ȡҩ",24,32,RED);
							page = 1;
							delay(500);
							pan = 1;
							break;
						}else if((p)->payreg == 1){
							cleardevice();
				  			setfillstyle(1,WHITE);
				  			bar(0, 0,640 ,480);
							setfillstyle(3,DARKGRAY);
							bar(230, 390,260+153 ,400+34);
							setfillstyle(1,WHITE);
							bar(235, 395,255+153 ,395+34);
							puthz(260,400,"��δ�ɷ�",24,32,RED);
							page = 1;
							delay(500);
							pan = 1;
							break;
						}
						else if((p)->payreg == 0){
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
							pan = 1;
							break;
						}else{
							//page = load();
							pan = 1;
							IN = 1;
							page = 0;
						}
		  			}
		  			p = p->next;
		  		}
		  	if(!pan){
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
			}		
	if(IN){
		clrmous(MouseX,MouseY);
		MouseS = 0;
		cleardevice();
		setbkcolor(WHITE);
		p16_screen();
		NO_XY_flash(medi_head->next);
		Number_no_same(p16_patient_head,1);
		p16_patient = p16_patient_head->next;
		delay(300);
	}
		while(page == 0 && IN)
		{
			newmouse(&MouseX,&MouseY,&press);
	
				page_t = CreateButton_OUT(600,0,1,&button[0]);
				if(page_t)
				{
					//������ת����⣬����ť��������ı��ҳ����ת����page_t����page��ֵ����������ҳ��ѭ�����˳�ҳ�溯����Ȼ������ѡ��ҳ��
					page = page_t;
					break;
				}
				
				if(yes){
				page_t = CreateButton_4  ("ȡҩ",buttondata3,&button[4]);
				if(page_t)
				{
					//������ת����⣬����ť��������ı��ҳ����ת����page_t����page��ֵ����������ҳ��ѭ�����˳�ҳ�溯����Ȼ������ѡ��ҳ��
					PatientData*m = p16_patient_head->next;
					while(m!= NULL){
							if(m->numreg == ID){
								m->nummed = 0;
								setfillstyle(11,LIGHTGRAY);
								bar(80,150,80+200,350);
								puthz(100,280,"������ȡ��",24,24,BLUE);
								outtextxy(100,310,m->name);
								delay(1000);
							}	
						m = m->next;
					}
					page = page_t;
					break;
				}
				}
	
				if
				(CreateButton_pagechange (sheet_data[4],sheet_data[5]+8*sheet_data[0],
				button2,&sheet_page,
				sheet_data[1]+sheet_data[2]+sheet_data[3]))
				{
					int i=0 ;
					for(;i<10;i++){
						check2[i] = 1;
					}
				}	

				show = SheetCreate_3 (sheet_data,p16_patient,sheet_page,check2);
	
				if(timing >  50){
					int t1 = 0;
					PatientData*m = p16_patient_head->next;
					timing = 0;
					timing2 ++;
					Number_no_same(p16_patient_head,1);
					p16_patient = p16_patient_head->next;
					Robot_analyse(medi_head->next,&page/*û����*/,p16_patient,&ro[0],&ro[1]);
					Store_draw (drawdata,medi_head->next);
					Robot_draw (drawdata,&ro[0]);
					Robot_draw (drawdata,&ro[1]);
					Robotstate_Show(30,13,&ro[0],"��ҩ������һ��",&robotflash);
					Robotstate_Show(260,13,&ro[1],"��ҩ�����˶���",&robotflash2);
					settextstyle(3,0,2);
					for(t1 = 0;t1<10;t1++){
						check2[t1] = 1;
					}
					while(m!= NULL){
						if(m != NULL &&	m->payreg == 4 && timing2 > 8){
								setfillstyle(11,LIGHTGRAY);
								bar(80,150,80+200,350);
								setcolor(RED);
								puthz(100,160,"���кţ��뻼�ߣ�",24,24,RED);
								outtextxy(100,200,m->name);
								puthz(100,240,"������ȡҩ",24,24,RED);
								delay(2000);
								m->payreg = 5;
							if(m->numreg != *IDnumber){
								m->nummed = 0;
								setcolor(BLUE);
								puthz(100,280,"������ȡ��",24,24,BLUE);
								outtextxy(100,310,m->name);
								delay(500);
								Number_no_same(p16_patient_head,1);
								p16_patient = p16_patient_head->next;
							}else{
								yes = 1;
							}
							timing2 = 0;
						}	
						if(m != NULL &&	m->payreg == 5 && m->numreg == ID){
							yes = 1;
						}
						m = m->next;
					}
					delay(5);
				}else{
					timing++;
					delay(5);
				}
		}
			Robot_Output (ro,2);
			printlist_FILE(medi_head);
			Patient_Output(p16_patient_head);
			deletall(p16_patient_head);
			mt = medi_head->next;
			while(mt != NULL){
				free(medi_head);
				medi_head = mt;
				mt = mt->next;
			}
			free(medi_head);
			free(medicine);
		return page;    
		//�˳�ҳ�棬���ظı��ҳ��ֵ

}   
