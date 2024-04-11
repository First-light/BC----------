#define NAME_MAX_LENGTH 20
#ifndef _STRUCT_H_
#define _STRUCT_H_
struct robot
{
	int x;
	int y;
	int x2;
	int y2;
	int state;
	int medi;
	int count;
	int ystart;
	int pat;
};

typedef struct patient{
		char name[NAME_MAX_LENGTH];//�û���
		int payreg;//�Ƿ���ϣ�1��0�� 
		int paymed;//�Ƿ�ҩ�ѣ�1��0�� 
		int numreg;//�Һź��� 
		int nummed;//ȡҩ���� 
		int window;//ȡҩ���� 
		int medicine_list[6][3];//��Ϸ���
		char doctor[5];
		char timer[13];
		int sexual;
		int age;
		struct patient *next;//����
} PatientData ;

typedef struct MedData
{
	int ID;//ÿһ��ҩ��ר����Ϣ 
	int Store_No;//ҩƷ����ҩ����� 
	char name[25];//ҩƷ�� 
	int margin;//���� 
	int inventory;//������� 
	int price;//���� 
	int x;//x���� 
	int y;//y���� 
	struct MedData *next;//ָ����
} MED;



#endif 
