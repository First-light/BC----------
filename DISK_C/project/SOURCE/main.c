#include <common.h>

/******************************************************************
	���������� 
��д�ˣ�������������
���룺void
������void
�������ܣ�ҳ����ת��������ѭ������¼���ݣ���ʼ����ͼ�������˳�����
*******************************************************************/
void main(void)
{

	int page = -1;//ҳ��
	int graphdriver = VGA;
    int	graphmode = VGAHI;
    int IDnumber = 0; //����Һź���
	int flash = 1;//���ν��뻼����
	//��ʼ��ͼ�ν���
    initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");
	mouseinit();
	setbkcolor(WHITE);
	setviewport(0,0,MAX_X_LENGTH,MAX_Y_LENGTH,1);
	setfillstyle(BKSLASH_FILL,LIGHTGRAY);
	setlinestyle(0,0,3);
	setcolor(BROWN);
	settextstyle(0,HORIZ_DIR,2);
	
	while(1)
	{
		switch(page)//ҳ��ѡ��
		{
			case -1:
				//������
				page = p0();
				break;		
			case 1:
				//����ѡ�����
				if(flash == 1)
				{//�����ߵ�һ�ν���չʾ��ҽ����
					Notice_Page_p1();
					flash = 0;
				}
				page = p1plus(&IDnumber) ;
				break;		
			case 2:
				//���߹ҺŽ���
				page = Registered(&IDnumber);
				break;
			case 4:
				//������Ͻ���
				page = p4(&IDnumber);
				break;
			case 6:
				//���߽ɷѽ���
				page = p6(&IDnumber);
				break;
			case 7:
				//����ģ��ȡҩ����
				page = p7(&IDnumber);
				break;
			case 19:
				//���ع���ҳ��
				page = load();
				break;			
			case 13:
				//ҽ����¼ҳ��
				page = p13();
				break;
			case 14:
				//ҽ��ѡ��ҳ��
				page = p14();
				break;
			case 15:
				//�Һż�¼����ҳ��
				page = p15();
				break;
			case 16:
				//ҽ��ģ��к�ҳ��
				page = p16();
				break;					
			case 23:
				//ҽ��ҩƷ���Ĳ鿴ҳ��
				page = DrugOutAnalyse();
				break;
			case 26:
				//ҩ�����ҳ��
				page =drstma();
				break;	
			case 30:
				//ҩ�������ҩ����
				page =adddrug();
				break;				
			case 20://�˳����� 
				closegraph();
				exit(0);
				break;
		}
	}
}
