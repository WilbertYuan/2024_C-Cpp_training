#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int j = 0, i, k, l, m, n, b1 = 0, b2 = 0, a1, a2;
	//char A[20];
	string A = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	char B1[4] = { 0 };
	char B2[4] = { 0 };
	char C1[8] = { 0 };
	char C2[8] = { 0 };
	printf("���벻�������������Ԫ�ĺ�ʽ��ʽ����������ȼ��Ӹߵ��ͣ���");
	//gets(A);
	cin >> A;
	for (i = 0; i < 20; i++)
	{
		if (A[i] == 0)///��ֹ�������ж��ַ�������///
			break;

		if (int(A[i]) == 82)///���������Ǽ�����Ԫ///
		{
			j++;
		}
	}
	if (j == 0)
	{
		printf("�ú�ʽ��ʽ��ֵ������ͼ��ʾ��\n");
		printf("  P    Q    A  \n");
		for (k = 1; k >= 0; k--)
		{
			for (m = 1; m >= 0; m--)
			{
				for (l = 0; l < i; l++)
				{
					if (int(A[l]) == 80)
						A[l] = k;
					if (int(A[l]) == 81)
						A[l] = m;
				}
				for (l = 0; l < i; l++)
				{
					if (int(A[l]) == 33)///ȡ��///
						A[l + 1] = 1 - A[l + 1];
					if (int(A[l]) == 38)///��ȡ///
					{
						if (A[l - 1] + A[l + 1] == 2)
							A[l + 1] = 1;
						else
							A[l + 1] = 0;
					}
					if (int(A[l]) == 124)///��ȡ///
					{
						if (A[l - 1] + A[l + 1] == 0)
							A[l + 1] = 0;
						else
							A[l + 1] = 1;
					}
					if (int(A[l]) == 62)///������///
					{
						if (A[l - 1] == 1 && A[i + 1] == 0)
							A[l + 1] = 0;
						else
							A[l + 1] = 1;
					}
					if (int(A[l]) == 45)///˫����///
					{
						if (A[l - 1] == A[i + 1])
							A[l + 1] = 1;
						else
							A[l + 1] = 0;
					}
					printf("  %d    %d    %d  \n", k, m, A[i - 1]);
					///����дѭ����///
					if (A[i - 1] = 1)
					{
						B1[b1] = 10 * k + m + 1;///��ѡһ///
						b1++;
					}
					else
					{
						B2[b2] = 10 * k + m + 1;
						b2++;
					}
				}
			}
		}
		printf("�ú�ʽ��ʽ������ȡ��ʽΪ��");
		for (a1 = 0; a1 < 4; a1++)
		{
			if (A[a1] = 12)
				printf("P&Q");
			if (A[a1] = 11)
				printf("P&!Q");
			if (A[a1] = 2)
				printf("!P&Q");
			if (A[a1] = 1)
				printf("!P&!Q");
			if (a1 != 3 && A[a1 + 1] != 0)
				printf("|");
		}
		printf("�ú�ʽ��ʽ������ȡ��ʽΪ��");
		for (a2 = 0; a2 < 4; a2++)
		{
			if (A[a2] = 12)
				printf("!P|!Q");
			if (A[a2] = 11)
				printf("!P|Q");
			if (A[a2] = 2)
				printf("P|!Q");
			if (A[a2] = 1)
				printf("P|Q");
			if (a2 != 3 && A[a2 + 1] != 0)
				printf("&");
		}
	}
	else
	{
		printf("�ú�ʽ��ʽ��ֵ������ͼ��ʾ��\n");
		printf("  P    Q    R    A  \n");
		for (k = 1; k >= 0; k--)
		{
			for (m = 1; m >= 0; m--)
			{
				for (n = 1; n >=i; n--)
				{
					for (l = 0; l < i; l++)
					{
						if (int(A[l]) == 80)
							A[l] = k;
						if (int(A[l]) == 81)
							A[l] = m;
						if (int(A[l]) == 82)
							A[l] = n;
					}
					for (l = 0; l < i; l++)
					{
						if (int(A[l]) == 33)
							A[l + 1] = 1 - A[l + 1];
						if (int(A[l]) == 38)
						{
							if (A[l - 1] + A[l + 1] == 2)
								A[l + 1] = 1;
							else
								A[l + 1] = 0;
						}
						if (int(A[l]) == 124)
						{
							if (A[l - 1] + A[l + 1] == 0)
								A[l + 1] = 0;
							else
								A[l + 1] = 1;
						}
						if (int(A[l]) == 62)
						{
							if (A[l - 1] == 1 && A[i + 1] == 0)
								A[l + 1] = 0;
							else
								A[l + 1] = 1;
						}
						if (int(A[l]) == 45)
						{
							if (A[l - 1] == A[i + 1])
								A[l + 1] = 1;
							else
								A[l + 1] = 0;
						}
						printf("  %d    %d    %d    %d  \n", k, m, n, A[i - 1]);

						if (A[i - 1] = 1)
						{
							B1[b1] = 100 * k + 10 * m + n * 1;///��ѡһ///
							b1++;
						}
						else
						{
							B2[b2] = 10 * k + m + 1;
							b2++;
						}
					}
				}
			}
		}
		printf("�ú�ʽ��ʽ������ȡ��ʽΪ��");
		for (a1 = 0; a1 < 4; a1++)
		{
			if (A[a1] = 112)
				printf("P&Q&R");
			if (A[a1] = 111)
				printf("P&Q&!R");
			if (A[a1] = 102)
				printf("P&!Q&R");
			if (A[a1] = 101)
				printf("P&!Q&!R");
			if (A[a1] = 12)
				printf("!P&Q&R");
			if (A[a1] = 11)
				printf("!P&Q&!R");
			if (A[a1] = 2)
				printf("!P&!Q&R");
			if (A[a1] = 1)
				printf("!P&!Q&!R");
			if (a1 != 3 && A[a1 + 1] != 0)
				printf("|");
		}
		printf("�ú�ʽ��ʽ������ȡ��ʽΪ��");
		for (a1 = 0; a1 < 4; a1++)
		{
			if (A[a1] = 112)
				printf("!P|!Q|!R");
			if (A[a1] = 111)
				printf("!P|!Q&|R");
			if (A[a1] = 102)
				printf("!P|Q|!R");
			if (A[a1] = 101)
				printf("!P|Q|R");
			if (A[a1] = 12)
				printf("P|!Q|!R");
			if (A[a1] = 11)
				printf("P|!Q|R");
			if (A[a1] = 2)
				printf("P|Q|!R");
			if (A[a1] = 1)
				printf("P|Q|R");
			if (a1 != 3 && A[a1 + 1] != 0)
				printf("&");
		}
	}
	return 0;
}