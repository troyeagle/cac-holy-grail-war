#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define Random(x)(rand()%x)//��������ɺ���������0~x֮���һ�������,ʹ��ʱ����1+Random(99)��ȡ��1~100�е������������Ӷ���ԭ1D100

int Roll_number(int bonus)
{
	int roll=1+Random(99);
	cout<<"Ͷ������Ϊ��"<<roll<<endl;
	if(bonus==0)//������ֱ���������ַ���
	{
		return roll;
	}
	if(bonus>0)//���������뽱�����ж�
	{
		for(int i=0;i<bonus;i++)
		{
			cout<<"�����"<<i+1<<"�ν�����"<<endl;
			int roll_new=1+Random(99);//������Ͷ������
			cout<<"����������:"<<roll_new<<endl;
			if(roll>roll_new)
			{
				roll=roll_new;	
			}
			cout<<"Ŀǰ��Ч����Ϊ:"<<roll<<endl;
		}
		return roll;
	}
	if(bonus<0)//�ͷ�������ͷ����ж�
	{
		for(int i=0;i<-bonus;i++)
		{
			cout<<"�����"<<i+1<<"�γͷ���"<<endl;
			int roll_new=1+Random(99);//������Ͷ������
			cout<<"�ͷ�������:"<<roll_new<<endl;
			if(roll<roll_new)
			{
				roll=roll_new;	
			}
			cout<<"Ŀǰ��Ч����Ϊ:"<<roll<<endl;
		}
		return roll;
	}
	return roll;//�����������������ж�= -=
}
int Decide(int ability,int bonus)//ȷ����õ�Ϊ����ʧ�ܣ�ʧ�ܣ��ɹ�����ɹ����Ǽ���ɹ������طֱ�Ϊ-1��0��1��2��3
{
	int roll_number=Roll_number(bonus);
	if(roll_number>ability)
	{
		return 0;
	}
	else if(roll_number>ability/2)
	{
		return 1;
	}
	else if(roll_number>ability/5)
	{
		return 2;
	}
	else if(roll_number>ability/50)
	{
		return 3;
	}
	else 
	{
		return 4;
	}
}
void Report(int power)//�㱨�ж�״̬
{
	if(power==0)
	{
		cout<<"�ж�Ϊʧ��(����0)"<<endl;
	}
	else if(power==1)
	{
		cout<<"�ж�Ϊ�ɹ�������1��"<<endl;
	}
	else if(power==2)
	{
		cout<<"�ж�Ϊ��ɹ�������2��"<<endl;
	}
	else if(power==3)
	{
		cout<<"�ж�Ϊ����ɹ�������3��"<<endl;
	}
	else if(power==4)
	{
		cout<<"��ע�⣡�����ж�Ϊ���޳ɹ�������4��"<<endl;
	}
}
void All_check(int attack,int defend)
{
	int situation;
	cout<<"�������ж�״�����ţ�1Ϊ���ܣ�2Ϊ������3Ϊ����񵲣�4Ϊħ���񵲣�"<<endl;
	cin>>situation;
	if(situation==1)//����״��
	{
		if(attack<defend)//����ȥ��
		{
			cout<<"�������ɹ����ܣ��յ��˺�Ϊ0"<<endl;
			return;
		}
		else//û����ȥ��ͬ���˺�1���ȼ���Խ���˺�Խ��
		{
			cout<<"���������ʧ�ܣ��յ��˺�Ϊ"<<attack-defend+1<<"���˺�"<<endl;			
			return;
		}
	}
	if(situation==2)//����״��
	{
		if(defend>attack)
		{
			cout<<"�����������ɹ����������ܵ�һ���˺����������ܵ�"<<defend-attack<<endl;			
			return;
		}
		else
		{
			cout<<"����������ʧ�ܣ��������ܵ�"<<1+attack-defend<<endl;
			return;
		}
	}
	if(situation==3)//�����
	{
		if(defend>attack)
		{
			cout<<"�����������ɹ���û���ܵ��˺�"<<endl;			
			return;
		}
		else
		{
			cout<<"����������ʧ�ܣ��������ܵ�1���˺�"<<endl;
			if(attack-defend>1)
			{
				cout<<"���ڲ�༶������2�������������»غϷ��������ж������ͷ�"<<endl;
			}
			return;
		}
	}
	if(situation==4)//ħ������
	{
		cout<<"������ʧȥ10��mp"<<endl;
		if(defend>attack)
		{
			cout<<"�����������ɹ���û���ܵ��˺�"<<endl;			
			return;
		}
		else
		{
			cout<<"����������ʧ�ܣ��������ܵ�1���˺�"<<endl;
			if(attack-defend>1)
			{
				cout<<"���ڲ�༶������2�������������»غϷ��������ж������ͷ�"<<endl;
			}
			return;
		}
	}
	cout<<"������󣬲�����Ч��ָ�����"<<endl;
	return;
}
void main()
{
	srand((int)time(0));//��ʼ����������ɺ�������
	cout<<"������Ҫִ�еĲ������ţ�0.�˳� 1.���������ж�ϵͳ 2.1d100ϵͳ"<<endl;
	int i;
	cin>>i;
	for(;i!=0;)
	{
		if(i==1)
		{
			cout<<"�����빥�������ж���ֵ������ѡ�����ͳͷ���������"<<endl;
			cout<<"���������ж����ݣ����֣���"<<endl;
			int attack=0;
			cin>>attack;
			cout<<"�����뽱���ͳͷ�������������Ϊ����������Ϊ�ͷ�"<<endl;
			int attack_bonus;
			cin>>attack_bonus;
			int attack_power=Decide(attack,attack_bonus);
			Report(attack_power);
			int defend;	
			cout<<"���������ж����ݣ����֣���"<<endl;
			cin>>defend;
			cout<<"�����뽱���ͳͷ�������������Ϊ����������Ϊ�ͷ�"<<endl;
			int defend_bonus;
			cin>>defend_bonus;
			int defend_power=Decide(defend,defend_bonus);
			Report(defend_power);
			All_check(attack_power,defend_power);
		}
	else if(i==2)
	{
		cout<<"��������Ҫ����������"<<endl;
		int number;
		cin>>number;
		cout<<"roll��Ϊ:"<<1+Random(number)<<endl;;
	}
	else
	{
		cout<<"�������˴����ָ����������"<<endl;
	}
	cout<<"������Ҫִ�еĲ������ţ�0.�˳� 1.���������ж�ϵͳ 2.1d100ϵͳ"<<endl;
	cin>>i;
	}
}

