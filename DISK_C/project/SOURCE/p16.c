#include "common.h"
#define p16_button_num 4
/*������������������������������������������������
				��ҽ��������桿 
��д�ˣ�������
�˽���ʵ����ҽ������ϵͳʱ��Ҫ��������Ĺ��̡�
������������������������������������������������*/


void p16_screen()
{
/*����������������������������������
		����ʼ����ͼ������ 
		��д�ˣ�������
		�����ử������ı�����
������������������������������������*/
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	frameline2();
}



int p16()
{
/*������������������������������������
		��ҽ������ҳ�溯����
		��д�ˣ�������
��
��������������������������������������*/
	int button[p16_button_num] = {1,1,1,1};
	int page = 0;
	int page_t = 0;
	int robotflash = 1;
	int robotflash2 = 1;
	int show = -1;
	int button2[3]={1,1,1};
	int sheet_1_page = 1;
	int sheet_1_data[7]= {30,30,120,80,380,185,0};
	int buttondata3[9] = {485,70,1,127,62,24,32,-25,2};
	int buttondata[4] = {485,15,90,25};
		int key = 1;
		int keyold = key;
	int check[10] = {1,1,1,1,1,1,1,1,1,1};
	struct robot ro[2] =
	{
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0}
	};
	int timing = 201;
	int drawdata[2] = {20,140};
	char a[7] = {0};
	int yes = 0;
	int yes2 = 1;
	int show2 = 0;
	int IDpat = -1;
	int yes_t = 0;
	MED* medicine = (MED*)malloc(sizeof(MED));
	MED* medi_head =reopen(medicine);
	MED* mt = medi_head->next;
	
	PatientData* p16_patient = creat(0);
	PatientData* p16_patient_head = p16_patient;
	p16_patient = p16_patient->next;//����ͷ�ڵ�
	
	Patient_Setup (p16_patient_head);

	Number_no_same(p16_patient_head,1);
	p16_patient = p16_patient_head->next;

	Robot_Setup (&ro[0],0);
	Robot_Setup (&ro[1],1);
	clrmous(MouseX,MouseY);
	MouseS = 0;
	cleardevice();	
	setbkcolor(WHITE);
	p16_screen();
	setfillstyle(1,YELLOW);
	bar(485,45,485+16*8,65);
	puthz(485,45,"�кŻ�����ȡҩ",16,16,BLUE);
	NO_XY_flash(medi_head->next);

	delay(300);

	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);

			page_t = CreateButton_OUT(600,0,14,&button[0]);
			//���ذ�ť
			if(page_t)
			{
				//������ת����⣬����ť��������ı��ҳ����ת����page_t����page��ֵ����������ҳ��ѭ�����˳�ҳ�溯����Ȼ������ѡ��ҳ��
				page = page_t;
				break;
			}

			if
			(CreateButton_pagechange (sheet_1_data[4],sheet_1_data[5]+8*sheet_1_data[0],
			button2,&sheet_1_page,
			sheet_1_data[1]+sheet_1_data[2]+sheet_1_data[3]))
			{
				int i=0 ;
				for(;i<10;i++){
					check[i] = 1;
				}
			}
			
			
			
			CreateButton_open  (buttondata,&button[3],&key);
			if(keyold != key)
			{
				keyold = key;
				yes2 = key;
				if(key == 0){
					setfillstyle(1,YELLOW);
					bar(485,45,485+16*8,65);
					puthz(485,45,"�кŻ��߲���ȡҩ",16,16,RED);
				}else{
					setfillstyle(1,YELLOW);
					bar(485,45,485+16*8,65);
					puthz(485,45,"�кŻ�����ȡҩ",16,16,BLUE);					
				}
			}

			show = SheetCreate_3 (sheet_1_data,p16_patient,sheet_1_page,check);
			if(show != -1){
				show2 = 1;
				IDpat = show;
			}
			if(show2){
				yes_t = CreateButton_4  ("�к�",buttondata3,&button[4]);
				if(yes_t){
					yes = 1;
				}
			}
			
			if(timing >  100){
				int t1 = 0;
				timing = 0;
				Robot_analyse(medi_head->next,&page/*û����*/,p16_patient,&ro[0],&ro[1]);
				Store_draw (drawdata,medi_head->next);
				Robot_draw (drawdata,&ro[0]);
				Robot_draw (drawdata,&ro[1]);
				Robotstate_Show(30,13,&ro[0],"��ҩ������һ��",&robotflash);
				Robotstate_Show(260,13,&ro[1],"��ҩ�����˶���",&robotflash2);
				settextstyle(3,0,2);
				for(t1 = 0;t1<10;t1++){
					check[t1] = 1;
				}
				if(yes){
					PatientData*m = p16_patient_head->next;
					settextstyle(3,0,2);
					while(m!= NULL){
						if(m != NULL &&	m->payreg >= 4 && m->nummed == IDpat){
								setfillstyle(11,LIGHTGRAY);
								bar(80,150,80+200,350);
									setcolor(RED);
									puthz(100,160,"���кţ��뻼�ߣ�",24,24,RED);
									outtextxy(100,200,m->name);
									puthz(100,240,"������ȡҩ",24,24,RED);
									delay(2000);
									m->payreg = 5;
								if(yes2){
									m->nummed = 0;
									setcolor(BLUE);
									puthz(100,280,"������ȡ��",24,24,BLUE);
									outtextxy(100,310,m->name);
									delay(1000);
								}
							}	
							m = m->next;
						}
						Number_no_same(p16_patient_head,1);
						p16_patient = p16_patient_head->next;
						delay(5);	
					yes = 0;			
				}
				delay(5);
			}else{
				timing++;
				delay(5);
			}
			

//����������������������������������������������������������������������������

//			page_t = CreateButton_1("����",240,300,1,&button[0]);
//			if(page_t)
//			{
//				page = page_t;
//				break;
//			}		

//          �� ��ť������ʹ�ù淶 ��

//				��д�� ��������
//����������������������������������������������������������������������������
		
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
