#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<random>
#include<iostream>
#include<chrono>

using namespace std;

int main()
{
	while (true)
	{
		int num = 0, num2 = 0;
		cout << "�����뼯��Ԫ�صĸ�����" << endl;
		cin >> num;
		if (!num)
		{
			cout << endl << "�������Է���" << endl << "���㷴�Է���" << endl << "����Գ���" << endl << "���㷴�Գ���" << endl;
		}
		else
		{
			int** p = new int* [num];
			for (int i = 0; i < num; i++)
			{
				*(p + i) = new int[num];
			}

			std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
			//default_random_engine generator;
			uniform_int_distribution<int> distribution(0, 1);

			for (int i = 0; i < num; i++)
			{
				for (int j = 0; j < num; j++)
				{
					*(*(p + i) + j) = distribution(generator);
				}
			}

			cout << "������������������" << endl;
			for (int i = 0; i < num; i++)
			{
				for (int j = 0; j < num; j++)
				{
					cout << *(*(p + i) + j) << " ";
				}
				cout << endl;
			}

			int flag1 = 1;
			for (int j = 0; j < num; j++)
			{
				if (*(*(p + j) + j) == 0)
				{
					cout << "�������Է��ԣ�����ĵ�" << j + 1 << "�У���" << j + 1 << "��Ӧ��Ϊ1" << endl;
					flag1 = 0;
					break;
				}
			}
			if (flag1) cout << "�����Է���" << endl;


			int flag2 = 1;
			for (int j = 0; j < num; j++)
			{
				if (*(*(p + j) + j) == 1)
				{
					cout << "�����㷴�Է��ԣ�����ĵ�" << j + 1 << "�У���" << j + 1 << "��Ӧ��Ϊ0" << endl;
					flag2 = 0;
					break;
				}
			}
			if (flag2) cout << "���㷴�Է���" << endl;

			int flag3 = 1;
			for (int i = 0; i < num; i++)
			{
				if (flag3)
				{
					for (int j = 0; j < num; j++)
					{
						if (*(*(p + i) + j) != *(*(p + j) + i))
						{
							cout << "������Գ��ԣ�����ĵ�" << j + 1 << "�У���" << i + 1 << "��Ӧ��Ϊ" << *(*(p + i) + j) << endl;
							flag3 = 0;
							break;
						}
					}
				}
			}
			if (flag3) cout << "����Գ���" << endl;

			int flag4 = 1;
			for (int i = 0; i < num; i++)
			{
				if (flag4)
				{
					for (int j = 0; j < num; j++)
					{
						if ((*(*(p + i) + j) == 1) && (*(*(p + i) + j) == *(*(p + j) + i)) && (i != j))
						{
							cout << "�����㷴�Գ��ԣ�����ĵ�" << j + 1 << "�У���" << i + 1 << "��Ӧ��Ϊ" << 0 << endl;
							flag4 = 0;
							break;
						}
					}
				}
			}
			if (flag4) cout << "���㷴�Գ���" << endl;

			for (int i = 0; i < num; i++)
			{
				delete[] * (p + i);
			}
			delete[] p;
		}

		cout << endl << endl;
	}

	return 0;
}