//ʵ����Ŀ2 ����һ��ʱ����Time��������˽�г�Ա����Hour��Minute��Second�����幹�캯������������
//�Լ����ڸı䡢��ȡ�����ʱ����Ϣ�Ĺ��к������������ж���ʱ����󣬲�ͨ�����ø��ֳ�Ա�������ʱ��
// ���趨���ı䡢��ȡ������ȹ��ܡ�
//�� ��Ҫ�������Ķ�����ʵ�֡�
//�� �޸����ݳ�Ա�ķ��ʷ�ʽ���۲��������
//�� ��Time���ж���һ����Ա����������ʵ��ʱ������һ��Ĺ��ܣ���������ͨ��������øú������������
// ��һ����ʱ����Ϣ��
//�� ����һ����ͨ������
// 
//void f(Time  t)
//{
//	t.PrintTime();
//}
// 
//��Time�������ӿ������캯���Ķ��壬�������е��øú��������õ��Թ��߸��٣���������������ù��캯
// ���������������캯���������������Ĵ������ٽ�f��������ʽ�����ֱ��޸�Ϊ���ò�����ָ���������ʱ
// ���������޸�Ϊ{ t->PrintTime(); }, �������е��ã��ٷ�����ʱ���ù��캯�������������Ĵ�����
#include<iostream>
#include<string>
using namespace std;
class Time 
{
private:
	int Hour,Minute,Second;
public:
	//Time(int _Hour, int _Minute, int _Second);
	Time(const Time& t);
	~Time();
	void PrintTime();
	void IncreseOneSecond();

};

//Time::Time(int _Hour,int _Minute,int _Second):Hour(_Hour),Minute(_Minute),Second(_Second)
//{
//	cout << "constuct" << Second << endl;
//}


//�����������Ѿ�����λ�ĺ����ں�����copy constructor�����У����������Ĵ��룬
//�����һ��ǰ�IncreaceOneSecond()������д��һ�£��ڴ˶δ�������
Time::Time(const Time& t)
{
	Second = t.Second;
	Minute = t.Minute;
	Hour = t.Hour;
	if (Second <= 59)
	{
		Second = t.Second + 1;
	}
	else if (Minute <= 59)
	{
		Second = 0;
		Minute = t.Minute + 1;
	}
	else
	{
		Minute = 0;
		Hour = t.Hour + 1;
	}
	cout << "copy constuct" << Second << endl;
}
void Time::IncreseOneSecond()
{
	if (Second <= 59)
	{
		Second++;
	}
	else if (Minute <= 59)
	{
		Second = 0;
		Minute++;
	}
	else
	{
		Minute = 0;
		Hour++;
	}
}
Time::~Time()
{
	cout << "destruct" << Second << endl;
}
void Time::PrintTime()
{
	cout << Hour << "-" << Minute << "-" << Second << endl;
}

void f(Time* t)
{
	t->PrintTime();
}

int main()
{
	Time t1;
	Time t2 = t1;
	Time t3 = t2;
	cout << t3.Hour << "-" << t3.Minute << "-" << t3.Second << endl;
	f(&t3);
	return 0;
}