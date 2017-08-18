#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define Random(x)(rand()%x)//随机数生成函数，生成0~x之间的一个随机数,使用时采用1+Random(99)来取得1~100中的任意整数，从而还原1D100

int Roll_number(int bonus)
{
	int roll=1+Random(99);
	cout<<"投出数字为："<<roll<<endl;
	if(bonus==0)//正常，直接骰个数字返回
	{
		return roll;
	}
	if(bonus>0)//奖励，进入奖励骰判定
	{
		for(int i=0;i<bonus;i++)
		{
			cout<<"进入第"<<i+1<<"次奖励骰"<<endl;
			int roll_new=1+Random(99);//奖励骰投出数字
			cout<<"奖励骰骰出:"<<roll_new<<endl;
			if(roll>roll_new)
			{
				roll=roll_new;	
			}
			cout<<"目前有效数字为:"<<roll<<endl;
		}
		return roll;
	}
	if(bonus<0)//惩罚，进入惩罚骰判定
	{
		for(int i=0;i<-bonus;i++)
		{
			cout<<"进入第"<<i+1<<"次惩罚骰"<<endl;
			int roll_new=1+Random(99);//奖励骰投出数字
			cout<<"惩罚骰骰出:"<<roll_new<<endl;
			if(roll<roll_new)
			{
				roll=roll_new;	
			}
			cout<<"目前有效数字为:"<<roll<<endl;
		}
		return roll;
	}
	return roll;//出现特殊情况，随便判定= -=
}
int Decide(int ability,int bonus)//确定获得的为极大失败，失败，成功，大成功还是极大成功，返回分别为-1，0，1，2，3
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
void Report(int power)//汇报判定状态
{
	if(power==0)
	{
		cout<<"判定为失败(级别0)"<<endl;
	}
	else if(power==1)
	{
		cout<<"判定为成功（级别1）"<<endl;
	}
	else if(power==2)
	{
		cout<<"判定为大成功（级别2）"<<endl;
	}
	else if(power==3)
	{
		cout<<"判定为极大成功（级别3）"<<endl;
	}
	else if(power==4)
	{
		cout<<"请注意！本次判定为极限成功（级别4）"<<endl;
	}
}
void All_check(int attack,int defend)
{
	int situation;
	cout<<"请输入判定状况代号（1为闪避，2为反击，3为物理格挡，4为魔力格挡）"<<endl;
	cin>>situation;
	if(situation==1)//闪避状况
	{
		if(attack<defend)//闪过去了
		{
			cout<<"防御方成功闪避，收到伤害为0"<<endl;
			return;
		}
		else//没闪过去，同级伤害1，等级差越高伤害越高
		{
			cout<<"防御方规避失败，收到伤害为"<<attack-defend+1<<"点伤害"<<endl;			
			return;
		}
	}
	if(situation==2)//反击状况
	{
		if(defend>attack)
		{
			cout<<"防御方反击成功，防御方受到一点伤害，进攻方受到"<<defend-attack<<endl;			
			return;
		}
		else
		{
			cout<<"防御方反击失败，防御方受到"<<1+attack-defend<<endl;
			return;
		}
	}
	if(situation==3)//物理格挡
	{
		if(defend>attack)
		{
			cout<<"防御方防御成功，没有受到伤害"<<endl;			
			return;
		}
		else
		{
			cout<<"防御方防御失败，防御方受到1点伤害"<<endl;
			if(attack-defend>1)
			{
				cout<<"由于差距级数大于2，发生崩防，下回合防御方的行动将被惩罚"<<endl;
			}
			return;
		}
	}
	if(situation==4)//魔力防御
	{
		cout<<"防御方失去10点mp"<<endl;
		if(defend>attack)
		{
			cout<<"防御方防御成功，没有受到伤害"<<endl;			
			return;
		}
		else
		{
			cout<<"防御方防御失败，防御方受到1点伤害"<<endl;
			if(attack-defend>1)
			{
				cout<<"由于差距级数大于2，发生崩防，下回合防御方的行动将被惩罚"<<endl;
			}
			return;
		}
	}
	cout<<"输入错误，并非有效的指令代码"<<endl;
	return;
}
void main()
{
	srand((int)time(0));//初始化随机数生成函数种子
	cout<<"请输入要执行的操作代号：0.退出 1.进攻防御判定系统 2.1d100系统"<<endl;
	int i;
	cin>>i;
	for(;i!=0;)
	{
		if(i==1)
		{
			cout<<"请输入攻击方的判定数值，并且选择奖励和惩罚骰的数量"<<endl;
			cout<<"攻击方的判定数据（数字）："<<endl;
			int attack=0;
			cin>>attack;
			cout<<"请输入奖励和惩罚骰数量，正数为奖励，负数为惩罚"<<endl;
			int attack_bonus;
			cin>>attack_bonus;
			int attack_power=Decide(attack,attack_bonus);
			Report(attack_power);
			int defend;	
			cout<<"防御方的判定数据（数字）："<<endl;
			cin>>defend;
			cout<<"请输入奖励和惩罚骰数量，正数为奖励，负数为惩罚"<<endl;
			int defend_bonus;
			cin>>defend_bonus;
			int defend_power=Decide(defend,defend_bonus);
			Report(defend_power);
			All_check(attack_power,defend_power);
		}
	else if(i==2)
	{
		cout<<"请输入您要的骰子面数"<<endl;
		int number;
		cin>>number;
		cout<<"roll点为:"<<1+Random(number)<<endl;;
	}
	else
	{
		cout<<"您输入了错误的指令，请从新输入"<<endl;
	}
	cout<<"请输入要执行的操作代号：0.退出 1.进攻防御判定系统 2.1d100系统"<<endl;
	cin>>i;
	}
}

