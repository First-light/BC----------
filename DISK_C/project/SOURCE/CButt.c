#include <common.h>

/******************************************************************
		����ť����.C�ļ���
��д�ˣ�������
�ļ����ܣ������󲿷ְ�ť���ܺ������ļ�
*******************************************************************/

//����������������������������������������������������������������������������

//          �� ��ť������ʹ�ù淶 ��

//			������ť��
//			page_t = CreateButton_1("����",240,300,1,&button[0]);

//			����߼���
//			if(page_t)
//			{
//				page = page_t;
//				break;
//			}

//				��д�� ��������
//����������������������������������������������������������������������������


/******************************************************************
		����ť������ʽ������
��д�ˣ�������
���룺text(��ť����ʾ�ı�)��data����ť�Ĳ�����
������void
�������ܣ�������ť�������˰�ť�Ĳ�ͬ��ʽ�����Ը�����ʽ�ı䰴ťɫ�ʺ��ı�
*******************************************************************/
void Button_Light(char* text,int* data)
{
	int style = 0;
	int x = data[0];
	int y = data[1];
	int length_x = data[3];
	int length_y = data[4];
	int textsize = data[5];
	int textlength = data[6];
	
	if(data[8] < 10 && data[8] > 0)//������ʽ��Χ
	{
		style = data[8];
	}
	clrmous(MouseX,MouseY);
	MouseS = 1;
	switch (style)
	{
	case 5:
		setfillstyle(1,LIGHTGRAY);
		bar(x, y, x+length_x,y+length_y);
		puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,DARKGRAY);
		break;
	case 4:
		setfillstyle(1,YELLOW);
		bar(x, y, x+length_x,y+length_y);
		setfillstyle(1,DARKGRAY);
		bar(x+1, y+1, x+length_x-1,y+length_y-1);
		puthz(x+length_x/2-textlength-textsize-data[7] +1,y+length_y/4+1,text,textsize,textlength,LIGHTGRAY);
		puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,YELLOW);
		break;
	case 3:
		
		setfillstyle(1,DARKGRAY);
		bar(x, y, x+length_x,y+length_y);
		setfillstyle(1,CYAN);
		bar(x+3, y+3, x+length_x-3,y+length_y-3);
		puthz(x+length_x/2-textlength-textsize-data[7] +2,y+length_y/4+2,text,textsize,textlength,DARKGRAY);
		puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,YELLOW);
		break;
	case 2:
		setfillstyle(1,BLUE);
		bar(x, y, x+length_x,y+length_y);
		puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,LIGHTBLUE);
		break;
	case 1:
		setfillstyle(1,BLUE);
		bar(x, y, x+length_x,y+length_y);
		puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,WHITE);
		break;
	default:
		setfillstyle(1,LIGHTGRAY);
		bar(x, y, x+length_x,y+length_y);
		puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,DARKGRAY);
		break;
	}
}

/******************************************************************
		����ť�ָ���ʽ������
��д�ˣ�������
���룺text(��ť����ʾ�ı�)��data����ť�Ĳ�����
������void
�������ܣ��ָ���ť��ɫ�������˰�ť�Ĳ�ͬ��ʽ�����Ը�����ʽ�ı䰴ťɫ�ʺ��ı�
*******************************************************************/
void Button_Recover(char* text,int* data)
{
	int style = 0;
	int x = data[0];
	int y = data[1];
	int length_x = data[3];
	int length_y = data[4];
	int textsize = data[5];
	int textlength = data[6];
	
	if(data[8] < 10 && data[8] > 0)//������ʽ��Χ
	{
		style = data[8];
	}
	clrmous(MouseX,MouseY);
	MouseS = 0;
	switch (style)
	{
		case 4:
			setfillstyle(1,LIGHTGRAY);
			bar(x, y, x+length_x,y+length_y);
			setfillstyle(1,DARKGRAY);
			bar(x+1, y+1, x+length_x-1,y+length_y-1);
			puthz(x+length_x/2-textlength-textsize-data[7] +1,y+length_y/4+1,text,textsize,textlength,LIGHTGRAY);
			puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,WHITE);
		break;
		case 3:
			setfillstyle(1,LIGHTGRAY);
			bar(x, y, x+length_x,y+length_y);
			setfillstyle(1,LIGHTBLUE);
			bar(x+3, y+3, x+length_x-3,y+length_y-3);
			puthz(x+length_x/2-textlength-textsize-data[7] +2,y+length_y/4+2,text,textsize,textlength,DARKGRAY);
			puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,YELLOW);
			break;
		case 2:
			setfillstyle(1,BLUE);
			bar(x, y, x+length_x,y+length_y);
			puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,WHITE);
		break;
		case 1:
			setfillstyle(1,BLUE);
			bar(x, y, x+length_x,y+length_y);
			puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,WHITE);
		break;
		default:
			setfillstyle(1,LIGHTGRAY);
			bar(x, y, x+length_x,y+length_y);
			puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,DARKGRAY);
		break;
	}
}

/******************************************************************
		����ť������(���Ĵ��Ż�)
��д�ˣ�������
���룺text(��ť����ʾ�ı�)��data����ť�Ĳ�������button����ť��״̬��
������int�������õķ���ֵ��
�������ܣ���ָ��λ������ָ����С����ʽ�İ�ť����ť���е������ܣ���ť���ص�int
		����ʵ��ҳ����ת��״̬�ı䣬����,�������ڵĹ���
*******************************************************************/
int CreateButton_4  (char* text,int* data,int* button)
//data����9
//1��2���꣬3�Ƿ���ֵ��4��5�ǰ�ť��С��6�ֺţ�7�ּ�࣬8�ֵĿ�ʼλ�ã�9Ϊ��ʽ
//����button��Ϊ�˲鿴��ť��״̬����ֹ��ť��˸��Ӱ������
{
	int back = 0;
	int x = data[0];
	int y = data[1];
	int change = data[2];
	int length_x = data[3];
	int length_y = data[4];

	if(*button != 3)//��ⰴť�Ƿ�����
	{
		if(mouse_press(x, y, x+length_x,y+length_y) != *button)//�������λ�ù�ϵ�ı�
		{
			if(mouse_press(x, y, x+length_x,y+length_y) == 2)//������
			{
				Button_Light(text,data);//����
				*button = 2;//����״̬
			}
			else//������
			{	
				Button_Recover(text,data);//�ָ�
				*button = 0;		
			}
		}
		if(mouse_press(x, y, x+length_x,y+length_y) == 1)//�������
		{
			int t = data[8];
			data[8] = 5;//�л���ʽ
			Button_Light(text,data);//�л����µ���ʽ
			data[8] = t;
			back = change;//���÷���ֵ
		}	
	}
	//�������õķ���ֵ
	return back;
}

/******************************************************************
		�����غ�����
��д�ˣ�������
���룺data�����صĲ�����button�������ڿ��ص�״̬��key(���ؿ��Ƶı���ָ��)��
������void
�������ܣ���ָ��λ������ָ����С�Ŀ��أ����ؾ��е������ܣ�
		���ؿ����޸�ָ����intֵ,���������������ʵ�ְ�ť����,
		�к�״̬ת��Ĺ���
*******************************************************************/
void CreateButton_open  (int* data,int* button,int* key)
//data����4
//1,2����.	3,4,��С
//����button��Ϊ�˲鿴�ϴο��ص�״̬����ֹ������˸��Ӱ������
{
	int x =data[0];
	int y= data[1];
	int length_x = data[2];
	int length_y = data[3];
	
	if(mouse_press(x, y, x+length_x,y+length_y) != *button)//�������λ�ù�ϵ�ı�
	{
		if(mouse_press(x, y, x+length_x,y+length_y) == 0)//������
		{
			clrmous(MouseX,MouseY);
			MouseS = 0;
			setfillstyle(1,DARKGRAY);
			bar(x, y, x+length_x,y+length_y);
			setfillstyle(1,WHITE);
			bar(x+1, y+1, x+length_x-1,y+length_y-1);
			setfillstyle(1,LIGHTGRAY);
			bar(x+7, y+7, x+length_x-7,y+length_y-7);
			if(*key)//�������״̬Ϊ 1
			{
				setfillstyle(1,WHITE);
				bar(x+7+1, y+7+1, x+length_x-7+1,y+length_y-7+1);
			}
			*button = 0;			
		}
		else//������
		{
			clrmous(MouseX,MouseY);
			MouseS = 1;
			setfillstyle(1,DARKGRAY);
			bar(x, y, x+length_x,y+length_y);
			setfillstyle(1,LIGHTBLUE);
			bar(x+1, y+1, x+length_x-1,y+length_y-1);
			setfillstyle(1,BLUE);
			bar(x+7, y+7, x+length_x-7,y+length_y-7);
			if(*key)//�������״̬Ϊ 1
			{
				setfillstyle(1,LIGHTBLUE);
				bar(x+7+1, y+7+1, x+length_x-7+1,y+length_y-7+1);
			}
			*button = 2;	
		}
	}
	if(mouse_press(x, y, x+length_x,y+length_y) == 1)//��������������
	{
		*key = !(*key); //�ı俪�ؿ��Ƶı���
		delay(300);//�ӳٷ�ֹ��ʱ����
	}	
}


/******************************************************************
		�����ؼ���ͼ������
��д�ˣ�������
���룺x , y�����꣩
������void 
�������ܣ��������ؼ�
*******************************************************************/
void CreateButton_OUT_Draw(int x,int y,int style)
{
	int length_x  = 40;
	int length_y = 40;
	int xt = length_x/6;
	int yt = length_y/6;

	switch(style){
		case 1://�ָ�
			clrmous(MouseX,MouseY);
			MouseS = 0;
			setfillstyle(1,DARKGRAY);
			bar(x, y, x+length_x,y+length_y);
			setfillstyle(1,WHITE);
			bar(x+2, y+2, x+length_x-2,y+length_y-2);
			setcolor(DARKGRAY);
			setlinestyle(0, 0, 3);
			line(x+xt,y+yt,x+length_x-xt,y+length_y-yt);
			line(x+xt,y+length_y-yt,x+length_x-xt,y+yt);
		break;
		case 2://����
			clrmous(MouseX,MouseY);
			MouseS = 1;
			setfillstyle(1,RED);
			bar(x, y, x+length_x,y+length_y);
			setcolor(WHITE);
			setlinestyle(0, 0, 3);
			line(x+xt,y+yt,x+length_x-xt,y+length_y-yt);
			line(x+xt,y+length_y-yt,x+length_x-xt,y+yt);
		break;	
		default://������ת
			yt = 0;
			setfillstyle(1,WHITE);
			bar(0, 395-10+yt,640,395+34+10+yt);
			setfillstyle(11,DARKGRAY);
			bar(0, 395-10+yt,640,395+34+10+yt);
			setfillstyle(1,WHITE);
			bar(0, 395-5+yt,640,395+34+5+yt);
			setfillstyle(1,WHITE);
			bar(235-5, 395+yt,255+153-5,395+34+yt);
			setlinestyle(2,0,5);
			setcolor(RED);
			line(0,412+yt,230-10+20,412+yt);
			line(260+153+10-20,412+yt,640,412+yt);
			frameline2();
			puthz(260-2,400+yt,"���ڷ���",24,32,RED);
			delay(500);			
		break;	
	}
}

/******************************************************************
		�����ؼ�������
��д�ˣ�������
���룺x , y�����꣩button�������ڰ�ť��״̬��
		change(���õķ�����)
������int 
�������ܣ���ָ��λ�����ɷ��ؼ�,���з�����һ��ҳ��Ĳ���
*******************************************************************/
int CreateButton_OUT  (int x,int y,int change,int* button)
{
	int back = 0;
	int length_x  = 40;
	int length_y = 40;//���ù̶���С
 
	if(mouse_press(x, y, x+length_x,y+length_y) != *button)//��������ڰ���״̬�ı�
	{
		if(mouse_press(x, y, x+length_x,y+length_y) == 0)
		{
			CreateButton_OUT_Draw(x,y,1);
			*button = 0;	
		}
		else
		{
			CreateButton_OUT_Draw(x,y,2);
			*button = 2;		
		}
	}
	if(mouse_press(x, y, x+length_x,y+length_y) == 1)
	{
		CreateButton_OUT_Draw(x,y,0); //����������ʾ
		back = change;
	}	
	return back;//�����ϼ�ҳ������
}


/******************************************************************
		�������⺯����
��д�ˣ�������
���룺input(���������)
������int (�Ƿ����)
�������ܣ���������Ƿ���ȷ
*******************************************************************/
int Password_Check(char* input)
{
	int back = 0;
	if(!strcmp(input,PASSWORD))
	{
		back = 1;
	}
	return back;
}
/******************************************************************
		��������ͼ�߿�����
��д�ˣ�������
���룺x y����,���ȸ߶�
������void
�������ܣ������߿�
*******************************************************************/
void INPUTbutton_Write_3(int x,int y,int length_x,int length_y)
{		
	setfillstyle(1,DARKGRAY);
	bar(x -3, y-3, x+length_x+3,y+length_y+3);
	setfillstyle(1,WHITE);
	bar(x, y, x+length_x,y+length_y);
}

/******************************************************************
		��������ͼ������
��д�ˣ�������
���룺data(��ť����),style(��ʽ)
		input(�������������),text(�������ʾ���ı�)
		key(�Ƿ���*����չʾ)
������void
�������ܣ���ָ��λ������ָ����ʽ�ʹ�С�������,
*******************************************************************/
void CreateButton_INPUT_3_Draw(int *data,char* input,char* text,int key,int style)
{
	int length_x =data[2];
	int length_y =data[3];
	int textlenth = data[4];
	int textstart = data[5];
	int textsize = data[8];
	int x = data[0];
	int y = data[1];
	
	switch (style)
	{
		case 1:
			clrmous(MouseX,MouseY);
			MouseS = 0;
			setfillstyle(1,LIGHTGRAY);
			bar(x -3, y-3, x+length_x+3,y+length_y+3);
			setfillstyle(1,WHITE);
			bar(x, y, x+length_x,y+length_y);
			settextstyle(data[7],0,textsize);
			setcolor(LIGHTGRAY);
			if(input[0] != 0)
			{
				if(key)
				{
					outtextxy(textstart + x, y , input);//����ֻ�����ַ���
				}
				else
				{
					int i=0;
					for(;i < (int)strlen(input);i++)
					{
						outtextxy(textstart + x + i * textlenth, y + 8, "*");//����ֻ�����ַ���	
					}
				}				
			}
			else
			{
				puthz(textstart + x+5,y+length_y/2-8, text, 16, 19, LIGHTGRAY);
			}
		break;
		default:
			clrmous(MouseX,MouseY);
			MouseS = 2;
			setfillstyle(1,DARKGRAY);
			bar(x -3, y-3, x+length_x+3,y+length_y+3);
			setfillstyle(1,WHITE);
			bar(x, y, x+length_x,y+length_y);
			settextstyle(data[7],0,textsize);
			setcolor(DARKGRAY);
			if(input[0] != 0){
				if(key){
					outtextxy(textstart + x, y , input);//����ֻ�����ַ���
				}else{
					int i=0;
					for(;i < strlen(input);i++){
					outtextxy(textstart + x + i * textlenth, y + 8, "*");//����ֻ�����ַ���	
					}
				}		
			}else{
				puthz(textstart + x+5,y+length_y/2-8, text, 16, 19, DARKGRAY);
			}			
		break;
	}
}

/******************************************************************
		������ģʽ������
��д�ˣ�������
���룺data(��ť����)
		input(�������������)
		key(�Ƿ���*����չʾ)
������void
�������ܣ���������ģʽ,�������״̬,����չʾ������ַ�
*******************************************************************/
void INPUTbutton_3 (int* data,char* input,int key)
{
	char password[NAME_MAX_LENGTH] = {0};//��ʱ�洢����ֵ
	int i = 0;//���������ַ�����
	char a[2] = {"\0"};//�洢���������ַ�,��ֱֹ����������ַ�����������
	int textlenth = data[4];
	int x = data[0];
	int y = data[1];
	int maxlenth = data[6];
	int textstart = data[5];
	int length_x = data[2];
	int length_y = data[3];
	int textsize =data[8];
	
	strcpy(input,"\0");//��֮ǰ���������
	clrmous(MouseX, MouseY);
	INPUTbutton_Write_3(x,y,length_x,length_y);
	settextstyle(data[7],0,textsize);
	setcolor(DARKGRAY);
	line(textstart + x + 3,y+7,textstart + x + 3,y+length_y-7);//�������
	while (1)//��������ѭ��
	{
		a[0] = bioskey(0);//�������
		if (i < maxlenth)//����Ƿ񵽴������������
		{
			if (a[0] != '\n' && a[0] != '\r')//033��esc
			{
				if (a[0] != '\b')
				{
					bar(textstart + x + (i) * textlenth-2, y ,textstart + x + (i+1) * textlenth +10, y + length_y);
					password[i] = a[0];
					password[i + 1] = '\0';
					if(key)//����Ƿ���Ҫ��������
					{
						outtextxy(textstart + x + i * textlenth, y, a);//����ֻ�����ַ���
					}
					else
					{
						outtextxy(textstart + x + i * textlenth, y + 8, "*");//����ֻ�����ַ���
					}				
					line(textstart + x + (i+1) * textlenth,y+5,textstart + x + (i+1) * textlenth,y+length_y-5);
					i++;
				}
				else if (a[0] == '\b' && i > 0)
				{
					bar(x + i * textlenth - textlenth, y , x + (i+1) * textlenth +10, y + length_y);
					i--;
					line(textstart + x + (i) * textlenth,y+5,textstart + x + (i) * textlenth,y+length_y-5);
					password[i] = '\0';//���
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			if (a[0] != '\n' && a[0] != '\r')//���»س�
			{
				if (a[0] == '\b' && i > 0)
				{
					bar(x + i * textlenth - textlenth, y , x + (i+1) * textlenth +10, y + length_y);
					i--;
					line(textstart + x + (i) * textlenth,y+5,textstart + x + (i) * textlenth,y+length_y-5);
					password[i] = '\0';//���
				}
			}
			else
			{
				break;
			}
		}
	}
	strcpy(input,password);//չʾ��������
}
/******************************************************************
		�����������(�������޸�)
��д�ˣ�������
���룺data(��ť����),button(�����ڰ�ť����ʷ״̬)
		input(�������������),text(�������ʾ���ı�)
		key(�Ƿ���*����չʾ)
������void
�������ܣ���ָ��λ������ָ����ʽ�ʹ�С�������,
*******************************************************************/
void CreateButton_INPUT_3  (int *data,int* button,char* input,char* text,int key)
//������û����ť����������0�����£�����������ת��ҳ����
//have 8 data
//����button��Ϊ�˲鿴�ϴΰ�ť��״̬,��ֹ��˸
//1.2��λ��3.4��С��5�ּ�࣬6�ֵĿ�ʼλ�ã�7�ֵ�������������8�ֵ����壬9�ֵĴ�С
{
	int length_x = data[2];
	int length_y = data[3];
	int x = data[0];
	int y = data[1];

	if(mouse_press(x, y, x+length_x,y+length_y) != *button)
	{
		if(mouse_press(x, y, x+length_x,y+length_y) == 0)
		{
			CreateButton_INPUT_3_Draw(data,input,text,key,1);
			*button = 0;			
		}
		else
		{
			CreateButton_INPUT_3_Draw(data,input,text,key,0);
			*button = 2;	
		}
	}
	if(mouse_press(x, y, x+length_x,y+length_y) == 1)
	{
		char t;
		for(;bioskey(1);)
		{
			t = bioskey(0);
			if(t){}
		}//������̻�����
		INPUTbutton_3(data,input,key);
		*button = 1;
		clrmous(MouseX,MouseY);
		newmouse(&MouseX,&MouseY,&press);
	}	
}

/******************************************************************
		����ť����������
��д�ˣ�������
���룺old(��ť����ʷ״̬)��count���Ƿ���������
		change ��ť��ʽ��check ����Ŀ�꣬style ���ģʽ
������int���޸İ�ť��״̬��1Ϊ������3Ϊ������
�������ܣ����������Ƿ������ݣ��еĻ��������ť��
		�ı䰴ť��ʽ��û�еĻ���������ť����ֹ���
*******************************************************************/
int Button_4_Lock(int old,int* count,int* change,char*check,int style)
{
	int back;
	back = old;
	if(style == 1)//�Ƿ���
	{
		if(check[0] == 0)//�����Ϊ��
		{
			if(*count == 0)
			{//���ڼ�������״̬
				back = 3;//����ť����3������
			}
			if(*count == 1)
			{//����δ����״̬
				*change = 0;//�ı䰴ť��ʽ
				back = 1;//��ťˢ�£�����ʽ�ı�
				*count = 0;//���뼴������״̬
			}
		}
		else
		{
			if(old == 3)
			{//��������״̬
				*change = 1;//�ı䰴ť��ʽ
				back = 1;//��ťˢ�£�����ʽ�ı�
				*count = 1;//�������״̬
			}
		}		
	}
	//����״̬
	return back;
}
