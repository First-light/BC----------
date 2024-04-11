#include <common.h>


/******************************************************************
	������ҩƷ����ͷ�ڵ㺯���� 
��д�ˣ�����
���룺void 
������MED*headNode��ͷ�ڵ�ָ��) 
�������ܣ�����ҩƷ��ͷ�ڵ� 
*******************************************************************/
MED*creatlist(void)
{
	MED*headNode = (MED*)malloc(sizeof(MED));//��headNode��Ϊ�ṹ�����
	headNode->next = NULL;
	headNode->ID = 0;
	return headNode; 	 
}

/******************************************************************
	������ҩƷ������ͨ�ڵ㺯���� 
��д�ˣ�����
���룺MED*medicine���յĹ���ָ�룩 
������MED*newNode������ͨ�ڵ�ָ��) 
�������ܣ�����ҩƷ�µ���ͨ�ڵ� 
*******************************************************************/

MED*creatNode(MED*medicine)
{
	MED*newNode = (MED*)malloc(sizeof(MED));
	newNode->ID=medicine->ID;
	newNode->Store_No=medicine->Store_No;
	strcpy(newNode->name,medicine->name);
	newNode->margin=medicine->margin;
	newNode->inventory=medicine->inventory;
	newNode->price=medicine->price;
	newNode->next = NULL;
	return newNode;
}

/******************************************************************
	��ҩƷ��Ϣд�뺯���� 
��д�ˣ�����
���룺MED*headNode��ͷ���ָ�룩 
������void 
�������ܣ���������������Ʒ��Ϣ�ؽ���ͬ���ı���д��ҩƷ�����ı� 
*******************************************************************/

void printlist_FILE(MED *headNode)
{
	MED*pMove = headNode->next;//�������������Ľṹָ�� 
	FILE*fp;
	fp=fopen("C:\\project\\DATABASE\\drugdata.txt","w+");
	while(pMove)
	{
		fprintf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",pMove->ID,pMove->Store_No,pMove->name,pMove->price,pMove->margin,pMove->inventory);
		pMove = pMove->next;
		printf("\n");
	}//�߱�����д�� 
	printf("\n");
	fclose(fp);
}


/******************************************************************
	��intתchar������ 
��д�ˣ�����
���룺int number����Ҫת�������Σ�,char*nowchar��ת����Ĵ��λ�ã� 
������void 
�������ܣ������λ��Ϊ��λ������ת��Ϊ�ַ��� 
*******************************************************************/

void int_trans_char(int number,char*nowchar)
{
	int a = number / 100;
	int c = number % 10;
	int b = (number - 100 * a - c) / 10;
	if (a != 0)
	{
		nowchar[0] = a+'0';
		nowchar[1] = b+'0';
		nowchar[2] = c+'0';
	}
	else if (a == 0 && b != 0)
	{
		nowchar[0] = b+'0';
		nowchar[1] = c+'0';
		nowchar[2] = '\0';
	}
	else if (a == 0 && b == 0)
	{
		nowchar[0] = c+'0';
		nowchar[1] = '\0';
		nowchar[2] = '\0';
	}//��λת�� 

}

/******************************************************************
	��charתint������ 
��д�ˣ�����
���룺char*num����Ҫת�����ַ����� 
������int NUM��ת��������ͣ� 
�������ܣ������λ��Ϊʮ��λ���ַ���ת��Ϊ���� 
*******************************************************************/

int char_trans_int(char*num)
{
	int i=0;
	int k=0;
	int NUM=0;
	for(i=0;i<6;i++)
	{
	if(num[i]!='\0')
	k++;
	else 
	break;
    }
	switch(k)
	{
		case 0:
			NUM=0;
			break;
		case 1:
			NUM=num[0]-'0';
			break;
		case 2:
			NUM=(num[0]-'0')*10+(num[1]-'0');
			break;
		case 3:
			NUM=(num[0]-'0')*100+(num[1]-'0')*10+(num[2]-'0');
			break;
		case 4:
			NUM=(num[0]-'0')*1000+(num[1]-'0')*100+(num[2]-'0')*10+(num[3]-'0');
			break;
		case 5:
			NUM=(num[0]-'0')*10000+(num[1]-'0')*1000+(num[2]-'0')*100+(num[3]-'0')*10+(num[4]-'0');
			break;
		case 6:
			NUM=(num[0]-'0')*100000+(num[1]-'0')*10000+(num[2]-'0')*1000+(num[3]-'0')*100+(num[4]-'0')*10+(num[5]-'0');
			break;				
	}//λ���жϺ���λת�� 
    return NUM;
}

/******************************************************************
	�����ɾ������������ 
��д�ˣ�����  ������ 
���룺MED*headNode��ͷ�ڵ㣩,int*Delet_Item����ѡ��¼�ű�ѡ���ҩƷ��ID�����飩 
������void 
�������ܣ�����ѡ��ѡ���ҩƷ����һ��ɾ������������д���ļ� 
*******************************************************************/

void deletNode(MED*headNode,int*Delet_Item)
 {
	int i=0;

    for(i=0;i<34;i++)
	{
		if(Delet_Item[i]==0)
		{
			continue; 
		}///��״̬Ϊ0���� 
		else
		{
			MED*posNode = headNode->next;
			MED*posNodeFront = headNode;
			while(posNode->ID != Delet_Item[i] && posNode != NULL)
			{
				posNodeFront = posNode;
				posNode = posNode->next;
			}
			if(posNode != NULL)
			{
				posNodeFront->next = posNode->next;
				free(posNode);
				posNode = posNodeFront->next;
			}
			Delet_Item[i]=0;
		}//��״̬��Ϊ0ɾ�� 
	}	
	printlist_FILE(headNode);//��ӡ���ļ��� 
 }
  
/******************************************************************
	����ͷ����ڵ㺯���� 
��д�ˣ����� 
���룺MED*headNode��ͷ�ڵ㣩,MED*medicine�����߿սṹ�� 
������void 
�������ܣ����´����Ľڵ������ͷ���������� 
*******************************************************************/

void insertNodeByHead(MED*medicine,MED*headNode)
{
	MED*newNode = creatNode(medicine);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
 
 /******************************************************************
	����β����ڵ㺯���� 
��д�ˣ����� 
���룺MED*headNode��ͷ�ڵ㣩,MED*medicine�����߿սṹ�� 
������void 
�������ܣ����´����Ľڵ������ĩβ�������� 
*******************************************************************/

void insertNodeByTail(MED*medicine,MED*headNode)
{   
    MED*posNode = headNode;//��������ָ�� 
	MED*newNode = creatNode(medicine);
	while(posNode->next!=NULL)
	{
	 posNode=posNode->next;
	}//�ҵ�����ĩβ 
	
	posNode->next=newNode;
	newNode->next=NULL;
} 

/******************************************************************
	����ʼ���ļ�������ҩƷ��Ϣ�������� 
��д�ˣ����� 
���룺MED*medicine�����߿սṹ�� 
������MED*list�����Ѵ������˵���Ϣ�걸������ͷ�ڵ㴫���� 
�������ܣ����ļ��б߶��ߴ����������������������ͷ�ڵ㴫�� 
*******************************************************************/

MED*reopen(MED*medicine) 
{
	int i=0;//���int���������������ݸ������㴴��ʼ����� 
	int j=0;//��������� 
	FILE*fp; 
	MED*list =creatlist();//����һ��ͷָ��
	fp=fopen("C:\\project\\DATABASE\\drugdata.txt","rt");
    while(!feof(fp))
	{
	 fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
	 if(medicine->ID<1000&&medicine->ID>0)
	 {
	 	i++;
	 }
	}//���ļ�����һ�鿴Ҫ���������ڵ� 
	rewind(fp);
	medicine->ID=0;
	medicine->Store_No=0;
	strcpy(medicine->name,"\0");
	medicine->margin=0;
	medicine->inventory=0;
	medicine->price=0;
	medicine->next=NULL;//���ù��߽ṹָ�� 
	for(j=0;j<i;j++)
	{
	 fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
	insertNodeByTail(medicine,list);
	 medicine->ID=0;
	 medicine->Store_No=0;
	 strcpy(medicine->name,"\0");
	 medicine->margin=0;
	 medicine->inventory=0;
	 medicine->price=0;
	 medicine->next=NULL;
	}//�߶�ȡ�ߴ�β�������� 
	fclose(fp);
	return list;//����ͷ�ڵ�ָ�� 
}
 
/******************************************************************
	�������ҩƷ���߼��жϺ����� 
��д�ˣ����� 
���룺MED*medicine�����߿սṹ��MED*headNode��ͷ�ڵ㣩 
������int k�������Ƿ��ڲ�����������ʾ��ӳɹ��� 
�������ܣ�����ҩƷ���߼��жϣ������⴫����ʾ�ж��ź� 
*******************************************************************/

int add(MED*medicine,MED*headNode)
{
     int i=1;
     int j = 0;
     int k = 0;
     int l = 0; 
     int m = 0; 
     int n = 0;
     int p = 0;
   //	 int q = 0;
     FILE*fp;
     MED*posNode = headNode;
     MED*posNode2 = headNode->next;
	 fp=fopen("C:\\project\\DATABASE\\drugdata.txt","rt+");
	 while(1)
	 {
	 	if(medicine->Store_No == posNode2->Store_No)
	 	{
	 		cleardevice();
	        setbkcolor(WHITE);
	        setfillstyle(11,YELLOW);
	        bar(0,0,640,480);
            frameline();
            puthz(150, 180, "����ӵ���ҩ���ѱ�ռ��", 32, 32, DARKGRAY);
            puthz(200, 230, "�����һ��ҩ��", 32, 32, DARKGRAY);
	        delay(2000); 
	        j = 1;
	 		break;
		}//�ж�ҩ���Ƿ�ռ�� 
		else if(medicine->Store_No >34)
	 	{
	 		cleardevice();
	        setbkcolor(WHITE);
	        setfillstyle(11,YELLOW);
	        bar(0,0,640,480);
            frameline();
            puthz(150, 180, "����ӵ���ҩ���Ѵ�����", 32, 32, DARKGRAY);
            puthz(200, 230, "�����һ��ҩ��", 32, 32, DARKGRAY);
	        delay(2000); 
	        m = 1;
	 		break;
		}//�ж�ҩ���Ƿ�Խ���� 
		else if(medicine->Store_No ==0)
	 	{
	 		cleardevice();
	        setbkcolor(WHITE);
	        setfillstyle(11,YELLOW);
	        bar(0,0,640,480);
            frameline();
            puthz(150, 180, "����ӵ���ҩ���Ѳ�����", 32, 32, DARKGRAY);
            puthz(200, 230, "�����һ��ҩ��", 32, 32, DARKGRAY);
	        delay(2000); 
	        p = 1;
	 		break;
		}//�ж�ҩ���Ƿ�Խ���� 
		else if(!strcmp(medicine->name,posNode2->name))
		{
			cleardevice();
	        setbkcolor(WHITE);
	        setfillstyle(11,YELLOW);
	        bar(0,0,640,480);
            frameline();
            puthz(150, 180, "����ӵ�ҩƷ���ѱ�ռ��", 32, 32, DARKGRAY);
            puthz(200, 230, "�����һ������", 32, 32, DARKGRAY);
	        delay(2000); 
	        l = 1;
	 		break;
		}//�ж�ҩƷ�Ƿ����� 
		else if(!(strcmp(medicine->name,'\0')&&medicine->Store_No>0&&medicine->price>0&&medicine->inventory>0))
		{
			cleardevice();
	        setbkcolor(WHITE);
	        setfillstyle(11,YELLOW);
	        bar(0,0,640,480);
            frameline();
            puthz(200, 180, "����д������Ϣ", 32, 32, DARKGRAY);
	        delay(2000); 
	        n = 1;
	 		break;
		}//�ж�ҩƷ�Ƿ���Ϣ���� 
		else if(posNode2->next == NULL)
		{
			break;
		}
//		else
//		{
//			cleardevice();
//	        setbkcolor(WHITE);
//	        setfillstyle(11,YELLOW);
//	        bar(0,0,640,480);
//            frameline();
//            puthz(200, 180, "��Ϣ����", 32, 32, DARKGRAY);
//	        delay(2000); 
//	        q = 1;
//	 		break;
//		}//�ж�ҩƷ�Ƿ���Ϣ�Ϸ� 
		posNode2 = posNode2->next;
      }//�ж��Ƿ��ܴ�����ҩƷ 
		if(j == 0&&l == 0&&m == 0&&n == 0&&p ==0)
		{
			k = 1;
			while(posNode!=NULL)
	   {
		if(posNode->ID == i )
		{
			i++;
			posNode = headNode;
		}
		if(posNode->next == NULL)
		{
			break;
		}
	    posNode=posNode->next;
	   }
	 medicine->margin = medicine->inventory;
	 medicine->inventory = 200;
	 medicine->ID = i;
	 insertNodeByTail(medicine,headNode);

     printlist_FILE(headNode);
	}  //���Բ������벢����д���ļ� 
	fclose(fp);
	return k;//����״ֵ̬ 
}
